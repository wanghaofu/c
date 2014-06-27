#include <iostream>


using namespace std;

std::vector<int> vecTest;
std::map<int,int> mapText;

const int nTestCount = 5000000;
vecTest.resize(nTestCount);

for(int i=0;i<nTestCount;i++)
{
    vecTest[i] = i;
    mapTest[i] =i;
}
DWORD dwTime1 =timeGetTime();
std::vector<int>::iterator iterVect = vecTest.begin();
for(;iterVec!=vecTest.end();iterVec++)
{
}

DWORD vectimeCost = timeGetTime() -dwTime1;
