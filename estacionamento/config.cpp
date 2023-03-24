#include "config.h"

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
