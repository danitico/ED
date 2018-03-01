/*! 
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/
#include <iostream>
#include <cmath>
#include <cassert>
#include "Vector3D.hpp"
// OBSERVADORES
double ed::Vector3D::modulo() const{
	double valor=sqrt(get1()*get1() + get2()*get2() + get3()*get3());
	#ifndef NDEBUG
	assert(abs(valor-sqrt(get1()*get1() + get2()*get2() + get3()*get3()))<COTA_ERROR);
	#endif
	return valor;
}
double ed::Vector3D::angulo(ed::Vector3D v) const{
	#ifndef NDEBUG
	assert((modulo()*v.modulo())>0);
	#endif
	double valor=acos(dotProduct(v)/(modulo() * v.modulo()));
	#ifndef NDEBUG
	assert(abs(valor - acos(dotProduct(v)/(modulo() * v.modulo())))<COTA_ERROR);
	#endif
	return valor;
}
double ed::Vector3D::alfa() const{
	#ifndef NDEBUG
	assert(modulo()>0);
	#endif
	ed::Vector3D a(1,0,0);
	double res=angulo(a);
	#ifndef NDEBUG
	assert(abs(res - angulo(a))<COTA_ERROR);
	#endif
	return res;
}
double ed::Vector3D::beta() const{
	#ifndef NDEBUG
	assert(modulo()>0);
	#endif
	ed::Vector3D a(0,1,0);
	double res=angulo(a);
	#ifndef NDEBUG
	assert(abs(res - angulo(a))<COTA_ERROR);
	#endif
	return res;
}
double ed::Vector3D::gamma() const{
	#ifndef NDEBUG
	assert(modulo()>0);
	#endif
	ed::Vector3D a(0,0,1);
	double res=angulo(a);
	#ifndef NDEBUG
	assert(abs(res - angulo(a))<COTA_ERROR);
	#endif
	return res;
}
double ed::Vector3D::dotProduct(ed::Vector3D v) const{
	double res=get1()*v.get1() + get2()*v.get2() + get3()*v.get3();
	#ifndef NDEBUG
	assert(abs(res - (get1()*v.get1() + get2()*v.get2() + get3()*v.get3()))<COTA_ERROR);
	#endif
	return res;
}
ed::Vector3D ed::Vector3D::crossProduct(ed::Vector3D v) const{
	#ifndef NDEBUG
	assert(angulo(v)>0.0 && modulo()>0.0 && v.modulo()>0.0);
	#endif	
	double w1, w2, w3;
	
	w1=get2()*v.get3() - get3()*v.get2();
	w2=get3()*v.get1() - get1()*v.get3();
	w3=get1()*v.get2() - get2()*v.get1();
	
	ed::Vector3D w(w1,w2,w3);
	#ifndef NDEBUG
	assert(dotProduct(w)<COTA_ERROR && v.dotProduct(w)<COTA_ERROR && (abs(w.modulo() - modulo()*v.modulo()*sin(angulo(v)))<COTA_ERROR));
	#endif
	return w;
}	
double ed::Vector3D::productoMixto(ed::Vector3D v, ed::Vector3D w) const{
	#ifndef NDEBUG
	assert(v.angulo(w) > 0.0);
	#endif
	double res=dotProduct(v.crossProduct(w));
	#ifndef NDEBUG
	assert(abs(res - dotProduct(v.crossProduct(w)))<COTA_ERROR);
	#endif
	return res;
}
////////////////////////////////////////////////////////////////

// MODIFICADORES
void ed::Vector3D::vectorUnitario(){
	ed::Vector3D aux(*this);
	#ifndef NDEBUG
	assert(modulo() > 0);
	#endif
	double m=modulo();	
	
	set1(get1() / m);
	set2(get2() / m);
	set3(get3() / m);
	#ifndef NDEBUG
	assert(abs(get1() - aux.get1()/m)<COTA_ERROR && abs(get2() - aux.get2()/m)<COTA_ERROR && abs(get3() - aux.get3()/m)<COTA_ERROR);
	#endif
}
void ed::Vector3D::sumConst(double k){
	ed::Vector3D aux(*this);
	set1(get1() + k);
	set2(get2() + k);
	set3(get3() + k);
	#ifndef NDEBUG
	assert(abs(get1() - (aux.get1() + k))<COTA_ERROR && abs(get2() - (aux.get2() + k))<COTA_ERROR && abs(get3() - (aux.get3() + k))<COTA_ERROR);
	#endif
}
void ed::Vector3D::sumVect(Vector3D v){
	ed::Vector3D aux(*this);	
	set1(get1() + v.get1());
	set2(get2() + v.get2());
	set3(get3() + v.get3());
	#ifndef NDEBUG
	assert(abs(get1() - (aux.get1() + v.get1()))<COTA_ERROR && abs(get2() - (aux.get2() + v.get2()))<COTA_ERROR && abs(get3() - (aux.get3() + v.get3()))<COTA_ERROR);
	#endif
}
void ed::Vector3D::multConst(double k){
	ed::Vector3D aux(*this);
	set1(get1() * k);
	set2(get2() * k);
	set3(get3() * k);
	#ifndef NDEBUG
	assert(abs(get1() - (aux.get1() * k))<COTA_ERROR && abs(get2() - (aux.get2() * k))<COTA_ERROR && abs(get3() - (aux.get3() * k))<COTA_ERROR);
	#endif
}
void ed::Vector3D::multVect(Vector3D v){
	ed::Vector3D aux(*this);
	set1(get1() * v.get1());
	set2(get2() * v.get2());
	set3(get3() * v.get3());
	#ifndef NDEBUG
	assert(abs(get1() - (aux.get1() * v.get1()))<COTA_ERROR && abs(get2() - (aux.get2() * v.get2()))<COTA_ERROR && abs(get3() - (aux.get3() * v.get3()))<COTA_ERROR);
	#endif
}
////////////////////////////////////////////////////////////////////////////////
// OPERADORES
bool ed::Vector3D::operator==(Vector3D const &objeto) const{
	bool res;	
	if(get1()==objeto.get1() && get2()==objeto.get2() && get3()==objeto.get3()){res=true;}
	else{res=false;}
	#ifndef NDEBUG
	assert(res==(abs(get1()-objeto.get1())<COTA_ERROR && abs(get2()-objeto.get2())<COTA_ERROR && abs(get3()-objeto.get3())<COTA_ERROR));
	#endif
	return res;
}
ed::Vector3D& ed::Vector3D::operator=(Vector3D const &objeto){
	set1(objeto.get1());
	set2(objeto.get2());
	set3(objeto.get3());
	#ifndef NDEBUG
	assert(abs(get1()-objeto.get1())<COTA_ERROR && abs(get2()-objeto.get2())<COTA_ERROR && abs(get3()-objeto.get3())<COTA_ERROR);
	#endif
	return *this;
}
ed::Vector3D& ed::Vector3D::operator+(Vector3D const &objeto) const{
	ed::Vector3D *res=new ed::Vector3D();
	res->set1(get1() + objeto.get1());
	res->set2(get2() + objeto.get2());
	res->set3(get3() + objeto.get3());
	#ifndef NDEBUG
	assert(abs(res->get1()-(get1() + objeto.get1()))<COTA_ERROR && abs(res->get2()-(get2() + objeto.get2()))<COTA_ERROR && abs(res->get3()-(get3() + objeto.get3()))<COTA_ERROR);
	#endif
	return *res;
}
ed::Vector3D& ed::Vector3D::operator+() const{
	ed::Vector3D *res=new ed::Vector3D(*this);
	#ifndef NDEBUG
	assert(abs(res->get1()-get1())<COTA_ERROR && abs(res->get2()-get2())<COTA_ERROR && abs(res->get3()-get3())<COTA_ERROR);
	#endif
	return *res;
}
ed::Vector3D& ed::Vector3D::operator-(Vector3D const &objeto) const{
	ed::Vector3D *res=new ed::Vector3D();
	res->set1(get1() - objeto.get1());
	res->set2(get2() - objeto.get2());
	res->set3(get3() - objeto.get3());
	#ifndef NDEBUG
	assert(abs(res->get1()-(get1() - objeto.get1()))<COTA_ERROR && abs(res->get2()-(get2() - objeto.get2()))<COTA_ERROR && abs(res->get3()-(get3() - objeto.get3()))<COTA_ERROR);
	#endif	
	return *res;
}
ed::Vector3D& ed::Vector3D::operator-() const{
	ed::Vector3D *res=new ed::Vector3D(*this);
	res->set1(-(res->get1()));
	res->set2(-(res->get2()));
	res->set3(-(res->get3()));
	#ifndef NDEBUG
	assert(abs(res->get1()+get1())<COTA_ERROR && abs(res->get2()+get2())<COTA_ERROR && abs(res->get3()+get3())<COTA_ERROR);
	#endif	
	return *res;
}
ed::Vector3D& ed::Vector3D::operator*(double k) const{
	ed::Vector3D *res=new ed::Vector3D();
	res->set1(get1() * k);
	res->set2(get2() * k);
	res->set3(get3() * k);
	#ifndef NDEBUG
	assert(abs(res->get1()-(get1()*k))<COTA_ERROR && abs(res->get2()-(get2()*k))<COTA_ERROR && abs(res->get3()-(get3()*k))<COTA_ERROR);
	#endif
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
	std::cout<<"("<<get1()<<", "<<get2()<<", "<<get3()<<")";
}
void ed::Vector3D::leerVector3D(){
	double v1=0, v2=0, v3=0;	
	std::cout<<"Primer elemento = ";
	std::cin>>v1;
	set1(v1);
	std::cout<<"Segundo elemento = ";
	std::cin>>v2;
	set2(v2);
	std::cout<<"Tercer elemento = ";
	std::cin>>v3;
	set3(v3);
}
// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{
	// Producto "por un" escalar (prefijo): k * v
	ed::Vector3D & operator* (double k, ed::Vector3D const & objeto){
		ed::Vector3D *res = new ed::Vector3D();
		res->set1(objeto.get1() * k);
		res->set2(objeto.get2() * k);
		res->set3(objeto.get3() * k);
		#ifndef NDEBUG
		assert(abs(res->get1()-(objeto.get1()*k))<COTA_ERROR && abs(res->get2()-(objeto.get2()*k))<COTA_ERROR && abs(res->get3()-(objeto.get3()*k))<COTA_ERROR);
		#endif

		return *res;
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
