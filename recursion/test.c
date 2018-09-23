int main()
{
	static int i=0;
	while(i<200000)
	{
		printf(" %d \n",i);
		i++;
		main();
		main();
	}
}
