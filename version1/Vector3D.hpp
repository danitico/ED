/*! 
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/
#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_
#include <iostream>
#include <cmath>
#include <cassert>
using std::istream;
using std::ostream;
#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales
namespace ed{
//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$ 
	class Vector3D{
	  //! \name Atributos privados de la clase Vector3D
		private: 
			double v1_, v2_, v3_;	
		//! \name Funciones o métodos públicos de la clase Vector3D
		public:
		//! \name Constructores de la clase Vector3D
			Vector3D(){
				v1_=0; v2_=0; v3_=0;
			}
			Vector3D(double v1, double v2, double v3){
				v1_=v1; v2_=v2; v3_=v3;
			}
			Vector3D(const Vector3D &v){
				v1_=v.get1(); v2_=v.get2(); v3_=v.get3();
			}
		//! \name Observadores: funciones de consulta de Vector3D
			inline double get1() const{return v1_;}
			inline double get2() const{return v2_;}
			inline double get3() const{return v3_;}
			inline double modulo() const{return sqrt(v1_*v1_ + v2_*v2_ + v3_*v3_);}
			double angulo(Vector3D v) const;
			double alfa() const;
			double beta() const;
			double gamma() const;
			double dotProduct(Vector3D v) const;
			Vector3D crossProduct(Vector3D v) const;
			double productoMixto(Vector3D v, Vector3D w) const;
		//! \name Modificadores: funciones de modificación de Vector3D
			inline void set1(double v1){v1_=v1;}
			inline void set2(double v2){v2_=v2;}
			inline void set3(double v3){v3_=v3;}
			void sumConst(double k);
			void sumVect(Vector3D v);
			void multConst(double k);
			void multVect(Vector3D v);
		//! \name Operadores de la clase
		//hace falta doxygen en todas las funciones
		Vector3D &operator=(Vector3D const &objeto);//ok
		bool operator==(Vector3D const &objeto) const;//ok
		Vector3D& operator+(Vector3D const &objeto)  const;//ok
		Vector3D& operator+() const;//ok
		Vector3D& operator-(Vector3D const &objeto) const;//ok
		Vector3D& operator-() const;//ok
		Vector3D& operator*(double k) const;//ok
		double operator*(Vector3D const &objeto) const;//ok
		Vector3D& operator^(Vector3D const &objeto) const;
		//! \name Funciones lectura y escritura de la clase Vector3D
			void leerVector3D();
			void escribirVector3D() const;
	}; // Fin de la definición de la clase Vector3D



//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	// COMPLETAR COMENTARIOS DE DOXYGEN
   Vector3D & operator* (double k, Vector3D const & objeto);//ok

	// COMPLETAR COMENTARIOS DE DOXYGEN
	istream &operator>>(istream &stream, Vector3D &objeto);//ok

	// COMPLETAR COMENTARIOS DE DOXYGEN    
	ostream &operator<<(ostream &stream, Vector3D const &objeto);//ok


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif
