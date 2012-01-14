/* LED Light Sensor
 * by Duane O'Brien
 * for IBM Developer Works
 */
  int recvPin = 0;
  int wait = 1000;
  int val = 0;

  void setup()
  {
    // Initialize the Serial Interface
    Serial.begin(9600);
  }

  void loop()
  {
    // Take a reading from the Analog Pin
    val = analogRead(recvPin);
    // Output the detected value
    Serial.print("DETECT : ");
    Serial.println(val);
    // Wait to take the next reading.
    delay(wait);
  }
