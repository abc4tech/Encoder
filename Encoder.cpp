#include "Encoder.h"

const int ENCODER_PULSE = 16;
const int GEAR_RATIO = 19;
const float CIRCUMFERENCE = 22.9415; //cm

//ENCODER
Encoder::Encoder(int in1, int in2)
{
    pinMode(in1, INPUT);
    pinMode(in2, INPUT);
    _in1 = in1;
    _in2 = in2;
}

int Encoder::getRotations(int count)
{
    return int(float(count)/float(ENCODER_PULSE*GEAR_RATIO));
}

float Encoder::getSpeed(int count1, int count2, int timeDelay)
{
    // timeDelay between count1 and count2 in milliseconds

    //Get rotations from counts
    int rotations1 = getRotations(count1);
    int rotations2 = getRotations(count2);
    
    // Rotations per milliseconds
    float rot_ms = float(rotations2-rotations1) /  timeDelay;
    // Speed in cm/ms
    float speed = rot_ms*CIRCUMFERENCE;
    // Convert speed to m/s  | ms --> s = *1000 ; cm --> m = /100
    return 1000*speed/100;
}
float Encoder::getSpeed2(int count1, int count2, int timeDelay)
{
    // timeDelay between count1 and count2 in milliseconds
    
    // Rotations per milliseconds
    float rot_ms = float((count2-count1) / float(ENCODER_PULSE*GEAR_RATIO)) /  timeDelay;
    // Speed in cm/ms
    float speed = rot_ms*CIRCUMFERENCE;
    // Convert speed to m/s  | ms --> s = *1000 ; cm --> m = /100
    return 1000*speed/100;
}