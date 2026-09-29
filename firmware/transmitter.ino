// Variables to store the count and time
int objectCount = 0;
unsigned long startTime;
// Constants for time calculations
const unsigned long hourInMillis = 3600000; // 1 hour in milliseconds
char message[50];                           // message string
char receivedmessage[50];                   // message string
dht DHT;
void setup() {
  Serial.begin(9600);
  delay(500); // Delay to let system boot
  Serial.println("Sensors Data Transfer\n\n");
  delay(1000); // Wait before accessing Sensor
  pinMode(infraredSensorPin, INPUT);
  startTime = millis(); // Record the start time
}
void loop() {
  if (Serial.available()) // while message received
  {
    // Clear the message array before receiving new data
    memset(receivedmessage, 0, sizeof(receivedmessage));
  }
  // Read the DHT11 sensor data
  DHT.read11(dht_apin);
  // Read soil moisture sensor data
  int soilMoisture = analogRead(soil_apin);
  int sensorState = digitalRead(infraredSensorPin);
  // Check if an object is detected
  if (sensorState == HIGH) {
    // Increment the count
    objectCount++;
    // Print a message to the serial monitor
    Serial.println("Object detected!");
    Serial.print("Objects detected so far: ");
    Serial.println(objectCount);
  }
  // Check if an hour has passed
  if (millis() - startTime >= hourInMillis) {
    // Print the count and reset variables
    Serial.println("Hourly Report:");
    Serial.print("Objects detected in the last hour: ");
    Serial.println(objectCount);
    // Reset variables for the next hour
    objectCount = 0;
    startTime = millis();
  }
  // Format the data as a comma-separated string
  sprintf(message, "%d,%d,%d,%d,%d,%d", DHT.temperature, DHT.humidity, soilMoisture,
          sensorState, objectCount, millis());
