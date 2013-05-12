/*
encoder_test - Example using the Encoder library
Created by MJC; Mikkel, Joakim & Casper
April 2013
*/

#include "Encoder.h"

//Channel A and B
Encoder testEncoder(11,10);

void readEncoder(){
    testEncoder.update();
}

void setup(){
    //Serial
    Serial.begin(9600);

    //Setup Encoder values
    testEncoder.setGearRatio(10);
    testEncoder.setPulsesPerRotation(360);

    //Software Interrupt
    attachInterrupt(3, readEncoder, RISING);
}

void loop(){
    //Output number of rotations
    Serial.println(testEncoder.getPulses());
}