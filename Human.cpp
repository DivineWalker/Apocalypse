
#include <cstdlib>
#include "Human.h"
Human::Human(){
	age = 0;
	married = false;
	health = 10;
	immunity = 0;
	gender = "Female";
	x = rand()%10;
	y = rand()%10;
}
Human::Human(int _immunity){ ;
	age = 0;
	married = false;
	randomizeGender();
	x = rand()%10;
	y = rand()%10;
	health = 10;
	immunity = _immunity;

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
	age+=10; //Age up
	switch(age/10){ //Add immunity
	case 0:
		immunity+=.10;
		break;
	case 1:
		immunity+=.10;
		break;
	case 2:
		immunity+=.20;
		break;
	default:
		immunity+=.10;
	}
	if(age>=65)
		health-=.5;
}

bool Human::CanHaveChildren(){
	if(age>=18 && !married)
		return true;
	else
		return false;
}
Human Human::operator+(Human& h1){
	married = true;
	h1.married = true;
	return Human(immunity+h1.getImmunity());
}
void Human::Attributes(){ //FOR TESTING PURPOSES
	cout<<"Age: "<<age<<endl;
	cout<<"Married: "<<married<<endl;
	cout<<"Health: "<<health<<endl;
	cout<<"Immunity: "<<immunity<<endl;
	cout<<"gender: "<<gender<<endl;
	cout<<"Position: "<<x<<", "<<y<<endl;

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
				x++;
				break;
			case 1: //Move Left
				x--;
				break;
			case 2: //Move Up
				y++;
				break;
			case 3: //Move Down
				y--;
				break;
			case 4: //Move Right, Up
				x++;
				y++;
				break;
			case 5: //Move Right, Down
				x++;
				y--;

				break;
			case 6: //Move Left, Up
				x++;
				y--;
				break;
			case 7: //Move left, Down
				x--;
				y--;
				break;
			default:
				break;

		}
}