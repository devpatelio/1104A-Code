#include "globals.hpp"
#include "AutoPart.hpp"
extern int DrivingPositionTarget;
extern int AnglerTarget;
int DriveStraight();
bool isDriverSettled();
void disableDriverPID();
void setDriverPID(int target, int AngleTarget);
void waitUntilSettled(int positionError, int VelocityError);
void enableDriverPID ();
//declaration that noone cares about just go to cpp file
