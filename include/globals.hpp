#pragma once
#include "pros/main.h"

void move_drive(int r_wheels, int l_wheels);
void conveyor_move(int ct, int cb);
void intake_move(int intf, int intr);

extern pros::Controller main_controller;