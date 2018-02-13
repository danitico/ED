/*! 
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/
#include <iostream>
#include <cmath>
#include <cassert>
#include "Vector3D.hpp"
// OBSERVADORES
double ed::Vector3D::angulo(ed::Vector3D v) const{
	return acos(dotProduct(v)/(modulo() * v.modulo()));
}
double ed::Vector3D::alfa() const{
	ed::Vector3D a(1,0,0);
	return angulo(a);
}
double ed::Vector3D::beta() const{
	ed::Vector3D a(0,1,0);
	return angulo(a);
}
double ed::Vector3D::gamma() const{
	ed::Vector3D a(0,0,1);
	return angulo(a);
}
double ed::Vector3D::dotProduct(ed::Vector3D v) const{
	return v1_*v.get1() + v2_*v.get2() + v3_*v.get3();
}
ed::Vector3D ed::Vector3D::crossProduct(ed::Vector3D v) const{
	double w1, w2, w3;
	
	w1=get2()*v.get3() - get3()*v.get2();
	w2=get3()*v.get1() - get1()*v.get3();
	w3=get1()*v.get2() - get2()*v.get1();
	
	ed::Vector3D w(w1,w2,w3);
	return w;
}	
double ed::Vector3D::productoMixto(ed::Vector3D v, ed::Vector3D w) const{
	return dotProduct(v.crossProduct(w));
}
////////////////////////////////////////////////////////////////

// MODIFICADORES
void ed::Vector3D::sumConst(double k){
	set1(get1() + k);
	set2(get2() + k);
	set3(get3() + k);
}
void ed::Vector3D::sumVect(Vector3D v){
	set1(get1() + v.get1());
	set2(get2() + v.get2());
	set3(get3() + v.get3());
}
void ed::Vector3D::multConst(double k){
	set1(get1() * k);
	set2(get2() * k);
	set3(get3() * k);
}
void ed::Vector3D::multVect(Vector3D v){
	set1(get1() * v.get1());
	set2(get2() * v.get2());
	set3(get3() * v.get3());
}
////////////////////////////////////////////////////////////////////////////////
// OPERADORES
bool ed::Vector3D::operator==(Vector3D const &objeto) const{
	if(get1()==objeto.get1() && get2()==objeto.get2() && get3()==objeto.get3()) return true;
	else return false;
}
ed::Vector3D& ed::Vector3D::operator=(Vector3D const &objeto){
	set1(objeto.get1());
	set2(objeto.get2());
	set3(objeto.get3());
	return *this;
}
ed::Vector3D& ed::Vector3D::operator+(Vector3D const &objeto) const{
	ed::Vector3D *res=new ed::Vector3D();
	res->set1(get1() + objeto.get1());
	res->set2(get2() + objeto.get2());
	res->set3(get3() + objeto.get3());
	return *res;
}
ed::Vector3D& ed::Vector3D::operator+() const{
	ed::Vector3D *res=new ed::Vector3D(*this);
	return *res;
}
ed::Vector3D& ed::Vector3D::operator-(Vector3D const &objeto) const{
	ed::Vector3D *res=new ed::Vector3D();
	res->set1(get1() - objeto.get1());
	res->set2(get2() - objeto.get2());
	res->set3(get3() - objeto.get3());
	return *res;
}
ed::Vector3D& ed::Vector3D::operator-() const{
	ed::Vector3D *res=new ed::Vector3D(*this);
	res->set1(-(res->get1()));
	res->set2(-(res->get2()));
	res->set3(-(res->get3()));
	return *res;
}
ed::Vector3D& ed::Vector3D::operator*(double k) const{
	ed::Vector3D *res=new ed::Vector3D();
	res->set1(get1() * k);
	res->set2(get2() * k);
	res->set3(get3() * k);
	return *res;
}
double ed::Vector3D::operator*(Vector3D const &objeto) const{
	return dotProduct(objeto);
}
ed::Vector3D& ed::Vector3D::operator^(Vector3D const &objeto) const{
	ed::Vector3D *res=new ed::Vector3D();
	*res=crossProduct(objeto);
	return *res;
}
////////////////////////////////////////////////////////////////////////////////

// FUNCIONES DE LECTURA Y ESCRITURA
void ed::Vector3D::escribirVector3D() const{
	std::cout<<*this;
}
void ed::Vector3D::leerVector3D(){
	std::cin>>*this;
}
// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{
	// Producto "por un" escalar (prefijo): k * v
	ed::Vector3D & operator* (double k, ed::Vector3D const & objeto){
		ed::Vector3D *vectorResultado = new ed::Vector3D();
		vectorResultado->set1(objeto.get1() * k);
		vectorResultado->set2(objeto.get2() * k);
		vectorResultado->set3(objeto.get3() * k);
		return *vectorResultado;
	}
	// Sobrecarga del operador de salida
	// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
	ostream &operator<<(ostream &stream, ed::Vector3D const &objeto){
		stream<<"("<<objeto.get1()<<", "<<objeto.get2()<<", "<<objeto.get3()<<")";
		return stream;
	}

	// Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Vector3D &objeto){
		double v1=0, v2=0, v3=0;
		stream>>v1>>v2>>v3;
		objeto.set1(v1); objeto.set2(v2); objeto.set3(v3);
		return stream;
	}
}
