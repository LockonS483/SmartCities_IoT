#include <Arduino.h>
#include <SoftwareSerial.h>
#include <RFSoft.h>

//Variables
const int envelopePin = A0;
int sensorValue = 0;

SoftwareSerial rfSerial(2,4); //Radio Serial. rx: 2,  tx: 4

int mode = 0; //Mode Selection for test (0: Broadcast, 1: Listen)

void setup() {
  // put your setup code here, to run once:

  //Begin Serial Communication
  Serial.begin(9600);

  //Begin RF SoftSerial
  rfSerial.begin(9600);
  delay(100);

  //Send ID message test:
  //rfSerial.write(idSetTest, 9);
  for(int i=0; i<5; i++){
    rfSerial.write(idCheckTest[i]);
  }
  rfSerial.write(idCheckTest2, 14);
  delay(500);
  //rfSerial.write(messageSendTest, 12);
  Serial.println("Ready");
}

void loop() {
  // put your main code here, to run repeatedly:

  //Check for output from TCM320
  if(rfSerial.available()){
    Serial.println("rfSerial available: Reading...");
    String cmd = "";
    while(rfSerial.available()){
      cmd += (byte)rfSerial.read();
      cmd += (" ");
      delay(10); //delay cushion
    }

    Serial.println(cmd);
    cmd = "";
  }

  if (Serial.available()){
    delay(10); // The delay is necessary to get this working!
    rfSerial.write((byte)Serial.read());
    /*for(int i=0; i<sizeof(messageBytes); i++){
      btSerial.write(messageBytes[i]);
      Serial.print("Send: " + messageBytes[i]);
    }
    Serial.println("wee");
    */
    Serial.println("wee");
  }

  delay(50);
}
