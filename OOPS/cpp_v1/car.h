#ifndef CAR_H
#define CAR_H

class Car
{
	public:
	Car(const char *);
	~Car();
	
	void Accelerate();
	void Brake();
	void Refuel(double);
	
	char name[32];
	double speed;
	double fuel;
	
};

#endif