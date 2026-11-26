// TRABALHO N2 - ALGORITMOS II
// SISTEMA DE CONTROLE DE PNEUS
// Integrantes:
// Pessoa 1: Gabrielly de Oliveira
// Pessoa 2: Rayssa Carasilo
// Professor: Alessandro João Brassanini

#include <stdio.h>
#include <string.h>

#define linhas 5
#define colunas 4

// ==========================================
// FUNCAO DE LOGIN
// ==========================================
int login() {
    char usuario[30];
    char senha[30];

    printf("====================================\n");
    printf("          SISTEMA DE PNEUS\n");
    printf("====================================\n");

    printf("\nUsuario: ");
    scanf("%29s", usuario);

    printf("Senha: ");
    scanf("%29s", senha);

    if (strcmp(usuario, "uniavan") == 0 && strcmp(senha, "123") == 0) {
        printf("\nLogin realizado com sucesso!\n");
        return 1;
    } else {
        printf("\nUsuario ou senha incorretos!\n");
        return 0;
    }
}

// ==========================================
// FUNCOES DE CADASTRO 
// ==========================================

// Inicializa a matriz de acordo com o veiculo:
//  0 = posicao valida e vazia
// -1 = posicao inexistente nesse veiculo
void matrizes(int pneus[linhas][colunas], int tipoVeiculo) {
    int totalEixos = 0;

    switch (tipoVeiculo) {
        case 1:
            totalEixos = 2; // Toco: 1 dianteiro + 1 traseiro
            break;
        case 2:
            totalEixos = 3; // Truck: 1 dianteiro + 2 traseiros
            break;
        case 3:
            totalEixos = 5; // Carreta: 1 dianteiro + 1 cavalo + 3 carreta
            break;
        default:
            totalEixos = 0;
            break;
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (i >= totalEixos) {
                pneus[i][j] = -1;
            } else if (i == 0 && (j == 1 || j == 2)) {
                pneus[i][j] = -1; // Eixo dianteiro possui apenas DE e DD
            } else {
                pneus[i][j] = 0;
            }
        }
    }
}

// Verifica se o numero de fogo ja existe na matriz (1 = repetido, 0 = livre)
int fiscalizacaoPneus(int pneus[linhas][colunas], int nFogo) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (pneus[i][j] == nFogo) {
                return 1;
            }
        }
    }
    return 0;
}

// Cadastra os numeros de fogo sem permitir repeticao ou valores <= 0
void cadastroPneus(int pneus[linhas][colunas], int tipoVeiculo) {
    matrizes(pneus, tipoVeiculo);

    int num;
    int totalEixos = (tipoVeiculo == 1) ? 2 : (tipoVeiculo == 2) ? 3 : 5;

    printf("\n--- CADASTRO DE NUMERO DE FOGO ---\n");

    for (int i = 0; i < totalEixos; i++) {
        for (int j = 0; j < colunas; j++) {
            if (pneus[i][j] == -1) {
                continue;
            }

            do {
                printf("Digite o numero de fogo para Eixo %d, Posicao %d: ", i + 1, j + 1);
                scanf("%d", &num);

                if (num <= 0) {
                    printf("Numero invalido! Digite um numero maior que zero.\n");
                } else if (fiscalizacaoPneus(pneus, num)) {
                    printf("Numero ja cadastrado! Digite outro numero unico.\n");
                }
            } while (num <= 0 || fiscalizacaoPneus(pneus, num));

            pneus[i][j] = num;
        }
    }
}

// Imprime o numero do pneu ou "---" se ainda nao houver pneu vinculado
void imprimirPneu(int valor) {
    if (valor <= 0) {
        printf("[ --- ]");
    } else {
        printf("[%5d]", valor);
    }
}

// ==========================================
// DESENHOS COM DADOS DA MATRIZ
// ==========================================

void mostrarToco(int pneus[linhas][colunas]) {
    printf("\n====================================\n");
    printf("             CAMINHAO TOCO\n");
    printf("====================================\n");

    printf("\n                 FRENTE\n");
    printf("             ______________\n");
    printf("            |              |\n");
    printf("            |    CABINE    |\n");
    printf("            |______________|\n\n");

    printf("        ");
    imprimirPneu(pneus[0][0]); // DE
    printf("       ");
    imprimirPneu(pneus[0][3]); // DD
    printf("\n\n");

    printf("        ");
    imprimirPneu(pneus[1][0]); // TEE
    printf("     ");
    imprimirPneu(pneus[1][2]); // TDI
    printf("\n");

    printf("        ");
    imprimirPneu(pneus[1][1]); // TEI
    printf("     ");
    imprimirPneu(pneus[1][3]); // TDE
    printf("\n\n");

    printf("                TRASEIRA\n");
}

void mostrarTruck(int pneus[linhas][colunas]) {
    printf("\n====================================\n");
    printf("              CAMINHAO TRUCK\n");
    printf("====================================\n");

    printf("\n                 FRENTE\n");
    printf("             ______________\n");
    printf("            |              |\n");
    printf("            |    CABINE    |\n");
    printf("            |______________|\n\n");

    printf("        ");
    imprimirPneu(pneus[0][0]); // DE
    printf("       ");
    imprimirPneu(pneus[0][3]); // DD
    printf("\n\n");

    printf("        ");
    imprimirPneu(pneus[1][0]); // TEE (Eixo 1)
    printf("     ");
    imprimirPneu(pneus[1][2]); // TDI (Eixo 1)
    printf("\n");

    printf("        ");
    imprimirPneu(pneus[1][1]); // TEI (Eixo 1)
    printf("     ");
    imprimirPneu(pneus[1][3]); // TDE (Eixo 1)
    printf("\n\n");

    printf("        ");
    imprimirPneu(pneus[2][0]); // TEE (Eixo 2)
    printf("     ");
    imprimirPneu(pneus[2][2]); // TDI (Eixo 2)
    printf("\n");

    printf("        ");
    imprimirPneu(pneus[2][1]); // TEI (Eixo 2)
    printf("     ");
    imprimirPneu(pneus[2][3]); // TDE (Eixo 2)
    printf("\n\n");

    printf("                TRASEIRA\n");
}

void mostrarCarreta(int pneus[linhas][colunas]) {
    printf("\n====================================\n");
    printf("          CARRETA DE 3 EIXOS\n");
    printf("====================================\n");

    printf("\n                 FRENTE\n");
    printf("             ______________\n");
    printf("            |              |\n");
    printf("            |    CABINE    |\n");
    printf("            |______________|\n\n");

    printf("        ");
    imprimirPneu(pneus[0][0]); // DE
    printf("       ");
    imprimirPneu(pneus[0][3]); // DD
    printf("\n\n");

    printf("       EIXO TRASEIRO DO CAVALO\n");
    printf("        ");
    imprimirPneu(pneus[1][0]);
    printf("     ");
    imprimirPneu(pneus[1][2]);
    printf("\n");
    printf("        ");
    imprimirPneu(pneus[1][1]);
    printf("     ");
    imprimirPneu(pneus[1][3]);
    printf("\n\n");

    printf("              CARRETA\n\n");

    printf("               EIXO 1\n");
    printf("        ");
    imprimirPneu(pneus[2][0]);
    printf("     ");
    imprimirPneu(pneus[2][2]);
    printf("\n");
    printf("        ");
    imprimirPneu(pneus[2][1]);
    printf("     ");
    imprimirPneu(pneus[2][3]);
    printf("\n\n");

    printf("               EIXO 2\n");
    printf("        ");
    imprimirPneu(pneus[3][0]);
    printf("     ");
    imprimirPneu(pneus[3][2]);
    printf("\n");
    printf("        ");
    imprimirPneu(pneus[3][1]);
    printf("     ");
    imprimirPneu(pneus[3][3]);
    printf("\n\n");

    printf("               EIXO 3\n");
    printf("        ");
    imprimirPneu(pneus[4][0]);
    printf("     ");
    imprimirPneu(pneus[4][2]);
    printf("\n");
    printf("        ");
    imprimirPneu(pneus[4][1]);
    printf("     ");
    imprimirPneu(pneus[4][3]);
    printf("\n\n");

    printf("                TRASEIRA\n");
}

// Exibe a disposicao atual conforme o veiculo selecionado
void exibirVeiculo(int pneus[linhas][colunas], int tipoVeiculo) {
    if (tipoVeiculo == 1) {
        mostrarToco(pneus);
    } else if (tipoVeiculo == 2) {
        mostrarTruck(pneus);
    } else if (tipoVeiculo == 3) {
        mostrarCarreta(pneus);
    } else {
        printf("\nNenhum veiculo cadastrado ainda! Escolha as opcoes 1, 2 ou 3 primeiro.\n");
    }
}

// ==========================================
// RODIZIO DE PNEUS 
// ==========================================
void rodizioPneus(int pneus[linhas][colunas], int tipoVeiculo) {
    if (tipoVeiculo == 0) {
        printf("\nCadastre um veiculo (Toco, Truck ou Carreta) antes de fazer o rodizio.\n");
        return;
    }

    int pneu1, pneu2;
    int l1 = -1, c1 = -1, l2 = -1, c2 = -1;

    exibirVeiculo(pneus, tipoVeiculo);

    printf("\nDigite o numero de fogo do primeiro pneu: ");
    scanf("%d", &pneu1);

    printf("Digite o numero de fogo do segundo pneu: ");
    scanf("%d", &pneu2);

    if (pneu1 == pneu2) {
        printf("\nVoce digitou o mesmo pneu duas vezes!\n");
        return;
    }

    if (!fiscalizacaoPneus(pneus, pneu1)) {
        printf("\nPneu %d nao encontrado no veiculo!\n", pneu1);
        return;
    }

    if (!fiscalizacaoPneus(pneus, pneu2)) {
        printf("\nPneu %d nao encontrado no veiculo!\n", pneu2);
        return;
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (pneus[i][j] == pneu1) {
                l1 = i;
                c1 = j;
            }
            if (pneus[i][j] == pneu2) {
                l2 = i;
                c2 = j;
            }
        }
    }

    int temp = pneus[l1][c1];
    pneus[l1][c1] = pneus[l2][c2];
    pneus[l2][c2] = temp;

    printf("\nRodizio realizado com sucesso entre os pneus %d e %d!\n", pneu1, pneu2);
    printf("\n--- NOVA DISPOSICAO DOS PNEUS ---\n");
    exibirVeiculo(pneus, tipoVeiculo);
}

// ==========================================
// TELA DE LEGENDA
// ==========================================
void legenda() {
    printf("\n====================================\n");
    printf("          LEGENDA DOS PNEUS\n");
    printf("====================================\n");

    printf("\nDE  - Dianteiro Esquerdo");
    printf("\nDD  - Dianteiro Direito");

    printf("\nTEE - Traseiro Externo Esquerdo");
    printf("\nTEI - Traseiro Interno Esquerdo");

    printf("\nTDE - Traseiro Externo Direito");
    printf("\nTDI - Traseiro Interno Direito");

    printf("\n\n====================================\n");
}

// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================
int main() {
    int opcao;
    int tipoVeiculo = 0; // 1 = Toco, 2 = Truck, 3 = Carreta
    int pneus[linhas][colunas];

    if (login() == 0) {
        return 0;
    }

    do {
        printf("\n\n====================================\n");
        printf("           MENU PRINCIPAL\n");
        printf("====================================\n");

        printf("\n1 - Caminhao Toco");
        printf("\n2 - Caminhao Truck");
        printf("\n3 - Carreta de 3 eixos");
        printf("\n4 - Realizar rodizio de pneus");
        printf("\n5 - Ver disposicao atual do veiculo");
        printf("\n6 - Ver legenda dos pneus");
        printf("\n0 - Sair");

        printf("\n\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                tipoVeiculo = 1;
                cadastroPneus(pneus, tipoVeiculo);
                mostrarToco(pneus);
                break;

            case 2:
                tipoVeiculo = 2;
                cadastroPneus(pneus, tipoVeiculo);
                mostrarTruck(pneus);
                break;

            case 3:
                tipoVeiculo = 3;
                cadastroPneus(pneus, tipoVeiculo);
                mostrarCarreta(pneus);
                break;

            case 4:
                rodizioPneus(pneus, tipoVeiculo);
                break;

            case 5:
                exibirVeiculo(pneus, tipoVeiculo);
                break;

            case 6:
                legenda();
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
