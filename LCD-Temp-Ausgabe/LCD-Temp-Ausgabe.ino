/* 
    Autor: Andrej Stratmann
    Project: An einem LCD display die Temperatur Ausgeben
    Funktion: Ein Temperatursensor wird gelsesen - Ausgabe der Temperatur an einem display
*/
#include <LiquidCrystal.h> 
#include <OneWire.h>
#include <DallasTemperature.h>
 
LiquidCrystal lcd(13, 12 ,27 , 14 ,26 ,25);
/* Syntax
    LiquidCrystal(rs, enable, d4, d5, d6, d7) <- verwendung
    LiquidCrystal(rs, rw, enable, d4, d5, d6, d7)
    LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7)
    LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)
*/
const int oneWireBus = 33;
const int HintergrundBeleuchtung = 32;
                                    
OneWire oneWire(oneWireBus);          // einichtung von einer OneWire-Instanz, um mit beliebigen OneWire-Geräten zu kommunizieren
                                     
DallasTemperature sensors(&oneWire);  // Übergeben von OneWire-Referenz an Dallas Temperature
//-------------------------------------------------------------------------------------------------------------------//
void startlcd(int HintergrundBeleuchtung){
    lcd.begin(16, 2);                            // startet den monitor das 16 Spalten und 2 Zeilen hat
    pinMode(HintergrundBeleuchtung, OUTPUT);     // pin als output
    digitalWrite(HintergrundBeleuchtung, HIGH ); // den pin einschalten
}
//-------------------------------------------------------------------------------------------------------------------//
void Temperaturausgabe(){
  sensors.requestTemperatures();                   // Anfrage an alle Geräte am Bus
  float temperatureC = sensors.getTempCByIndex(0); // nimmt vom ic 0 die Temp.
 
  lcd.setCursor(9,0);      // Ausgabe an der 10. Spalte und 1. Zeile
  lcd.print(temperatureC); // Ausgabe von der Temp.
  lcd.print("\337C");          
  
  delay(1000); // verzögerung
}
//-------------------------------------------------------------------------------------------------------------------//
void setup() {
  sensors.begin();
  startlcd(HintergrundBeleuchtung);
  lcd.print("Celsius:"); // Text Ausgabe
}
//-------------------------------------------------------------------------------------------------------------------//
void loop() {  
Temperaturausgabe();
}
