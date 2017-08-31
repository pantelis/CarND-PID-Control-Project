#ifndef PID_H
#define PID_H

#include <vector>
#include <uWS/uWS.h>

using namespace std;

class PID {
public:
    /*
    * Errors
    */
    double p_error;
    double i_error;
    double d_error;

    /*
    * Coefficients
    */
    double Kp;
    double Ki;
    double Kd;

    int tuning_period;

    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();

    // Twiddle algorithm
    void Twiddle(double cte, double tolerance, vector<double> dp);

    double EvaluateError(double cte, int tuning_period);

    void Restart(uWS::WebSocket<uWS::SERVER> ws);
};

#endif /* PID_H */
