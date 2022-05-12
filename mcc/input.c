int (fun)(const char *a,const char*b)
{
	return 1;
}
//fun will be def later
int undef(void);
char sym = 's';
int main()
{
	int (fun) (int,char);
	int a = 10+3;
	int arr[15];
	int braces =(5);
	int ccc = arr["zzzz"];
	const static int;
	float zzz=3,bbb=3;
	{
		int var =3;
		float z=3;
		{
			float g=10;
		}
	}
	fun(a,sym);
	fun("%s","hello");
	fun(1,2);
	return 0;
}
