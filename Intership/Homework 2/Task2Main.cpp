#include <iostream>


#include "Task2.h"



/* Task 2. Function calculating distance from point to bouded line */
float PointToLineDistance(const Vector & P1, const Vector & P2, const Vector & P3){

	float t, t1 = 0.0, t2 = 1.0;
	Vector x;
	Vector a = P1;
	Vector b = P2 - P1;

	t = ( (P3 * b) - (a * b)) /  (b.vecLen() * b.vecLen());
	x = a + (t * b) - P3;

	if(t1 <= t && t <= t2) { return x.vecLen(); }
	else if (P3.vecDist(P1) >= P3.vecDist(P2)) {return P3.vecDist(P2); }
	else { return P3.vecDist(P1); }

}
	
	
int main(){
    std::cout << "\n*********************************\n\n";
	std::cout << "1-st case, t in range of line end points" << std::endl;
	
	//visualization in png files
	Vector P1(5, -4 , 6);
	Vector P2(4 , 4, 5);
	Vector P3(9, -1, 5);
	std::cout << "Distance of " << P3 << " to line segment " << P1 << "-" << P2 << " is " << PointToLineDistance(P1, P2, P3) << std::endl;
	

	std::cout << "\n*********************************\n\n";
	std::cout << "2-nd case, t out of line end points" << std::endl;


	P3(8, 7, 3);
	std::cout << "Distance of " << P3 << " to line segment " << P1 << "-" << P2 << " is " << PointToLineDistance(P1, P2, P3) << std::endl;

	std::cout << "\n*********************************\n\n";

	return 0;
}
