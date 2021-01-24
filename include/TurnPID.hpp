#include "globals.hpp"
extern int TurningPositionTarget;
int movemotor();
bool isTurnSettled;
void disableTurnPID();
void setTurnPID(int target);
void waitUntilSettled(int positionError, int VelocityError);
void enableDrivePID ();
