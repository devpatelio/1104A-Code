#include "pros/main.h"
#include "globals.hpp"
#include "globals.cpp"

void intake_conveyor(int ct_v, int cb_v, int int_vel){
    conveyor_move(ct_v, cb_v);
    intake_move(int_vel, -1*int_vel);
}

void delayed_cycle_shoot(int ct_v, int cb_v, int int_vel, int delay=1000){
    conveyor_t.move_velocity(ct_v);
    pros::delay(delay);
    conveyor_b.move_velocity(cb_v);
    intake_move(int_vel, -1*int_vel);
}

void driving_func()
{
    while (!(pros::competition::is_autonomous() || pros::competition::is_disabled()))
    {
        int power = main_controller.get_analog(ANALOG_LEFT_Y);
        int turn = main_controller.get_analog(ANALOG_RIGHT_X);
        int left = power + turn;
        int right = power - turn;
        move_drive(right, left);
        pros::delay(10);
    };
}

void control_func(){

    while (!(pros::competition::is_autonomous || pros::competition::is_disabled())){

        if (main_controller.get_digital(DIGITAL_R1))        // index
            intake_conveyor(600, 0, 0);
        else if (main_controller.get_digital(DIGITAL_R1))        // cycle
            delayed_cycle_shoot(600, 600, 600);
        else if (main_controller.get_digital(DIGITAL_L1))   // shoot
             delayed_cycle_shoot(600, 600, 0);
        else if (main_controller.get_digital(DIGITAL_L2))   // intake
             intake_conveyor(0, 0, 600);
        else if (main_controller.get_digital(DIGITAL_UP))   // eject
             intake_conveyor(-600, -600, -600);
        else if (main_controller.get_digital(DIGITAL_DOWN)) // convey down
             intake_conveyor(-600, -600, 0);
        else if (main_controller.get_digital(DIGITAL_LEFT)) // itk eject fast
             intake_conveyor(0, 0, -600);
        else if (main_controller.get_digital(DIGITAL_RIGHT))    // itk eject slow
             intake_conveyor(0, 0, -200);
        else
            intake_conveyor(0, 0, 0);

        pros::delay(10);
    }
};

void opcontrol(){
    pros::Task drive_task {driving_func};
    pros::Task control_task {control_func};

}
