//determining the R0 value using serial monitor//

float sensor_volt = 0; //voltage
float RS = 0; //Gas resistance
float R0 = 0; //initial resistance
float sensorValue = 0; //direct value from sensor on a scale from 0 to 1023

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0 ; i < 100 ; i++)
  {
    sensorValue = sensorValue + analogRead(A0);
  }

  delay(10);
  sensorValue = sensorValue / 100; //determine the average
  sensor_volt = sensorValue / (1024 * 5.0); //Calculates sensor voltage
  
  Serial.print("Volt: ");
  Serial.println(sensor_volt);

  RS = (5.0 - sensor_volt) / sensor_volt; //Calculates RS
  R0 = RS / 50.0; //Calculates R0

  Serial.print("R0 = ");
  Serial.println(R0, 5);

  delay(100);
  sensorValue = 0; //reset
}
