#include<stdio.h>
#include "car.h"

int main(int argc, char **argv)
{
	car_t car1;
	
	car_construct(&car1,"Maruti");
	car_refuel(&car1,100.0);
	printf("car is refueled to [%f]\n",car1.fuel);
	
	while( car1.fuel > 0 )
	{
		printf("car fuel level [%f]\n",car1.fuel);
		if(car1.speed < 80)
		{
			car_accelerate(&car1);
			printf("car has been accelerated to speed [%f]\n",car1.speed);
		}
		else
		{
			car_brake(&car1);
			printf("car has been slowed down to the speed [%f]\n",car1.speed);
		}
	}
	
	printf("car ran out of the fuel! Slowing down...\n");
	while(car1.speed > 0)
	{
		car_brake(&car1);
		printf("car has been slowed down to the speed [%f]\n",car1.speed);
	}
	
	car_destruct(&car1);
	
	return 0;
}