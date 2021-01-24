#include"TurnPID.hpp"
#include "globals.hpp"
int TurningPositionTarget = 0;
int Turnerror = 0;
bool isTurnPIDrunning = true;
int movemotor(){
  double kP = 1.0;
  double Ki = 0.5;
  double kD = 5.0;
  double deltaerror = 0;
  double previousPosition =  motor_rf.rotation;
while (true){
  if (!isTurnPIDrunning){
 pros::delay(10);
  }
}
}
