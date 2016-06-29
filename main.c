#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Sistema de Classe
Desenvolvedor: Melque Henrique Lemes de Castro
*/



char nomequalquer [10][10],jogador1[25], jogador2[25], aux[25];
int linha=0, coluna=0, win, matriz[3][3],j;


void velha( int i, int j){ /*Função pra colocar espaços vazios e os 'X' e os 'O' no jogo*/
  if (matriz [i] [j] == '\0') printf(" ");
  if (matriz [i] [j] == 1) printf ("X");
  if (matriz [i] [j] == 2) printf ("O");

}

void jogo() {
  printf("\n================================JOGA DA VELHA=================================\n\n");
  printf("  1   2   3\n");
  printf("1 ");
  velha(0,0);
  printf(" | ");              /*Desenhando o jogo da velha*/
  velha(0,1) ;
  printf(" | ");
  velha(0,2);
  printf("\n ---+---+---\n2 ");
  velha(1,0);
  printf(" | ");
  velha(1,1);
  printf(" | ");
  velha(1,2);
  printf("\n ---+---+---\n3 ");
  velha(2,0);
  printf(" | ");
  velha(2,1);
  printf(" | ");
  velha(2,2);

}

void checagem() {  /*Função para checar o resultado do jogo*/
  int i;
  for (i=0;i<3;i++) { /* Checando a horizontal */
    if (matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]) {
      if (matriz[i][0] == 1) win=1;
      if (matriz[i][0] == 2) win=2;
    }
  }
  for (i=0;i<3;i++) { /*checando a vertical */
    if (matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i]) {
      if (matriz[0][i] == 1) win=1;
      if (matriz[0][i] == 2) win=2;
    }
  }
  if (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]) { /* checando a diagonal cima-baixo*/
    if (matriz[0][0] == 1) win=1;
    if (matriz[0][0] == 2) win=2;
  }
  if (matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0]) { /* checando a diagonal baixo-cima */
    if (matriz[0][2] == 1) win=1;
    if (matriz[0][2] == 2) win=2;
  }
system("cls");
}


void nomes(){
    printf("\n================================JOGA DA VELHA=================================\n\n");
  printf("Entre com o nome do jogador 1:");
  scanf("%s",&jogador1);
  printf("Entre com o nome do jogador 2:");/*Pega os nomes do jogadores*/
  scanf("%s",&jogador2);
}

void play(int player) {
  if (player==1) strcpy (aux, jogador1);

  if (player==2) strcpy (aux, jogador2);


  play:
  linha=0;
  coluna=0;
  while (linha<1 || linha>3) {
    printf("\n|%s | escolha a Linha (1,2,3): ", aux);
    scanf("%d",&linha);
    getchar();
  }
  while (coluna<1 || coluna>3) {
    printf("\n|%s | escolha a Coluna (1,2,3): ", aux);
    scanf("%d",&coluna);
    getchar();
  }
  linha--;
  coluna--;
  if (matriz[linha][coluna] != 1 && matriz[linha][coluna] != 2) matriz[linha][coluna]=player;
  else {
    printf("Alguem ja marcou ai. Tente outro lugar!.\n");

    jogo();

    goto play;

  }

}

int main() {
  nomes();
  jogo();
  play(1);
  checagem();
  if (win == 1 || win == 2) goto end;
  jogo();
  play(2);
  checagem();
  if (win == 1 || win == 2) goto end;
  jogo();
  play(1);
  checagem();
  if (win == 1 || win == 2) goto end;
  jogo();
  play(2);
  checagem();
  if (win == 1 || win == 2) goto end;
  jogo();
  play(1);
  checagem();
  if (win == 1 || win == 2) goto end;
  jogo();
  play(2);
  checagem();
  if (win == 1 || win == 2) goto end;
  jogo();
  play(1);
  checagem();
  if (win == 1 || win == 2) goto end;
  jogo();
  play(2);
  checagem();
  if (win == 1 || win == 2) goto end;
  jogo();
  play(1);
  checagem();
  if (win == 1 || win == 2) goto end;

  end:
  jogo();
  if (win == 1 || win == 2){
      printf("\n========================\n");
      printf("\nParabens, O Jogador |%s| venceu o jogo!\n\a\a\a\a", aux);
      printf("\n========================\n");

system("pause");
  }
  else{
      printf("\n========================\n");
      printf("\nVelha!\n\a\a\a\a\a\a");
      printf("\n========================\n");

system("pause");

}
 printf("\n\n-------------------------\n\n");
      printf("Gamer Desenvolvido por Melque Henrique\n Graduando em Ciencia da Computação.");
      printf("\n\n-------------------------\n\n");
      printf("Saindo do Jogo...");
      system("pause");
}
