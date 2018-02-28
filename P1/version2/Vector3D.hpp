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
using std::abs;
#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales
/**
 * @namespace ed
 * @brief Este es el espacio de nombres ed
 */
namespace ed{
//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$ 
	/**
	 * @class Vector3D
    * @brief Esta es la clase Vector3D
    */
	class Vector3D{
	  //! \name Atributos privados de la clase Vector3D
		private: 
			double v_[3]; ///<Vector de elementos privados			
		//! \name Funciones o métodos públicos de la clase Vector3D
		public:
		//! \name Constructores de la clase Vector3D
			/**
          * @fn Vector3D()
          * @brief Constructor de la clase Vector3D
          *
			 * Este constructor iguala a cero los tres miembros privados de la clase
			 */
			Vector3D(){
				v_[0]=0; v_[1]=0; v_[2]=0;
				#ifndef NDEBUG
				assert(get1()==0 && get2()==0 && get3()==0);
				#endif
			}
			/**
          * @fn Vector3D(double v1, double v2, double v3)
          * @brief Constructor de la clase Vector3D
			 * @param v1 El valor que va a tomar la variable privada v1_
			 * @param v2 El valor que va a tomar la variable privada v2_
          * @param v3 El valor que va a tomar la variable privada v3_
			 *
			 * Este constructor iguala el vector de elementos privados de la clase a los parametros pasados respectivamente
			 */
			Vector3D(double v1, double v2, double v3){
				v_[0]=v1; v_[1]=v2; v_[2]=v3;
				#ifndef NDEBUG
				assert(abs(get1() - v1)<COTA_ERROR && abs(get2() - v2)<COTA_ERROR && abs(get3() - v3)<COTA_ERROR);
				#endif
			}
			/**
          * @fn Vector3D(const Vector3D &v)
          * @brief Constructor de copia de la clase Vector3D
			 * @param v El vector que vamos a obtener es copia de v
			 *
			 * Este constructor iguala el vector de elementos privados de la clase a los parametros pasados respectivamente
			 */
			Vector3D(const Vector3D &v){
				v_[0]=v.get1(); v_[1]=v.get2(); v_[2]=v.get3();
				#ifndef NDEBUG
				assert(abs(get1() - v.get1())<COTA_ERROR && abs(get2() - v.get2())<COTA_ERROR && abs(get3() - v.get3())<COTA_ERROR);
				#endif
			}
		//! \name Observadores: funciones de consulta de Vector3D
			/**
          * @fn inline double get1() const
          * @brief Observador de la clase Vector3D
          * @return Devuelve v_[0]
			 *
			 * Este observador devuelve el miembro privado v_[0]
			 */
			inline double get1() const{return v_[0];}
			/**
          * @fn inline double get2() const
          * @brief Observador de la clase Vector3D
          * @return Devuelve v_[1]
			 *
			 * Este observador devuelve el miembro privado v_[1]
			 */
			inline double get2() const{return v_[1];}
			/**
          * @fn inline double get3() const
          * @brief Observador de la clase Vector3D
          * @return Devuelve v_[2]
			 *
			 * Este observador devuelve el miembro privado v_[2]
			 */
			inline double get3() const{return v_[2];}
			/**
          * @fn double modulo() const
          * @brief Observador de la clase Vector3D
          * @return Devuelve el modulo del vector
			 *
			 * Este observador devuelve el modulo el cual se calcula como \f$ \left \| \vec{v} \right \|=\sqrt{v1\_^2 + v2\_^2 + v3\_^2} \f$ 
			 */
			double modulo() const;
			/**
          * @fn double angulo(Vector3D v) const
          * @brief Observador de la clase Vector3D
			 * @param v Dato de tipo Vector3D
          * @return Devuelve el angulo entre el vector pasado por parametro y el mismo
			 *
			 * Este observador devuelve el angulo entre los dos vectores el cual se calcula como \f$ \arccos \left ( \frac{\vec{u}*\vec{v}}{\left \| \vec{u} \right \|* \left \| \vec{v} \right \|} \right ) \f$ 
			 */
			double angulo(Vector3D v) const;
			/**
          * @fn double alfa() const
          * @brief Observador de la clase Vector3D
			 * @return Devuelve el angulo entre el vector y el eje X
			 *
			 * Este observador devuelve el angulo entre el vector y el eje X el cual se calcula como \f$ \arccos \left ( \frac{\vec{u}*\vec{v}}{\left \| \vec{u} \right \|* \left \| \vec{v} \right \|} \right ) \f$ siendo \f$ \vec{v}= \left ( 1,0,0 \right ) \f$
			 */
			double alfa() const;
			/**
          * @fn double beta() const
          * @brief Observador de la clase Vector3D
			 * @return Devuelve el angulo entre el vector y el eje Y
			 *
			 * Este observador devuelve el angulo entre el vector y el eje Y el cual se calcula como \f$ \arccos \left ( \frac{\vec{u}*\vec{v}}{\left \| \vec{u} \right \|* \left \| \vec{v} \right \|} \right ) \f$ siendo \f$ \vec{v}= \left ( 0,1,0 \right ) \f$
			 */
			double beta() const;
			/**
          * @fn double gamma() const
          * @brief Observador de la clase Vector3D
			 * @return Devuelve el angulo entre el vector y el eje Z
			 *
			 * Este observador devuelve el angulo entre el vector y el eje Z el cual se calcula como \f$ \arccos \left ( \frac{\vec{u}*\vec{v}}{\left \| \vec{u} \right \|* \left \| \vec{v} \right \|} \right ) \f$ siendo \f$ \vec{v}= \left ( 0,0,1 \right ) \f$
			 */
			double gamma() const;
			/**
          * @fn double dotProduct(Vector3D v) const
          * @brief Observador de la clase Vector3D
			 * @param v Dato de tipo Vector3D
			 * @return Devuelve el producto escalar entre el vector v y el mismo
			 *
			 * Este observador devuelve el producto escalar el cual se calcula como \f$ \vec{u}*\vec{v}=u_{1}*v_{1} + u_{2}*v_{2} + u_{3}*v_{3} \f$
			 */
			double dotProduct(Vector3D v) const;
			/**
          * @fn Vector3D crossProduct(Vector3D v) const
          * @brief Observador de la clase Vector3D
			 * @param v Dato de tipo Vector3D
			 * @return Devuelve el producto vectorial entre el vector v y el mismo
			 *
			 * Este observador devuelve el producto escalar el cual se calcula como \f$ \vec{u}\times\vec{v}=w_1\vec{i} + w_2\vec{j} + w_3\vec{k} \f$ donde \f$ w_1=u_2*v_3-u_3*v_2 \f$ , \f$ w_2=-u_1*v_3 + u_3*v_1 \f$ y \f$ w_3=u_1*v_2 - u_2*v_1 \f$
			 */
			Vector3D crossProduct(Vector3D v) const;
			/**
          * @fn double productoMixto(Vector3D v, Vector3D w) const
          * @brief Observador de la clase Vector3D
			 * @param v Dato de tipo Vector3D
			 * @param w Dato de tipo Vector3D
			 * @return Devuelve el resultado de calcular el producto escalar del vector actual con el vector obtenido al calcular el producto vectorial de otros dos vectores
			 *
			 * Este observador devuelve \f$ \vec{u}* \left(\vec{v} \times \vec{w} \right) \f$
			 */
			double productoMixto(Vector3D v, Vector3D w) const;
		//! \name Modificadores: funciones de modificación de Vector3D
			/**
          * @fn inline void set1(double v1)
          * @brief Modificador de la clase Vector3D
			 * @param v1 Valor al que se va a igualar v_[0]
          * 
			 * Este modificador iguala v_[0] al parametro recibido
			 */			
			inline void set1(double v1){
				v_[0]=v1;
				#ifndef NDEBUG
				assert(abs(v1 - get1())<COTA_ERROR);
				#endif
			}
			/**
          * @fn inline void set2(double v2)
          * @brief Modificador de la clase Vector3D
			 * @param v2 Valor al que se va a igualar v_[1]
          * 
			 * Este modificador iguala v_[1] al parametro recibido
			 */
			inline void set2(double v2){
				v_[1]=v2;
				#ifndef NDEBUG
				assert(abs(v2 - get2())<COTA_ERROR);
				#endif
			}
			/**
          * @fn inline void set3(double v3)
          * @brief Modificador de la clase Vector3D
			 * @param v3 Valor al que se va a igualar v_[2]
          * 
			 * Este modificador iguala v_[2] al parametro recibido
			 */
			inline void set3(double v3){
				v_[2]=v3;
				#ifndef NDEBUG
				assert(abs(v3 - get3())<COTA_ERROR);
				#endif
			}
			/**
			 * @fn void vectorUnitario()
			 * @brief Funcion que convierte el vector en unitario
			 *
			 * Este modificador calcula el vector unitario de la siguiente manera: \f$ \frac{\vec{v}}{\| \vec{v} \|} \f$
			 */
			void vectorUnitario();
			/**
          * @fn void sumConst(double k)
          * @brief Modificador de la clase Vector3D
			 * @param k Dato de tipo double
          * 
			 * Modifica el vector sumandolo con la constante que recibe como parametro
			 */
			void sumConst(double k);
			/**
          * @fn void sumVect(Vector3D v)
          * @brief Modificador de la clase Vector3D
			 * @param v Dato de tipo Vector3D
          * 
			 * Modifica el vector sumandole el que recibe como parametro
			 */
			void sumVect(Vector3D v);
			/**
          * @fn void multConst(double k)
          * @brief Modificador de la clase Vector3D
			 * @param k Dato de tipo double
          * 
			 * Modifica el vector multiplicandolo con la constante que recibe como parametro
			 */
			void multConst(double k);
			/**
          * @fn void multVect(Vector3D v)
          * @brief Modificador de la clase Vector3D
			 * @param v Dato de tipo Vector3D
          * 
			 * Modifica el vector multiplicandolo con el que recibe como parametro
			 */
			void multVect(Vector3D v);
			//! \name Operadores de la clase
			/**
          * @fn Vector3D &operator=(Vector3D const &objeto)
          * @brief Modificador de la clase Vector3D
			 * @param objeto Dato de tipo const Vector3D&
          * @return Devuelve un dato de tipo Vector3D&
			 *
			 * Este operador sobrecargado iguala el vector con el parametro
			 */
			Vector3D &operator=(Vector3D const &objeto);
			/**
          * @fn bool operator==(Vector3D const &objeto) const
          * @brief Modificador de la clase Vector3D
			 * @param objeto Dato de tipo const Vector3D&
          * @return Devuelve un valor booleano
			 *
			 * Este operador sobrecargado devuelve true si los dos vectores son iguales, y false en el caso contrario.
			 */
			bool operator==(Vector3D const &objeto) const;
			/**
          * @fn Vector3D& operator+(Vector3D const &objeto) const
          * @brief Modificador de la clase Vector3D
			 * @param objeto Dato de tipo const Vector3D&
          * @return Devuelve un dato de tipo Vector3D&
			 *
			 * Este operador sobrecargado devuelve la suma de dos vectores
			 */
			Vector3D& operator+(Vector3D const &objeto) const;
			/**
          * @fn Vector3D& operator+() const
          * @brief Modificador de la clase Vector3D
			 * @return Devuelve un dato de tipo Vector3D&
			 *
			 * Este operador sobrecargado devuelve una copia del vector actual
		 	 */
			Vector3D& operator+() const;
			/**
          * @fn Vector3D& operator-(Vector3D const &objeto) const
          * @brief Modificador de la clase Vector3D
			 * @param objeto Dato de tipo const Vector3D&
          * @return Devuelve un dato de tipo Vector3D&
			 *
			 * Este operador sobrecargado devuelve la resta de dos vectores
			 */
			Vector3D& operator-(Vector3D const &objeto) const;
			/**
          * @fn Vector3D& operator-() const
          * @brief Modificador de la clase Vector3D
			 * @return Devuelve un dato de tipo Vector3D&
			 *
			 * Este operador sobrecargado devuelve un vector que es opuesto al vector actual
		 	 */
			Vector3D& operator-() const;
			/**
          * @fn Vector3D& operator*(double k) const
          * @brief Modificador de la clase Vector3D
			 * @param k Dato de tipo double
          * @return Devuelve un dato de tipo Vector3D&
			 *
			 * Este operador sobrecargado devuelve otro vector el cual es resultado de multiplicar el vector anterior por una constante k
			 */
			Vector3D& operator*(double k) const;
			/**
          * @fn double operator*(Vector3D const &objeto) const
          * @brief Modificador de la clase Vector3D
			 * @param objeto Dato de tipo const Vector3D&
          * @return Devuelve un dato de tipo double
			 *
			 * Este operador sobrecargado devuelve el producto escalar de dos vectores
			 */
			double operator*(Vector3D const &objeto) const;
			/**
          * @fn Vector3D& operator^(Vector3D const &objeto) const
          * @brief Modificador de la clase Vector3D
			 * @param objeto Dato de tipo const Vector3D&
          * @return Devuelve un dato de tipo Vector3D&
			 *
			 * Este operador sobrecargado devuelve otro vector que es resultado del prodcuto vectorial de dos vectores
			 */
			Vector3D& operator^(Vector3D const &objeto) const;
			//! \name Funciones lectura y escritura de la clase Vector3D
			/**
          * @fn void leerVector3D()
          * @brief Modificador de la clase Vector3D
			 * 
			 * Esta función pide por pantalla introducir cada elemento del vector
			 */		
			void leerVector3D();
			/**
          * @fn void escribirVector3D() const
          * @brief Observador de la clase Vector3D
			 * 
			 * Esta función muestra pantalla el vector
			 */
			void escribirVector3D() const;
	}; // Fin de la definición de la clase Vector3D



//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	/**
    * @fn Vector3D & operator* (double k, Vector3D const & objeto)
    * @brief Modificador de la clase Vector3D
	 * @param k Dato de tipo double
	 * @param objeto Dato de tipo const Vector3D&
    * @return Devuelve un dato de tipo Vector3D&
	 *
	 * Este operador sobrecargado devuelve otro vector, el cual es el producto entre el vector actual y la constante
	 */
   Vector3D & operator* (double k, Vector3D const & objeto);
	/**
    * @fn istream &operator>>(istream &stream, Vector3D &objeto)
    * @brief Modificador de la clase Vector3D
	 * @param stream Dato de tipo istream
	 * @param objeto Dato de tipo Vector3D&
	 * @return Devuelve un dato de tipo istream&
	 *
	 * Esta función sobrecarga el operador de entrada para leer un dato de tipo Vector3D
	 */
	istream &operator>>(istream &stream, Vector3D &objeto);
	/**
    * @fn ostream &operator<<(ostream &stream, Vector3D const &objeto)
    * @brief Observador de la clase Vector3D
	 * @param stream Dato de tipo ostream
	 * @param objeto Dato de tipo const Vector3D&
	 * @return Devuelve un dato de tipo ostream&
	 *
	 * Esta función sobrecarga el operador de salida para mostrar por pantalla un dato de tipo Vector3D
	 */
   ostream &operator<<(ostream &stream, Vector3D const &objeto);
} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif
