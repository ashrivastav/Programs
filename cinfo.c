#include <stdio.h>

int main()
{
	#ifdef DEBUG
	printf("Compiled:" __DATE__ " on" __TIME__ "\n");
	printf("This is line %d of file ",__LINE__ __FILE__"\n");
	#endif
	exit(0);
}
