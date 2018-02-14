/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author 
  \date  
*/
#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_
#include "Vector3D.hpp"
namespace ed{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
	int menu();
	/**
    * @fn void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w)
    * @brief Función que invoca a otras relacionadas con la lectura de vectores
	 * @param u Dato de tipo Vector3D&
	 * @param v Dato de tipo Vector3D&
	 * @param w Dato de tipo Vector3D&
	 *
	 * Se invocan a las funciones leerVector3D(), y la sobrecarga del operador de entrada
	 */
	void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);
	/**
    * @fn void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w)
    * @brief Función que invoca a otras relacionadas con la muestra de información de los vectores
	 * @param u Dato de tipo const Vector3D&
	 * @param v Dato de tipo const Vector3D&
	 * @param w Dato de tipo const Vector3D&
	 *
	 * Se invocan a las funciones escribirVector3D() y la sobrecarga del operador de salida
	 */
	void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);
	/**
    * @fn void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v)
    * @brief Función que invoca a los observadores de la clase Vector3D
	 * @param u Dato de tipo const Vector3D&
	 * @param v Dato de tipo const Vector3D&
	 *
	 * Se invocan a las funciones escribirVector3D(), modulo(), angulo(Vector3D v), get1(), get2(), get3(), alfa(), beta() y gamma().
	 */
	void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);
	/**
    * @fn void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k)
    * @brief Función que invoca a los modificadores de la clase Vector3D
	 * @param u Dato de tipo Vector3D&
	 * @param v Dato de tipo const Vector3D&
	 * @param k Dato de tipo double
	 *
	 * Se invocan a las funciones sumConst(double k), multConst(double k), sumVect(Vector3D v) y multVect(Vector3D v)
	 */
	void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);
	/**
    * @fn void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v)
    * @brief Función en la que se calcula el producto escalar
	 * @param u Dato de tipo const Vector3D&
	 * @param v Dato de tipo const Vector3D&
	 *
	 * Se invocan a la funcion dotProduct() y operator*(), mostrando los resultados esperados
	 */
	void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v); 
	/**
    * @fn void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v)
    * @brief Función en la que se calcula el producto vectorial
	 * @param u Dato de tipo const Vector3D&
	 * @param v Dato de tipo const Vector3D&
	 *
	 * Se invocan a la funcion crossProduct() y operator^(), mostrando los resultados esperados
	 */
	void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);
	/**
    * @fn void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w)
    * @brief Función en la que se calcula el producto mixto
	 * @param u Dato de tipo const Vector3D&
	 * @param v Dato de tipo const Vector3D&
	 * @param w Dato de tipo const Vector3D&
	 *
	 * Se invoca a la funcion productoMixto(Vector3D v, Vector3D w)
	 */	
	void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);
/**
    * @fn void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k)
    * @brief Función en la que se llama a los operadores sobrecargados
	 * @param u Dato de tipo const Vector3D&
	 * @param v Dato de tipo const Vector3D&
	 * @param w Dato de tipo const Vector3D&
	 * @param k Dato de tipo double
	 */	
	void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);
} // Fin del espacio de nombre de la asignatura: ed
// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
