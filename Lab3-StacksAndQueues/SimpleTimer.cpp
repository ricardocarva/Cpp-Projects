#include "SimpleTimer.h"
#include <iostream>
using std::cout;
using std::endl;

SimpleTimer::SimpleTimer(const char *msg) {
	message = msg;
	start = highResClock::now(); 
}

SimpleTimer::~SimpleTimer() {
	end = highResClock::now();
	elapsed = end - start;
	//cout << elapsed.count() << ",";
	//cout << "Elapsed time: " << elapsed.count() << endl;
	cout << elapsed.count() << ",";

}