#include <vector>
#include "sim.h"
#include "World.h"

sim::sim(){
	ClearGrid();
	PlaceHumans();
	char b;
	cout<<"There are "<<humans.size()<<" healthy Humans and One Deadly Virus."<<endl;
	cout <<"Are you ready? (y/n)"<<endl;
	cin >> b;
	day = 0;
	while(b == 'y'){
		cout<<"Year : "<<day<<endl;
		cout <<"Humans Alive: "<<humans.size()<<endl;
		if(day%10 == 0){
			newVirus();
		}
		cout << "PRINT"<<endl;
		PrintGrid();
		cout << "CLEAR"<<endl;
		ClearGrid();
		cout << "Age"<<endl;
		AgeUpHumans();
		cout << "MOVE"<<endl;
		MoveHumans();
		

		if(humans.empty()){
			cout<<"The virus has taken over."<<endl;
			cout<<"Run."<<endl;
			exit(0);
		}
		day++;
		
		cout <<"Humans Contaminated: "<<infectedHumans.size()<<endl;
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
			if(humans[i].isInfected()){
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
		cout <<"MOVING"<<endl;
		humans[i].Move();
		Check();
		cout << "CHECKED"<<endl;
		if(humans[i].isInfected())
			infectedHumans.push_back(humans[i]);
	}
	UpdateGrid();
}
void sim::SpawnHuman(Human h1, Human h2){
	cout<<"HUMAN HAS BEEN SPAWNED"<<endl;
	Human h3 = h1+h2;
	humans.push_back(h3);
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
		if(humans[j].getHealth() <= 0){
			humans.erase(humans.begin()+j);
			cout<<"A Human has died of old age."<<endl;
		}
	}
}
void sim::newVirus(){
	virus.push_back(Virus());
	for(int i = 0; i < virus.size();i++){
		while(grid[virus[i].getY()][virus[i].getX()] == 'H' || grid[virus[i].getY()][virus[i].getX()] == '!'){
			cout <<"Randomizing"<<endl;
			virus[i].Move();
		}
		grid[virus[i].getY()][virus[i].getX()] = 'V';
	}
}

void sim::Check(){
	cout << "WE HIT A CHECK"<<endl;
	for(int i = 0; i < humans.size();i++){
		for(int j = 0; j < humans.size();j++){
			if(humans[i] == humans[j])
				SpawnHuman(humans[i], humans[j]);
			else if(humans[i].getX() == humans[j].getX() && humans[i].getY() == humans[j].getY()){
				humans[i].Move();
				j = 0;;
			}
		}
		for(int j = 0; j < virus.size();j++){
			if(humans[i].getX() == virus[j].getX() && humans[i].getY() == virus[j].getY()) 
				humans[i].Attacked(rand()%2);
		}
	}
}