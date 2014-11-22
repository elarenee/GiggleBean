char val;
int ledpin = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available() ) {
    val = Serial.read();
  }
  
  if (val == '1') {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  } else {
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  }
  delay(100);
}
