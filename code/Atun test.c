#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in2,    Lf,             sensorLineFollower)
#pragma config(Sensor, dgtl1,  Button,         sensorTouch)
#pragma config(Motor,  port2,           Fr,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           Fl,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Ball,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Fork,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           Br,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Bl,            tmotorVex393_MC29, openLoop)
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
void resetGyro(){
	SensorType[in3] = sensorNone;
	wait1Msec(1000);
	SensorType[in3] = sensorGyro;
	wait1Msec(2000);
}
//Finction to turn whith gyro
void gyroTurn(int r,int l,int input){
	int deg = input*100;
	while(SensorValue[in1] < deg){
		motor[Fr] = r;
		motor[Fl] = l;
		motor[Br] = r;
		motor[Bl] = l;
	}
	stopMotors();
}
//function to move until button is pressed
void buttMove(int r,int l,int inc){
	int count = 0;
	while(inc != count){
		if(SensorValue[Button] == 1){
			count++;
		}
		motor[Fr] = r;
		motor[Br] = r;
		motor[Fl] = l;
		motor[Bl] = l;
	}
	stopMotors();
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
	resetGyro();
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
resetGyro();
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

	}
}
