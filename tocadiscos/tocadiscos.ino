int led = 12;
int motor = 10;
long start=0;

// int base =95; // parte externa
int base= 110;
//int valoroptimo=1743;
//int valoroptimo=59; //parte externa

int valoroptimo= 54;
int valoroptimof=54;

int distancia=0,lento=0,rapido=0,velocidad = 0,estable=0;
double extremo=0,medio=0,interior=0;
int minimo=140,maximo=200;
int veces=0;
int promedio=0;
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
    valoroptimo=71;
  }
  analogWrite(motor, base);
  
  int l=analogRead(A5);
  if((l)<minimo ){
    minimo=l;
  }
  if((l)>maximo ){
    maximo=l;
  }
  int p= ((minimo+maximo)/2);
 
  if(promedio!=p){
  //Serial.print(p);
  //Serial.print("  vof: ");
  
  if((p-promedio)<0){
    minimo=140;
    maximo=200;
  }
  promedio=p;

  extremo =  FuncionGradoInversa(promedio, 208, 235);
  medio=    FuncionTriangulo( promedio,230, 245, 260);
  interior=  FuncionGrado(promedio, 250, 280);

  valoroptimof= valoroptimo-((extremo*2)+(medio*0)+(interior*-2)/(extremo+medio+interior));

  //Serial.print(valoroptimof);
  //Serial.print("\n");
  }

  
 
}

void react(){
  long fin= millis();
  if(veces==3){
  if(fin-start>=10 ){
    int tiempo=fin-start;
   //Serial.print("//> tiempo :");
  //Serial.print(tiempo);
  //Serial.print("\n"); 
  
  
  distancia=valoroptimof-(tiempo);
  start= millis();
   
  if(distancia<=10 && distancia>=-10){
    digitalWrite(led, HIGH);
   Serial.print(0);
  Serial.print("\n");
  }else{
    digitalWrite(led, LOW);
    
    estable=FuncionTriangulo(distancia,-20,0,20);
    lento=FuncionGrado(distancia, 5, 10);
    rapido=FuncionGradoInversa(distancia, -10, -5);
   
    base= base+((lento*-1)+(estable*0)+(rapido*1)/(rapido+estable+lento));
  }
  
  Serial.print(distancia);
  Serial.print("\n");
  /*Serial.print(" //> distancia:");
  Serial.print(distancia);
   
  Serial.print("> base ");
  Serial.print(base);
  Serial.print("\n");*/
 
  }
  }else{
    veces=veces+1;
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

