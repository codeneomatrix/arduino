int led = 12;

int prueba;
void setup() {  
  Serial.begin(9600);  
  pinMode(led, OUTPUT);     
//  pinMode(foto, INPUT);       
}


void loop() {
  
  prueba = analogRead(A0);
  Serial.print(prueba);
  Serial.print("\n");  
  
  //if(prueba>=90){//valor del sesor del plato
  if(prueba>=10){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW); 
  }
  
  
}
