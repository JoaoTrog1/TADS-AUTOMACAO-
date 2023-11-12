int ledVerde = 9;
int ledAzul = 10;
int ledVermelho = 11;
int pot1 = 0;
int pot2 = 1;
int pot3 = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(pot3, INPUT);
}

void loop()
{

  float vermelho = analogRead(pot1);
  int corR = valorCor(vermelho, 0, 1023, 0, 255);
  Serial.println(corR);
  analogWrite(ledVermelho, corR);
  
  
  float verde = analogRead(pot2);
  int corG = valorCor(verde, 0, 1023, 0, 255);
  Serial.println(corG);
  analogWrite(ledVerde, corG);
  
  
  float azul = analogRead(pot3);
  int corB = valorCor(azul, 0, 1023, 0, 255);
  Serial.println(corB);
  analogWrite(ledAzul, corB);
  
}
int valorCor(int leitura,int limInfEntrada,int limSupEntrada,int limInfSaida, int limSupSaida){
  Serial.print(leitura);
  Serial.print("--");
  Serial.print(limInfEntrada);
  Serial.print("--");
  Serial.print(limSupEntrada);
  Serial.print("--");
  Serial.print(limInfSaida);
  Serial.print("--");
  Serial.println(limSupSaida);
  
  int reusltado = map(leitura, limInfEntrada, limSupEntrada, limInfSaida, limSupSaida);
  return reusltado;
}
