#include "Task2.h"



Vector::Vector(float x, float y , float z):m_x(x), m_y(y), m_z(z){}



Vector Vector::operator-(const Vector & toSub)const{
	Vector tmp;
	tmp.m_x = this->m_x - toSub.m_x;
	tmp.m_y = this->m_y - toSub.m_y;
	tmp.m_z = this->m_z - toSub.m_z;
	return tmp;
}

Vector Vector::operator+(const Vector & toAdd)const{
	Vector tmp;
	tmp.m_x = this->m_x + toAdd.m_x;
	tmp.m_y = this->m_y + toAdd.m_y;
	tmp.m_z = this->m_z + toAdd.m_z;
	return tmp;
}


float Vector::operator*(const Vector & toMul)const{
	return (float) (this->m_x * toMul.m_x) + (this->m_y * toMul.m_y) + (this->m_z * toMul.m_z);
}


 Vector & operator*(float t, Vector &toMul){
	toMul.m_x *= t;
	toMul.m_y *= t;
	toMul.m_z *= t;
	return toMul;
}



// Vector & Vector::vecCross(const Vector & toCMul)const{

// }

// float Vector::vecDist(const Vector & toCMul)const{

// }
		


float Vector::vecLen()const{
	return sqrt((this-> m_x * this-> m_x) + (this-> m_y * this-> m_y) + (this-> m_z * this-> m_z));
}


std::ostream & operator <<(std::ostream & o, const Vector & tP){
	return o << "[" << tP.m_x << ", " << tP.m_y << ", " << tP.m_z << "]" << std::endl; 
}
