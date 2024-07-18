#include <math.h>
#include <stdio.h>

#include "node.h"

void calcNodeVelocity(waveNode *node)
{
  const double SCALING_FACTOR = 1;
  double positionDifference = 0;
  
  positionDifference += (*(node)).position - (*(node-1)).position;
  positionDifference += (*(node)).position - (*(node+1)).position;
  
  (*(node)).velocity -= positionDifference * SCALING_FACTOR;
}

void calcNodePos(waveNode *node)
{
  (*(node)).position += (*(node)).velocity;
}

void driverNode(waveNode *driver,int frame)
{
  const double FREQUENCY = 0.1; //this value is just a frequency multiple
  (*driver).position = sin(FREQUENCY * frame);
}
