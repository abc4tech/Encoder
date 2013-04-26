/*
Encoder.cpp - Library for Incremental Shaft Encoders
Created by MJC; Mikkel, Joakim & Casper
April 2013
*/

#include "Encoder.h"

Encoder::Encoder(int in1, int in2)
{
    pinMode(in1, INPUT);
    pinMode(in2, INPUT);
    
    _in1 = in1;
    _in2 = in2;
    
    _pulses = 0;
    _pulsesPerRotation = 1;

    gearRatio = 1;
}

void Encoder::setGearRatio(int ratio)
{
    gearRatio = ratio;
}

void Encoder::setPulsesPerRotation(int ppr)
{
    _pulsesPerRotation = ppr;
}

void Encoder::update(){
    _pulses++;
}

int Encoder::getRotations()
{
    return int(float(_pulses)/float(_pulsesPerRotation*gearRatio));
}