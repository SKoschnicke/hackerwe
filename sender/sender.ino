  int sendPin = 11;
  int LEDPin = 10;

  void setup()
  {
    // Initialize the Serial Interface
    Serial.begin(9600);
    pinMode(sendPin, OUTPUT);
    pinMode(LEDPin, OUTPUT);
  }

  // min 250us
  // max 1750us
  void sendSingleSignal(long timeInMicroseconds) {
    for(long i = 0; i < timeInMicroseconds / 25; i++) {
      digitalWrite(sendPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(sendPin, LOW);
      delayMicroseconds(10);
    }
  }

  // min 250us
  // max 1750us
  long startBit     =  550;
  long oneBit       =  425;
  long zeroBit      =  300;

  unsigned int gap  =  350; // min 250us

  void sendData(byte player, byte weapon) {
    sendByte(player + (weapon << 4));
  }

  void sendByte(byte data) {

    sendSingleSignal(startBit);
    delayMicroseconds(gap);
    for(int i = 0; i < 8; i++) {
      if ((data >> i) & B00000001) {
        sendSingleSignal(oneBit);
      } else {
        sendSingleSignal(zeroBit);
      }
      delayMicroseconds(gap);
    }
  }

  void loop()
  {
    //Serial.println("Starting...");


    // switch status LED on
    digitalWrite(LEDPin, HIGH);

    sendData(5,2);
    /*
    sendData(1,8);
    sendData(12,3);
    */
    // switch status LED off
    digitalWrite(LEDPin, LOW);

    //Serial.println("Finished, waiting 2 seconds...");
    delay(2500);
  }
