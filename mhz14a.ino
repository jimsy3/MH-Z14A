// from https://arduinomania.in.ua/datchik-co2-mh-z14
int CO2; // co2 variable
int pin_CO2 = 0; // D3 as GPIO0 - aka IO5 on Ard.Uno 

void setup()
{
Serial.begin(9600); // open COM-port 
pinMode(pin_CO2, INPUT); // sensor CO2 pin is initiated

}

void loop()
{
 // CO2 pulse duration
 while(digitalRead(pin_CO2)==HIGH){;}
 float duration_h = pulseIn(pin_CO2,HIGH)/1000; // asd
 CO2=int(5000*(duration_h-2)/(duration_h+(1004-duration_h)-4)); // recalculate in ppm
 //output
 Serial.print("CO2 level: ");
 Serial.print(CO2);
 Serial.println(" ppm");
 delay(1000); // loop 1 sec
  
}
