#include "config.h"

void setup() {

  Serial.begin(9600);
  
  motor.attach(4);
  motor.write(0);
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 


  pinMode(A,OUTPUT); // segmento A
  pinMode(B,OUTPUT); //segmento  B
  pinMode(C,OUTPUT); //segmento C
  pinMode(D,OUTPUT); //segmento D
  pinMode(E,OUTPUT); //segmento E
  pinMode(F,OUTPUT); //segmento F
  pinMode(G,OUTPUT); //segmento G
  pinMode(DP,OUTPUT); //segmento DP


}

void loop() {
  
  verifica_dados();

  exibir_numero(qte_vagas); 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
 


 if ((distance < 20) && (qte_vagas != 0))
  {
 
      Serial.println("Carro chegou");
      delay(1000);
      Serial.println("Verifica se tem vaga");
    //  delay(1000);
    
      Serial.println("Abre a cancela");
      abrir_cancela();

      delay(5000);

      Serial.println("Fecha a cancela");
      fechar_cancela();

     delay(5000);
  
 }


}
