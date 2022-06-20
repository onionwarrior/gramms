int puts(int * string)
{
	return 1;
}
int with_const_param(const int param)
{
	param=10;
	return param;
}
int try_assign_to_rvalue()
{
	with_const_param(20)=10;
	return 42;
}
int * return_ptr()
{
	return (int*)0xDEADBEEF;
}
implicit_int_write_to_mem_check_type_cast_bidir()
{
	(*((int*)(int)return_ptr()))=10;
}
int ignore_return(int * string)
{
	return puts(string);
}
const int * NULL =(int*)0;
void try_math_with_ptr()
{
	int *ptr ;
	ptr /=2;
	ptr%=2;
	ptr*=2;
	ptr&=0xFFFF;
	ptr|=0xABCD;
	ptr^=0x1234;
}
void broken_initializer()
{
	int array[123]=20;
	int * val = array;
	int deref =array[12];
	char hello[123]="HELLO WORLD!\n";
	int helloint[123]="HELLO WORLD";
}
int ternary_operator_type_mismatch()
{
	int array[10];
	return 1?2:ternary_operator_type_mismatch;
}
const int RETURN_VALUE_ERROR = 0xFF;
const int RETURN_VALUE_OK = 0x0;
int main(int argc,char ** argv)
{
					//Assignment to const
	RETURN_VALUE_OK = RETURN_VALUE_ERROR;
	char array[10];
	puts(array);
	does_not_exist(123);
	if(argc<2)
		return RETURN_VALUE_ERROR;
	return RETURN_VALUE_OK;
	int i=0;
	for( i=0;i<5;i++)
	{
		array[i]=i;
	}
	int ardesadfs[2];
	float sum_with_epsilon;
	const float eps=0.0000000001f;
	for(i =0;i<5;i++)
	{
		sum_with_epsilon+=(eps+(float)array[i]);
	}
}
