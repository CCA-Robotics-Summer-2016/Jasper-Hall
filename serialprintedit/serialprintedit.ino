const int numberOfReadings = 600;
int measurements[numberOfReadings] ;
const int ldrPin = A0;
 
void setup() {
  Serial.begin(9600);
}
 
 
void loop() {
 
  for (int readings = 0; readings < numberOfReadings; readings++) {
    measurements[readings] = analogRead(ldrPin);
    delay(1);
  }
 
 
  // calculate the average
  int sum = 0;
 
  for (int readings = 0; readings < numberOfReadings; readings++) {
    sum = sum + measurements[readings];
  }
 
  int average = sum / numberOfReadings;
  Serial.print("average is ");
  Serial.println(average);

 
  // what's the difference between print() and println()?
  Serial.print("the highest reading is ");
  Serial.println(measurements[highestReading()]);
  
 
// return the index of the highest reading
// if there are multiple readings return one of them
int highestReading() {
 
  int latestHighestReading = 0;
 
  for (int readings = 0; readings < numberOfReadings; readings++) 
  { 
    if (measurements[readings] > measurements[latestHighestReading]) 
    {
      latestHighestReading = readings;
    }
  }
  return latestHighestReading;

}
int averageReading() {
 
  int latestAverageReading = 0;
 
  for (int readings = 0; readings < numberOfReadings; readings++) 
  { 
    if (measurements[readings] > measurements[latestAverageReading]) 
    {
      latestAverageReading = readings;
    }
  }
  return latestHighestReading;
 
}
