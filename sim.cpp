#include <vector>
#include "sim.h"
#include "World.h"
#include "Virus.h"

sim::sim(){
	ClearGrid();
	PlaceHumans();
	char b;
	cout <<"Are you ready?"<<endl;
	cin >> b;
	day = 0;
	while(b == 'y'){
		cout<<"Year : "<<day<<endl;
		PrintGrid();
		
		cout <<"FRONT: "<<endl;
		humans.front().Attributes();
		cout<<"BACK: "<<endl;
		humans.back().Attributes();
		ClearGrid();
		AgeUpHumans();
		MoveHumans();
		

		if(humans.empty()){
			cout<<"The virus has taken over."<<endl;
			cout<<"Run."<<endl;
			exit(0);
		}
		day++;
		cout <<"Humans Alive: "<<humans.size()<<endl;
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
		if(checkBounds(humans[i].getX(), humans[i].getY()))
			grid[humans[i].getY()][humans[i].getX()] = 'H';
		for(int j = 0; j < 10; j++){
			if(grid[i][j]!= 'H')
				grid[i][j] == '*';
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

		humans[i].Move();		
		if(!checkBounds(humans[i].getX(), humans[i].getY()))
			humans.erase(humans.begin()+i);

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
	for(int j = 0; j < humans.size();j++)
		humans[j].AgeUp();
}
