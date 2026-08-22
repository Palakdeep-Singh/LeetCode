#include <iostream>

using namespace std;

int main()
{

  int p = 10;

  // we casted to double but the value is integer which is 4 bytes now compiler
  // will allocate 8 bytes , hence these 8 bytes doesn't represent an integer.
  double *ptr = (double *)&p;

  cout << ptr << endl;
  cout << *ptr << endl;

  // void* means compiler doesn't know the type of the value stored.
  // pointer is an integer which holds the address.
  // and we specify the type like int*, double* to acces the data or do manipulations.

  void *pt = &p;

  // produces error because the type is not complete what we can do is static_cast<int> to an another type.
  // dereferencing -> caste to another type -> point that particular type memory address.
  // cout << *pt << endl;

  int *casted = static_cast<int *>(pt);
  cout << *casted << endl;

  return 0;
}