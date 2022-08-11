#include<iostream>
#include"car.h"

int main(int argc,char **argv)
{
	Car car1("maruti");
	car1.refuel(100.0);
	std::cout<<"car is refuelled, the correct fuel level is"<<car1.fuel<<std::endl;
	while(car1.fuel > 0 )
	{
		std::cout<<"car fuel level:"<<car1.fuel<<std::endl;
		if(car1.speed < 80)
		{
			car1.Accelerate();
			std::cout<<"car has been accelerated to the speed:"<<car1.speed<<std::endl;
		}
		else
		{
			car1.Brake();
			std::cout<<"car has been slowed down to the speed:"<<car1.speed<<std::endl;
		}
	}
	
	std::cout<<"car ran out of fuel! slowing down..."<<std::endl;
	while(car1.speed > 0)
	{
		car1.Brake();
		std::cout<<"Car has been slowed down to the speed:"<<car1.speed<<std::endl;
	}
	
	std::cout<<"car is stopped!"<<std::endl;
	
	return 0;
}
