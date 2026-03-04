#include <stdio.h>
#include <string.h>

#define qtd_itens 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

int main() {
    Item mochila[qtd_itens];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n--- INVENTÁRIO BÁSICO ---\n");
        printf("1. Adicionar Item\n");
        printf("2. Buscar item por nome\n");
        printf("3. Listar Itens\n");
        printf("4. Remover Item (por nome)\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); //limpar o buffer

        switch (opcao) {
            case 1: // bloco de adição dos itens
                if (totalItens < qtd_itens) {
                    printf("Nome do item: ");
                    fgets(mochila[totalItens].nome, 30, stdin);
                    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = 0; // Remove o \n

                    printf("Tipo (Arma, Municao, Cura,etc.): ");
                    fgets(mochila[totalItens].tipo, 20, stdin);
                    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = 0;

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    
                    totalItens++;
                    printf("Item adicionado com sucesso!\n");
                } else {
                    printf("Mochila cheia! Remova algo primeiro.\n");
                }
                break;

            case 2:// bloco de busca
                char busca[30];
                int encontrado =0;
                
                printf("Digite o nome do item que deseja buscar: ");
                fgets (busca, 30, stdin);
                busca[strcspn(busca, "\n")] = 0;

                for (int i=0;i<totalItens;i++){
                    if(strcmp(mochila[i].nome, busca)==0){
                        printf("Item Encontrado! \n");
                        printf("Nome: %s\n", mochila[i].nome);
                        printf("Descricao: %s\n",mochila[i].tipo);
                        printf("Qtd: %d\n", mochila[i].quantidade);
                        encontrado=1;
                        break;//parar a busca assim que encontrar o item
                        }
                    }
                
                if(!encontrado){
                    printf("ERRO! O item %s não está no seu inventario.\n",busca);
                }
                break;
            
             case 3: // bloco de resumo do inventario
                printf("\n--- RESUMO DO SEU INVENTÁRIO ---\n");
                printf("%-15s | %-10s | %-5s\n", "NOME", "TIPO", "QTD");
                printf("--------------------------------------\n");
                for (int i = 0; i < totalItens; i++) {
                    printf("%-15s | %-10s | %-5d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                }
                if (totalItens == 0) printf("Vazio...\n");
                break;

            case 4://bloco de remoção de item
               if (totalItens == 0) {
                    printf("A mochila está vazia.\n");
                } else {
                    char busca[30];
                    int encontrado = 0;
                    printf("Nome do item para remover: ");
                    fgets(busca, 30, stdin);
                    busca[strcspn(busca, "\n")] = 0;

                    for (int i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, busca) == 0) {
                            for (int j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            totalItens--;
                            encontrado = 1;
                            printf("Item '%s' removido.\n", busca);
                            break;
                        }
                    }
                    if (!encontrado) printf("❌ Item não encontrado.\n");
                }
                break;

            case 5:
                printf("Saindo do jogo... Até mais!\n");
               break;
               
               default:
                printf("Opção inválida!\n");
        }
    } while (opcao !=6);

    return 0;
}