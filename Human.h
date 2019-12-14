/*Name: Divine Walker & Moriah Young
 *Date Completed: 12/14/2019 12:00pm
 *Description: Header file for the Human object
 *Input Req: N/A. 
 *Output: N/A
 */
#include <iostream>

using namespace std;

class Human{
public:
	Human();
	Human(int);
	int getX();
	int getY();
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