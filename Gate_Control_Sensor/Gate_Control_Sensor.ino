senso /*
   Aula Curso Arduino Básico ao Avançado e prototipagem
   Instrutor Otávio Jesus França Oliveira
   Sorocaba - SP
   otaviojf_oliveira@outlook.com
 */

#define aberto 7
#define fechado 6
#define barreira 10
#define botao 11
#define motorD  12 //define pino motor 1 pra frente
#define motorE  13
// ------------------------------------------------------------------------------

void setup()
{
     pinMode(motorD, OUTPUT);//define os pinos dos motores como saida   
     pinMode(motorE,OUTPUT);
     pinMode(aberto,INPUT_PULLUP); // define o pino como entrada e ativa o resistor pullup  
     pinMode(fechado,INPUT_PULLUP);
     pinMode(botao,INPUT_PULLUP);
     pinMode(barreira,INPUT_PULLUP);
     
     digitalWrite(motorD,LOW);
     digitalWrite(motorE,LOW);
  
     Serial.begin(9600);
} // end loop
//--------------------------------------------------------------------------------------
void loop() 
{ 
  if(!digitalRead(botao)) 
  {
    delay(500);
    if(!digitalRead(aberto)&&digitalRead(barreira)) fechar();
    else
    if(!digitalRead(fechado)) abrir();
  }


} //fecha o loop
//------------------------------------------------------------------------
void fechar ()
  { //função
      while(digitalRead(fechado)&&digitalRead(barreira))
     {
       Serial.println("Fechando o portao");
       digitalWrite(motorD, HIGH); // motor indo para frente
       digitalWrite(motorE,LOW);
     }
     if(!digitalRead(barreira))
     {
      parar(); // para o motor 
      Serial.println("Sensor de barreira ativado");
      delay(2000); // aguarda dois segundos e chama a funçao abrir
      abrir();
     }

     else
     {
          parar(); // para o movimento do motor 
          Serial.println("Portao fechado");
     }   
  }
//------------------------------------------------------------------------
void abrir()
    {
      while(digitalRead(aberto))
      {
        Serial.println("Abrindo o portao");
        digitalWrite(motorD, LOW); 
        digitalWrite(motorE,HIGH); // motor indo para traz
      }
      parar();
      Serial.println("Portao aberto");
    }
//------------------------------------------------------------------------    
void parar()
{
    digitalWrite(motorD, LOW); 
    digitalWrite(motorE,LOW);
}

    

