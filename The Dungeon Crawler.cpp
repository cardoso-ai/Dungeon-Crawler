

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int vidas;
int arma;

int px, py;   
char dir;     

char vila[10][10];
char m1[10][10];
char m2[15][15];
char m3[25][25];

int botao2_ativo;
int boss_vivo;
int bx, by;
int boss_turno;

int frente_l;
int frente_c;



int limpar_tela()
{
    printf("\033[2J\033[H");
    return 0;
}

int pausar()
{
    
    printf("\n[pressione qualquer tecla]\n");
    return 0;
}

char ler_tecla()
{
    int c;
    
    do
    {
        fflush(stdin);
        c = getchar();
    } while (c == '\n' || c == '\r' || c == ' ');
    return (char)c;
}

int eh_parede(char cel)
{
    if (cel == '*') return 1;
    if (cel == 'k') return 1;
    if (cel == 'D') return 1;
    if (cel == 'X') return 1;
    if (cel == 'Y') return 1;
    if (cel == 'Z') return 1;
    if (cel == 'N') return 1;
    return 0;
}

char simbolo_jogador()
{
    return dir;
}

int abs_val(int n)
{
    if (n < 0) return -n;
    return n;
}



int imprimir_vila()
{
    int l, c, v;
    printf("\n");
    for (l = 0; l < 10; l++)
    {
        for (c = 0; c < 10; c++)
            printf("%c ", vila[l][c]);
        printf("\n");
    }
    printf("\n  Vidas: ");
    for (v = 0; v < vidas; v++) printf("*");
    if      (arma == 1) printf("   Arma: Espada\n");
    else if (arma == 2) printf("   Arma: Arco e Flecha\n");
    else if (arma == 3) printf("   Arma: Cajado\n");
    else                printf("   Arma: Nenhuma\n");
    return 0;
}

int imprimir_m1()
{
    int l, c, v;
    printf("\n");
    for (l = 0; l < 10; l++)
    {
        for (c = 0; c < 10; c++)
            printf("%c ", m1[l][c]);
        printf("\n");
    }
    printf("\n  Vidas: ");
    for (v = 0; v < vidas; v++) printf("*");
    if      (arma == 1) printf("   Arma: Espada\n");
    else if (arma == 2) printf("   Arma: Arco e Flecha\n");
    else                printf("   Arma: Cajado\n");
    return 0;
}

int imprimir_m2()
{
    int l, c, v;
    printf("\n");
    for (l = 0; l < 15; l++)
    {
        for (c = 0; c < 15; c++)
            printf("%c ", m2[l][c]);
        printf("\n");
    }
    printf("\n  Vidas: ");
    for (v = 0; v < vidas; v++) printf("*");
    if      (arma == 1) printf("   Arma: Espada\n");
    else if (arma == 2) printf("   Arma: Arco e Flecha\n");
    else                printf("   Arma: Cajado\n");
    return 0;
}

int imprimir_m3()
{
    int l, c, v;
    printf("\n");
    for (l = 0; l < 25; l++)
    {
        for (c = 0; c < 25; c++)
            printf("%c ", m3[l][c]);
        printf("\n");
    }
    printf("\n  Vidas: ");
    for (v = 0; v < vidas; v++) printf("*");
    if      (arma == 1) printf("   Arma: Espada\n");
    else if (arma == 2) printf("   Arma: Arco e Flecha\n");
    else                printf("   Arma: Cajado\n");
    return 0;
}



int ataque_m1(int nl, int nc)
{
    if (nl < 0 || nl >= 10 || nc < 0 || nc >= 10) return 0;
    if (m1[nl][nc] == 'k') { m1[nl][nc] = '.'; }
    return 0;
}

int ataque_m2(int nl, int nc)
{
    if (nl < 0 || nl >= 15 || nc < 0 || nc >= 15) return 0;
    if (m2[nl][nc] == 'k') { m2[nl][nc] = '.'; }
    if (m2[nl][nc] == 'X') { m2[nl][nc] = '.'; }
    return 0;
}

int ataque_m3(int nl, int nc)
{
    if (nl < 0 || nl >= 25 || nc < 0 || nc >= 25) return 0;
    if (m3[nl][nc] == 'k') { m3[nl][nc] = '.'; return 0; }
    if (m3[nl][nc] == 'X') { m3[nl][nc] = '.'; return 0; }
    if (m3[nl][nc] == 'Y') { m3[nl][nc] = '.'; return 0; }
    if (m3[nl][nc] == 'Z') { m3[nl][nc] = '.'; boss_vivo = 0; return 1; }
    return 0;
}


int executar_ataque(int andar)
{
    int i, acertou_boss, c, l;
    int nl, nc;

    acertou_boss = 0;

    if (arma == 1) 
    {
        if (dir == '^')
        {
            for (c = py - 1; c <= py + 1; c++)
                for (i = px - 1; i >= px - 2; i--)
                {
                    if (andar == 1) ataque_m1(i, c);
                    else if (andar == 2) ataque_m2(i, c);
                    else acertou_boss = acertou_boss | ataque_m3(i, c);
                }
        }
        else if (dir == 'v')
        {
            for (c = py - 1; c <= py + 1; c++)
                for (i = px + 1; i <= px + 2; i++)
                {
                    if (andar == 1) ataque_m1(i, c);
                    else if (andar == 2) ataque_m2(i, c);
                    else acertou_boss = acertou_boss | ataque_m3(i, c);
                }
        }
        else if (dir == '<')
        {
            for (l = px - 1; l <= px + 1; l++)
                for (i = py - 1; i >= py - 2; i--)
                {
                    if (andar == 1) ataque_m1(l, i);
                    else if (andar == 2) ataque_m2(l, i);
                    else acertou_boss = acertou_boss | ataque_m3(l, i);
                }
        }
        else
        {
            for (l = px - 1; l <= px + 1; l++)
                for (i = py + 1; i <= py + 2; i++)
                {
                    if (andar == 1) ataque_m1(l, i);
                    else if (andar == 2) ataque_m2(l, i);
                    else acertou_boss = acertou_boss | ataque_m3(l, i);
                }
        }
    }
    else if (arma == 2) 
    {
        for (i = 1; i <= 4; i++)
        {
            nl = px; nc = py;
            if      (dir == '^') nl = px - i;
            else if (dir == 'v') nl = px + i;
            else if (dir == '<') nc = py - i;
            else                 nc = py + i;

            if (andar == 1) ataque_m1(nl, nc);
            else if (andar == 2) ataque_m2(nl, nc);
            else acertou_boss = acertou_boss | ataque_m3(nl, nc);
        }
    }
    else 
    {
        int dl, dc;
        for (dl = -1; dl <= 1; dl++)
            for (dc = -1; dc <= 1; dc++)
            {
                if (dl == 0 && dc == 0) continue;
                if (andar == 1) ataque_m1(px + dl, py + dc);
                else if (andar == 2) ataque_m2(px + dl, py + dc);
                else acertou_boss = acertou_boss | ataque_m3(px + dl, py + dc);
            }
    }

    return acertou_boss;
}


int calc_frente()
{
    frente_l = px;
    frente_c = py;
    if      (dir == '^') frente_l = px - 1;
    else if (dir == 'v') frente_l = px + 1;
    else if (dir == '<') frente_c = py - 1;
    else                 frente_c = py + 1;
    return 0;
}



int init_vila()
{
    int l, c;
    for (l = 0; l < 10; l++)
        for (c = 0; c < 10; c++)
            vila[l][c] = '.';

    for (l = 0; l < 10; l++) { vila[l][0] = '*'; vila[l][9] = '*'; }
    for (c = 0; c < 10; c++) { vila[0][c] = '*'; vila[9][c] = '*'; }

    vila[2][2] = 'N';
    vila[8][8] = 'L';

    px = 5; py = 5; dir = 'v';
    vila[px][py] = dir;
    return 0;
}

int init_m1()
{
    int l, c;
    for (l = 0; l < 10; l++)
        for (c = 0; c < 10; c++)
            m1[l][c] = '.';

    for (l = 0; l < 10; l++) { m1[l][0] = '*'; m1[l][9] = '*'; }
    for (c = 0; c < 10; c++) { m1[0][c] = '*'; m1[9][c] = '*'; }

   
    for (l = 1; l < 5; l++) m1[l][5] = '*';   
    for (l = 6; l < 9; l++) m1[l][5] = '*';   
    m1[5][5] = 'D';  

    
    m1[2][5] = 'k';
    m1[3][5] = 'k';   

    m1[6][2] = '@';   
    m1[8][8] = 'L';   

    px = 1; py = 2; dir = 'v';
    m1[px][py] = dir;
    return 0;
}

int init_m2()
{
    int l, c;
    for (l = 0; l < 15; l++)
        for (c = 0; c < 15; c++)
            m2[l][c] = '.';

    for (l = 0; l < 15; l++) { m2[l][0] = '*'; m2[l][14] = '*'; }
    for (c = 0; c < 15; c++) { m2[0][c] = '*'; m2[14][c] = '*'; }

    m2[5][3] = '#'; m2[5][4] = '#'; m2[5][5] = '#';
    m2[5][6] = '#'; m2[5][7] = '#';

    for (l = 1; l < 10; l++) m2[l][8] = '*';
    m2[4][8] = 'D';
    m2[8][8] = 'D';

    m2[2][3] = '@';
    m2[7][3] = '@';
    m2[11][4] = 'O';
    m2[3][11] = 'X';
    m2[7][12] = 'X';
    m2[12][12] = 'k';
    m2[13][13] = 'L';

    px = 1; py = 2; dir = 'v';
    m2[px][py] = dir;
    botao2_ativo = 0;
    return 0;
}

int init_m3()
{
    int l, c;
    for (l = 0; l < 25; l++)
        for (c = 0; c < 25; c++)
            m3[l][c] = '.';

    for (l = 0; l < 25; l++) { m3[l][0] = '*'; m3[l][24] = '*'; }
    for (c = 0; c < 25; c++) { m3[0][c] = '*'; m3[24][c] = '*'; }

    for (c = 1;  c < 10; c++) m3[5][c]  = '*';
    for (c = 1;  c < 16; c++) m3[10][c] = '*';
    for (c = 14; c < 24; c++) m3[15][c] = '*';
    for (l = 5;  l < 15; l++) m3[l][15] = '*';

    m3[5][10]  = 'D';
    m3[10][7]  = 'D';
    m3[15][20] = 'D';
    m3[8][15]  = '=';

    m3[3][5]  = '@';
    m3[7][3]  = '@';
    m3[13][6] = '@';

    m3[3][10] = '#'; m3[3][11] = '#'; m3[3][12] = '#';
    m3[12][16] = '#'; m3[12][17] = '#';

    m3[4][18] = 'k';
    m3[9][20] = 'k';
    m3[20][5] = 'O';

    m3[2][18] = 'X';
    m3[6][20] = 'X';
    m3[14][18] = 'Y';
    m3[18][10] = 'Y';

    bx = 22; by = 22;
    m3[bx][by] = 'Z';
    boss_vivo  = 1;
    boss_turno = 0;

    px = 1; py = 2; dir = 'v';
    m3[px][py] = dir;
    return 0;
}



int tela_tutorial()
{
    limpar_tela();
    printf("========================================\n");
    printf("   A LENDA DO CRISTAL SOMBRIO - TUTORIAL\n");
    printf("========================================\n\n");
    printf("HISTORIA:\n");
    printf("  O Cristal da Aurora foi roubado pelo necromante\n");
    printf("  Valdrak. Voce, guardiao de Eldoria, deve\n");
    printf("  recupera-lo nas profundezas da Masmorra.\n\n");
    printf("SIMBOLOS:\n");
    printf("  ^ < v >  Jogador (direcao)\n");
    printf("  *        Parede\n");
    printf("  #        Espinho (voce morre ao pisar)\n");
    printf("  k        Caixa (destrua com ataque)\n");
    printf("  O        Botao (pressione com 'i')\n");
    printf("  D        Porta fechada\n");
    printf("  @        Chave\n");
    printf("  =        Porta aberta\n");
    printf("  L        Escada (proxima fase)\n");
    printf("  X        Monstro vagante\n");
    printf("  Y        Monstro perseguidor\n");
    printf("  Z        Boss Final - Valdrak\n");
    printf("  N        NPC\n\n");
    printf("CONTROLES:\n");
    printf("  w / a / s / d  Mover\n");
    printf("  i              Interagir com objeto a frente\n");
    printf("  o              Atacar\n");
    printf("  q              Sair para o menu\n\n");
    printf("ARMAS:\n");
    printf("  Espada      : 3x2 celulas a frente\n");
    printf("  Arco/Flecha : linha reta, 4 celulas\n");
    printf("  Cajado      : 8 celulas ao redor\n\n");
    pausar();
    return 0;
}

int tela_creditos()
{
    limpar_tela();
    printf("========================================\n");
    printf("     A LENDA DO CRISTAL SOMBRIO\n");
    printf("========================================\n\n");
    printf("  Desenvolvido por:\n");
    printf("  [Coloque os nomes do grupo aqui]\n\n");
    printf("  Disciplina: Programacao I\n");
    printf("  Engenharia de Computacao\n\n");
    printf("  Obrigado por jogar!\n\n");
    printf("========================================\n\n");
    pausar();
    return 0;
}

int menu_principal()
{
    char op;
    limpar_tela();
    printf("========================================\n");
    printf("     A LENDA DO CRISTAL SOMBRIO\n");
    printf("       [ DUNGEON CRAWLER em C ]\n");
    printf("========================================\n\n");
    printf("  1. Jogar\n");
    printf("  2. Tutorial\n");
    printf("  3. Sair\n\n");
    printf("  Escolha: ");
    fflush(stdin);
    op = (char)getchar();
    return op - '0';
}

int escolher_arma()
{
    char op;
    limpar_tela();
    printf("========================================\n");
    printf("  FERREIRO BROM diz:\n");
    printf("  'Guerreiro, escolha sua arma!'\n");
    printf("========================================\n\n");
    printf("  1. Espada    (3x2 a frente)\n");
    printf("  2. Arco      (linha reta, 4 celulas)\n");
    printf("  3. Cajado    (8 celulas ao redor)\n\n");
    printf("  Escolha: ");
    fflush(stdin);
    op = (char)getchar();

    if      (op == '1') arma = 1;
    else if (op == '2') arma = 2;
    else                arma = 3;

    if      (arma == 1) printf("\n  Voce escolheu: Espada!\n");
    else if (arma == 2) printf("\n  Voce escolheu: Arco e Flecha!\n");
    else                printf("\n  Voce escolheu: Cajado!\n");

    pausar();
    return 0;
}



int tela_game_over()
{
    limpar_tela();
    printf("\n\n");
    printf("   GGGG   AAAAA  M   M EEEEE\n");
    printf("  G       A   A  MM MM E    \n");
    printf("  G  GGG  AAAAA  M M M EEEE \n");
    printf("  G    G  A   A  M   M E    \n");
    printf("   GGGG   A   A  M   M EEEEE\n");
    printf("\n");
    printf("  OOO  V   V EEEEE RRRR  \n");
    printf(" O   O V   V E     R   R \n");
    printf(" O   O V   V EEEE  RRRR  \n");
    printf(" O   O  V V  E     R  R  \n");
    printf("  OOO    V   EEEEE R   R \n");
    printf("\n");
    printf("  Eldoria caiu nas trevas...\n");
    printf("  O Cristal da Aurora permanece perdido.\n\n");
    pausar();
    return 0;
}

int tela_vitoria()
{
    limpar_tela();
    printf("\n");
    printf("  *  *  *  VITORIA!  *  *  *\n\n");
    printf("  Valdrak foi derrotado!\n\n");
    printf("  Com um ultimo golpe, voce destroca o necromante.\n");
    printf("  O Cristal da Aurora brilha novamente em suas maos.\n");
    printf("  As trevas recuam. Eldoria esta salva.\n\n");
    printf("  Os moradores de Arenor saem as ruas em festa.\n");
    printf("  O Cristal e restaurado ao seu pedestal sagrado.\n");
    printf("  E a lenda do ultimo guardiao sera contada\n");
    printf("  por geracoes.\n\n");
    printf("  FIM.\n\n");
    pausar();
    return 0;
}


int loop_vila()
{
    int npc_falou, nl, nc;
    char nova_dir, cmd, dest;

    npc_falou = 0;
    init_vila();
    limpar_tela();
    printf("  Voce chega a vila de Arenor...\n");
    printf("  Fale com o ferreiro (N) para pegar sua arma\n");
    printf("  e entre pela escada (L) na masmorra!\n");
    pausar();

    while (1)
    {
        limpar_tela();
        printf("  === VILA DE ARENOR ===\n");
        imprimir_vila();

        cmd = ler_tecla();
        if (cmd == 'q') return 0;

        nl = px; nc = py; nova_dir = dir;

        if      (cmd == 'w') { nl--; nova_dir = '^'; }
        else if (cmd == 's') { nl++; nova_dir = 'v'; }
        else if (cmd == 'a') { nc--; nova_dir = '<'; }
        else if (cmd == 'd') { nc++; nova_dir = '>'; }
        else if (cmd == 'i')
        {
            calc_frente();
            if (frente_l >= 0 && frente_l < 10
             && frente_c >= 0 && frente_c < 10)
            {
                if (vila[frente_l][frente_c] == 'N')
                {
                    npc_falou = 1;
                    escolher_arma();
                }
            }
            continue;
        }
        else continue;

        dir = nova_dir;
        if (nl < 0 || nl >= 10 || nc < 0 || nc >= 10) continue;

        dest = vila[nl][nc];

        if (dest == 'L')
        {
            if (npc_falou == 0 || arma == 0)
            {
                printf("\n  Fale com o ferreiro (N) antes de entrar!\n");
                pausar();
                continue;
            }
            return 1;
        }

        if (eh_parede(dest))
        {
            vila[px][py] = simbolo_jogador();
            continue;
        }

        vila[px][py] = '.';
        px = nl; py = nc;
        vila[px][py] = simbolo_jogador();
    }
}


int loop_m1()
{
    int tem_chave, nl, nc;
    char nova_dir, cmd, dest;

    tem_chave = 0;

    reinicio_m1:
    init_m1();
    tem_chave = 0;

    while (1)
    {
        limpar_tela();
        printf("  === MASMORRA - ANDAR 1 ===\n");
        imprimir_m1();

        cmd = ler_tecla();
        if (cmd == 'q') return 0;

        nl = px; nc = py; nova_dir = dir;

        if      (cmd == 'w') { nl--; nova_dir = '^'; }
        else if (cmd == 's') { nl++; nova_dir = 'v'; }
        else if (cmd == 'a') { nc--; nova_dir = '<'; }
        else if (cmd == 'd') { nc++; nova_dir = '>'; }
        else if (cmd == 'o')
        {
            executar_ataque(1);
            continue;
        }
        else if (cmd == 'i')
        {
            calc_frente();
            if (frente_l >= 0 && frente_l < 10
             && frente_c >= 0 && frente_c < 10)
            {
                if (m1[frente_l][frente_c] == '@')
                {
                    tem_chave++;
                    m1[frente_l][frente_c] = '.';
                    printf("\n  Voce pegou uma chave!\n");
                    pausar();
                }
                else if (m1[frente_l][frente_c] == 'D')
                {
                    if (tem_chave > 0)
                    {
                        tem_chave--;
                        m1[frente_l][frente_c] = '=';
                        printf("\n  Porta aberta!\n");
                        pausar();
                    }
                    else
                    {
                        printf("\n  Voce precisa de uma chave!\n");
                        pausar();
                    }
                }
            }
            continue;
        }
        else continue;

        dir = nova_dir;
        if (nl < 0 || nl >= 10 || nc < 0 || nc >= 10) continue;

        dest = m1[nl][nc];

        if (dest == 'L') return 2;

        if (dest == '#')
        {
            vidas--;
            printf("\n  ESPINHO! Perdeu uma vida! Vidas: %d\n", vidas);
            pausar();
            if (vidas <= 0) return 0;
            goto reinicio_m1;
        }

       
        if (dest == '@')
        {
            tem_chave++;
            printf("\n  Chave coletada! Total: %d\n", tem_chave);
            pausar();
            m1[nl][nc] = '.';
        }

        if (eh_parede(dest)) { m1[px][py] = simbolo_jogador(); continue; }

        m1[px][py] = '.';
        px = nl; py = nc;
        m1[px][py] = simbolo_jogador();
    }
}


int mover_monstros_m2()
{
    int l, c, dr, nl, nc;
    for (l = 1; l < 14; l++)
    {
        for (c = 1; c < 14; c++)
        {
            if (m2[l][c] == 'X')
            {
                dr = rand() % 4;
                nl = l; nc = c;
                if      (dr == 0) nl--;
                else if (dr == 1) nl++;
                else if (dr == 2) nc--;
                else              nc++;

                if (nl < 1 || nl >= 14 || nc < 1 || nc >= 14) continue;
                if (m2[nl][nc] == '.' || m2[nl][nc] == '=')
                {
                    m2[l][c] = '.';
                    m2[nl][nc] = 'X';
                }
            }
        }
    }
    return 0;
}

int monstro_tocou_jogador_m2()
{
    int dl, dc, nl, nc;
    for (dl = -1; dl <= 1; dl++)
        for (dc = -1; dc <= 1; dc++)
        {
            if (dl == 0 && dc == 0) continue;
            nl = px + dl; nc = py + dc;
            if (nl >= 0 && nl < 15 && nc >= 0 && nc < 15)
                if (m2[nl][nc] == 'X') return 1;
        }
    return 0;
}


int loop_m2()
{
    int tem_chave, nl, nc, k;
    char nova_dir, cmd, dest;

    tem_chave = 0;

    reinicio_m2:
    init_m2();
    tem_chave = 0;

    while (1)
    {
        limpar_tela();
        printf("  === MASMORRA - ANDAR 2 ===\n");
        imprimir_m2();

        cmd = ler_tecla();
        if (cmd == 'q') return 0;

        nl = px; nc = py; nova_dir = dir;

        if      (cmd == 'w') { nl--; nova_dir = '^'; }
        else if (cmd == 's') { nl++; nova_dir = 'v'; }
        else if (cmd == 'a') { nc--; nova_dir = '<'; }
        else if (cmd == 'd') { nc++; nova_dir = '>'; }
        else if (cmd == 'o')
        {
            executar_ataque(2);
            mover_monstros_m2();
            if (monstro_tocou_jogador_m2())
            {
                vidas--;
                printf("\n  MONSTRO! Perdeu uma vida! Vidas: %d\n", vidas);
                pausar();
                if (vidas <= 0) return 0;
                goto reinicio_m2;
            }
            continue;
        }
        else if (cmd == 'i')
        {
            calc_frente();
            if (frente_l >= 0 && frente_l < 15
             && frente_c >= 0 && frente_c < 15)
            {
                if (m2[frente_l][frente_c] == '@')
                {
                    tem_chave++;
                    m2[frente_l][frente_c] = '.';
                    printf("\n  Chave coletada! Total: %d\n", tem_chave);
                    pausar();
                }
                else if (m2[frente_l][frente_c] == 'D')
                {
                    if (tem_chave > 0)
                    {
                        tem_chave--;
                        m2[frente_l][frente_c] = '=';
                        printf("\n  Porta aberta!\n");
                        pausar();
                    }
                    else
                    {
                        printf("\n  Precisa de uma chave!\n");
                        pausar();
                    }
                }
                else if (m2[frente_l][frente_c] == 'O' && botao2_ativo == 0)
                {
                    botao2_ativo = 1;
                    for (k = 3; k <= 7; k++)
                        if (m2[5][k] == '#') m2[5][k] = '.';
                    printf("\n  O botao remove os espinhos do corredor!\n");
                    pausar();
                }
            }
            continue;
        }
        else continue;

        dir = nova_dir;
        if (nl < 1 || nl >= 14 || nc < 1 || nc >= 14) continue;

        dest = m2[nl][nc];

        if (dest == 'L') return 3;

        if (dest == '#')
        {
            vidas--;
            printf("\n  ESPINHO! Perdeu uma vida! Vidas: %d\n", vidas);
            pausar();
            if (vidas <= 0) return 0;
            goto reinicio_m2;
        }

        if (dest == 'X')
        {
            vidas--;
            printf("\n  MONSTRO! Perdeu uma vida! Vidas: %d\n", vidas);
            pausar();
            if (vidas <= 0) return 0;
            goto reinicio_m2;
        }

        
        if (dest == '@')
        {
            tem_chave++;
            printf("\n  Chave coletada! Total: %d\n", tem_chave);
            pausar();
            m2[nl][nc] = '.';
        }

        if (eh_parede(dest)) { m2[px][py] = simbolo_jogador(); continue; }

        m2[px][py] = '.';
        px = nl; py = nc;
        m2[px][py] = simbolo_jogador();

        mover_monstros_m2();
        if (monstro_tocou_jogador_m2())
        {
            vidas--;
            printf("\n  MONSTRO CHEGOU! Perdeu uma vida! Vidas: %d\n", vidas);
            pausar();
            if (vidas <= 0) return 0;
            goto reinicio_m2;
        }
    }
}


int mover_monstros_m3()
{
    int l, c, dr, nl, nc;
    int dlp, dcp;
    int melhor, mdist, i, d;
    int dl, dc, nl2, nc2;
    char dest;

    
    for (l = 1; l < 24; l++)
    {
        for (c = 1; c < 24; c++)
        {
            if (m3[l][c] == 'X')
            {
                dr = rand() % 4;
                nl = l; nc = c;
                if      (dr == 0) nl--;
                else if (dr == 1) nl++;
                else if (dr == 2) nc--;
                else              nc++;

                if (nl < 1 || nl >= 24 || nc < 1 || nc >= 24) continue;
                if (m3[nl][nc] == '.' || m3[nl][nc] == '=')
                {
                    m3[l][c] = '.';
                    m3[nl][nc] = 'X';
                }
            }
        }
    }

    
    for (l = 1; l < 24; l++)
    {
        for (c = 1; c < 24; c++)
        {
            if (m3[l][c] == 'Y')
            {
                nl = l; nc = c;
                dlp = px - l;
                dcp = py - c;

                if (abs_val(dlp) >= abs_val(dcp))
                    nl += (dlp > 0) ? 1 : -1;
                else
                    nc += (dcp > 0) ? 1 : -1;

                if (nl < 1 || nl >= 24 || nc < 1 || nc >= 24) continue;
                if (m3[nl][nc] == '.' || m3[nl][nc] == '=')
                {
                    m3[l][c] = '.';
                    m3[nl][nc] = 'Y';
                }
            }
        }
    }

    
    if (boss_vivo == 0) return 0;

    boss_turno++;

    if (boss_turno % 3 == 0)
    {
        int cantos[4][2];
        cantos[0][0] = 22; cantos[0][1] = 22;
        cantos[1][0] = 22; cantos[1][1] =  2;
        cantos[2][0] =  2; cantos[2][1] = 22;
        cantos[3][0] =  2; cantos[3][1] =  2;

        melhor = 0; mdist = 0;
        for (i = 0; i < 4; i++)
        {
            d = abs_val(cantos[i][0] - px) + abs_val(cantos[i][1] - py);
            if (d > mdist && m3[cantos[i][0]][cantos[i][1]] == '.')
            {
                mdist = d; melhor = i;
            }
        }
        m3[bx][by] = '.';
        bx = cantos[melhor][0];
        by = cantos[melhor][1];
        m3[bx][by] = 'Z';

        for (dl = -1; dl <= 1; dl++)
            for (dc = -1; dc <= 1; dc++)
            {
                if (dl == 0 && dc == 0) continue;
                nl2 = bx + dl; nc2 = by + dc;
                if (nl2 >= 1 && nl2 < 24 && nc2 >= 1 && nc2 < 24)
                    if (m3[nl2][nc2] == '.') m3[nl2][nc2] = '#';
            }
    }
    else
    {
        nl2 = bx; nc2 = by;
        dlp = px - bx; dcp = py - by;

        if (abs_val(dlp) >= abs_val(dcp))
            nl2 += (dlp > 0) ? 1 : -1;
        else
            nc2 += (dcp > 0) ? 1 : -1;

        if (nl2 >= 1 && nl2 < 24 && nc2 >= 1 && nc2 < 24)
        {
            dest = m3[nl2][nc2];
            if (dest == '.' || dest == '=')
            {
                m3[bx][by] = '.';
                bx = nl2; by = nc2;
                m3[bx][by] = 'Z';
            }
        }
    }

    return 0;
}

int monstro_tocou_jogador_m3()
{
    int dl, dc, nl, nc;
    for (dl = -1; dl <= 1; dl++)
        for (dc = -1; dc <= 1; dc++)
        {
            if (dl == 0 && dc == 0) continue;
            nl = px + dl; nc = py + dc;
            if (nl >= 0 && nl < 25 && nc >= 0 && nc < 25)
                if (m3[nl][nc] == 'X' || m3[nl][nc] == 'Y' || m3[nl][nc] == 'Z')
                    return 1;
        }
    return 0;
}


int loop_m3()
{
    int tem_chave, nl, nc, venceu, i;
    char nova_dir, cmd, dest;

    tem_chave = 0;

    reinicio_m3:
    init_m3();
    tem_chave = 0;

    while (1)
    {
        limpar_tela();
        printf("  === MASMORRA - ANDAR 3: DESAFIO FINAL ===\n");
        if (boss_vivo)
            printf("  [VALDRAK esta vivo! Derrote-o!]\n");
        imprimir_m3();

        cmd = ler_tecla();
        if (cmd == 'q') return 0;

        nl = px; nc = py; nova_dir = dir;

        if      (cmd == 'w') { nl--; nova_dir = '^'; }
        else if (cmd == 's') { nl++; nova_dir = 'v'; }
        else if (cmd == 'a') { nc--; nova_dir = '<'; }
        else if (cmd == 'd') { nc++; nova_dir = '>'; }
        else if (cmd == 'o')
        {
            venceu = executar_ataque(3);
            if (venceu || boss_vivo == 0) return 9;
            mover_monstros_m3();
            if (monstro_tocou_jogador_m3())
            {
                vidas--;
                printf("\n  Voce foi atingido! Vidas: %d\n", vidas);
                pausar();
                if (vidas <= 0) return 0;
                goto reinicio_m3;
            }
            continue;
        }
        else if (cmd == 'i')
        {
            calc_frente();
            if (frente_l >= 0 && frente_l < 25
             && frente_c >= 0 && frente_c < 25)
            {
                if (m3[frente_l][frente_c] == '@')
                {
                    tem_chave++;
                    m3[frente_l][frente_c] = '.';
                    printf("\n  Chave coletada! Total: %d\n", tem_chave);
                    pausar();
                }
                else if (m3[frente_l][frente_c] == 'D')
                {
                    if (tem_chave > 0)
                    {
                        tem_chave--;
                        m3[frente_l][frente_c] = '=';
                        printf("\n  Porta aberta!\n");
                        pausar();
                    }
                    else
                    {
                        printf("\n  Precisa de uma chave!\n");
                        pausar();
                    }
                }
                else if (m3[frente_l][frente_c] == 'O')
                {
                    for (i = -2; i <= 2; i++)
                    {
                        if (bx+i >= 1 && bx+i < 24)
                            if (m3[bx+i][by] == '.') m3[bx+i][by] = '#';
                        if (by+i >= 1 && by+i < 24)
                            if (m3[bx][by+i] == '.') m3[bx][by+i] = '#';
                    }
                    printf("\n  Espinhos invocados ao redor de Valdrak!\n");
                    pausar();
                }
            }
            continue;
        }
        else continue;

        dir = nova_dir;
        if (nl < 1 || nl >= 24 || nc < 1 || nc >= 24) continue;

        dest = m3[nl][nc];

        if (dest == '#')
        {
            vidas--;
            printf("\n  ESPINHO! Perdeu uma vida! Vidas: %d\n", vidas);
            pausar();
            if (vidas <= 0) return 0;
            goto reinicio_m3;
        }

        if (dest == 'X' || dest == 'Y' || dest == 'Z')
        {
            vidas--;
            printf("\n  INIMIGO! Perdeu uma vida! Vidas: %d\n", vidas);
            pausar();
            if (vidas <= 0) return 0;
            goto reinicio_m3;
        }

        
        if (dest == '@')
        {
            tem_chave++;
            printf("\n  Chave coletada! Total: %d\n", tem_chave);
            pausar();
            m3[nl][nc] = '.';
        }

        if (eh_parede(dest)) { m3[px][py] = simbolo_jogador(); continue; }

        m3[px][py] = '.';
        px = nl; py = nc;
        m3[px][py] = simbolo_jogador();

        mover_monstros_m3();
        if (boss_vivo == 0) return 9;

        if (monstro_tocou_jogador_m3())
        {
            vidas--;
            printf("\n  Voce foi atingido! Vidas: %d\n", vidas);
            pausar();
            if (vidas <= 0) return 0;
            goto reinicio_m3;
        }
    }
}


int main()
{
    int opcao, res;

    srand((unsigned int)time(0));

    while (1)
    {
        arma  = 0;
        vidas = 3;

        opcao = menu_principal();

        if (opcao == 1)
        {
            res = loop_vila();
            if (res == 0) continue;

            res = loop_m1();
            if (res == 0) { tela_game_over(); continue; }

            res = loop_m2();
            if (res == 0) { tela_game_over(); continue; }

            res = loop_m3();
            if (res == 0) { tela_game_over(); continue; }
            if (res == 9) { tela_vitoria();   continue; }
        }
        else if (opcao == 2)
        {
            tela_tutorial();
        }
        else if (opcao == 3)
        {
            tela_creditos();
            break;
        }
    }

    return 0;
}