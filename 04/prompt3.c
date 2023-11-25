/* Se é Linux ou Mac (se não é Windows) */
#ifndef _WIN32
#include <editline/readline.h>
#include <editline/history.h>
#endif

#include <stdio.h>
#include <stdlib.h>

/* Se é Windows */
#ifdef _WIN32
#include <string.h>

/* buffer para funções fake */
static char buffer[2048];

/* fake readline */
char *readline(char *prompt)
{
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char *cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;n
}

/* fake add_history */
void add_history(char *unused) {}
#endif

int main(int argc, char *argv[])
{
    /* Versão e informação de saída */
    puts("Lisp-CR, versão 0.0.1");
    puts("Digite \"C-c\" para sair.");

    /* Loop infinito do prompt */
    while (1)
    {
        /* Mostra o prompt e pega o input do usuário */ 
        char *input = readline("lispcr> ");

        /* Adiciona o input no histórico */
        add_history(input);

        /* Mostra o input do usuário */
        printf("Você digitou: %s\n", input);

        /* Libera a memória alocada por readline */
        free(input);
    }

    return 0;
}
