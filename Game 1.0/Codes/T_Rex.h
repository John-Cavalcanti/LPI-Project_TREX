#ifndef T_REX_H
#define T_REX_H

#include "T-Rex_v1.0.c"

// ranking.h
void carregaRanking();
void pegaPontuacao(int pontos);
void arquivamentoRanking();
void mostraRanking();

// desenhos.h
void DesenhaDino();
void DesenhaMenu(int opcao);
void desenhaJogoPausa(int opcao);
void mostraCreditos();
void mostraControles(char volta, int pontosPausa);
void MostraGameOver();

// game.h

void draw_dino();
void draw_dino_up(int y);
void draw_dino_down(int y);
void animation_dino_legs();
void ground();
void draw_cactusA();
void draw_cactusB();
void draw_time_score();
void set_dino(int x);
void resetDinoX(int x);
int colisao();
void gotoxy(int x, int y);
void delay(int ms);
void set_cactus(int x, int cactus);
void cactus(int time);
void setup();
void jump(char on_ground);
void engine();
void game(int pontosAtuais);
void selecionadoPausa(int acaoPausa, int pontosPausa);
void selectingPausaJogo(int pontosPausa);
void pausa(int pontosPausa);
void selecionadoMenu(int opcao);
void selectingMenu();
void menu();



#endif