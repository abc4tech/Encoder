#include "Encoder.h"

//Sæt encoder op - tallene er hvilke digital-pins
Encoder encoder(20,21);

//Encoder variable
unsigned long aCount = 0;
unsigned long omdrejninger = 0;

//  Encoders
void readEncoder();

void setup(){
    //Read from encoders
    //Husk at ændre 3-tallet
    attachInterrupt(3, readEncoder, RISING);
}

void loop(){

    //Print antal ticks
    Serial.println(aCount);

    //Sæt antal omdrejninger
    omdrejninger = encoder.getRotations(aCount);

    //Print antal omdrejninger
    Serial.println(omdrejninger);
}

void readEncoder(){
    aCount ++;
}