#include "Human.h"
#include "World.h"

class sim{
public:
	sim();
	void PrintGrid();
	void UpdateGrid();

	protected:
		int day; 
		char grid[10][10];
		vector<Human> humans;
		void initGrid();
		bool checkBounds(int, int);
		void firstHumans();
		void MoveHumans();
		void PlaceHumans();
		void SpawnHuman(Human, Human);
		void ClearGrid();
};