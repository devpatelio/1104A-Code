#pragma once
#include "pros/main.h"
void move_drive(int r_wheels, int l_wheels);
void conveyor_move(int ct, int cb);
void intake_move(int intf, int intr);

extern pros::Controller main_controller;
pros::Motor motor_rf (9,    pros::E_MOTOR_GEARSET_06,   true,     pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor motor_rb (10,   pros::E_MOTOR_GEARSET_06,   true,     pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor motor_lf (19,   pros::E_MOTOR_GEARSET_06,   false,    pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor motor_lb (20,   pros::E_MOTOR_GEARSET_06,   false,    pros::E_MOTOR_ENCODER_COUNTS);

//Messy Conveyor Declaration
pros::Motor conveyor_b (8,  pros::E_MOTOR_GEARSET_06,   true,     pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor conveyor_t (15, pros::E_MOTOR_GEARSET_06,   true,     pros::E_MOTOR_ENCODER_COUNTS);

//Messy Conveyor Declaration
pros::Motor intake_l (17,   pros::E_MOTOR_GEARSET_06,   true,     pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake_r (7,    pros::E_MOTOR_GEARSET_06,   true,     pros::E_MOTOR_ENCODER_COUNTS);
