#include <iostream>


#include "Task2.h"

/*Parametrization of the line
	l(t) = a + t*b 
	where are :
	a = P1, b = P2 - P1
	or, eguivalent to 
	a = x1*i + y1*j + z1*k
	b = (x2 - x1)*i + (y2 - y1)*j + (z2 - z1)*k
	there could be seperate class for a Line but task says that 
	only few operations are avaiable then I feel like class Vector is 
	to much already  
	*/


	/*x = a + t*b - P3; - x is vector perpendicular to direction vector b of the line 
	If line is infinite then shortest distane from point to a line will be always line
	perpendicular to the line we calculating distance to, we can represent such line as vector 
	with end point of crossover and point we caulculated distance to, x is such vector,
	to find appropriate point of crossover we use definition of dotProduct, hence x * b should equal 0, 
	now we only need to find t, using previous informations we get     
	t = ((P3 * b) - (a * b) / vecLen(b) * vecLen(b)), desired distance is length of vector x */	  

	/* implementation */

float PointToLineDistance_1(const Vector & P1, const Vector & P2, const Vector & P3){
	

	float t;
	Vector x;
	Vector a = P1;
	Vector b = P2 - P1;
	// l(t) = a + t*b 
	Vector c = P2 + P1;
	float dotProduct = P1 * P2;
	std::cout << "b length " << b.vecLen() << std::endl;
	t = ( (P3 * b) - (a * b)) /  (b.vecLen() * b.vecLen());

	std::cout << "t = " << t << std::endl;

	x = a + (t * b) - P3;

	std::cout << "Copying contructor test " << a;
	std::cout << "Substraction test " << b;
	std::cout << "Addition test " << c;
	std::cout << "DotProduct test " << dotProduct << std::endl;
	std::cout << "Length test " << a.vecLen() << std::endl;

	return x.vecLen();


}
	
	
int main(){

	

	Vector P1(1, 3 ,2);
	Vector P2(-5, 0,4);
	Vector P3(1, 1, 1);

	std::cout << "Distance is " << PointToLineDistance_1(P1, P2, P3) << std::endl;

	// PointToLineDistance_1(P1, P2, P3);


	return 0;
}