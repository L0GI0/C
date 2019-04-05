#pragma once 

#include <iostream>
#include <math.h>

/*  * Basic denotions :
	    Starting point of the line : P1 = x1*i + y1*j + z1*k or [x1, y2, z3]
	    End point the line : P2 = x2*i + y2*j + z2*k or [x2, y2, z2]
	    Point we calculate distance to :  P3 = x3*i + y3*j + z3*k or [x3, y3, z3]
		Parametrization of a line : l(t) = a + t*b 
		where:
		a = P1, b = P2 - P1
		eguivalent to : 
		a = x1*i + y1*j + z1*k
		b = (x2 - x1)*i + (y2 - y1)*j + (z2 - z1)*k
		x = a + t*b - P3; - x is vector perpendicular to direction vector b of the line	
		// t -  parameter of point of crossover with perpendicular line with P3 as starting point 
		// t1 - parameter value for point determining beggining of the line  
		// t2 - parameter value for point determining end of the line
	* Comments : 	
		There could be seperate class for a Line, but task says that, 
		only few operations are avaiable, then I feel like class Vector is 
		already to much  
		
  	* Technique :
		If line is infinite, then shortest distane from point to a line will be always line
		perpendicular to the line we calculating distance to, we can represent such line as vector 
		with end point of crossover and point we caulculated distance to, x is such vector,
		to find appropriate point of crossover, we use definition of dotProduct, hence x * b should equal 0, 
		now we only need to find parameter t, by using previous informations, we get     
		t = ((P3 * b) - (a * b) / vecLen(b) * vecLen(b)), desired distance is length of vector x
		if t is not in range [0:1], point of crossover is out of (bounded 3D line), then
		shorted distance will be distance between point we calculate distance to and one of the points determining
		boundary of the line, depending on which is closer .	  

	 * Implementation : 
	 	Vector operations, vecSub, vecAdd, vecDot 
   		are implemented as overloaded opeartors in class Vector
   		vecDist and vecLen as member methods 
   		vecCross - i didn't need Cross product in my approach, there is method using area of parallelogram  
   		calculated by Cross product in order to find distance, but I hope my implementation is enough, if not I can 
   		make it if nessecary.
   		
*/
class Vector{

	public:

		Vector(float x = 0, float y = 0, float z = 0);

		//VecAdd
		Vector operator+(const Vector & toAdd)const;

		//VecSub
		Vector operator-(const Vector & toSub)const;

		//VecDot
		float operator*(const Vector & toMul)const;

		//vecDist
		float vecDist(const Vector & toC)const;

		//vecLen
		float vecLen()const;

		//Changes coordinates
		void operator()(float x, float y, float z);

		//Multiplies every coordinate by paramater t 
		friend Vector & operator*(float t, Vector &toMul);

		//Prints vector 
		friend std::ostream & operator <<(std::ostream & o, const Vector & tP);

	private:

		//Corresponding coordinates of vector 
		float m_x, m_y, m_z;
};

	





