//TRABALHO N2 - ALGORITMOS II
//SISTEMA DE CONTROLE DE PNEUS
//Integrantes:
//Pessoa 1: Gabrielly de Oliveira
//Pessoa 2: Rayssa Carasilo

//Professor: Alessandro João Brassanini

====================================================
*/

#include <stdio.h>
#include <string.h>

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

if (strcmp(usuario, "uniavan") == 0 &&
    strcmp(senha, "123") == 0) {

    printf("\nLogin realizado com sucesso!\n");
    return 1;

} else {
    printf("\nUsuario ou senha incorretos!\n");
    return 0;
}
}
//=======================
// DESENHO DO TOCO
//======================

void mostrarToco() {

printf("\n====================================\n");
printf("             CAMINHAO TOCO\n");
printf("====================================\n");

printf("\n                 FRENTE\n");
printf("             ______________\n");
printf("            |              |\n");
printf("            |    CABINE    |\n");
printf("            |______________|\n\n");

printf("          [DE  ]       [DD  ]\n\n");

printf("          [TEE  ]     [TDE  ]\n");
printf("          [TEI  ]     [TDI  ]\n\n");

printf("                TRASEIRA\n");
}
//=======================
// DESENHO DO TRUCK
//=======================

void mostrarTruck() {

printf("\n====================================\n");
printf("              CAMINHAO TRUCK\n");
printf("====================================\n");

printf("\n                 FRENTE\n");
printf("             ______________\n");
printf("            |              |\n");
printf("            |    CABINE    |\n");
printf("            |______________|\n\n");

printf("          [DE  ]       [DD  ]\n\n");

printf("          [TEE  ]     [TDE  ]\n");
printf("          [TEI  ]     [TDI  ]\n\n");

printf("          [TEE  ]     [TDE  ]\n");
printf("          [TEI  ]     [TDI  ]\n\n");

printf("                TRASEIRA\n");
}
//=================================
// DESENHO DA CARRETA DE 3 EIXOS
//=================================

void mostrarCarreta() {

printf("\n====================================\n");
printf("          CARRETA DE 3 EIXOS\n");
printf("====================================\n");

printf("\n                 FRENTE\n");
printf("             ______________\n");
printf("            |              |\n");
printf("            |    CABINE    |\n");
printf("            |______________|\n\n");

printf("          [DE  ]       [DD  ]\n\n");

printf("       EIXO TRASEIRO DO CAVALO\n");
printf("          [TEE  ]     [TDE  ]\n");
printf("          [TEI  ]     [TDI  ]\n\n");

printf("              CARRETA\n\n");

printf("               EIXO 1\n");
printf("          [TEE  ]     [TDE  ]\n");
printf("          [TEI  ]     [TDI  ]\n\n");

printf("               EIXO 2\n");
printf("          [TEE  ]     [TDE  ]\n");
printf("          [TEI  ]     [TDI  ]\n\n");

printf("               EIXO 3\n");
printf("          [TEE  ]     [TDE  ]\n");
printf("          [TEI  ]     [TDI  ]\n\n");

printf("                TRASEIRA\n");
}

// ==========================================
// 3 - TELA DE LEGENDA
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

// VERIFICACAO DO LOGIN
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
    printf("\n4 - Ver legenda dos pneus");
    printf("\n0 - Sair");

    printf("\n\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {

        case 1:
            mostrarToco();
            break;

        case 2:
            mostrarTruck();
            break;

        case 3:
            mostrarCarreta();
            break;

        case 4:
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