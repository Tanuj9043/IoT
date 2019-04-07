void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}

//For a LDR(Light Detecting R) lower the LDR's resistance, more will be Voltage across LDR. We are
//measuring voltage across LDR.
//Lower the other rsistance, higher the LDR's senstivity
//LDR's resistance max when 100% darkness. More LDR's resistance, more sensorValue.

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(34);
  //Serial.println(sensorValue);
  int percent = map(sensorValue, 0, 4095, 0, 100);
  Serial.println(percent);//Try using Tools->Serial Plotter to see the graph
  delay(100); 
}
