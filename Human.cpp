/*Name: Divine Walker & Moriah Young
 *Date Completed: 12/14/2019 12:00pm
 *Description: Human object definitions. Contains functions to move the humans by one. It contains getters to get information and two overloaded operators to is with this object
 *Input Req: N/A. 
 *Output: N/A
 */
#include <cstdlib>
#include "Human.h"
Human::Human(){
	age = 0;
	married = false;
	health = 10;
	immunity = 1;
	gender = "Female";
	x = rand()%10;
	y = rand()%10;
	infected = false;
}
Human::Human(int _immunity){ //Second constructor for spanwed humans
	age = 0;
	married = false;
	randomizeGender();
	x = rand()%10;
	y = rand()%10;
	health = 10;
	immunity = _immunity;

}
void Human::Attacked(int val){
	if(immunity <= .25) //if the immunity of human decides whether it becomes infected or not
		infected = true;
	else
		immunity = val - immunity;
}

bool Human::isInfected(){
	return infected;
}
//Actions
void Human::randomizeGender(){
	if(rand()%10==0)
		gender = "Male";
	else
		gender = "Female";
}

//Getters
string Human::getGender(){
	return gender;
}
int Human::getHealth(){
	return health;
}
int Human::getX(){
	return x;
}
int Human::getY(){
	return y;
}
double Human::getImmunity(){
	return immunity;
}

//Setters
void Human::setGender(string gen){
	if(gen == "Female" || gen == "Male")
		gender = gen;
}


void Human::AgeUp(){
	age++; //Age up
	if(age>=65) //health starts decreasing down 
		health-=.5;
}

bool Human::CanHaveChildren(){
	if(age>=18 && !married && !infected)
		return true;
	else
		return false;
}
Human Human::operator+(Human& h1){
	married = true;
	h1.married = true;
	return Human(immunity+h1.getImmunity());
}

bool Human::operator==(Human& h1){ //Compatable to have another human
	if((x == h1.getX() && y == h1.getY())
		&&(gender != h1.getGender())
		&& CanHaveChildren() && h1.CanHaveChildren())
		return true;
	return false;
}
void Human::Move(){
		switch(rand()%10){
				case 0: //Move Right
					if(x < 9)
					x++;
					break;
				case 1: //Move Left
					if(x > 0)
					x--;
					break;
				case 2: //Move Up
					if(y < 9)
					y++;
					break;
				case 3: //Move Down
					if(y > 0)
					y--;
					break;
				case 4: //Move Right, Up
					if(x < 9 && y < 9){
						x++;
						y++;
					}
					break;
				case 5: //Move Right, Down
					if(x < 9 && y > 0){
						x++;
						y--;
					}
					break;
				case 6: //Move Left, Up
					if(x > 0 && y < 9)
					{
						x--;
						y++;
					}
					break;
				case 7: //Move left, Down
					if(x > 0 && y > 0){
						x--;
						y--;
					}
					break;
				case 8:
					if(x < 9 && y > 0){
						x++;
						y--;
					}
					break;
		}
}