int led = 12;
long start=0;
int prueba;

void setup() {  
  Serial.begin(9600);  
  pinMode(led, OUTPUT);     
  pinMode(2, INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(led, HIGH);
  
  randomSeed(millis());
  delay(random(1000,3000));
  attachInterrupt(0,react,RISING); 
  start= millis();
}


void loop() {
  
  prueba = analogRead(A0);
  //Serial.print(analogRead(A0));
  //Serial.print("\n");  
  //if(prueba>=90){//valor del sesor del plato
  if(prueba>=135){
    digitalWrite(led, LOW);
  }else{
    digitalWrite(led, HIGH);
  }
  
}

void react(){
  long fin= millis();
  //detachInterrupt(0);
  //digitalWrite(led, HIGH);
  Serial.print("tiempo ");
  Serial.print(fin-start);
  Serial.print("\n"); 
  if((fin-start)==1278){
    Serial.print("33 rv"); 
    Serial.print("\n"); 
  }
  if((fin-start)==1279){
    Serial.print("33 rv"); 
    Serial.print("\n"); 
  }
  if((fin-start)==1280){
    Serial.print("33 rv"); 
    Serial.print("\n"); 
  }
  if((fin-start)==1742){
    Serial.print("45 rv"); 
    Serial.print("\n"); 
  }
  if((fin-start)==1743){
    Serial.print("45 rv"); 
    Serial.print("\n"); 
  }
  if((fin-start)==1744){
    Serial.print("45 rv"); 
    Serial.print("\n"); 
  }
  if((fin-start)==1745){
    Serial.print("45 rv"); 
    Serial.print("\n"); 
  }
   
  
  start= millis();
  
}

