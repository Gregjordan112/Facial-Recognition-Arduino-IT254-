#define GREEN_LED 13  // where my green led will be
#define RED_LED 12  // where my red led will be   

String incomingData = ""; // To store incoming serial data

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW); // makes sure that the green led start OFF
  digitalWrite(RED_LED, LOW); // makes sure that the red led start OFF

  Serial.begin(9600); // serial communication
}

void loop() {
  if (Serial.available()) {
    incomingData = Serial.readStringUntil('\n'); // read until newline
    incomingData.trim(); // cleans any extra spaces or line breaks

    if (incomingData == "ON") {
      digitalWrite(GREEN_LED, HIGH); // turns the green led ON.
      digitalWrite(RED_LED, LOW); // turns the red led OFF. 
    }
    else if (incomingData == "OFF") {
      digitalWrite(GREEN_LED, LOW);  // turns the green led OFF.
      digitalWrite(RED_LED, HIGH); // turns the red led ON.
    }
  }
}