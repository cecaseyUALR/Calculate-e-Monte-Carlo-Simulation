#include <iostream>
#include <math.h>
#include <stdlib.h>
#define numdarts 30000
using namespace std;


int main()
{
	double left, right, midpoint, x, y, prcentDarts, area;
	long count = 0;
	left = 2;
	right = 4;
	while (right - left >= 0.00001) {
		midpoint = (double)left + ((right - left) / 2);
		
		for (int i = 0; i < numdarts; i++)
		{
			x = (double)rand() / RAND_MAX * (midpoint - 1) + 1;
			y = (double)rand() / RAND_MAX;
			
			if (y <= (1 / x)) { // if dart falls under curve
				count++;
			}
		}
		prcentDarts = (double)count / numdarts;
		area = (double)prcentDarts * (midpoint - 1);
		// area = where darts hit between midpoint -1 and midpoint
		if (area < 1) {
			left = (double)midpoint;
		}
		else if (area > 1) {
			right = (double)midpoint;
		}
		count = 0;
	}
	cout << "The value of e is: " << midpoint << endl;
	system("pause");
	return 0;
}