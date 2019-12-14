/*Name: Divine Walker & Moriah Young
 *Date Completed: 12/14/2019 12:00pm
 *Description: Header file for the simulation
 *Input Req: N/A. 
 *Output: N/A
 */
#include "Human.h"
#include "World.h"
#include "Virus.h"

class sim{
public:
	sim(); //Simulation
	void PrintGrid(); //Print the grid layout with characters in it
	void UpdateGrid(); //Updates with H, V, ! 

	protected:
		int day; 
		char grid[10][10];
		vector<Human> humans; //healthy humans
		vector<Virus> virus; //virus objects
		vector<Human> infectedHumans; //infected humans
		void initGrid(); //initializes the grid
		bool checkBounds(int, int); //checks if position is within the grid
		void firstHumans(); //the first humans, 5 female, 5 male
		void MoveHumans(); //Moves the humans if the bounds are right and each is in their own place
		void PlaceHumans(); //Places the FIRST humans
		void SpawnHuman(Human, Human); //Spawn a new human
		void AgeUpHumans(); //Ages up the humans 
		void newVirus(); //Spawns a new virus every 10 years
		void Check(); //Check if anything is on another object
};