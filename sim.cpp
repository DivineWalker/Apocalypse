#include <vector>
#include "sim.h"
#include "World.h"

sim::sim(){
	ClearGrid();
	PlaceHumans();
	char b;
	cout<<"There are "<<humans.size()<<" healthy Humans and One Deadly Virus."<<endl;
	cout <<"Are you ready?"<<endl;
	cin >> b;
	day = 0;
	while(b == 'y'){
		cout<<"Year : "<<day<<endl;
		cout <<"Humans Alive: "<<humans.size()<<endl;
		if( day%10 = 0)
			newVirus();
		PrintGrid();
		ClearGrid();
		AgeUpHumans();
		MoveHumans();
		

		if(humans.empty()){
			cout<<"The virus has taken over."<<endl;
			cout<<"Run."<<endl;
			exit(0);
		}
		day+=10;
		
		cout <<"Humans Contaminated: "<<endl;
		cout <<"Would you like to continue? (y/n)"<<endl;
		cin >> b;
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
	//ClearGrid();
	for(int i = 0; i < humans.size();i++){
		if(checkBounds(humans[i].getX(), humans[i].getY())){
			if(humans[i].isInfected){
				grid[humans[i].getY()][humans[i].getX()] = '!';
			}
			grid[humans[i].getY()][humans[i].getX()] = 'H';
		}

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
	for(int i = 0; i < humans.size();i++){
		if(checkBounds(humans[i].getX(), humans[i].getY()))
			humans[i].Move();
		for(int j = 0; j < humans.size();j++){
			if(j != i)
				if(humans[i] == humans[j])
					SpawnHuman(humans[i], humans[j]);
		}
	}
	UpdateGrid();
}
void sim::SpawnHuman(Human h1, Human h2){
	cout<<"HUMAN HAS BEEN SPAWNED"<<endl;
	Human h3 = h1+h2;
	humans.push_back(h3);
	humans.back().Attributes();
}
void sim::ClearGrid(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			grid[i][j] = '*';
		}
	}
}
void sim::AgeUpHumans(){
	for(int j = 0; j < humans.size();j++){
		humans[j].AgeUp();
		if(humans[j].getHealth() <= 0)
			humans.erase(humans.begin()+j);
	}
}