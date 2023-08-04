#pragma once
#ifdef shipping_cost
#define shipping_cost
#endif // shipping_cost

#include <iostream>
#include <string>

#include <curl.h>
#include <document.h> 

using namespace std;

int cost(int Location) {
	if (Location == 1) {
		cout << "NA have a flat shipping cost of $30" << endl;
	}
	else if (Location == 2) {
		cout << "International cost is $100, plus cargo coverage fee.\nCoverage Fee is 15% of the total invoice" << endl;
	}
	return 0;
}
