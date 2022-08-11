#include<stdio.h>
#include<stdlib.h>

#include "car.h"

int main(int argc, char **argv)
{
	struct car_t *car = car_new();//Allocate memory for car object
	
	car_ctor(car);//Construct car object
	
	printf("Engine temp before staring the car [%f]\n",car_get_engine_temperature(car));
	car_start(car);
	printf("Engine temp after starting the car [%f]\n",car_get_engine_temperature(car));
	car_stop(car);
	printf("Engine temp after stopping the car [%f]\n",car_get_engine_temperature(car));
	car_dtor(car);
	free(car);//free the memory for the car object
	return 0;
	
}