/*! 
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/


// Ficheros de cabecera
#include <iostream>

// Para usar sqrt, acos
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include "Vector3D.hpp"

// OBSERVADORES
double ed::angulo(Vector3D v) const{
	return dotProduct(v)/(modulo() * v.modulo());
}
double ed::alfa() const{
	Vector3D a(1,0,0);
	return angulo(a);
}
double ed::beta() const{
	Vector3D a(0,1,0);
	return angulo(a);
}
double ed::gamma() const{
	Vector3D a(0,0,1);
	return angulo(a);
}
double ed::dotProduct(Vector3D v) const{
	return v1_*v.get1() + v2_*v.get2() + v3_*v.get3();
}
Vector3D ed::crossProduct(Vector3D v) const{
	double w1, w2, w3;
	
	w1=v2_*v.get3() - v3_*v.get2();
	w2=v3_*v.get1() - v1_*v.get3();
	w3=v1_*v.get2() - v2_*v.get1();
	
	Vector3D w(w1,w2,w3);
	return w;
}	
double ed::productoMixto(Vector3D v, Vector3D w) const{
	return dotProduct(crossProduct(v, w));
}
////////////////////////////////////////////////////////////////

// MODIFICADORES

// COMPLETAR



////////////////////////////////////////////////////////////////////////////////

// OPERADORES

// COMPLETAR



////////////////////////////////////////////////////////////////////////////////

// FUNCIONES DE LECTURA Y ESCRITURA

// COMPLETAR


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{


// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();

	// COMPLETAR

	return *vectorResultado;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{
	// COMPLETAR

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
  // COMPLETAR

  return stream;
} 

} // Fin del espacio de nombres ed
