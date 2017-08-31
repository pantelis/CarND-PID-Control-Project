# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Manual Tuning of PID Steering and Throttle Parameters

The PID controller has three independent means of control. The description below was based on Wikipedia. 

**Proportional**
The obvious method is proportional control where the control variable (steering angle) is set in proportion to the existing  cross track error (CTE). The gain associated with this control is $K_p$. However, this control alone will fail when the car is traveling at high speeds as the oscilations around the setpoint are becoming significant. This is evident in the following experiment: the car successfully goes through the track at very low speeds with Kp=1.0 and with no other control applied. 

**Integral**
An integral term increases steering angle in relation not only to the CTE but also the time for which it has persisted. The gain associated with this control is $K_i$. A pure "I" controller could bring the error to zero, however, it would be both slow reacting at the start (because steering action would be small at the beginning, needing time to get significant), brutal (the steering action increases as long as the error is positive, even if the error has started to approach zero), and slow to end (when the error switches sides, this for some time will only reduce the strength of the steering action from "I", not make it switch sides as well), prompting overshoot and oscillations. Moreover, it could even move the system out of zero error: remembering that the system had been in error, it could prompt a steering action when not needed. Due to lack of any observable steering drift and the aggressive nature of the track, the manually tuned Ki was set to a very small number. 

**Derivative**
A derivative term does not consider the CTE (meaning it cannot bring it to zero: a pure D controller cannot bring the system to its set point), but the rate of change of CTE, trying to bring this rate to zero. It aims at flattening the CTE trajectory into a horizontal line, dampening the steering angle applied, and so reduces overshoot (error on the other side because too great applied steering). 

For the manual tuning we started with a P only controller and as the oscilations became dominant in the first turn, we started increaseding the Kd gain until they were dumped down. The Ki term as stated above was set to very low value. The optimal set was found to be (Kp, Ki, kd) = (0.19, 0.00001, 3.0). We also implemented the following enhancements: another PID controller to control throttle and therefore keep velocity at a constant (currently around 20 mph) and we also limited the max steering angle to a reasonable value of 40deg. 

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

