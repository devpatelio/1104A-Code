#include "globals.hpp"
#include "AutoPart.hpp"
extern int TurningPositionTarget;
int movemotor();
bool isTurnSettled();
void disableTurnPID();
void setTurnPID(int target);
void waitUntilSettled(int positionError, int VelocityError);
void enableTurnPID ();
//declaration that noone cares about just go to cpp file
