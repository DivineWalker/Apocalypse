#include <iostream>

using namespace std;

class Virus{
  
  public: 
    
     Virus();
    int getX;
    void getVirus();
    void setX(int);
    int getY;
    void setY(int);
  
  protected: 
  int x, y;
  void Position();  
    
};
