#include <conio2.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "TADPilha.h"

//Moldura
int moldura(int colunai, int linhai, int colunaf, int linhaf, int frente, int fundo){
	textcolor(frente);
	textbackground(fundo);
	
	gotoxy(colunai, linhai); 
	printf("%c", 201); //canto superior esquerdo
	gotoxy(colunaf, linhai); 
	printf("%c", 187);//canto superior direito
	gotoxy(colunai, linhaf); 
	printf("%c", 200); //canto inferior esquerdo
	gotoxy(colunaf, linhaf); 
	printf("%c", 188);//canto inferior direito
	
	
	for(int a = colunai + 1; a < colunaf; a++) {
		gotoxy(a, linhai); printf("%c", 205); //faz a linha reta // caracter de parede reta
		//Sleep(20);
		gotoxy(a, linhaf); printf("%c", 205);
	}

	for(int b = linhai + 1; b < linhaf; b++) {
		gotoxy(colunai, b); printf("%c", 186);//faz a coluna reta
		//Sleep(20);
		gotoxy(colunaf, b); printf("%c", 186);
	}
	
	//voltar cores de texto e fundo padrão
	textcolor(7);
	textbackground(0);
	
}
void molde(void){
	//system("cls");
	//jogo
	moldura(8, 3, 78, 23, 7, 13); //borda externa
	moldura(9, 4, 77, 6, 7, 5); //titulo
	gotoxy(31, 5); 
	//torres
	printf("* * * TORRES DE HANOI * * *");
	moldura(9, 7, 31, 22, 7, 15);//torre 1
    gotoxy(18, 9);
    printf("TORRE 1");
    moldura(32, 7, 54, 22, 7, 15);//torre 2
    gotoxy(41, 9);
    printf("TORRE 2");
    moldura(55, 7, 77, 22, 7, 15);//torre 3 
    gotoxy(63, 9);
    printf("TORRE 3");
    	
}
void Limpar(void){
	int l = 8, c = 24;
	for(int i = 0 ; i < 3 ; i++){
		gotoxy(l, c);
		printf("								        						");	
		c++;	
	}
}
void LimparTorres(void){
	int l = 10, c = 10;
	for(int i = 0; i < 12; i++){
		gotoxy(l, c);
		printf("                     ");
		c++;
	}
	l = 33; c = 10;
	for(int i = 0; i < 12; i++){
		gotoxy(l, c);
		printf("                     ");
		c++;
	}
	l = 56; c = 10;
	for(int i = 0; i < 12; i++){
		gotoxy(l, c);
		printf("                     ");
		c++;
	}

}
void LimparMeio(void){
	int l = 10, c = 8;
	for(int i = 0 ; i < 14 ; i++){
		gotoxy(l, c);
		printf("                                                                  ");
		c++;
	}
}
int MenuDiscos(void){
	int l = 8, c = 24;
	int x;
	gotoxy(l, c);
	printf("Com quantos discos deseja jogar? ");
	c++; gotoxy(l, c);
	printf("[3] a [10]");
	c++; gotoxy(l, c);
	fflush(stdin);
	scanf("%d", &x);
	return x;
}	
char MenuJogo(void){
	Limpar();
	int l = 8, c = 24;
	gotoxy(l, c);
	printf("Selecione o modo de jogo:");
	c++; gotoxy(l, c);
	printf("[A] Automatico			[B] Manual");
	c++; gotoxy(l, c);
	fflush(stdin);
	return toupper(getch());
}
void PreencherPilha(int x, TpPilhaM3 &PM, int NP){
	for(int i = x - 1; i >= 0 ; i--)
		Push(PM, i + 48, NP);

}
int ContarDiscos(TpPilhaM3 PM, int NP){
	int cont = 0;

	while(!PilhaVazia(PM, NP)){
		Pop(PM, NP);
		cont++;
	}

	return cont;
}
int ExibirBarras(int barras, int l){
	int c = 11;
	for(int i = 0 ; i < barras; i++){
		gotoxy(l, c);
		printf(" |");
		c++;
	}

	return c;
}
void ExibirDiscos(int discos, int l , int c, TpPilhaM3 PM, int NP){
	int aux, linha;
	for(int i = 0; i < discos; i++){
		aux = Pop(PM, NP) - 48;
		linha = (l - aux * 2 + 1) + aux;
		textcolor(aux + 1);
		for(int j = 0 ; j < aux * 2 + 1; j++){
			gotoxy(linha, c);
			printf("#");
			linha++;
		}
		c++;
	}
	textcolor(7);
}
void ExibirNormal(int discos, int l, int c, TpPilhaM3 PM, int NP){
	for(int i = 0 ; i < discos ; i++){
		gotoxy(l, c);
		printf("[%c]", Pop(PM, NP));
		c++;
	}
}
void ExibirTorres(TpPilhaM3 PM){
	int l = 18, c = 11, cor = 2;
	
	LimparTorres();

	int discA = ContarDiscos(PM, 0);
    int discB = ContarDiscos(PM, 1);
    int discC = ContarDiscos(PM, 2);
	
	int barras = 10;
	int colunaA = ExibirBarras(barras - discA, 19);
	int colunaB = ExibirBarras(barras - discB, 42);
	int colunaC = ExibirBarras(barras - discC, 65);
	
	ExibirDiscos(discA, 19, colunaA, PM, 0);
	ExibirDiscos(discB, 42, colunaB, PM, 1);
	ExibirDiscos(discC, 65, colunaC, PM, 2);
}
int Vitoria(TpPilhaM3 PM, int discos){
	int qtdA = ContarDiscos(PM, 0);
	int qtdC = ContarDiscos(PM, 2);

	if(qtdA == discos || qtdC == discos)
		return 1;
	else 
		return 0;
}
void PassarTorre(TpPilhaM3 &PM, int &mov){
	int l = 8, c = 24;
	int torreA, torreB;
	int elemauxA, elemauxB;

	gotoxy(l, c);
	printf("Deseja pegar de qual torre?");
	c++; gotoxy(l, c);
	printf("[1]  [2]  [3]");
	c++; gotoxy(l, c);
	scanf("%d", &torreA);
	Limpar();
	
	l = 8, c = 24;
	gotoxy(l, c);
	printf("Deseja colocar em qual torre?");
	c++; gotoxy(l, c);
	printf("[1]  [2]  [3]");
	c++; gotoxy(l, c);
	scanf("%d", &torreB);
	Limpar();

	torreA = torreA - 1;
	torreB = torreB - 1;

	l = 8, c = 24;

	if(torreA == torreB){
		gotoxy(l, c);
		printf("Operacao Invalida");
		getch();
	} else{
		if(PilhaVazia(PM, torreB)){
			Push(PM, Pop(PM, torreA), torreB);
			mov++;
		} else{
			elemauxA = Pop(PM, torreA);
			elemauxB = Pop(PM, torreB);
			if(elemauxA > elemauxB){
				gotoxy(l, c);
				printf("Operacao Invalida");
				getch();
				Push(PM, elemauxB, torreB); //voltar elemento torreB
				Push(PM, elemauxA, torreA); //voltar elemento torreA
			} else{
				gotoxy(l, c);
				Push(PM, elemauxB, torreB);
				Push(PM, elemauxA, torreB);
				mov++;
			}	
		}	
	}
}
void OrganizarTorre(TpPilhaM3 &PM, int origem, int destino){
	if (PilhaVazia(PM, origem)) {
        Push(PM, Pop(PM, destino), origem);
    } else if (PilhaVazia(PM, destino)) {
        Push(PM, Pop(PM, origem), destino);
    } else if (ElementoTopo(PM, origem) > ElementoTopo(PM, destino)){
        Push(PM, Pop(PM, destino), origem);
    } else {
        Push(PM, Pop(PM, origem), destino);
    }
}
void PassarAutomatico(TpPilhaM3 &PM, int discos, int minimo, int &mov){
	Limpar();
	int origem = 1, destino = 0, auxiliar = 2;
    int aux = minimo;
    for (int i = 1; i <= aux; i++) {	
        if (i % 3 == 1) {
            OrganizarTorre(PM, 1, 0);
        } else if (i % 3 == 2) {
            OrganizarTorre(PM, 1, 2);
        } else {
            OrganizarTorre(PM, 2, 0);
        }
        minimo--;
        mov++;
		ExibirTorres(PM);
		gotoxy(8, 2); printf("Movimentos:	%d", mov);
		Sleep(500);
	}
}

void TelaVitoria(void){
	LimparMeio();
	Limpar();
	do{
		for(int i = 2; i < 14; i++){
			textcolor(i);
			gotoxy(26, 13); printf("#"); gotoxy(27, 14); printf("#"); gotoxy(28, 15); printf("#"); gotoxy(29, 16); printf("#"); gotoxy(30, 15); printf("#"); gotoxy(31, 14); printf("#"); gotoxy(32, 13); printf("#");
			Sleep(50);
			gotoxy(34, 13); printf("#"); gotoxy(34, 14); printf("#"); gotoxy(34, 15); printf("#"); gotoxy(34, 16); printf("#");
			Sleep(50);
			gotoxy(36, 13); printf("#"); gotoxy(37, 13); printf("#"); gotoxy(38, 13); printf("#"); gotoxy(39, 13); printf("#"); gotoxy(40, 13); printf("#"); gotoxy(38, 14); printf("#"); gotoxy(38, 15); printf("#"); gotoxy(38, 16); printf("#");
			Sleep(50);
			gotoxy(42, 13); printf("#"); gotoxy(43, 13); printf("#"); gotoxy(44, 13); printf("#"); gotoxy(45, 13); printf("#"); gotoxy(46, 13); printf("#"); gotoxy(42, 14); printf("#"); gotoxy(42, 15); printf("#"); gotoxy(42, 16); printf("#"); gotoxy(46, 14); printf("#"); gotoxy(46, 15); printf("#"); gotoxy(46, 16); printf("#"); gotoxy(43, 16); printf("#"); gotoxy(44, 16); printf("#"); gotoxy(45, 16); printf("#");
			Sleep(50);
			gotoxy(48, 13); printf("#"); gotoxy(48, 14); printf("#"); gotoxy(48, 15); printf("#"); gotoxy(48, 16); printf("#"); gotoxy(49, 13); printf("#"); gotoxy(50, 13); printf("#"); gotoxy(51, 13); printf("#"); gotoxy(52, 13); printf("#"); gotoxy(52, 14); printf("#"); gotoxy(51, 15); printf("#"); gotoxy(52, 16); printf("#");  
			Sleep(50);
			gotoxy(54, 13); printf("#"); gotoxy(54, 14); printf("#"); gotoxy(54, 15); printf("#"); gotoxy(54, 16); printf("#");
			Sleep(50);
			gotoxy(56, 16); printf("#"); gotoxy(56, 15); printf("#"); gotoxy(57, 14); printf("#"); gotoxy(58, 13); printf("#"); gotoxy(59, 14); printf("#"); gotoxy(60, 15); printf("#"); gotoxy(58, 15); printf("#"); gotoxy(57, 15); printf("#"); gotoxy(59, 15); printf("#"); gotoxy(60, 16); printf("#");
			Sleep(50);
		}
		
	}while(!kbhit());
	
	textcolor(7);
}
int main(void){
	TpPilhaM3 pilha;
	int discos, movminimo, usuariomov;
	char op;

	molde();
	discos = MenuDiscos();
	movminimo = pow(2, discos) - 1;
	usuariomov = 0;

	Limpar();
	Inicializar(pilha, 3);
	PreencherPilha(discos, pilha, 1);
	ExibirTorres(pilha);

	op = MenuJogo();

	while(op != 'A' && op != 'B'){
		Limpar();
		gotoxy(8, 24);
		printf("Opcao Invalida, aperte enter para digitar novamente!");
		getch();
		op = MenuJogo();
	}	

	Limpar();

	if(op == 'A'){
		PassarAutomatico(pilha, ContarDiscos(pilha, 1), movminimo, usuariomov);
		TelaVitoria();
	}else{
		do{
			gotoxy(8, 2); printf("Movimentos:	%d", usuariomov);
			PassarTorre(pilha, usuariomov);
			ExibirTorres(pilha);
			
		}while(!Vitoria(pilha,discos));
		
		if(Vitoria(pilha, discos)){
			gotoxy(8, 2); printf("Movimentos:	%d", usuariomov);
			TelaVitoria();
		}
	}

	LimparTorres();
	getch();

	return 0;
}
