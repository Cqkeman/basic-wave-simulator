#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include "waveform.h"
#include "node.h"

void display_waveform(waveNode *waveform, const int NUMBER_NODES);
void run_frame(waveNode *waveform, const int NUMBER_NODES, const int frame);

int main(void)
{
  const int NUMBER_NODES = 200;
  const int SIMULATION_FRAMES = 500;
  const int FRAME_DELAY = 1000 * 50; //1000 is put there to make the delay 500 milliseconds rather than microseconds
  
  waveNode waveform[NUMBER_NODES + 2]; // plus two makes one index at 0 for driverand
  waveNode *ptrWaveform = &waveform[0];   // and index NUMBER_NODES + 1 for an end node
  
  for(int i = 0; i<NUMBER_NODES+1; i++){
    waveform[i].position = 0;
    waveform[i].velocity = 0;
  }
  
  for(int frame = 0 ; frame < SIMULATION_FRAMES ; frame++){
    run_frame(ptrWaveform, NUMBER_NODES, frame);
    display_waveform( ptrWaveform, NUMBER_NODES);

    usleep(FRAME_DELAY);
  }

  return 0;

}


/*
 *
 * Basic implementation
 *
 * make an array of nodes
 *
 * for every frame
 *
 * loop over every node and calculate velocity of the node based on the difference in position to all of the nodes around it
 * loop over the nodes and calculate every nodes position relative to its previous position and its velocity
 *
 */
