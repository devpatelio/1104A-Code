#include"TurnPID.hpp"
#include "pros/main.h"
#include "globals.hpp"
#pragma once
int TurningPositionTarget = 0;
int AnglerTarget = 0;
int Turnerror = 0;
bool isTurnPIDrunning = true;
int deltaerror = 0;
 void DriveStraight(){
  //modify below to increase or decrease the speed that the robot goes when reaching the target
  double kP = 1.0;
  double Ki = 0.5;
  double kD = 5.0;

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
//integral crap
int deltaPosition = currentPosition - previousPosition;
double derivative = deltaPosition;
//derivative crap
Turnerror = TurningPositionTarget - currentPosition;
int UnevenError= motor_rf.get_position() - motor_lf.get_position();
int AbsoluteUnevenError = AnglerTarget-UnevenError;
//angle target thing crap
double power = (kP* Turnerror) - (kD *derivative)- (integral *Ki);
move_drive((10*power) + AbsoluteUnevenError ,(10*power)+AbsoluteUnevenError);
// multiplied by the power and add/subtracted absolute Unevenerror so it says on course and does its thing
deltaerror = maxerror;
previousPosition = currentPosition;
//pain
pros::delay(10);
}
 }


 bool isDriverSettled(int positionError, int velocityError){
return (abs(Turnerror)<positionError)&& (fabs(motor_rb.get_actual_velocity()) < velocityError);
}
void disableDriverPID(){
  isTurnPIDrunning = false;
}
void enableDriverPID(){
  isTurnPIDrunning = true;
}
void setDriverPID(int target, int AngleTarget){
  enableDriverPID();
  TurningPositionTarget=target;
  AnglerTarget = AngleTarget;
  //use this function to activate the PID in autonomous
}
void waitUntilSettled(int positionError, int velocityError){
  while(!isDriverSettled(positionError,velocityError)== false){
    pros::delay(10);
//current problem

  }
disableTurnPID();
}
