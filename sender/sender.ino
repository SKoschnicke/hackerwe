  int sendPin = 12;

  void setup()
  {
    // Initialize the Serial Interface
    Serial.begin(9600);
    pinMode(sendPin, OUTPUT);
  }

  void sendSingleSignal(int timeInMilliseconds) {
    for(int i = 0; i < timeInMilliseconds * 4; i++) {
      digitalWrite(sendPin, HIGH);
      delayMicroseconds(12);
      digitalWrite(sendPin, LOW);
      delayMicroseconds(13);
    }
  }

  void loop()
  {
    Serial.println("Starting...");
    sendSingleSignal(2000);
    delay(100);
    sendSingleSignal(1500);
    delay(100);
    sendSingleSignal(750);
    delay(100);
    sendSingleSignal(1500);
    Serial.println("Finished, waiting 5 seconds...");
    delay(5000);
  }
