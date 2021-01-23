#include "globals.hpp"

//Messy Chassis Declaration
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

pros::Controller main_controller (CONTROLLER_MASTER);


void move_drive(int r_wheels, int l_wheels)
{
    motor_rf.move_velocity(r_wheels);
    motor_rb.move_velocity(r_wheels);
    motor_lf.move_velocity(l_wheels);
    motor_lb.move_velocity(l_wheels);
}

void conveyor_move(int ct, int cb){
    conveyor_t.move_velocity(ct);
    conveyor_b.move_velocity(cb);
}

void intake_move(int intl, int intr){
    intake_l.move_velocity(intl);
    intake_r.move_velocity(intr);
}


