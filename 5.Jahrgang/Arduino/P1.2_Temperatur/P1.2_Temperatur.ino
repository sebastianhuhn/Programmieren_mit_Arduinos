#include <Display.h>
#include <TemperaturSensor.h>

Display display;
TemperaturSensor sensor( A3 );

float temperatur;

void setup() {
  temperatur = 0.0;
  // put your setup code here, to run once:
  display.initialisiere();
  display.schreibeText("Temperatur:");
}

void loop() {
  delay(500);
  temperatur = sensor.missTemperatur();
  display.geheZweiteZeile();
  display.schreibeText( temperatur );
  display.schreibeText( " Grad-C" );
  // put your main code here, to run repeatedly:

}
