#include <stdio.h>

/* Buffer para o input do usuário, com até 2048 caracteres */
static char input[2048];

int main(int argc, char *argv[])
{
    /* Versão e informação de saída */
    puts("Lisp-CR, versão 0.0.1");
    puts("Digite \"Ctrl + C\" para sair.");

    /* Loop infinito do prompt */
    while (1)
    {
        /* Mostra o prompt */
        fputs("lispcr> ", stdout);

        /* Lê o input do usuário, até o limite de 2048 caracteres */
        fgets(input, 2048, stdin);

        /* Mostra o input do usuário */
        printf("Você digitou: %s", input);
    }

    return 0;
}
