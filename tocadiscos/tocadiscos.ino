int led = 12;
int motor = 10;
long start=0;

int base =77;
int valoroptimo=1743;
int margen=15;
int distancia=0,lento=0,rapido=0,velocidad = 0;
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
  if(analogRead(A0)<20){
    base=100;
    valoroptimo=1277;
  }
  analogWrite(motor, base);
  
}

void react(){
  long fin= millis();
  if(fin-start>=500){
  Serial.print(fin-start);
  Serial.print("\n"); 
  distancia=valoroptimo-(fin-start);
  if(distancia<margen && distancia>-margen){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  //estable=FuncionTriangulo(distancia,-1,0,1);
  lento=FuncionTrapezoide(distancia,1,margen-5,1145,1245);
  rapido=FuncionTrapezoide(distancia,-900,-950,-margen+5,-1);
  if(lento>10){
    lento=0;
  }
  if(rapido>10){
    rapido=0;
  }
  velocidad=int(lento)+int(-rapido);
  base=base-velocidad;
  /*Serial.print(" distancia:");
  Serial.print(distancia); 
  Serial.print(" //>");
  Serial.print(base);  
  Serial.print("\n"); */
  
  start= millis();
  }
}

/*int FuncionTriangulo( int x,int x0, int  x1, int x2){
int membresia=0;
if(x<=x0) membresia=0;
else if(x>x0 && x<=x1) membresia=int(((x/(x1-x0))-(x0/(x1-x0))))*100;
else if(x>x1 && x<=x2) membresia=int(((-(x/(x2-x1))+(x2/(x2-x1)))))*100;
else if(x>x2) membresia=0;

return membresia;
}*/

int FuncionTrapezoide(int x,int x0,int x1,int x2,int x3){
int membresia=0;
if(x<=x0) membresia=0;
else if(x>x0 && x<=x1) membresia=0;
else if(x>x1 && x<=x2) membresia=1;
else if(x>x2 && x<=x3) membresia=0;
else if(x>x3) membresia=0;

return membresia;
}

