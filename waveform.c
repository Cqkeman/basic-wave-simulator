#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

#include "waveform.h"
#include "node.h"


void run_frame(waveNode *waveform, const int NUMBER_NODES, const int frame)
{
  driverNode(waveform, frame);

  for(int i = 1 ; i<=NUMBER_NODES ; i++){
    calcNodeVelocity((waveform + i));
  }

  for(int i = 1 ; i <= NUMBER_NODES ; i++){
    calcNodePos((waveform + i));
  }
}

void display_waveform(waveNode *waveform, const int NUMBER_NODES)
{
  const double DISPLAY_FACTOR = 100;
  
  system("clear");

  for(int i = 0; i<NUMBER_NODES; i++){
    double nodePos = (*(waveform +i)).position;
    double green_amount = 0;
    double red_amount = 0;

    if(nodePos >= 0)
      green_amount += (nodePos * DISPLAY_FACTOR);
    else {
      red_amount -= (nodePos * DISPLAY_FACTOR);
    }

    printf("\e[38;2;%i;%i;0m", (int)red_amount, (int)green_amount ); //sets colour
    printf("0");
  }
  printf("\n\x1b[0m");
}
