#include <cstdlib>
#include "Virus.h"

Virus::Virus()
{
   x = rand()%10;
   y = rand()%10;
}

int Virus::getX()
{
  return x;
}

int Virus::getY()
{
  return y;
}

void Virus::setX(int _X){
  if(_X> 0 && _X < 10)
  {
    x = _X;
    }
}
  
 void Virus::setY(int _Y){
  if(_Y > 0 && _Y < 10)
  {
    y = _Y;
    }
}
void Virus::Move(){
  x = rand()%10;
  y = rand()%10;
}