int inputPin = A0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int value = analogRead(inputPin);
  Serial.println(value);
}
