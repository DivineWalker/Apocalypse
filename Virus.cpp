#include "Virus.h"

Virus::Virus()
{
   x = rand()%10;
   y = rand()%10;
}

Virus::Position()
{
  x = rand()% 10;
  y = rand()% 10;
}

int Virus::getX()
{
  return x;
}

int Virus::getY()
{
  return y;
}

void Virus::setX(int X_){
  if(X_ > 0 && X_ < 10)
  {
    x = X_;
}
  
 void Virus::setY(int Y_){
  if(Y_ > 0 && Y_ < 10)
  {
    Y = Y_;
}


