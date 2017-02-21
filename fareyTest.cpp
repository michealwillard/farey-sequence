//  Farey Test Units
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "fareySequence.h"

void asserttrue (int bln, char* msg);

int main() {
	//  Randomize the order of the Farey sequence
	int order = rand() % 16 + 1;
	vector<FAREYMEMBER> newSequence;
	createSequence(newSequence, order);
	cout << "TESTING THE ORDER OF: " << order << endl;

	// TEST #1:  if neighbors a/b < c/d, then c/d - a/b = 1/(b*d)


	//  TEST #2:  Middle Sequence Member = 1/2 (if order > 1)
	if (order > 1) {
		int middle = newSequence.size()/2;
		asserttrue((newSequence[middle].a == 1)&&(newSequence[middle].b == 2), "TEST #2");
	}

	//  TEST #3:  All denominators are less than or equal to n
	int test3Flag = 0;
	int j = 0;
	while(j < newSequence.size() && test3Flag != -1) {
		if(newSequence[j].b <= order) {
			j++;
		}
		else {
			test3Flag = -1;
			cout << "TEST 3 FAILED at position: " << j << endl;
		}
	}
	if(test3Flag == 0) {
		cout << "TEST #3: PASS" << endl;
	}

	//  TEST #4:  Verify each next neighbor is greater?
	double x, y = 0;
	int test4Flag = 0;
	int m = 0;
	while(j < newSequence.size() - 1 && test4Flag != -1) {
		x = ((double)newSequence[m].a/(double)newSequence[m].b);
		y = ((double)newSequence[m+1].a/(double)newSequence[m+1].b);
		//asserttrue((x < y), "TEST #4");
		if(x < y) {
			m++;
		}
		else {
			test4Flag = -1;
			cout << "TEST 4: FAILED at position: " << m << endl;
		}
	}
	if(test3Flag == 0) {
		cout << "TEST #4: PASS" << endl;
	}
	//delete [] newSequence;
	return 0;
}
void asserttrue (int bln, char* msg) {
  if (bln) {
    printf("%s: PASS\n", msg);
  }
  else {
    printf("%s: FAIL\n", msg);
  }
}
