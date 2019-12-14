#include <iostream>

using namespace std;

class Human{
public:
	Human();
	Human(int);
	//void Position();
	int getX();
	int getY();
	void Attributes(); //FOR TESTING PURPOSES
	int getHealth();
	string getGender();
	double getImmunity();
	Human operator+(Human&);
	bool operator==(Human&);
	bool CanHaveChildren();
	void AgeUp();
	void Move();
	void setGender(string);
	void Attacked(int);
	bool isInfected();
protected:
	void initialPosition();
	void randomizeGender();
	

private:
	int age;
	bool married;
	string gender;
	int x;
	int y;
	double health;
	double immunity;
	bool infected;
};