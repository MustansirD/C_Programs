#include<string.h>
#include"car.h"	

Car::Car(const char *name)
{
	strcpy(this->name,name);
	this->speed = 0.0;
	this->fuel = 0.0;
}

Car::~Car()
{
	//Nothing to do
}

void Car::Accelerate()
{
	this->speed = this->speed + 0.05;
	this->fuel = this->fuel - 1.0;
	if (this->fuel < 0.0)
	{
		this->fuel = 0.0;
	}
}

void Car::Brake()
{
	this->speed = this->speed - 0.07;
	if (this->speed < 0.0 )
	{
		this->speed = 0.0;
	}
	this->fuel = this->fuel - 2.0;
	if ( this->fuel < 0.0 )
	{
		this->fuel = 0.0;
	}
}	

