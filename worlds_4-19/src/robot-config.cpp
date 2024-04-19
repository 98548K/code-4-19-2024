#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor intake = motor(PORT12, ratio6_1, false);
motor poncher = motor(PORT2, ratio18_1, false);

motor LF = motor(PORT20, ratio18_1, true);
motor LM = motor(PORT8, ratio18_1, true);
motor LB = motor(PORT3, ratio18_1, true);
motor RF = motor(PORT11, ratio18_1, false);
motor RM = motor(PORT13, ratio18_1, false);
motor RB = motor(PORT1, ratio18_1, false);

inertial Inertial7 = inertial(PORT19);
digital_out elevation = digital_out(Brain.ThreeWirePort.A);
digital_out LHwings = digital_out(Brain.ThreeWirePort.B);
digital_out RHwings = digital_out(Brain.ThreeWirePort.H);
digital_out LVwings = digital_out(Brain.ThreeWirePort.C);
digital_out RVwings = digital_out(Brain.ThreeWirePort.G);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1XBButtonsControlMotorsStopped = true;
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonX/ButtonB status to control intake
      if (Controller1.ButtonL2.pressing()) {
        intake.spin(forward);
        Controller1XBButtonsControlMotorsStopped = false;
      } else if (Controller1.ButtonL1.pressing()) {
        intake.spin(reverse);
        Controller1XBButtonsControlMotorsStopped = false;
      } else if (!Controller1XBButtonsControlMotorsStopped) {
        intake.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1XBButtonsControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}