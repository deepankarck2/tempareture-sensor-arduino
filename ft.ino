#include <dht.h>
#define dht_apin A0 // Analog Pin sensor is connected to

dht DHT;
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup(){
  lcd.begin(16, 2);
  // Print a message to the LCD.

  
  Serial.begin(9600);
  delay(2000);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(2000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature);
    Serial.println("C  ");
    float temp_faren= (DHT.temperature*1.8)+32; 

    
    lcd.setCursor(0, 0);
    lcd.print("Tem.:");
    lcd.print(DHT.temperature,1);
    lcd.print("C,");
    lcd.print(temp_faren,1);
    lcd.print("F ");
    
    
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(DHT.humidity); 
    lcd.print("%  ");
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
}// end loop(
