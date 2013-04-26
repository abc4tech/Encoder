/*
Encoder.h - Library for motor control
Created by MJC; Mikkel, Joakim & Casper
December 2011
*/

#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

class Encoder
{
    public:
        Encoder(int in1, int in2);
        int getRotations(int count);
        float getSpeed(int count1, int count2, int timeDelay);
        float getSpeed2(int count1, int count2, int timeDelay);
    private:
        int _in1, _in2;
        int count;
};

#endif