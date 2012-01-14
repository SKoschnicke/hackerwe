  int sendPin = 12;
  int LEDPin = 8;

  void setup()
  {
    // Initialize the Serial Interface
    Serial.begin(9600);
    pinMode(sendPin, OUTPUT);
    pinMode(LEDPin, OUTPUT);
  }

  void sendSingleSignal(int timeInMilliseconds) {
    for(int i = 0; i < timeInMilliseconds / 25 * 1000; i++) {
      digitalWrite(sendPin, HIGH);
      delayMicroseconds(13);
      digitalWrite(sendPin, LOW);
      delayMicroseconds(12);
    }
  }

  void loop()
  {
    Serial.println("Starting...");
          
    digitalWrite(LEDPin, HIGH);
    sendSingleSignal(2000);
    delay(1000);
    sendSingleSignal(1500);
    delay(1000);
    sendSingleSignal(700);
    delay(1000);
    sendSingleSignal(1500);
    digitalWrite(LEDPin, LOW);
    Serial.println("Finished, waiting 5 seconds...");
    delay(5000);
  }
