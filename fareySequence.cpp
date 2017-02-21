//  Micheal Willard

//  Farey Sequence
//  For Test Cases:
//  if neighbors a/b < c/d, then c/d - a/b = 1/(b*d)

#include <iostream>
#include <vector>
#include <string>
#include "fareySequence.h"
using namespace std;

// struct FAREYMEMBER {
// 	int a;
// 	int b;
// };

int createSequence (vector<FAREYMEMBER> &sequence, int order) {
	if(order > 0) {
		int a = 0;
		int b = 1;
		int c = 1;
		int d = order;
		int n = order;
		int i = 0;
		int k = 0;
		int p = 0;
		int q = 0;
		sequence.push_back(FAREYMEMBER());
		sequence[i].a = a;
		sequence[i].b = b;
		i++;
		while(p <= order) {
			sequence.push_back(FAREYMEMBER());
			sequence[i].a = c;
			sequence[i].b = d;
			// next neighbor p/q
			// p = ((n+b)/d) * c-a
			// q = ((n+b)/d) * d-b
			k = ((n+b)/d);
			p = k*c-a;
			q = k*d-b;
			a = c;
			b = d;
			c = p;
			d = q;
			i++;
		}
		return 0;
	}
	else {
		cout << "Error:  Invalid order value";
		return -1;
	}
}

int sampleRun(int order) {
	order = 5;
	vector<FAREYMEMBER> newSequence;
	createSequence(newSequence, order);
	for (int i = 0; i < newSequence.size(); i++) {
		cout << newSequence[i].a;
		cout << "/";
		cout << newSequence[i].b << endl;
	}
	//delete [] newSequence;
	return 0;
}
