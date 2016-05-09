int led = 12;
int motor = 10;
long start=0;
boolean chico=false;
int veces=1;
void setup() {  
  Serial.begin(9600);  
  pinMode(led, OUTPUT);     
  pinMode(2, INPUT);
  pinMode(motor, OUTPUT);
  
  digitalWrite(2,HIGH);
  digitalWrite(led, LOW);
  
  randomSeed(millis());
  delay(random(1000,3000));
  attachInterrupt(0,react,RISING); 
  start= millis();
}


void loop() {
  
  //prueba = analogRead(A0);
  /*Serial.print(digitalRead(2));
  Serial.print("\n");
  Serial.print(analogRead(A0)/4);
  Serial.print("\n");  */
  
  if(analogRead(A0)<20){
    chico= true;
  }
  analogWrite(motor, analogRead(A0)/4);
  /*if(chico){
    Serial.print("va a 45 rv");
    Serial.print("\n");
  }else{
    Serial.print("va a 33 rv");
    Serial.print("\n");
  }*/
  
  
}

void react(){
  long fin= millis();
  if(fin-start>=500){
 
  //detachInterrupt(0);
  //digitalWrite(led, HIGH);
  //Serial.print("tiempo ");
  Serial.print(fin-start);
  Serial.print("-->");
  Serial.print( analogRead(A0)/4);
  Serial.print("\n"); 
  if(((fin-start)>=1275)&&((fin-start)<=1280)){
    Serial.print("33 rv"); 
    Serial.print("\n"); 
    digitalWrite(led, HIGH);
  }
  if(((fin-start)>=1740)&&((fin-start)<=1745)){
    Serial.print("45 rv"); 
    Serial.print("\n"); 
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
    }
   
  
  start= millis();
  
  
  }
  
  
}

