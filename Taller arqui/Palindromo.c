#include <stdio.h>

int main()
{
    char palindromo[20];
    printf("Escribe una cadena (de menos de 50 caracteres) y te voy a decir si es palindroma o no\n\t");
    scanf("%s", &palindromo);
    printf("De manera recursiva, '%s' es palindroma\n", palindromo);
    return 1;
}