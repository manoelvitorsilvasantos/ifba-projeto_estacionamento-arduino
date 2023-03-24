#include <Servo.h>

Servo motor;

int qte_vagas;
long duration; 
int distance; 
int pos;

int matriz[10][7] = {
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




#define echoPin 2 
#define trigPin 3 

#define A 8
#define B 9
#define C 12
#define D 11
#define E 10
#define F 6
#define G 5
#define DP 13



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


void exibir_numero(int numero)
{

  digitalWrite(A,0);
  digitalWrite(B,0);
  digitalWrite(C,0);
  digitalWrite(D,0);
  digitalWrite(E,0);
  digitalWrite(F,0);
  digitalWrite(G,0);

  digitalWrite(A,matriz[numero][0]);
  digitalWrite(B,matriz[numero][1]);
  digitalWrite(C,matriz[numero][2]);
  digitalWrite(D,matriz[numero][3]);
  digitalWrite(E,matriz[numero][4]);
  digitalWrite(F,matriz[numero][5]);
  digitalWrite(G,matriz[numero][6]);

}




void abrir_cancela()
{
  for (int pos = 0; pos <= 90; pos += 5) { 
    motor.write(pos);         
    delay(15);
                      
  }
  //  qte_vagas--;   
}


void fechar_cancela()
{

  for (pos = 90; pos >= 0; pos -= 5) { 
    motor.write(pos);                 
    delay(15); 
                            
  }
    exibir_numero(qte_vagas); 
}

void verifica_dados (void)
{

  if(Serial.available()>0)
  qte_vagas = Serial.read();

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
