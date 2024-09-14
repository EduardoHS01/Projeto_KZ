// C++ code
//
int motorA1 = 5;
int motorA2 = 6;
int motorB1 = 10;
int motorB2 = 11;
int sensor_L =9;
int sensor_R =8;
int sensor_irT = 13;
int sensor_irL = 2;
int sensor_irR = 3;
void setup()
{
  Serial.begin(9600);
  pinMode(motorA1,OUTPUT);
  pinMode(motorA2,OUTPUT);
  pinMode(motorB1,OUTPUT);
  pinMode(motorA1,OUTPUT);
  pinMode(sensor_L,INPUT);
  pinMode(sensor_R,INPUT);
  pinMode(sensor_irR,INPUT);
  pinMode(sensor_irL,INPUT);
  pinMode(sensor_irT,INPUT);
  delay(1000);
}

void loop()
{ 
  //Right side base infrared sensor //Sensor infra vermelho da base direito
  int sir = digitalRead(sensor_irR);
  //Left side base infrared sensor //Sensor infra vermelho da base esquerda
  int sil = digitalRead(sensor_irL);
  //Back base infrared sensor //Sensor infra vermelho da base parte traseira
  int sit = digitalRead(sensor_irT);

  //Left side infrared sensor //Sensor infra vermelho esquerdo
  int sl = digitalRead(sensor_L);
  //Right side infrared sensor //Sensor infra vermelho direito
  int sr = digitalRead(sensor_R);
  if(sir)
  {
    analogWrite(motorA1,0);
    analogWrite(motorA2,255);
    analogWrite(motorB1,0);
    analogWrite(motorB2,255);
    delay(700); 
    analogWrite(motorA1,200);
    analogWrite(motorA2,0);
    analogWrite(motorB1,0);
    analogWrite(motorB2,255);
    delay(600); 
  }
  if(sil)
  {
    analogWrite(motorA1,0);
    analogWrite(motorA2,255);
    analogWrite(motorB1,0);
    analogWrite(motorB2,255);
    delay(700); 
    analogWrite(motorA1,0);
    analogWrite(motorA2,255);
    analogWrite(motorB1,200);
    analogWrite(motorB2,0);
    delay(600); 
  }
  if (sl == LOW)
  {
    analogWrite(motorA1,150);
    analogWrite(motorA2,0);
    analogWrite(motorB1,255);
    analogWrite(motorB2,0);
    delay(200);
  }
  if (sr == LOW)
  {
    analogWrite(motorA1,255);
    analogWrite(motorA2,0);
    analogWrite(motorB1,150);
    analogWrite(motorB2,0);  
    delay(200);
  }
   if(sr == LOW && sl == LOW)
  {
    analogWrite(motorA1,0);
    analogWrite(motorA2,255);
    analogWrite(motorB1,0);
    analogWrite(motorB2,255);  
    delay(1000);
  }
  else {
    analogWrite(motorA1,0);
    analogWrite(motorA2,0);
    analogWrite(motorB1,0);
    analogWrite(motorB2,0);
    }
    
  delay(20); // Delay a little bit to improve simulation performance
}
