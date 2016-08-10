int bulletsLeft = 6;
bool isDetected = 0;
bool wasDetected = 0;

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
}

void loop() {
  //Serial.println(analogRead(A0));
  delay(5);
  // put your main code here, to run repeatedly:
int sensor = analogRead(A0);
isDetected = 0;
if (sensor < 100||sensor > 700){
  isDetected = 1;
}
if (isDetected > wasDetected){
  bulletsLeft = bulletsLeft - 1;
  Serial.println("");
  Serial.print("You have ");
  Serial.print(bulletsLeft);
  Serial.print(" bullets left.");
  delay(50);
}
wasDetected = isDetected;
}
