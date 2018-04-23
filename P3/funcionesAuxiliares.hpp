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
	 * @fn int menu()
	 * @brief Función que muestra por pantalla utilizando macros las opciones del menú.
	 * @sa macros.hpp
	 */
	int menu();
	/**
	 * @fn void cargarMonticuloDeFichero(ed::MonticuloMediciones & monticulo)
	 * @param monticulo Objeto de la clase MonticuloMediciones en el que se guarda la informacion
	 * @brief Función que vuelca la informacion del fichero en un objeto de la clase MonticuloMediciones
	 */
	void cargarMonticuloDeFichero(ed::MonticuloMediciones & monticulo);
	/**
	 * @fn void grabarMonticuloEnFichero(ed::MonticuloMediciones const & monticulo);
	 * @param monticulo Objeto de la clase MonticuloMediciones que posee la informacion que se quiere guardar
	 * @brief Función que guarda la informacion del objeto de la clase MonticuloMediciones en un fichero
	 */
	void grabarMonticuloEnFichero(ed::MonticuloMediciones const & monticulo);
	/**
	 * @fn void consultarDatosdePrecipitacion(ed::Fecha const & fecha, ed::MonticuloMediciones const & monticulo)
	 * @param monticulo Objeto de la clase MonticuloMediciones que posee la informacion que se quiere guardar
	 * @brief Función que muestra la precipitación de una fecha específica
	 */
	void consultarDatosdePrecipitacion(ed::MonticuloMediciones const & monticulo);
	/**
	 * @fn void mostrarPrecipitacionDescendente(ed::MonticuloMediciones const & monticulo)
	 * @param monticulo Objeto de la clase MonticuloMediciones que posee la informacion que se quiere guardar
	 * @brief Muestra los datos ordenados por la cantidad de precipitación de manera descendente
	 */
	void mostrarPrecipitacionDescendente(ed::MonticuloMediciones const & monticulo);
	/**
	 * @fn void modificarCimaMonticulo(ed::MonticuloMediciones const & monticulo)
	 * @param monticulo Objeto de la clase MonticuloMediciones que posee la informacion que se quiere guardar
	 * @brief Modifica la cima del montículo
	 */
	void modificarCimaMonticulo(ed::MonticuloMediciones & monticulo);
	/**
	 * @fn void modificarElementoMonticulo(ed::MonticuloMediciones & monticulo)
	 * @param monticulo Objeto de la clase MonticuloMediciones que posee la informacion que se quiere guardar
	 * @brief Modifica la precipitacion de una de las mediciones del monticulo
	 */
	void modificarElementoMonticulo(ed::MonticuloMediciones & monticulo);
	/**
	 * @fn void insertarMedicionMonticulo(ed::MonticuloMediciones const & monticulo)
	 * @param monticulo Objeto de la clase MonticuloMediciones que posee la informacion que se quiere guardar
	 * @brief Inserta una medicion en el heap
	 */
	void insertarMedicionMonticulo(ed::MonticuloMediciones & monticulo);
	/**
	 * @fn void borrarElementoMedicion(ed::Fecha const & fecha, ed::MonticuloMediciones const & monticulo)
	 * @param monticulo Objeto de la clase MonticuloMediciones que posee la informacion que se quiere guardar
	 * @brief Borra la medicion la cual está definida por su fecha
	 */
	void borrarElementoMedicion(ed::MonticuloMediciones & monticulo);
	/**
	 * @fn void borrarMonticulo(ed::MonticuloMediciones & monticulo)
	 * @param monticulo Objeto de la clase MonticuloMediciones que posee la informacion que se quiere guardar
	 * @brief Borrar todas las mediciones del montículo
	 */
	void borrarMonticulo(ed::MonticuloMediciones & monticulo);
} // Fin del espacio de nombre de la asignatura: ed
// Fin de _FuncionesAuxiliares_HPP_
#endif
