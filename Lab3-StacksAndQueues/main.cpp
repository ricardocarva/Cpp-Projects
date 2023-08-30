#include <iostream>
#include "ABS.h"
#include "ABQ.h"
#include "leaker.h"
#include "SimpleTimer.h"

using std::cout;
using std::endl;

void Test_ABS();
void Test_ABQ();
void Test_ABS_Cases(float scale_factor, int N);
void Test_ABQ_Cases(float scale_factor, int N);


int main()
{
	Test_ABS();
	Test_ABQ();


	return 0;
}

void Test_ABS()
{
	int number_of_items[] = { 10000000, 30000000, 50000000, 75000000, 100000000 };
	float scale_factors[] = { 1.5, 2.0, 3.0, 10.0, 100.0 };
	unsigned int i;
	unsigned int j;

	// ABS Tests
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) 
		{
			Test_ABS_Cases(scale_factors[i], number_of_items[j]);
		}

	}

}
void Test_ABQ()
{
	//int number_of_items[] = { 10000, 30000, 50000, 75000, 100000 };
	//int number_of_items[] = { 300000, 300000, 5000000, 7000000, 15000000 };

	int number_of_items[] = { 10000000, 30000000, 50000000, 75000000, 100000000 };
	float scale_factors[] = { 1.5, 2.0, 3.0, 10.0, 100.0 };
	unsigned int i;
	unsigned int j;

	// ABQ Tests
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) 
		{
			Test_ABQ_Cases(scale_factors[i], number_of_items[j]);
		}
	}

}

void Test_ABS_Cases(float scale_factor, int N)
{	
	//cout << "********** Begin of Test **********" << endl;
	cout << endl;
	cout << "ABS," << scale_factor << "," << N << ",";

	ABS<int> intABS(2, scale_factor);
	{
		SimpleTimer timer("Test Pushing");
		for (int i = 0; i < N; i++)
			intABS.push(i);
	}	
	//cout << "Finished Pushing... Begining Popping..." << endl;
	unsigned int resizes_during_push = intABS.getTotalResizes();

	cout << resizes_during_push << ",";
	{
		SimpleTimer timer("Test Popping");
		for (int i = 0; i < N; i++)
			intABS.pop();
	}
	cout << intABS.getTotalResizes() - resizes_during_push << ",";
	//cout << "********** End of Test **********" << endl;
}

void Test_ABQ_Cases(float scale_factor, int N)
{
	//cout << "********** Begin of Test **********" << endl;
	cout << endl;

	cout << "ABQ," << scale_factor << "," << N << ",";
	ABQ<int> intABQ(2, scale_factor);
	{
		SimpleTimer timer("Test Enqueueing");
		for (int i = 0; i < N; i++)
			intABQ.enqueue(i);
	}
	unsigned int resizes_during_enqueue = intABQ.getTotalResizes();
	cout << resizes_during_enqueue << ",";

	{
		SimpleTimer timer("Test Enqueueing");
		for (int i = 0; i < N; i++)
			intABQ.dequeue();
	}
	cout << intABQ.getTotalResizes() - resizes_during_enqueue << ",";

	//cout << "********** End of Test **********" << endl;
}
