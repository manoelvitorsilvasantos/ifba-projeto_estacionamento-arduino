#include <Servo.h>

//definindo valores dos pinos.
#define echoPin 2
#define trigPin 3
#define MOTOR 4
  
//inicializando variaveis
long duration=0;
float distance=0.0f;


//cria uma instancia da biblioteca Servo
Servo motor;


void setup(){
	Serial.begin(9600);
 	//SERVO MOTOR
  	motor.attach(MOTOR);
  	motor.write(180);
  
  	//CONFIGURACAO DO SENSOR ULTRASONICO
  	pinMode(trigPin, OUTPUT);
  	pinMode(echoPin, INPUT);
}

void loop(){
  	if(getDistance() >= 100){
      	fecharCancela();  
    }
  	else{
      	abrirCancela();
    }
}


//função para abrir cancela
void abrirCancela(){
	motor.write(90);
  delay(3000);
}

//função para fechar cancela
void fecharCancela(){
	motor.write(180);
  delay(3000);
}

// função verifica distância do objeto 
float getDistance(){
	digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;
  return distance;
}