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

// COMPLETAR



////////////////////////////////////////////////////////////////////////////////

// OPERADORES

// COMPLETAR



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

		// COMPLETAR

		return *vectorResultado;
	}
	// Sobrecarga del operador de salida
	// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
	ostream &operator<<(ostream &stream, ed::Vector3D const &objeto){
		stream<<"("<<objeto.get1()<<", "<<objeto.get2()<<", "<<objeto.get3()<<")\n";
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
