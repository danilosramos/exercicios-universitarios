#include <stdio.h>
#define TAMANHO_VETOR 10

char codigo[TAMANHO_VETOR], busca;
int estoque[TAMANHO_VETOR], opcao, mb, mc, maes, mees, qtd_produtos, encontrado;
float valor[TAMANHO_VETOR], ve, total;

int main() {
    ve = 0;
    mb = 0;
    mc = 0;
    maes = 0;
    mees = 0;
    qtd_produtos = 0;
    encontrado = 0;

    do {
        printf("1.Cadastrar Produto\n");
        printf("2.Produtos em Estoque\n");
        printf("3.Buscar Produto por Codigo\n");
        printf("4.Produto mais Caro\n");
        printf("5.Produto mais Barato\n");
        printf("6.Produto com Menos Estoque\n");
        printf("7.Produto com Mais Estoque\n");
        printf("8.Valor do Estoque da Empresa\n");
        printf("9.Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                if (qtd_produtos < TAMANHO_VETOR) {
                    printf("Digite o codigo do produto (letra): ");
                    scanf(" %c", &codigo[qtd_produtos]);
                    printf("Digite o valor unitario do produto: ");
                    scanf("%f", &valor[qtd_produtos]);
                    printf("Digite a quantidade do produto: ");
                    scanf("%d", &estoque[qtd_produtos]);
                    qtd_produtos++;
                } else {
                    printf("Limite Max. de Produtos (10).\n");
                }
                break;
                
            }
            case 2: {
                printf("Produtos em Estoque:\n");
                for (int i = 0; i < qtd_produtos; i++) {
                    printf("Codigo: %c\n", codigo[i]);
                    printf("Estoque: %d\n", estoque[i]);
                }
                break;
                
            }
            case 3: {
                printf("Digite o codigo do produto: ");
                scanf(" %c", &busca);
                for (int i = 0; i < qtd_produtos; i++) {
                    if (codigo[i] == busca) {
                        printf("Produto encontrado:\n");
                        printf("Código: %c\n", codigo[i]);
                        printf("Valor: %.2f\n", valor[i]);
                        printf("Estoque: %d\n", estoque[i]);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Produto nao encontrado.\n");
                }
                break;
                
            }
            case 4: {
                if (qtd_produtos > 0) {
                    for (int i = 1; i < qtd_produtos; i++) {
                        if (valor[i] > valor[mc]) {
                            mc = i;
                        }
                    }
                    printf("Produto mais caro:\n");
                    printf("Codigo: %c\n", codigo[mc]);
                    printf("Valor: %.2f\n", valor[mc]);
                    printf("Estoque: %d\n", estoque[mc]);
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                break;
            }
            case 5: {
                if (qtd_produtos > 0) {
                    for (int i = 1; i < qtd_produtos; i++) {
                        if (valor[i] < valor[mb]) {
                            mb = i;
                        }
                    }
                    printf("Produto mais barato:\n");
                    printf("Código: %c\n", codigo[mb]);
                    printf("Valor: %.2f\n", valor[mb]);
                    printf("Estoque: %d\n", estoque[mb]);
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                
                break;
            }
            case 6: {
                if (qtd_produtos > 0) {
                    for (int i = 1; i < qtd_produtos; i++) {
                        if (estoque[i] < estoque[mees]) {
                            mees = i;
                        }
                    }
                    printf("Produto com menso estoque:\n");
                    printf("Código: %c\n", codigo[mees]);
                    printf("Valor: %.2f\n", valor[mees]);
                    printf("Estoque: %d\n", estoque[mees]);
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                break;
            }
            case 7: {
                if (qtd_produtos > 0) {
                    for (int i = 1; i < qtd_produtos; i++) {
                        if (estoque[i] > estoque[maes]) {
                            maes = i;
                        }
                    }
                    printf("Produto com mais estoque:\n");
                    printf("Codigo: %c\n", codigo[maes]);
                    printf("Valor: %.2f\n", valor[maes]);
                    printf("Estoque: %d\n", estoque[maes]);
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                break;
            }
            case 8: {
                if (qtd_produtos > 0) {
                    total = 0;
                    for (int i = 0; i < qtd_produtos; i++) {
                        total += valor[i] * estoque[i];
                    }
                    printf("Valor do Estoque da Empresa: %.2f\n", total);
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                break;
            }
            case 9: {
                printf("Tchau ! ! !\n");
                break;
            }
            default: {
                printf("Opcao invalida.\n");
                break;
            }
        }
    }while (opcao != 9);

    return 0;
}

