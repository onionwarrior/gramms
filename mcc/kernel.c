const int VIDEO_BUF_PTR = (0xb8000);
const int IDT_TYPE_INTR = (0x0E);
const int IDT_TYPE_TRAP =(0x0F); // Селектор секции кода, установленный загрузчиком ОС
const int GDT_CS = (0x8); 
const int PIC1_PORT =(0x20); 
const int CURSOR_PORT = (0x3D4); 
const int VIDEO_WIDTH =(80);// Ширина текстового экрана
    void
    default_intr_handler();
void intr_init();
void intr_start();
void intr_enable();
void intr_disable();
void keyb_process_keys();
void keyb_handler();
void keyb_init();
void cursor_moveto(int strnum, int pos);
void out_str(int color, const char *ptr, int strnum);
void out_symb(int color, const char symb, int strnum);
char inb(short port);              // чтение из порта
void outb(short port, char data);  // Запись
void outw(short port, short data); // pintos
short enter = 0;
// поддерживаемые команды
const char INFO[] = "info";
const char HELP[] = "help";
const char CLEAR[] = "clear";
const char TICKS[] = "ticks";
const char LOADTIME[] = "loadtime";
const char CURTIME[] = "curtime";
const char UPTIME[] = "uptime";
const char CPUID[] = "cpuid";
const char SHUTDOWN[] = "shutdown";
void clear();
void info();
void help();
void loadtime();
void uptime();
void Cpuid();
void Ticks();
void curtime();
long ticks = 0;
int CurrentStr = 0, CurrentPos = 0;
int datalen = 0, starth = 0, startm = 0, starts = 0;
char data[41];     // что пользователь вводит
char scan_codes[]; //таблица скан-кодов

// Пустой обработчик прерываний. Другие обработчики могут быть реализованы по
// этому шаблону
void default_intr_handler()
{
}

// Функция инициализации системы прерываний: заполнение массива с адресами
// обработчиков
void intr_init() {
  int i;
}

void intr_start() {}

void intr_enable() {}

void intr_disable() {}

void ticks_intr_handler() {
  ticks++; // увеличиваем количетсво тиков
  outb(PIC1_PORT, 0x20); // Отправка контроллеру 8259 нотификации о том, что
                         // прерывание обработано
}

void ticks_intr_init() {
  //За разрешение прерываний от системного таймера отвечает бит 0x01 в маске
}

char inb(short port) // Чтение из порта
{
  char data;

  return data;
}

void outb(short port, char data) // Запись
{}

/* Writes the 16-bit DATA to PORT. */
void outw(short port, short data) // pintos
{
  /* See [IA32-v2b] "OUT". */
}

int strCmp(char *s1, const char *s2) // сравнение строк
{
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(char *)s1 - *(char *)s2;
}

void commands() // обработка команд
{
  if (!strCmp(data, INFO))
    info();
  else if (!strCmp(data, HELP))
    help();
  else if (!strCmp(data, CLEAR))
    clear();
  else if (!strCmp(data, TICKS))
    Ticks();
  else if (!strCmp(data, CURTIME))
    curtime();
  else if (!strCmp(data, LOADTIME))
    loadtime();
  else if (!strCmp(data, UPTIME))
    uptime();
  else if (!strCmp(data, CPUID))
    Cpuid();
  else if (!strCmp(data, SHUTDOWN))
    outw(0x604, 0x2000);
  else {
    if (CurrentStr == 24) // для предпоследней строки
      clear();
    out_str(0x07, "Invalid command. Please, try again", CurrentStr++);
    CurrentPos = 0;
    cursor_moveto(CurrentStr, CurrentPos);
  }
  datalen = 0; // чистим буфер данных
	int i;
  for (i = 0; i < 41; i++)
    data[i] = '\0';
}

void on_key(char scan_code) // обработка введённого символа
{
  enter = 0;
  if (scan_code == 14) // бекспейс
  {
    if (!datalen) // ничего не было введено -- стирать нельзя
      return;
    CurrentPos--;
    data[--datalen] = '\0';
    out_symb(0x07, '\0', CurrentStr);
    cursor_moveto(CurrentStr, --CurrentPos);
  } else if (scan_code == 28) // энтер
  {
    if (CurrentStr == 24) {
      clear();
      CurrentStr--;
    }
    out_symb(0x07, scan_codes[scan_code], CurrentStr++);
    CurrentPos = 0;
    commands(); // обрабатываем, что было введено
  } else if (CurrentPos >= 40) // нельзя вводить больше 40 символов
    return;
  else if (scan_code == 15) // табуляция как 4 символа
  {
    if (CurrentPos == 37) // иначе вылет за 40 символов
      return;
    out_str(0x07, "    ", CurrentStr);
    data[datalen++] = ' ';
    data[datalen++] = ' ';
    data[datalen++] = ' ';
    data[datalen++] = ' ';
  } else {
    out_symb(0x07, scan_codes[scan_code],
             CurrentStr); // выводим введённый символ
    data[datalen++] = scan_codes[scan_code]; // запоминаем его
  }
}

void keyb_process_keys() {
  // Проверка что буфер PS/2 клавиатуры не пуст (младший бит присутствует)
  if (inb(0x64) & 0x01) {
    char scan_code;
    char state;
    scan_code = inb(0x60); // Считывание символа с PS/2 клавиатуры
    if (scan_code < 128) // Скан-коды выше 128 - это отпускание клавиши
      on_key(scan_code);
  }
}
void keyb_handler() {
  // Обработка поступивших данных
  keyb_process_keys();
  // Отправка контроллеру 8259 нотификации о том, что прерывание обработано
  outb(PIC1_PORT, 0x20);
}
void keyb_init() { // Регистрация обработчика прерывания
  // Разрешение только прерываний клавиатуры от контроллера 8259
  outb(PIC1_PORT + 1,
       0xFF ^ 0x02); // 0xFF - все прерывания, 0x02 - бит IRQ1 (клавиатура).
} // Разрешены будут только прерывания, чьи биты установлены в 0

// Функция переводит курсор на строку strnum (0 – самая верхняя) в позицию pos
// на этой строке (0 – самое левое положение).
void cursor_moveto(int strnum, int pos) {
  if (CurrentStr > 24) // после 25 строки чистим экран
    clear();
  short new_pos = (strnum * VIDEO_WIDTH) + pos;
  outb(CURSOR_PORT, 0x0F);
  outb(CURSOR_PORT + 1, (char)(new_pos & 0xFF));
  outb(CURSOR_PORT, 0x0E);
  outb(CURSOR_PORT + 1, (char)((new_pos >> 8) & 0xFF));
  CurrentStr = strnum; // чтобы избежать несостыковок при вызовах с констатными
                       // значениями
  CurrentPos = pos;
}

void out_str(int color, const char *ptr, int strnum) {
  char *video_buf = (char *)VIDEO_BUF_PTR;
  video_buf +=
      80 * 2 * strnum +
      CurrentPos * 2; // для сдвига не только по строке, но и по позиции символа
  while (*ptr) {
    video_buf[0] = (char)*ptr; // Символ (код)
    video_buf[1] = color;      // Цвет символа и фона
    video_buf += 2;
    ptr++;
    CurrentPos++;
  }
  if (enter) // нужен ли перенос курсора на след строку
    CurrentPos = 0;
  cursor_moveto(CurrentStr, CurrentPos); // перенос курсора
}

void out_symb(int color, const char symb,
              int strnum) // аналог out_str, только с 1 символом
{
  char *video_buf = (char *)VIDEO_BUF_PTR;
  video_buf += 80 * 2 * strnum + CurrentPos * 2;
  video_buf[0] = (char)symb; // Символ (код)
  video_buf[1] = color;      // Цвет символа и фона
  video_buf += 2;
  CurrentPos++;
  cursor_moveto(CurrentStr, CurrentPos);
}

void help() // вывод поддерживаемых команд
{
  if (CurrentStr > 14) // максимальная строка 25-11
    clear();
  enter = 1; // каждая строка на новой строчке
  const char *COM = "The InfoOS supports these commands:";
  out_str(0x07, COM, CurrentStr++);
  out_str(0x07, INFO, CurrentStr++);
  out_str(0x07, HELP, CurrentStr++);
  out_str(0x07, CLEAR, CurrentStr++);
  out_str(0x07, TICKS, CurrentStr++);
  out_str(0x07, LOADTIME, CurrentStr++);
  out_str(0x07, CURTIME, CurrentStr++);
  out_str(0x07, UPTIME, CurrentStr++);
  out_str(0x07, CPUID, CurrentStr++);
  out_str(0x07, SHUTDOWN, CurrentStr++);
}
void info() // вывод информации
{
  enter = 1; // каждая строка на новой строчке
  if (CurrentStr > 19) // максимальная строка 25-6
    clear();
  out_str(0x07, "Author Teryoshkina E.A. 4851001/90001", CurrentStr++);
  out_str(0x07, "Task: InfoOS (var 12)", CurrentStr++);
  out_str(0x07, "OS: Linux", CurrentStr++);
  out_str(0x07, "ASM translator: GNU assembler (Intel)", CurrentStr++);
  out_str(0x07, "Kernel compiler: gcc", CurrentStr++);
}
void clear() // очистка экрана
{
  char *video_buf = (char *)VIDEO_BUF_PTR;
	int i;
  for ( i = 0; i < VIDEO_WIDTH * 25; ++i)
    *(video_buf + i * 2) = 0; // заполняем экран нулевым символом
  cursor_moveto(0, 0);
}
void Ticks() // вывод количетсва тиков, прошедших со старта
{
  if (CurrentStr == 24) // предпоследняя строка -- нужен вывод на 0,0
    clear();
  char tmpticks[50]; // простая реализация itoa()
  int i = 0;
  long int n = ticks;
  do {
    tmpticks[i++] = n % 10 + 48;
  } while ((n /= 10));
  tmpticks[i] = '\0';
  int j = i - 1;
  char c;
  for (i = 0; i < j; i++, j--) {
    c = tmpticks[i];
    tmpticks[i] = tmpticks[j];
    tmpticks[j] = c;
  }
  enter = 0; // перенос не нужен
  out_str(0x07, tmpticks, CurrentStr);
  enter = 1; // перенос нужен
  out_str(0x07, " ticks have passed since the start", CurrentStr++);
}
void curtime() // вывод текущего времени
{
  if (CurrentStr == 24) // предпоследняя строка -- нужен вывод на 0,0
    clear();
  enter = 0;
  out_str(0x07, "Current time is: ", CurrentStr);

  outb(0x70, 0); // записываем в порт выхода регистр отвечающий за секунды
  int seconds = inb(0x71); // получаем данные
  seconds = ((seconds & 0xF0) >> 4) * 10 + (seconds & 0x0F); // bcd_to_dec
  seconds %= 60;

  outb(0x70, 2); // записываем в порт выхода регистр отвечающий за минуты
  int minutes = inb(0x71);
  minutes = ((minutes & 0xF0) >> 4) * 10 + (minutes & 0x0F);
  minutes %= 60;

  outb(0x70, 4); // записываем в порт выхода регистр отвечающий за часы
  int hours = inb(0x71);
  hours = ((hours & 0xF0) >> 4) * 10 + (hours & 0x0F) +
          3; // часы получаются по GMT времени, для мск-времени +3
  hours %= 24;

  out_symb(0x07, (hours / 10) + 48, CurrentStr); // вывод в формате чч:мм:сс
  out_symb(0x07, (hours % 10) + 48, CurrentStr);
  out_symb(0x07, ':', CurrentStr);
  out_symb(0x07, (minutes / 10) + 48, CurrentStr);
  out_symb(0x07, (minutes % 10) + 48, CurrentStr);
  out_symb(0x07, ':', CurrentStr);
  out_symb(0x07, (seconds / 10) + 48, CurrentStr);
  out_symb(0x07, (seconds % 10) + 48, CurrentStr++);
  cursor_moveto(CurrentStr, 0);
}
void uptime() // вывод времени, прошедшее с момента старта ос
{
  if (CurrentStr == 24) // предпоследняя строка -- нужен вывод на 0,0
    clear();
  outb(0x70, 0);
  int seconds = inb(0x71);
  seconds = ((seconds & 0xF0) >> 4) * 10 + (seconds & 0x0F);
  seconds %= 60;
  outb(0x70, 2);
  int minutes = inb(0x71);
  minutes = ((minutes & 0xF0) >> 4) * 10 + (minutes & 0x0F);
  minutes %= 60;
  outb(0x70, 4);
  int hours = inb(0x71);
  hours = ((hours & 0xF0) >> 4) * 10 + (hours & 0x0F) + 3;
  hours %= 24;
  int diff =
      (seconds + minutes * 60 + hours * 3600) -
      (starts + startm * 60 + starth * 3600); // считаем разницу в секундах
  if (diff < 0)
    diff += (3600 *
             24); // если разница отрицательная то прибавляем "день" в секундах
  hours = diff / 3600; // часы
  diff -= (hours * 3600);
  minutes = diff / 60; // минуты
  diff -= (minutes * 60);
  seconds = diff; // секунды
  enter = 0;      // перенос не нужен
  out_str(0x07, "Uptime is ", CurrentStr);
  if (hours) // если есть прошедший(е) час(ы)
  {
    if (hours / 10) // если в 2 цифры
      out_symb(0x07, (hours / 10) + 48, CurrentStr);
    out_symb(0x07, (hours % 10) + 48, CurrentStr);
    out_str(0x07, (hours == 1) ? (" hour") : (" hours"),
            CurrentStr);    // обработка ед/мн числа
    if (minutes || seconds) // если есть минуты или секунды
      out_str(0x07, " and ", CurrentStr);
  }
  if (minutes) {
    if (minutes / 10)
      out_symb(0x07, (minutes / 10) + 48, CurrentStr);
    out_symb(0x07, (minutes % 10) + 48, CurrentStr);
    out_str(0x07, (minutes == 1) ? (" minute") : (" minutes"), CurrentStr);
    if (seconds)
      out_str(0x07, " and ", CurrentStr);
  }
  if (seconds) {
    if (seconds / 10)
      out_symb(0x07, (seconds / 10) + 48, CurrentStr);
    out_symb(0x07, (seconds % 10) + 48, CurrentStr);
    out_str(0x07, (seconds == 1) ? (" second") : (" seconds"), CurrentStr);
  }
  cursor_moveto(++CurrentStr, 0);
}
void loadtime() // вывод времени, которые было на момент загрузки ос
{
  if (CurrentStr == 24) // предпоследняя строка -- нужен вывод на 0,0
    clear();
  enter = 0;
  out_str(0x07, "OS loaded at: ", CurrentStr);
  char *tmp =
      (char
           *)0x100; // в загрузчике по этому адресу было помещено значение из ch
  int time = ((*tmp & 0xF0) >> 4) * 10 + (*tmp & 0x0F) + 3; // hours
  out_symb(0x07, (time / 10) + 48, CurrentStr);
  out_symb(0x07, (time % 10) + 48, CurrentStr);
  out_symb(0x07, ':', CurrentStr);

  tmp = (char *)0x101;                              // из cl
  time = ((*tmp & 0xF0) >> 4) * 10 + (*tmp & 0x0F); // minutes
  out_symb(0x07, (time / 10) + 48, CurrentStr);
  out_symb(0x07, (time % 10) + 48, CurrentStr);
  out_symb(0x07, ':', CurrentStr);

  tmp = (char *)0x102;                              // из dh
  time = ((*tmp & 0xF0) >> 4) * 10 + (*tmp & 0x0F); // seconds
  out_symb(0x07, (time / 10) + 48, CurrentStr);
  out_symb(0x07, (time % 10) + 48, CurrentStr++);
  cursor_moveto(CurrentStr, 0);
}

void Cpuid() // вывод вендорайди, запись в порядке HEX-значения EBX:EDX:ECX
{
  if (CurrentStr == 24) // предпоследняя строка -- нужен вывод на 0,0
    clear();
  enter = 0;
  out_str(0x07, "VendorId: ", CurrentStr);
  int a = 0x00, b, c, d;

  do {
    out_symb(0x07, b & 0xff, CurrentStr);
  } while (b >>= 8); // побайтово выводим справа налево
  do {
    out_symb(0x07, d & 0xff, CurrentStr);
  } while (d >>= 8);
  do {
    out_symb(0x07, c & 0xff, CurrentStr);
  } while (c >>= 8);
  cursor_moveto(++CurrentStr, 0);
}

int kmain() {
  clear(); // очищаем экран

  outb(0x70, 0); // вычисление времени старта
  starts = inb(0x71);
  starts = ((starts & 0xF0) >> 4) * 10 + (starts & 0x0F);
  starts %= 60;
  outb(0x70, 2);
  startm = inb(0x71);
  startm = ((startm & 0xF0) >> 4) * 10 + (startm & 0x0F);
  startm %= 60;
  outb(0x70, 4);
  starth = inb(0x71);
  starth = ((starth & 0xF0) >> 4) * 10 + (starth & 0x0F) + 3;
  starth %= 24;

  const char *hello = "Welcome to InfoOs!";
  out_str(0x07, hello, CurrentStr++);
  cursor_moveto(CurrentStr, 0);

  intr_init();       // прерывания
  keyb_init();       // клавиатуры
  ticks_intr_init(); // таймера
  intr_start();
  intr_enable(); // включаем

  while (1) {
    г
  }
  return 0;
}
