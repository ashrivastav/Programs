int main()
{
    int a = 10;
    int *b = (char *)&a - 1;
    *b = 200;
    char *c = 10000;
    printf("%x and %x \n", b, &a);
    printf("%x and %x ", *b, a);
}
