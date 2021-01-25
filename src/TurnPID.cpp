#include"TurnPID.hpp"
#include "pros/main.h"
#include "globals.hpp"
#pragma once
int TurningPositionTarget = 0;
int Turnerror = 0;
bool isTurnPIDrunning = true;
int deltaerror = 0;
int movemotor(){
  double kP = 1.0;
  double Ki = 0.5;
  double kD = 5.0;
  //how fast it will reach its target. Dont increase too much otherwise it will constantly go back and forth and waste time
  double deltaerror = 0;
  double previousPosition = motor_rf.get_position();
while(true){
  if (!isTurnPIDrunning){
 pros::delay(10);
 continue;
}
int currentPosition =  motor_rf.get_position();
double maxerror = Turnerror + deltaerror;
double integral = maxerror;
//intergal crap
int deltaPosition = currentPosition - previousPosition;
double derivative = deltaPosition;
//derivative crap
if(TurningPositionTarget>180){
TurningPositionTarget = TurningPositionTarget - 360;
}
else if (TurningPositionTarget < -180){
  TurningPositionTarget = TurningPositionTarget + 360;
}
Turnerror = TurningPositionTarget - currentPosition;
//power crap
double power = (kP* Turnerror) - (kD *derivative)- (integral *Ki);
move_drive(10*power,10*-power);
deltaerror = maxerror;
previousPosition = currentPosition;
pros::delay(10);
}
 }


bool isTurnSettled(int positionError, int velocityError){
return (abs(Turnerror)<positionError)&& (fabs(motor_rb.get_actual_velocity()) < velocityError);
}
void disableTurnPID(){
  isTurnPIDrunning = false;
}
void enableTurnPID(){
  isTurnPIDrunning = true;
}
void setTurnPID(int target){
  enableTurnPID();
  TurningPositionTarget=target;
}
void waitUntilSettled(int positionError, int velocityError){
  while(isTurnSettled(positionError,velocityError)= false){
    pros::delay(10);
//problem I don't understand
  }
disableTurnPID();
}
