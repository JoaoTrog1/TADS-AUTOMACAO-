#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 9
#define SS_PIN 10
String tag;
String tagm = "69b5599e";
int ledVermelho = 2;
int ledVerde = 3;
bool liberado = false;
bool ltag = false;
int posv = 0;
MFRC522 mfrc522(SS_PIN, RST_PIN);
String tagl[10];
void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}
void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      tag = tag + String(mfrc522.uid.uidByte[i], HEX);
    }
    if(tag == tagm){
      ltag = true;
      digitalWrite(ledVerde, HIGH);
      delay(300);
      digitalWrite(ledVerde, LOW);
      delay(100);
      digitalWrite(ledVerde, HIGH);
      delay(300);
      digitalWrite(ledVerde, LOW);
      delay(100);
      digitalWrite(ledVerde, HIGH);
      delay(300);
      digitalWrite(ledVerde, LOW);
      }else if(tag != ""){
        if(ltag){
            if(tagl[posv] == "" && posv < 10){
              tagl[posv] = tag;
              posv++;
              ltag = false;
              Serial.println(posv);
           }else if(posv == 9){
            Serial.println("Limites de tags adicionadas");
           }
        }

        for(int i = 0; i < 10; i++){
            if(tagl[i] == tag){
              liberado = true;
              Serial.println(i);
            }
        }
        if(liberado){
          digitalWrite(ledVerde, HIGH);
          delay(1000);
          digitalWrite(ledVerde, LOW);
          liberado = false;
        }else{
          digitalWrite(ledVermelho, HIGH);
          delay(1000);
          digitalWrite(ledVermelho, LOW);
        } 
      }
      tag = "";
  }
}

