#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <Servo.h>

Servo motor; //Cria uma instância da biblioteca Servo [Para servo motor]

#define A 8 //pino A DISPLAY7
#define B 9 //pino B DISPLAY7
#define C 12 //pino C DISPLAY7
#define D 11 //pino D DISPLAY7
#define E 10 //pino E DISPLAY7
#define F 6 //pino F DISPLAY7
#define G 5 //pino G DISPLAY7
#define DP 13 //pino DP DISPLAY7

#define echoPin 2 //pino do sensor ultrasonico [echo]
#define trigPin 3 //pino do sensor ultrasonico [trigger]


extern int qte_vagas; //variavel que armazena o números de vagas.
extern long duration; 
extern int distance; 
extern int pos; 

//matriz do display7
extern int matriz[10][7] = {
  {1,1,1,1,1,1,0},    // 0
  {0,1,1,0,0,0,0},    // 1
  {1,1,0,1,1,0,1},    // 2
  {1,1,1,1,0,0,1},    // 3
  {0,1,1,0,0,1,1},    // 4
  {1,0,1,1,0,1,1},    // 5
  {1,0,1,1,1,1,1},    // 6
  {1,1,1,0,0,0,0},    // 7
  {1,1,1,1,1,1,1},    // 8
  {1,1,1,1,0,1,1},    // 9
};

//função que exibe o numero de vagas.
void exibir_numero(int numero);
// função que abre a cancela da garagem
void abrir_cancela();
// função que fecha a cancela da garagem
void fechar_cancela();
// função que verifica as informações da outra placa
void verifica_dados (void);


#endif
