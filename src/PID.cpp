#include <iostream>
#include "PID.h"
#include <math.h>

using namespace std;


PID::PID() {
    Kp = 0.0;
    Ki = 0.0;
    Kd = 0.0;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;

}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

    this -> Kp = Kp;
    this -> Ki = Ki;
    this -> Kd = Kd;

}

void PID::UpdateError(double cte) {

    i_error += cte;
    d_error = cte - p_error;
    p_error = cte;
}

double PID::TotalError() {

    double steer = -Kp * p_error - Ki * i_error - Kd * d_error;

    // 40deg max steering angle assumed
    double max_steering_angle_rad = (M_PI * 40.0)/180.;

    if(steer > max_steering_angle_rad){
        steer = max_steering_angle_rad;
    }
    else if(steer < -max_steering_angle_rad){
        steer = -max_steering_angle_rad;
    }
    return steer;
}
