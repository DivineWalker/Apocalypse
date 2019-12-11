#include <iostream>

using namespace std;

class Virus{
  
  public: 
    
     Virus();
    int setX;
    void getVirus();
    void setX(int);
    int getY;
    void SetY(int);
  
  protected: 
  int x, y;
  void Position();  
    
};
