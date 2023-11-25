#include <editline/readline.h>
#include <editline/history.h>
#include <stdio.h>
#include <stdlib.h>

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
