#pragma once 

#include <iostream>
#include <math.h>

/*Start point of the line : P1 = x1*i + y1*j + z1*k or [x1, y2, z3]
  End point the line :P2 = x2*i + y2*j + z2*k or [x2, y2, z2]
  Point we calculate distance to P3 = x3*i + y3*j + z3*k or [x3, y3, z3]
	 */



/* Vector operations, vecSub, vecAdd, vecDot 
are implemented as overloaded opeartors in class Vector
vecCross, vecDist as member methods 
*/


class Vector{

	public:

		Vector(float x = 0, float y = 0, float z = 0);


		friend std::ostream & operator <<(std::ostream & o, const Vector & tP);
		//VecAdd
		Vector operator+(const Vector & toAdd)const;
		//VecSub
		Vector operator-(const Vector & toSub)const;
		//VecDot
		float operator*(const Vector & toMul)const;
		friend Vector & operator*(float t, Vector &toMul);
		// Vector & vecCross(const Vector & toCMul)const;
		// float vecDist(const Vector & toCMul)const;
		float vecLen()const ;
		inline float getX() {return m_x; }
		inline float getY() {return m_y; }
		inline float getZ() {return m_z; }

	private:
		//Corresponding coordinates of vector 
		float m_x, m_y, m_z;

};

	





