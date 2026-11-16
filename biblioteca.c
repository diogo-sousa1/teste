#include <stdio.h>
#include "biblioteca.h"

void exibirMenu(void) {
    printf("\n=================================\n");
    printf("       SISTEMA DE BIBLIOTECA\n");
    printf("=================================\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Listar livros\n");
    printf("3 - Consultar livro\n");
    printf("4 - Emprestar livro\n");
    printf("5 - Devolver livro\n");
    printf("0 - Sair\n");
}
void cadastrarLivro(Livro biblioteca[], int *quantidade) {

    printf("\n--- CADASTRO DE LIVRO ---\n");

    printf("Codigo: ");
    scanf("%d", &biblioteca[*quantidade].codigo);

    printf("Titulo: ");
    scanf(" %[^\n]", biblioteca[*quantidade].titulo);

    printf("Autor: ");
    scanf(" %[^\n]", biblioteca[*quantidade].autor);

    printf("Ano: ");
    scanf("%d", &biblioteca[*quantidade].ano);

    printf("Quantidade de exemplares: ");
    scanf("%d", &biblioteca[*quantidade].quantidade);

    (*quantidade)++;

    printf("\nLivro cadastrado com sucesso!\n");
}


void listarLivros(Livro biblioteca[], int quantidade) {

    while(1){
        int opcao;

        printf("\n--- LISTA DE LIVROS ---\n");

        for (int i = 0; i < quantidade; i++) {
            printf("\nCodigo: %d\n", biblioteca[i].codigo);
            printf("Titulo: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Ano: %d\n", biblioteca[i].ano);
            printf("Quantidade: %d\n", biblioteca[i].quantidade);
        }
        printf("\n\n0 - Sair");
        printf("\nsair: ");
        scanf("%d", &opcao);
        if(opcao == 0)
        {
            break;
        }
    }
}

void consultarLivros(Livro biblioteca[], int quantidade) {

    while(1){

        int codigo, opcao;
        printf("\n--- CONSULTA DE LIVROS ---\n");
        printf("\nInforme o codigo do livro: ");
        scanf("%d", &codigo);

        for (int i = 0; i < quantidade; i++) {

            if(biblioteca[i].codigo == codigo){
                printf("\nCodigo: %d\n", biblioteca[i].codigo);
                printf("Titulo: %s\n", biblioteca[i].titulo);
                printf("Autor: %s\n", biblioteca[i].autor);
                printf("Ano: %d\n", biblioteca[i].ano);
                printf("Quantidade: %d\n", biblioteca[i].quantidade);
                printf("\n\n0 - Sair");
                printf("\nsair: ");
                scanf("%d", &opcao);
                if(opcao == 0)
                {
                    return;
                }
            }
        }
        printf("\nLivro nao encontrado!\n");
        printf("\n\n0 - Sair");
        printf("\nsair: ");
        scanf("%d", &opcao);
        if(opcao == 0)
        {
            return;
        }
    }
}
void emprestarLivros(Livro biblioteca[], int quantidade) {

    int codigo, encontrado = 0, opcao, emprestimo, i;

    while(1){

        printf("\n--- EMPRESTIMO DE LIVROS ---\n");
        printf("0 - Sair\n");        
        printf("1 - Pesquisa por codigo\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        
        if(opcao == 0)
        {
            break;
        }
        
        if(opcao == 1){
            printf("\nInforme o codigo do livro: ");
            scanf("%d", &codigo);
        
            for (i = 0; i < quantidade; i++) {

                if(biblioteca[i].codigo == codigo){
                printf("\nCodigo: %d\n", biblioteca[i].codigo);
                printf("Titulo: %s\n", biblioteca[i].titulo);
                printf("Autor: %s\n", biblioteca[i].autor);
                printf("Ano: %d\n", biblioteca[i].ano);
                printf("Quantidade: %d\n", biblioteca[i].quantidade);

                encontrado = 1;
                break;
                }
            }
            if(encontrado == 0){
                printf("\nLivro nao encontrado!\n");
                continue;
            }
            if(biblioteca[i].quantidade != 0){
                printf("\n1 - Sim\n");
                printf("2 - Nao\n");
                printf("Deseja fazer emprestimo deste livro: ");
                scanf("%d", &emprestimo);

                if(emprestimo == 1){
                    biblioteca[i].quantidade--;
                    printf("\nEmprestimo realizado!\n");
                    continue;
                }
                else if(emprestimo == 2){
                    continue;
                }
            }
            else{
                printf("\nNao temos exemplares no momento!\n");
            }
        }

    }
}
