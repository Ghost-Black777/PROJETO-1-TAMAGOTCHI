#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VIDATotal 168  // Total de horas de vida
#include <windows.h>

int main() {
    char nome[30];
    int idade = 0, horas = 0;
    int felicidade = 5, limpeza = 10, fome = 0, doente = 0;
    int vidaAtual = VIDATotal, tempoRestante = 24;
    int opcao = 0;
    int PONTOSPOL = 0, PONTOSUSUARIO = 0;
    int OPCAOJ = 0, OPCAOPOL = 0;
    int partidasJogadas = 0;
    int HORASTATUSFOME = 0;
    int HORALIMPESA = 0;
    int HORASDOENTE = 0;


    srand(time(NULL));

    //EDUARDO
    printf("Bem-vindo! Escolha um nome para seu Pougotchi: ");
    scanf("%s", nome);

    while (vidaAtual > 0 && idade < 7) {
        printf("\n-------- POUGOTCHI --------\n");
        printf("1 - Avancar o tempo (8h)\n");
        printf("2 - Alimentar %s\n", nome);
        printf("3 - Jogar com %s\n", nome);
        printf("4 - Dar banho em %s\n", nome);
        printf("5 - Ver status de %s\n", nome);
        printf("6 - Desligar\n");
        printf("--------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // HUGO
        if (opcao == 1) {
    if (tempoRestante <= 8) {
        idade++;
        tempoRestante = 24;
        printf("Um dia se passou. Dias restantes: %d\n", 7 - idade);
    } else {
        tempoRestante -= 8;
    }

    vidaAtual -= 8;
    horas += 8;
    if (horas >= 24) horas = 0;

    // Reduz limpeza
    limpeza -= 2;
    if (limpeza < 0) limpeza = 0;

    // Fome aumenta
    HORASTATUSFOME += 8;
    while(HORASTATUSFOME >= 5) {
        fome += 2;

        if (fome > 10) fome = 10;
        HORASTATUSFOME -= 5;
    }

    //chance de ficar doente se ainda não estiver
    if(doente == 0) {
        int chanceDoenca = rand() % 10; // 10% de chance de ficar doente
        if(chanceDoenca == 0) {
            doente = 1;
            HORASDOENTE = 0;
            printf("\nOh não! %s ficou doente!\n", nome);
        }
    }else{
        // Se estiver doente acumula tempo doente
        HORASDOENTE += 8;

        if(HORASDOENTE >= 24) {
            doente = 0;
            printf("\nBoa notícia! %s se curou totalmente da doença.\n", nome);

        // 66.6% de chance de ser curado e após 24
        }else if(HORASDOENTE >= 16) {

            int chanceCura = rand() % 3;

            if (chanceCura < 2) {
                doente = 0;
                printf("\n%s se recuperou da doença!\n", nome);
            }
        } else if(HORASDOENTE >= 8) {

            int chanceCura = rand() % 3;

            if(chanceCura == 0) {
                doente = 0;
                printf("\n%s conseguiu se curar da doença!\n", nome);
            }
        }
    }

            printf("8 horas se passaram.\n");
}

        // EDUARDO
        else if (opcao == 2) {
            if (fome > 0) {
            fome -= 4;
            if (fome < 0) fome = 0;
            felicidade += 1;
            if (felicidade > 10) felicidade = 10;
            printf("%s foi alimentado!\n", nome);
            } else {
            felicidade -= 2;
            if (felicidade < 0) felicidade = 0;
            printf("%s não estava com fome e ficou triste!\n", nome);
            }
        }

        // HUGO
        else if (opcao == 3){

            while (PONTOSPOL <= 3 && PONTOSUSUARIO <= 3){
            printf("Digite:\n 1 Para escolher PEDRA\n 2 Para escolher PAPEL\n 3 Para escolher TESOURA\n 0 Para cancelar jogo\n");
            scanf("%d", &OPCAOJ);

            if (OPCAOJ == 0) {
            printf("Jogo cancelado!\n");
                break;
            }
            else if (OPCAOJ == 1) {
            printf("Voce escolheu PEDRA\n");

            }
            else if (OPCAOJ == 2) {
            printf("Voce escolheu PAPEL\n");

            }
            else if (OPCAOJ == 3) {
            printf("Voce escolheu TESOURA\n");

            } else {
            printf("Numero invalido!\n");

            }

            OPCAOPOL = (rand() % 3 + 1);

            if (OPCAOPOL == 1) {
                printf("%s escolheu PEDRA\n", nome);
            }
            else if(OPCAOPOL == 2) {
                printf("%s escolheu PAPEL\n", nome);

            }else{
                printf("%s escolheu TESOURA\n", nome);
        }

        if(OPCAOJ == OPCAOPOL){
            printf("EMPATE jogue novamente\n");

        }else if((OPCAOJ == 1 && OPCAOPOL == 2) || (OPCAOJ == 3 && OPCAOPOL == 1) ||(OPCAOJ == 2 && OPCAOPOL == 3)){

            printf("%s ganhou essa rodada!\n", nome);
            PONTOSPOL++;

        }else if((OPCAOJ == 2 && OPCAOPOL == 1) || (OPCAOJ == 1 && OPCAOPOL == 3) ||(OPCAOJ == 3 && OPCAOPOL == 2)){

            printf("Voce ganhou essa rodada!\n");
            PONTOSUSUARIO++;
        }

        if(PONTOSPOL > 3){
            printf("\nO %s venceu a partida!\n", nome);
            felicidade += 5;
        if(felicidade > 10) felicidade = 10;
        printf("A felicidade do seu pet aumentou!\n +5");

        printf("\n        ##########################            \\(^o^)/\n");
        printf("        ##########################             (   )\n");
        printf("   #####################################       /   \\\n");
        printf(" #########################################\n");
        printf("####      ######################       ####\n");
        printf("###       ######################        ###\n");
        printf("##        ######################        ###\n");
        printf("###     ##########################      ###\n");
        printf("###    ############################    ####\n");
        printf(" ###   ### #################### ###    ###\n");
        printf(" ####   ### ################## ####  ####\n");
        printf("   ####  ######################### #####\n");
        printf("    ######## ################ #########\n");
        printf("      ######  ##############   ######\n");
        printf("               ############\n");
        printf("                 ########\n");
        printf("                   ####\n");
        printf("                   ####\n");
        printf("                   ####\n");
        printf("                   ####\n");
        printf("               ############\n");
        printf("            ##################\n");
        printf("            ##################\n");
        printf("            ###            ###\n");
        printf("            ###            ###\n");
        printf("            ###            ###\n");
        printf("            ##################\n");
        printf("            ##################\n");
        printf("          ######################\n");
        printf("         ########################\n");

            break;
        }

        if(PONTOSUSUARIO > 3) {
        printf("\nVoce ganhou a partida!\n");
        felicidade += 3;
        if(felicidade > 10) felicidade = 10;
        printf("A felicidade do seu pet aumentou!\n +3");
            break;

        }

        printf("\nPlacar: Voce %d x %d %s\n", PONTOSUSUARIO, PONTOSPOL, nome);
        Sleep(2000);
        system("cls");

        }
            PONTOSPOL = 0;
            PONTOSUSUARIO = 0;
        }
        // LUCAS
        else if (opcao == 4) {
            if (limpeza == 10) {
                felicidade -= 6;
                if (felicidade < 0) felicidade = 0;
                printf("%s já está limpo e ficou triste.\n", nome);
            } else {
                limpeza = 10;
                printf("%s tomou banho e está limpo.\n", nome);
            }
        }

        // EDUARDO
        else if (opcao == 5) {
            printf("\n------- Status de %s -------\n", nome);
            printf("Idade: %d dias\n", idade);
            printf("Horas: %d/24\n", horas);
            printf("Felicidade: %d/10\n", felicidade);
            printf("Limpeza: %d/10\n", limpeza);
            printf("Fome: %d/10\n", fome);
            printf("Doente: %s\n", doente ? "Sim" : "Não");
            printf("----------------------------\n");
        }

        // LUCAS
        else if (opcao == 6) {
            printf("Desligando o jogo...\n");
            return 0;
        }

        if (felicidade <= 0 || fome >= 10 || limpeza <= 0 || idade >= 7) {
            printf("\nFim de jogo! %s não sobreviveu.\n", nome);
            break;
        }
    }

        printf("\nFim do jogo! Você não conseguiu manter %s vivo.\n", nome);


    return 0;
}

