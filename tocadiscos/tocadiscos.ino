int led = 12;
int motor = 10;
long start=0;

int veces=0;
int valorpre=0;
int base =70;
int valoroptimo=1743;
int margen=20;
int distancia=0,lento=0,rapido=0,velocidad = 0,estable=0;

int sum=0;int tot=0;
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
 /*Serial.print(analogRead(A5));
  Serial.print("\n"); */
  
}

void react(){
  long fin= millis();
  if(fin-start>=500){
  //Serial.print(fin-start);
  //Serial.print("\n"); 
  
  distancia=valoroptimo-(fin-start);
  start= millis();
  if(distancia==0){
    digitalWrite(led, HIGH);
    Serial.print(" //>");
  Serial.print(base);
  }else{
    digitalWrite(led, LOW);
    estable=FuncionTriangulo(distancia,-20,0,20);
  lento=FuncionGrado(distancia, 5, 10);
  rapido=FuncionGradoInversa(distancia, -10, -5);
  //lento=FuncionTrapezoide(distancia,1,margen,1145,1245);
  //rapido=FuncionTrapezoide(distancia,-900,-950,-margen,-1);
  //if(distancia>=-950 && distancia<0) base=base+1;
  //if(distancia>0 && distancia<=1145) base=base-1;
    base= base+((lento*-2)+(estable*0)+(rapido*2)/(rapido+estable+lento));
  }

  Serial.print("//> distancia:");
  Serial.print(distancia); 
  Serial.print(" //>");
  Serial.print(base);  
  Serial.print("\n"); 
  
  Serial.print(analogRead(A5));
  Serial.print("\n"); 
 
  

 
  }
 
}


double FuncionTrapezoide(double x,double x0,double x1,double x2,double x3){
  if(x<=x0) return 0.0;
  else if(x>x0 && x<=x1) return (x/(x1-x0))-(x0/(x1-x0));
  else if(x>x1 && x<=x2) return 1.0;
  else if(x>x2 && x<=x3) return -(x/(x3-x2))+(x3/(x3-x2));
  else if(x>x3) return 0.0;
  return 0.0;
}

double FuncionGrado(double x, double x0, double x1){
  if(x<=x0) return 0.0;
  else if(x>x0 && x<x1) return (x/(x1-x0))-(x0/(x1-x0));
  else if(x>=x1) return 1.0;
  return 0.0;
    }

double FuncionGradoInversa(double x, double x0, double x1){

  if(x<=x0) return 1.0;
  else if(x>x0 && x<x1) return -(x/(x1-x0))+(x1/(x1-x0));
  else if(x>=x1) return 0.0;
  return 0.0;
    }


double FuncionTriangulo( double x,double x0, double  x1, double x2){

  if(x<=x0) return 0.0;
  else if(x>x0 && x<=x1) return (x/(x1-x0))-(x0/(x1-x0));
  else if(x>x1 && x<=x2) return (-(x/(x2-x1))+(x2/(x2-x1)));
  else if(x>x2) return 0.0;
  return 0.0;
}

