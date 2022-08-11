#include<stdlib.h>

#include "engine.h"

typedef struct
{
	struct engine_t *engine;
}car_t;

car_t* car_new()
{
	return (car_t *)malloc(sizeof(car_t));
}

void car_ctor(car_t* car)
{
	
}