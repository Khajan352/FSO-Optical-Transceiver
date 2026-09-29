const int messageSize = 50;
byte receivedMessage[messageSize]; // To store the received bytes
void setup() {
  Serial.begin(9600);
  Serial.println("Data Receiver");
}
void loop() {
  // Check if there are bytes available to read
  if (Serial.available() >= messageSize) {
    // Read the incoming data into the receivedMessage array
    Serial.readBytes(receivedMessage, messageSize);
    // Process the received data as needed
    int temperature, humidity, soilMoisture, sensorState, objectCount;
    unsigned long millisValue;
    // Assuming the format is "%d,%d,%d,%d,%d,%lu"
    sscanf(reinterpret_cast<char *>(receivedMessage), "%d,%d,%d,%d,%d,%lu", &temperature,
           &humidity, &soilMoisture, &sensorState, &objectCount, &millisValue);
    // Print the received data to the serial monitor
    Serial.println("Received Data:");
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);
    Serial.print("Soil Moisture: ");
    Serial.println(soilMoisture);
    Serial.print("Infrared Sensor State: ");
    Serial.println(sensorState);
    Serial.print("Object Count: ");
    Serial.println(objectCount);
    Serial.print("Millis Value: ");
    Serial.println(millisValue);
    Serial.println();
  }
}
