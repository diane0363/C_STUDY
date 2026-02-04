#include <stdio.h>

union number
{
    char a;
    short b;
    long c;
} my_union;

int main()
{
    my_union.c = (long)0x12345678;
    printf("Long value :%08lx\n", my_union.c);
    printf("Short value: %08hx\n", my_union.b);
    printf("Char value : %08x\n", my_union.a);
}