/*Name: Divine Walker & Moriah Young
 *Date Completed: 12/14/2019 12:00pm
 *Description: Simulation. Includes functions to ease simulation progress. The program places 10 humans and one virus on a 10x10 grid and moves the humans around until they are 18 or when they are infected.
 *When they become 18, they are able to spawn children. When they iare infected, they are able to infect others. The virus is able to infect other humans.
 *Input Req: y/n
 *Output: Apocolypse simulation
 */
#include <vector>
#include "sim.h"
#include "World.h"

sim::sim(){//actual sim
	initGrid(); //initiailzie grid
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
		cout <<"Humans Contaminated: "<<infectedHumans.size()<<endl;

		PrintGrid();
		initGrid();
		AgeUpHumans();
		MoveHumans();
		
		if(humans.empty()){ //if the vector is empty, there are no more healthy humans.
			cout<<"The virus has taken over."<<endl;
			cout<<"Run."<<endl;
			exit(0);
		}
		else
			cout <<"You've survived another day."<<endl;
		
		day++;
		cout <<"Would you like to continue? (y/n)"<<endl;
		cin >> b;
	}
	
	
}
void sim::PrintGrid(){//function that prints out the grid
	cout<<" ---------------------------------------"<<endl;
	for(int i = 0; i < 10;i++){
		cout<<"|";
		for(int j = 0; j < 10; j++){
			cout<<" ";
			cout<<grid[i][j];
			cout<<" |";
		}
		cout<<endl;
		cout<<" ---------------------------------------"<<endl;
	} //
}
	
void sim::UpdateGrid(){ //Updates grid with new symbols as they move
	Check();
	for(int i = 0; i < humans.size();i++){
		if(checkBounds(humans[i].getX(), humans[i].getY())){
			grid[humans[i].getY()][humans[i].getX()] = 'H';
		}
	}
	for(int i = 0; i < infectedHumans.size();i++){
		if(checkBounds(infectedHumans[i].getX(), infectedHumans[i].getY())){
			grid[infectedHumans[i].getY()][infectedHumans[i].getX()] = '!';
		}
	}
	for(int i = 0; i < virus.size();i++){
		if(checkBounds(virus[i].getX(), virus[i].getY())){
			grid[virus[i].getY()][virus[i].getX()] = 'V';
		}
	}

}
void sim::initGrid(){//initializes the grid
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			grid[i][j] = ' ';
		}
	}
}
bool sim::checkBounds(int x, int y){ //check th ebounds
	return x < 10 && x > 0 && y < 10 && y > 0;
}
void sim::firstHumans(){ //Initializes the first 10 humans, 5 female, 5 male
	for(int i = 0; i < 10;i++){
		if(i <= 4)
			humans.push_back(Human());
		else if(i > 4){
			humans.push_back(Human());
			humans[i].setGender("Male");
		}
	}
}

void sim::PlaceHumans(){//only places the first humans
	firstHumans();
	for(int i = 0; i < 10;i++){
		grid[humans[i].getY()][humans[i].getX()] = 'H';
	}
}
void sim::MoveHumans(){ //Moves the humans about
	for(int i = 0; i < humans.size();i++){
		humans[i].Move();
		Check();
		if(humans[i].isInfected()){
			cout << "Infected Human found"<<endl;
			infectedHumans.push_back(humans[i]);
			humans.erase(humans.begin()+i);
		}
	}
	UpdateGrid();
}
void sim::SpawnHuman(Human h1, Human h2){//Takes the immunity from both parents and adds it for the child
	Human h3 = h1+h2;
	humans.push_back(h3);
}
void sim::AgeUpHumans(){ //+1 year, if theyre 65+, they start dying of old age.
	for(int j = 0; j < humans.size();j++){
		humans[j].AgeUp();
		if(humans[j].getHealth() <= 0){
			humans.erase(humans.begin()+j);
			cout<<"A Human has died of old age."<<endl;
		}
	}
}
void sim::newVirus(){ //A new virus should be spawned every 10 years
	virus.push_back(Virus());
	for(int i = 0; i < virus.size();i++){
		while(grid[virus[i].getY()][virus[i].getX()] == 'H' || grid[virus[i].getY()][virus[i].getX()] == '!'){
			//cout <<"Randomizing"<<endl;
			virus[i].Move();
		}
		UpdateGrid();
	}
}
void sim::Check(){ //Checks if any humans come into contact with anything.
	for(int i = 0; i < humans.size();i++){ //main
		for(int j = 0; j < humans.size();j++){ //compare to other humans
			if(i != j){
				if(humans[i] == humans[j])
					SpawnHuman(humans[i], humans[j]);
				while(humans[i].getX() == humans[j].getX() && humans[i].getY() == humans[j].getY()){
					humans[i].Move(); //move if you can't spawn a baby
				}
			}
		}
		for(int j = 0; j < infectedHumans.size();j++){ //compare to infected humans
			if(i < infectedHumans.size())
				if(humans[i].getX() == infectedHumans[j].getX() && humans[i].getY() == infectedHumans[j].getY()) 
					humans[i].Attacked(rand()%2); //Attack
		}

		for(int j = 0; j < virus.size();j++){ //compare to virus
			if(i < virus.size())
				if(humans[i].getX() == virus[j].getX() && humans[i].getY() == virus[j].getY()) 
					humans[i].Attacked(rand()%2); //Attack
		}
	}
}