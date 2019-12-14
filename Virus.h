
#include <iostream>

using namespace std;

class Virus{
  
  public: 
    
     Virus();
    int getX();
    void Move();
    void setX(int);
    int getY();
    void setY(int);
  
  protected: 
  int x, y;
   
    
};