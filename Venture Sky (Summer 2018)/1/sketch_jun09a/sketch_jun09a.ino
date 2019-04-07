int i;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  i=0;
  // int i=0; //Won't work as i won't be avilable in loop()
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    //i=Serial.read(); //This reads only first character and converts it to it's ASCII integer value. e.g 300 -> 3 and value of '3'=51
    //i=Serial.readInt(); //This works
    String s = Serial.readString();
    Serial.println(s);
  }
  Serial.print("i = ");
  Serial.println(i);
  i++;
  delay(1000);// Delay in milliseconds
}
