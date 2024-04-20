#include "vex.h"

/*

FIRST

"Match"
"Skills"

SECOND

"Left"
"Center"
"Right"

THIRD

"Simple"
"Complex"
"Half Winpoint"
"Winpoint"
*/

void pre_auton(){
  Calibrate();

  ms.Assign("Match", "Left", "Winpoint", new auton{
    [](){
      Inertial7.calibrate();
      intake.setVelocity(100,percent);
      intake.spinFor(50,degrees);
      chassis.drive_with_voltage(-5,-11);
      wait (1.6,sec);
      RVwings.set(true);
      chassis.drive_with_voltage(3,6);
      wait (1.3,sec);
      RVwings.set(false);
      chassis.drive_with_voltage(0,0);
      wait (1.5, sec);
      chassis.drive_with_voltage(-5.5,5.5);
      wait (.657,sec);
      chassis.drive_with_voltage(0,0);
      wait (1.5, sec);
      chassis.drive_with_voltage(-10,-10);
      wait (.25001,sec);
      chassis.drive_with_voltage(-1,-1);
      wait (.3, msec);
      chassis.drive_with_voltage(0,0);
      wait (10, msec);
      intake.spinFor(-10050,degrees);
    },
      "Basic winpoint"
  });


  ms.Assign("Match", "Right", "Simple", new auton{
    [](){
      Inertial7.calibrate();
      intake.setVelocity(100,percent);
      intake.spinFor(45,degrees,false);
      RHwings.set(true);
      wait (1,sec);
      RHwings.set(false);
      intake.spinFor(4300,degrees,false);
      chassis.drive_with_voltage(10, 10);
      wait (.8,sec);
      chassis.drive_with_voltage(5, 10);
      wait (.4,sec);
      chassis.drive_with_voltage(4, -4);
      wait (1.2,sec);
      RHwings.set(true);
      LHwings.set(true);
      chassis.drive_with_voltage(8, 8);
      wait (0,sec);
      intake.spinFor(-1900,degrees);
      chassis.drive_with_voltage(-10, -10);
      wait (.001,sec);
    },
      "5 ball"
  });

  
  ms.SetTestAutonomous("Match", "Right", "Simple");
	while(ms.should_update && (Competition.isFieldControl() || Competition.isCompetitionSwitch())){
		ms.Update();
		wait(20, msec);
	}
}