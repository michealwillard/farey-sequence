#ifndef __fareySequence__
#define __fareySequence__

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct FAREYMEMBER {
	int a;
	int b;
};

int createSequence (vector<FAREYMEMBER> &sequence, int order);
int sampleRun(int order);

#endif
