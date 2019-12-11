
#include <cstdlib>
//#include "World.h"
#include "Human.h"
Human::Human(){
	age = 0;
	married = false;
	health = 10;
	immunity = 0;
	gender = "Female";
	initialPosition();
}
Human::Human(int _immunity){ ;
	age = 0;
	married = false;
	randomizeGender();
	initialPosition();
	health = 10;
	immunity = _immunity;

}

//Position of Human
void Human::initialPosition(){ //Initial Position
	x = rand()%10;
	y = rand()%10;
}
void Human::setGender(string gen){
	if(gen == "Female" || gen == "Male")
		gender = gen;
}
void Human::randomizeGender(){
	if(rand()%10==0)
		gender = "Male";
	else
		gender = "Female";
}
string Human::getGender(){
	return gender;
}

int Human::getX(){
	return x;
}
int Human::getY(){
	return y;
}
void Human::setX(int _x){
	if(_x >0 && _x < 10){
		x = _x;
	}
}
void Human::setY(int _y){
	if(_y >0 && _y < 10){
		y = _y;
	}
}
double Human::getImmunity(){
	return immunity;
}
bool Human::CanHaveChildren(){
	if(age>=18 && !married)
		return true;
	else
		return false;
}
Human Human::operator+(Human h1){
	if(CanHaveChildren() && h1.CanHaveChildren
		&& gender != h1.getGender())
		return Human(immunity+h1.getImmunity());
}
void Human::Attributes(){
	cout<<"Age: "<<age<<endl;
	cout<<"Married: "<<married<<endl;
	cout<<"Health: "<<health<<endl;
	cout<<"Immunity: "<<immunity<<endl;
	cout<<"gender: "<<gender<<endl;
	cout<<"Position: "<<x<<", "<<y<<endl;

}
