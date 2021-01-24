#include "globals.hpp"

//Messy Chassis Declaration


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
