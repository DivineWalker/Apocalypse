//#include "World.h"
#include <iostream>

using namespace std;

class Human{
public:
	Human();
	Human(int);
	//void Position();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	void Attributes();
	void setGender(string);
	string getGender();
	double getImmunity();
	void operator+(Human);
	//void PrintGrid();


protected:
	void initialPosition();
	bool CanHaveChildren();
	void randomizeGender();
	string gender;
	int x,y;

private:
	int age;
	bool married;
	//String gender;
	
	double health;
	double immunity;
};