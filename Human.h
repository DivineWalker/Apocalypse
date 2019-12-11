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
	
	string getGender();
	double getImmunity();
	Human operator+(Human&);
	bool operator==(Human&);
	//void PrintGrid();
	bool CanHaveChildren();
	void AgeUp();
	void Move();
	void setGender(string);

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
};