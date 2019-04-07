#define ledPin 26

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<10; i++){
    digitalWrite(ledPin, LOW);
    delay(i*20);
    digitalWrite(ledPin, HIGH);
    delay(i*20); 
  }
  for(int i=10; i>=0; i--){
    digitalWrite(ledPin, LOW);
    delay(i*20);
    digitalWrite(ledPin, HIGH);
    delay(i*20); 
  }
}
