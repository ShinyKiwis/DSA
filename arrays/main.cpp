#include <cstdlib>
#include "iostream"
#include "nvector.h"
#include "nvector.cpp"
using namespace std;

int main (int argc, char *argv[])
{
  SK::NVector* newVector = new SK::NVector(10);
  newVector->push(12);
  newVector->push(13);
  newVector->push(14);
  newVector->push(15);
  newVector->insert(112, 0);
  newVector->insert(123, 3);
  newVector->insert(112399, 2);
  newVector->insert(11293, 0);
  newVector->push(16);
  newVector->push(1123);
  newVector->push(213);

  for(int i =0;i<newVector->getSize();i++){
    cout << newVector->at(i) << " ";
  }
  delete newVector;
  return 0;
}
