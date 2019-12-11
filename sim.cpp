#include <vector>
#include "sim.h"
#include "World.h"
//#include "Human.h"

sim::sim(){
	ClearGrid();
	PlaceHumans();
	cout <<"First Humans have been placed."<<endl;
	PrintGrid();
	ClearGrid();
	PrintGrid();
	int b = 1;
	
	while(b == 1){
		cin >> b;
		cout<<"The humans have moved."<<endl;
		MoveHumans();
		//UpdateGrid();
		PrintGrid();
		ClearGrid();
	}
	
	
}
void sim::PrintGrid(){
	cout<<" ---------------------------------------"<<endl;
	for(int i = 0; i < 10;i++){
		cout<<"|";
		for(int j = 0; j < 10; j++){
			cout<<"-";
			cout<<grid[i][j];
			cout<<"-|";
		}
		cout<<endl;
		cout<<" ---------------------------------------"<<endl;
	}
}
	
void sim::UpdateGrid(){
	for(int i = 0; i < humans.size();i++){
		grid[humans[i].getY()][humans[i].getX()] = 'H';

	}
}
void sim::initGrid(){

}
bool sim::checkBounds(int x, int y){
	if(x < 10 && x > 0)
		if(y < 10 && y > 0)
			return true; //may can do this in one line
}
void sim::firstHumans(){
	for(int i = 0; i < 10;i++){
		if(i <= 4)
			humans.push_back(Human());
		else if(i > 4){
			humans.push_back(Human());
			humans[i].setGender("Male");
		}
	}
}

void sim::PlaceHumans(){
	firstHumans();
	for(int i = 0; i < 10;i++){
		grid[humans[i].getY()][humans[i].getX()] = 'H';
	}
}
void sim::MoveHumans(){
	int _x, _y;
	Human currentHuman;
	for(int i = 0; i < humans.size();i++){
		currentHuman = humans[i];
		_x = humans[i].getX();
		_y = humans[i].getY();
		cout<<"Human at "<<_x<<", "<<_y<<" has moved ";
		switch(rand()%10){
			case 0: //Move Right
				cout<<"Right ";
				currentHuman.setX(_x++);
				break;
			case 1: //Move Left
				cout<<"Left ";
				currentHuman.setX(_x--);
				break;
			case 2: //Move Up
				cout<<"Up ";
				currentHuman.setY(_x++);
				break;
			case 3: //Move Down
				cout<<"Down ";
				currentHuman.setX(_y++);
				break;
			case 4: //Move Right, Up
				cout<<"Right and Up ";
				currentHuman.setX(++_x);
				currentHuman.setY(++_y);
				break;
			case 5: //Move Right, Down
				cout<<"Right and Down ";
				currentHuman.setX(++_x);
				currentHuman.setY(--_y);

				break;
			case 6: //Move Left, Up
				cout<<"Left and Up ";
				currentHuman.setX(--_x);
				currentHuman.setY(++_y);
				break;
			case 7: //Move left, Down
				cout<<"Left and Down ";
				currentHuman.setX(--_x);
				currentHuman.setY(--_y);
				break;
			default:
				cout <<"No Moves"<<endl;
				break;

		}
		cout<<"to "<<_x<<", "<<_y<<"."<<endl;

		

		for(int j = 0; j < humans.size();j++){
			if(currentHuman.getY() == humans[j].getY() 
				&& currentHuman.getX() == humans[j].getX())

				if(currentHuman.getGender() != humans[j].getGender() )
					SpawnHuman(currentHuman, humans[j]);
		}
	}
	UpdateGrid();
}
void sim::SpawnHuman(Human h1, Human h2){
	cout<<"HUMAN HAS BEEN SPAWNED"<<endl;
	humans.push_back(H1+h2);
	humans.back().Attributes();
}
void sim::ClearGrid(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			grid[i][j] = '*';
		}
	}
}
bool sim::operator+(Human h1){
	Human createHuman;
	if(h1.canHaveChildren())
	{
	   for(int i = 0; i < 10; i++)//loop through the grid
	   {
		for(int j = 0; j < 10; i++)
		{
		   if(grid[i][j] = "-")//if we find an empty spot, then place a human
		    {
			createHuman.PlaceHumans();
		   }
		}
	   }	   
	}
}
