/*
Encoder.h - Library for Incremental Shaft Encoders
Created by MJC; Mikkel, Joakim & Casper
April 2013
*/

#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

class Encoder
{
    public:
        Encoder(int in1, int in2);
        
        int gearRatio;
        
        void setGearRatio(int ratio);
        void setPulsesPerRotation(int ppr);
        
        void update();

        int getRotations();

    private:
        int _in1, _in2, _pulsesPerRotation;
        unsigned long _pulses;
};

#endif