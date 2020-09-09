#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
typedef BOOL WINAPI (*SetConsoleDisplayModeT)(HANDLE,DWORD,DWORD*);
BOOL WINAPI FullScreenConsoleNT(void){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD newmode = 1;
    DWORD oldmode;
    SetConsoleDisplayModeT SetConsoleDisplayMode;
    HINSTANCE hK32 = GetModuleHandle("KERNEL32.DLL");
    if ( hK32 == NULL ) {
        return FALSE;
    }
    SetConsoleDisplayMode = ( SetConsoleDisplayModeT )
		GetProcAddress(hK32,"SetConsoleDisplayMode");
    if ( SetConsoleDisplayMode == NULL ) {
	return FALSE;
    }
    SetConsoleDisplayMode(hStdOut,newmode,&oldmode);
    return TRUE;
}
void apresentacao(){
    system("CLS");
    printf ("\t   *******************************************************\n");
    printf ("\t   **          Batalha Naval  -  Thiago Sartori         **\n");
    printf ("\t   *******************************************************\n\n\n");
}
void jogar(){
    int tabela1[10][10]={0},tabela2[10][10]={0},tabela3[10][10]={0},tabela4[10][10]={0},ind,ind1,pos, ganha=0, perde=0, tiros=0;
    int i,j,k;
    FullScreenConsoleNT();
    srand(time(NULL));
    for (k=0;k<2;k++){
        apresentacao();
        printf ("Voce possui 2 submarinos e 2 fragatas (as fragatas tem 3 partes e os submarinos 1).\n");
        printf ("Legenda:\n1 --> Submarino\n3 --> Fragata\n5 --> Agua\n\n");
        printf ("\t   Esta e sua tabela\n");
        puts("");
        printf("Colunas --> 0 1 2 3 4 5 6 7 8 9\n");
        puts("");
        for (i=0;i<10;i++){
            printf("Linha %d -->", i);
            for (j=0;j<10;j++){
                printf(" %d", tabela2[i][j]);        
            }
            puts("");
        }
        printf ("Digite a linha e a coluna (ex: 1 2) para colocar o submarino\n");
        scanf ("%d %d", &ind,&ind1);
        if (tabela2[ind][ind1]==0){
            tabela2[ind][ind1]=1;
        }
        else {
            while (tabela2[ind][ind1]!=0){
                printf ("Nesta posi��o ja foi colocado um submarino.\n");
                printf ("Digite a linha e a coluna (ex: 1 2) para colocar o submarino\n");
                scanf ("%d %d", &ind,&ind1);
            }
            tabela2[ind][ind1]=1;
        }
    }
    for (k=0;k<2;k++){
        apresentacao();
        printf ("Voce possui 2 submarinos e 2 fragatas (as fragatas tem 3 partes e os submarinos 1).\n");
        printf ("Legenda:\n1 --> Submarino\n3 --> Fragata\n5 --> Agua\n\n");
        printf ("\t\t   ATENCAO!!!\n\n");
        printf ("Obs: Quando voce digitar as coordenadas de uma parte da fragata as outras 2 partes ser�o colocadas automaticamente (uma parte pra frente e outra para tras). Ent�o cuidado, pois se a coordenada informada for por exemplo linha 9 e coluna 9 de posicao horizontal, n�o ira ser possivel colocar a parte da frente da fragata pois nao tem a coluna 10, logo o jogo ficara com uma falha. FIQUE ATENTO!!!\n\n");
        printf ("\t   Esta e sua tabela\n\n");
        puts("");
        printf("Colunas --> 0 1 2 3 4 5 6 7 8 9\n");
        puts("");
        for (i=0;i<10;i++){
            printf("Linha %d -->", i);
            for (j=0;j<10;j++){
                printf(" %d", tabela2[i][j]);        
            }
            puts("");
        }
        printf ("Digite a linha e a coluna (ex: 1 2) para colocar a fragata\n");
        scanf ("%d %d", &ind,&ind1);
        printf ("Digite a posicao da fragata (1 -> Horizontal / 2 ->Vertical / 3 -> Longitudinal).\n");
        scanf ("%d", &pos);
        if (pos==1){
            if ((tabela2[ind][ind1-1]==0)&&(tabela2[ind][ind1]==0)&&(tabela2[ind][ind1+1]==0)){
                tabela2[ind][ind1-1]=3;
                tabela2[ind][ind1]=3;
                tabela2[ind][ind1+1]=3;
            }
            else {
                while ((tabela2[ind][ind1-1]!=0)||(tabela2[ind][ind1]!=0)||(tabela2[ind][ind1+1]!=0)){
                    apresentacao();
                    printf ("Nesta posi��o ja foi colocado um submarino ou uma fragata.\n");
                    printf ("Digite a linha e a coluna (ex: 1 2) para colocar a fragata\n");
                    scanf ("%d %d", &ind,&ind1);
                }
                tabela2[ind][ind1-1]=3;
                tabela2[ind][ind1]=3;
                tabela2[ind][ind1+1]=3;
            }
        }
        if (pos==2){
            if ((tabela2[ind-1][ind1]==0)&&(tabela2[ind][ind1]==0)&&(tabela2[ind+1][ind1]==0)){
                tabela2[ind-1][ind1]=3;
                tabela2[ind][ind1]=3;
                tabela2[ind+1][ind1]=3;
            }
            else {
                while ((tabela2[ind-1][ind1]!=0)||(tabela2[ind][ind1]!=0)||(tabela2[ind+1][ind1]!=0)){
                    apresentacao();
                    printf ("Nesta posi��o ja foi colocado um submarino ou uma fragata.\n");
                    printf ("Digite a linha e a coluna (ex: 1 2) para colocar a fragata\n");
                    scanf ("%d %d", &ind,&ind1);
                }
                tabela2[ind-1][ind1]=3;
                tabela2[ind][ind1]=3;
                tabela2[ind+1][ind1]=3;
            }
        }
        if (pos==3){
            if ((tabela2[ind-1][ind1-1]==0)&&(tabela2[ind][ind1]==0)&&(tabela2[ind+1][ind1+1]==0)){
                tabela2[ind-1][ind1-1]=3;
                tabela2[ind][ind1]=3;
                tabela2[ind+1][ind1+1]=3;
            }
            else {
                while ((tabela2[ind-1][ind1-1]!=0)||(tabela2[ind][ind1]!=0)||(tabela2[ind+1][ind1+1]!=0)){
                    apresentacao();
                    printf ("Nesta posi��o ja foi colocado um submarino ou uma fragata.\n");
                    printf ("Digite a linha e a coluna (ex: 1 2) para colocar a fragata\n");
                    scanf ("%d %d", &ind,&ind1);
                }
                tabela2[ind-1][ind1-1]=3;
                tabela2[ind][ind1]=3;
                tabela2[ind+1][ind1+1]=3;
            }
        }
    }
    apresentacao();
    printf ("\t   Esta e sua tabela\n\n--> Seu exercito naval esta posicionado.\n\n");
    puts("");
    printf("Colunas --> 0 1 2 3 4 5 6 7 8 9\n");
    puts("");
    for (i=0;i<10;i++){
        printf("Linha %d -->", i);
        for (j=0;j<10;j++){
            printf(" %d", tabela2[i][j]);        
        }
        puts("");
    }
    getch();
    /*Tabela 1 e 2* --> Jogador - Tabela 3 e 4*--> Computador*/
    for (k=0;k<2;k++){
        ind=rand()%10;
        ind1=rand()%10;
        if (tabela4[ind][ind1]==0){
            tabela4[ind][ind1]=1;
        }
        else {
            while (tabela4[ind][ind1]!=0){
                ind=rand()%10;
                ind1=rand()%10;
            }
            tabela4[ind][ind1]=1;
        }
    }
    for (i=0;i<2;i++){
        pos=rand()%3;
        if (pos==0){
            ind=rand()%10;
            ind1=rand()%7;
            if ((tabela4[ind][ind1]==0)&&(tabela4[ind][ind1+1]==0)&&(tabela4[ind][ind1+2]==0)){
                tabela4[ind][ind1]=3;
                tabela4[ind][ind1+1]=3;
                tabela4[ind][ind1+2]=3;
            }
            else {
                while ((tabela4[ind][ind1]!=0)||(tabela4[ind][ind1+1]!=0)||(tabela4[ind][ind1+2]!=0)){
                    ind=rand()%10;
                    ind1=rand()%10;
                }
                tabela4[ind][ind1]=3;
                tabela4[ind][ind1+1]=3;
                tabela4[ind][ind1+2]=3;    
            }
        }
        if (pos==1){
            ind=rand()%7;
            ind1=rand()%10;
            if ((tabela4[ind][ind1]==0)&&(tabela4[ind+1][ind1]==0)&&(tabela4[ind+2][ind1]==0)){
                tabela4[ind][ind1]=3;
                tabela4[ind+1][ind1]=3;
                tabela4[ind+2][ind1]=3;
            }
            else {
                while ((tabela4[ind][ind1]!=0)||(tabela4[ind+1][ind1]!=0)||(tabela4[ind+2][ind1]!=0)){
                    ind=rand()%10;
                    ind1=rand()%10;
                }
                tabela4[ind][ind1]=3;
                tabela4[ind+1][ind1]=3;
                tabela4[ind+2][ind1]=3;    
            }
        }
        if (pos==2){
            ind=rand()%7;
            ind1=rand()%7;
            if ((tabela4[ind][ind1]==0)&&(tabela4[ind+1][ind1+1]==0)&&(tabela4[ind+2][ind1+2]==0)){
                tabela4[ind][ind1]=3;
                tabela4[ind+1][ind1+1]=3;
                tabela4[ind+2][ind1+2]=3;
            }
            else {
                while ((tabela4[ind][ind1]!=0)||(tabela4[ind+1][ind1+1]!=0)||(tabela4[ind+2][ind1+2]!=0)){
                    ind=rand()%7;
                    ind1=rand()%7;
                }
                tabela4[ind][ind1]=3;
                tabela4[ind+1][ind1+1]=3;
                tabela4[ind+2][ind1+2]=3;    
            }
        }
    }
    apresentacao();
    printf ("\n\tO computador ja posicionou seu exercito naval.\n");
    getch();
    while (true){
        apresentacao();
        printf ("\tEsta e a tabela do computador\n");
        printf("Colunas --> 0 1 2 3 4 5 6 7 8 9\n");
        puts("");
        for (i=0;i<10;i++){
            printf("Linha %d -->", i);
            for (j=0;j<10;j++){
                printf(" %d", tabela3[i][j]);        
            }
            puts("");
        }
        printf ("\nLegenda:\n1 --> Submarino\n3 --> Fragata\n5 --> Agua\n\n");
        printf ("Digite o numero de uma linha e coluna para disparar um tiro.\n");
        scanf ("%d %d", &ind, &ind1);
        tiros++;
        apresentacao();
        puts("\n\t\t\t...:::INFORMACAO:::...\n\n");
        while (tabela3[ind][ind1]!=0){
            printf ("Voce ja disparou um tiro nestas coordenadas, atire novamente.\n\n");
            printf ("Digite o numero de uma linha e coluna para disparar um tiro.\n");
            scanf ("%d %d", &ind, &ind1);
        }
        if ((tabela4[ind][ind1]==1)||(tabela4[ind][ind1]==3)){
            tabela3[ind][ind1]=tabela4[ind][ind1];
            ganha++;
            if (tabela4[ind][ind1]==1){
                printf ("Voce acertou um submarino inimigo.\n");
                getch();
            }
            else {
                printf ("Voce acertou uma parte da fragata.\n");
                getch();
            }
        }
        else {
            tabela3[ind][ind1]=5;
            printf ("Voce atirou na agua.\n");
            getch();
        }
        ind=rand()%10;
        ind1=rand()%10;
        apresentacao();
        puts ("\t\t\t...:::INFORMACAO:::...\n\n");
        while (tabela1[ind][ind1]!=0){
            ind=rand()%10;
            ind1=rand()%10;
        }
        if ((tabela2[ind][ind1]==1)||(tabela2[ind][ind1]==3)){
            tabela1[ind][ind1]=tabela2[ind][ind1];
            perde++;
            if (tabela2[ind][ind1]==1){
                printf ("O computador destruiu um de seus submarinos.\n\n");
            }
            else {
                printf ("O computador atingiu uma parte da sua fragata.\n\n");
            }
        }
        else {
            tabela1[ind][ind1]=5;
            printf ("O computador atirou na agua.\n\n");
        }
        puts("\nAssim ficou seu jogo depois do computador ter atirado(so sera mostrado o que foi acertado no tiro)");
        printf("\nColunas --> 0 1 2 3 4 5 6 7 8 9\n");
        puts("");
        for (i=0;i<10;i++){
            printf("Linha %d -->", i);
            for (j=0;j<10;j++){
                printf(" %d", tabela1[i][j]);        
            }
            puts("");
        }
        getch();
        if((perde==8)&&(ganha==8)){
            apresentacao();
            printf ("\n\t\tVoce empatou com o computador.\n\n\t\tVoce deu %d disparos, sendo %d deles na agua.\n\n\n\tJogo Desenvolvido por: Thiago Sartori - thiagosartori@live.com", tiros, tiros-8);
            getch();
            return;
        }
        if (ganha==8){
            apresentacao();
            printf ("\n\t\tParabens voce ganhou do computador.\n\n\t\tVoce deu %d disparos, sendo %d deles na agua.\n\n\n\tJogo Desenvolvido por: Thiago Sartori - thiagosartori@live.com", tiros, tiros-8);
            getch();
            return;
        }
        if (perde==8){
            apresentacao();
            printf ("\n\tPerdeu playboy!!!\n\n\tJogo Desenvolvido por: Thiago Sartori - thiagosartori@live.com");
            getch();
            return;
        }
    }
}
int main(int argc, char *argv[]){
    while (true){
        apresentacao();
        char menu;
        cout<<"\n\t\t\t\tMenu:\n\n\t\t\t1 - Jogar Batalha Naval\n\t\t\t2 - Desenvolvedor\n\t\t\t3 - SAIR\n\n\t\t\tSua opcao: ";
        cin>>menu;
        switch(menu){
            case '1':
                jogar();
                break;
            case '2':
                apresentacao();
                cout<<"\n\tJogo Desenvolvido por THIAGO SARTORI - thiagosartori@live.com";
                getch();
                break;
            case '3':
                exit(0);
                break;
            default:
                apresentacao();
                cout<<"\n\t\t\t-->\aOpcao Invalida";
                getch();   
                break;
        }
    }
}
