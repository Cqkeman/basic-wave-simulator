#ifndef WAVEFORM_H
#define WAVEFORM_H

#include "node.h"

struct waveNode;

void run_frame(waveNode *waveform, const int NUMBER_NODES, const int frame);
void display_waveform(waveNode *waveform, const int NUMBER_NODES);


#endif
