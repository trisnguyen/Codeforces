/* ---------------------------------------------------------------------------
** This software is under the MIT license (MIT)
**
** 328A_IQTest.cpp
** Problem: http://codeforces.com/problemset/problem/328/A
**
** Author: Tristan Nguyen
** Email: trismnguyen@gmail.com
** -------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;


const int SEQUENCE_SIZE = 4;
const int DEFAULT_RESULT = 42;
int iSequence[SEQUENCE_SIZE];

/* Check if the vector's element is Arithmetically Progressive, and
- If yes, push the next element into the vector, and return true
- If no, return false
Params: a reference to a vector that contains SEQUENCE_SIZE element
*/
bool isArithmeticProgression(vector<int>* vec) 
{
  if (vec->size() != SEQUENCE_SIZE) return false;

  int i = 0, d = 0;
  for (auto it = vec->begin() + 1; it != vec->end(); ++it)
  {
    if (++i == 1) //first occurence
    {
      d = *it - *(vec->begin());
    }
    else
    {
      if (*it - *(vec->begin()) != d * i)
        return false;
    }
  }

  int nextValue = *(vec->begin()) + d * ++i;
  vec->push_back(nextValue);
  return true;
}

/* Check if the vector's element is Geometrically Progressive, and
- If yes, push the next element into the vector, and return true
- If no, return false
Params: a reference to a vector that contains SEQUENCE_SIZE element
*/
bool isGeometricProgression(vector<int>* vec)
{
  if (vec->size() != SEQUENCE_SIZE) return false;

  int b = *vec->begin();
  //Tristan: Using float instead of double will cause precision loss, and thus incorrect check of nextValue down below
  double q = *(vec->begin() + 1) / (double)*vec->begin();

  int i = 2;  //start at the 3rd element
  for (auto it = vec->begin() + 2; it != vec->end(); ++it, ++i)
  {
    if (*it != (int)(b * pow(q, i)))
      return false;
  }

  double nextValue = b * pow(q, i);
  if (nextValue != (int) nextValue) // not a whole number
    return false;
  vec->push_back(nextValue);
  return true;
}

void IQTest()
{
  vector<int> vSequence(iSequence, iSequence + SEQUENCE_SIZE);

  if (!isArithmeticProgression(&vSequence))
  {
    if (!isGeometricProgression(&vSequence))
      vSequence.push_back(DEFAULT_RESULT);
  }
  cout << vSequence.back() << endl;
}

int main_328A()
{
  for (int i = 0; i < SEQUENCE_SIZE; ++i)
  cin >> iSequence[i];
  IQTest();
  return 0;
}