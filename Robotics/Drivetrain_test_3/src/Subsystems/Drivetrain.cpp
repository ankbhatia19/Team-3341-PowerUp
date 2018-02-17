#include "Drivetrain.h"
#include "../Commands/TankDrive.h"
#include "../RobotMap.h"


Drivetrain::Drivetrain() : Subsystem("Drivetrain"),
rightMotor(new CANTalon(RIGHT_MOTOR_PORT)), leftMotor(new CANTalon(LEFT_MOTOR_PORT))
{

}

Drivetrain::~Drivetrain()
{
	delete rightMotor;
	delete leftMotor;
}

double Drivetrain::Limit(double num, double max)
{

	if (num > max)
	{
		return max;
	}

	if (num < -max)
	{
		return -max;
	}
	return num;
}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::tankDrive(double leftVal, double rightVal)
{
	leftMotor->Set(Limit(leftVal, 1.0));
	rightMotor->Set(Limit(rightVal, 1.0));
}

void Drivetrain::reverseDir()
{
	leftMotor->SetInverted(!leftMotor->GetInverted());
	rightMotor->SetInverted(!rightMotor->GetInverted());
}