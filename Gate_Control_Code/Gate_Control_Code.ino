 /*
   Aula Curso Arduino Básico ao Avançado e prototipagem
   Instrutor Otávio Jesus França Oliveira
   Sorocaba - SP
 */


#define motorD  7 //define pino motor 1 pra frente
#define motorE  6
#define aberto 8
#define fechado 9
#define botao 5

// ------------------------------------------------------------------------------

void setup()
{
     pinMode(motorD, OUTPUT);//define os pinos dos motores comoo saida   
     pinMode(motorE,OUTPUT);
     pinMode(aberto,INPUT_PULLUP);  
     pinMode(fechado,INPUT_PULLUP);
     pinMode(botao,INPUT_PULLUP);
     
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
    if(!digitalRead(aberto)) fechar();
    else
    if(!digitalRead(fechado)) abrir();
  }


} //fecha o loop
//------------------------------------------------------------------------
void fechar ()
  { //função
    while(digitalRead(fechado))
    {
    Serial.println("Fechando o portao");
    digitalWrite(motorD, HIGH); // motor indo para frente
    digitalWrite(motorE,LOW);
    }
     parar();
     Serial.println("Portao fechado");
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

    
