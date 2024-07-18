#ifndef NODE_H
#define NODE_H

typedef struct{
  double velocity;
  double position;
} waveNode;

void calcNodeVelocity(waveNode *node);
void calcNodePos(waveNode *node);
void driverNode(waveNode *driver, int frame);

#endif // !DEBUo
