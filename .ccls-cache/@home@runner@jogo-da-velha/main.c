#include <stdio.h>

void imprimeTabuleiro(char tabuleiro[3][3]){
for(int l=0; l<3; l++){
  for(int c=0; c<3; c++)
    {
    printf(" %c ", tabuleiro[l][c]);
    if(c<2)
      printf("|");
    else
      printf("\n");
    }
  if (l<3)
  printf("---+---+---\n");
    }
}
char verificaVencedor(char tabuleiro[3][3]){
for(int c=0; c<3; c++){
if(tabuleiro[0][c] == tabuleiro[1][c] && tabuleiro[2][c] == tabuleiro[1][c]){
return tabuleiro[0][c];
}
if(tabuleiro[c][0] == tabuleiro[c][1] && tabuleiro[c][2]==tabuleiro[c][1]){
return tabuleiro[c][0];
}
}
if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[2][2] == tabuleiro[1][1]){
return tabuleiro[0][0];
}
if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[2][0] == tabuleiro[1][1]){
return tabuleiro[0][2];
}
return ' ';
}

int main(void) {
char tabuleiro[3][3] = {{' ', ' ', ' '}, 
                        {' ', ' ', ' '}, 
                        {' ', ' ', ' '}};
int linha, coluna, jogadas=0;
char jogador1 = 'X';
char vencedor = ' ';

printf("Bem-vindo ao jogo da velha!\n");
while (vencedor == ' ' && jogadas < 9){
printf("Jogador %c, escolha uma linha de (1-3):", jogador1);
scanf("%d", &linha);
printf("Jogador %c, escolha uma coluna de (1-3):", jogador1);
scanf("%d", &coluna);

if(linha >3 || coluna >3 || linha <1 || coluna <1 || tabuleiro[linha-1][coluna-1] != ' '){
printf( "Jogada inválida. Tente novamente.\n");
continue;
}
tabuleiro[linha-1][coluna -1] = jogador1;
jogadas++;
imprimeTabuleiro(tabuleiro);
if (jogadas >4)
vencedor= verificaVencedor(tabuleiro);

if(jogador1 == 'X')
jogador1 = 'O';
else
jogador1 = 'X';
printf("jogada %d concluidada!\n", jogadas);
}
switch (vencedor){
case 'X' : printf("Jogador X venceu!\n");break;
case 'O' : printf("Jogador O venceu!\n");break;
default: printf("Empate!\n");break;
}
  return 0;
}