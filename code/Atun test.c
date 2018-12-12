#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  BL,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           Fr,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           Fl,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Bl,            tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port6,           Lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Fork,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           Br,            tmotorVex393_MC29, openLoop, reversed)
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
void stopMotors(){
	motor[Fr] = 0;
	motor[Fl] = 0;
	motor[Br] = 0;
	motor[Bl] = 0;
}
void resetEnc(){
	resetMotorEncoder(Bl);
}
void drive(int Fri,int Fli,int Bri,int Bli,int distance){
	while(abs(getMotorEncoder(Bl))<distance){
		motor[Fr] = Fri;
		motor[Fl] = Fli;
		motor[Br] = Bri;
		motor[Bl] = Bli;
	}
	stopMotors();
	resetEnc();
}
void breakk(int time,int dir){
	motor[Fr] = 0;
	motor[Fl] = 0;
	motor[Br] = 0;
	motor[Bl] = 0;
}

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
	stopMotors();
	resetEnc();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	resetEnc();
	drive(127,127,127,127,2200);
	drive(-127,-127,-127,-127,2700);
	
	drive(127,-127,127,-127,1250);
	drive(127,127,127,127,1200);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		// This is the main execution loop for the user control program.
		// Each time through the loop your program should update motor + servo
		// values based on feedback from the joysticks.

		// ........................................................................
		// Insert user code here. This is where you use the joystick values to
		// update your motors, etc.
		// ........................................................................

		// Remove this function call once you have "real" code.
		UserControlCodePlaceholderForTesting();
	}
}
