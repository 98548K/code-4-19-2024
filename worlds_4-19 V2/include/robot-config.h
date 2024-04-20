using namespace vex;

extern brain Brain;

// VEXcode devices
extern competition Competition;
extern controller Controller1;
extern motor intake;
extern motor poncher;
extern inertial Inertial7;
extern digital_out elevation;
extern digital_out LHwings;
extern digital_out RHwings;
extern digital_out RVwings;
extern digital_out LVwings;

extern motor LF;
extern motor LM;
extern motor LB;
extern motor RF;
extern motor RM;
extern motor RB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );