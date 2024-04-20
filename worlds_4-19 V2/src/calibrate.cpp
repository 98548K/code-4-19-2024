#include "vex.h"

void Calibrate(){
  vexcodeInit();
  intake.setVelocity(100,pct);
  chassis.drive_with_voltage(100, 100);
  default_constants();
  chassis.DriveR.spin(fwd);
  chassis.DriveL.spin(fwd);
  chassis.DriveR.setVelocity(0, pct);
  chassis.DriveL.setVelocity(0, pct);
  Inertial7.calibrate();
}