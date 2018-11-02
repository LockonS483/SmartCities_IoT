const int envelopePin = A0;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(envelopePin);
  Serial.println("Envelope Reading:\t " + sensorValue);
  delay(800);
}
