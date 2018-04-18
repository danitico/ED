/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 3
  \author Daniel Ranchal Parrado
  \date
*/
#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_
#include "MonticuloMediciones.hpp"
namespace ed{
	/**
	 * @fn void cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo)
	 * @param nombreFichero Nombre del fichero del que se carga la informacion
	 * @param monticulo Objeto de la clase MonticuloMediciones en el que se guarda la informacion
	 * @brief Función que vuelca la informacion del fichero en un objeto de la clase MonticuloMediciones
	 */
	void cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo);
	/**
	 * @fn void grabarMonticuloEnFichero (std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo);
	 * @param nombreFichero Nombre del fichero en el que se quiere guardar la informacion
	 * @param monticulo Objeto de la clase MonticuloMediciones que posee la informacion que se quiere guardar
	 * @brief Función que guarda la informacion del objeto de la clase MonticuloMediciones en un fichero
	 */
	void grabarMonticuloEnFichero (std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo);
} // Fin del espacio de nombre de la asignatura: ed
// Fin de _FuncionesAuxiliares_HPP_
#endif
