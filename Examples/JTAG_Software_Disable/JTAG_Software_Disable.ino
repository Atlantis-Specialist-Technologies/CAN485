void setup() {
  // Disable JTAG
  // Note there is an open issue regarding this code.
  // Refer to the link below for further details.
  // So far it works in all tests. 
  // https://github.com/Atlantis-Specialist-Technologies/CAN485/issues/2
  
  MCUCR = (1<<JTD);
  MCUCR = (1<<JTD);

  // Set JTAG pins as outputs
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
}

void loop() {
  // Blink the JTAG pins to test them
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
  digitalWrite(A6, HIGH);
  digitalWrite(A7, HIGH);
  delay(1000);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A6, LOW);
  digitalWrite(A7, LOW);
  delay(1000);
}
