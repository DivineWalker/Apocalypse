#include "Virus.h"

Virus::Virus()
{
  //int x = 0;
  //int y = 0;
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


