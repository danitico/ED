/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 2
  \author Daniel Ranchal Parrado
  \date 26/03/2018
*/
#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_
#include "Provincia.hpp"
namespace ed{
	/**
	 * @fn int menu()
	 * @brief Función que muestra por pantalla utilizando macros las opciones del menú.
	 * @sa macros.hpp
	 */
	int menu();

	///////////////////////////////////////////////////////////////////

	/**
	 * @fn 	void comprobarProvinciaVacia(ed::Provincia & provincia)
	 * @brief Función que comprueba si la Provincia tiene municipios.
		En caso afirmativo, se muestra por pantalla el nombre de la provincia y el número de municipios que tiene.
		En el caso contrario, se muestra que la provincia está vacía.
	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
	 * @sa macros.hpp, Provincia::hayMunicipios(), Provincia::getNombre(), Provincia::getNumeroMunicipios()
	 */
	void comprobarProvinciaVacia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/**
 	 * @fn void cargarProvincia(ed::Provincia & provincia)
 	 * @brief Función que pide por teclado el nombre de un archivo para volcar los datos en el objeto de la clase Provincia.
 	   Si el fichero se ha cargado correctamente, se muestra un mensaje por pantalla, utilizando macros,
 		 el buen funcionamiento de la operación. En el caso contrario, se muestra por pantalla el error de la operación.
 	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
 	 * @sa macros.hpp, Provincia::cargarFichero()
 	 */
	void cargarProvincia(ed::Provincia & provincia);

	/**
	 * @fn void grabarProvincia(ed::Provincia & provincia)
	 * @brief Función que pide por teclado el nombre de un archivo para volcar los datos desde el objeto de la clase Provincia
	 	hasta fichero con el nombre que se le ha pedido que Introduzca.
		Si los datos se han grabado correctamente, se muestra un mensaje por pantalla, utilizando macros, expresando
		 el buen funcionamiento de la operación. En el caso contrario, se muestra por pantalla el error de la operación.
	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
	 * @sa macros.hpp, Provincia::grabarFichero()
	 */
	void grabarProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/**
	 * @fn void consultarDatosDeProvincia(ed::Provincia & provincia)
	 * @brief Función que muestra por pantalla los datos del objeto de la clase Provincia. Por defecto, siempre se muestra
	 	el nombre y el código de la provincia. En el caso que la lista de municipios no este vacía, se procede a imprimir por
		pantalla el número de municipios y el número total de habitantes, desglosado en hombres y mujeres
	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
	 * @sa macros.hpp, Provincia::getNombre(), Provincia::getCodigo(), Provincia::hayMunicipios(), Provincia::getTotalHabitantes(), Provincia::getTotalMujeres(), Provincia::getTotalHombres()
	 */
	void consultarDatosDeProvincia(ed::Provincia & provincia);

	/**
	 * @fn void mostrarMunicipiosDeProvincia(ed::Provincia & provincia)
	 * @note La lista debe de no estar vacía para poder mostrar los municipios de la provincia.
	 * @brief Función que muestra por pantalla los municipios de la provincia con todos sus datos.
	 	Si la lista no está vacía, se procede a mostrar la información de los municipios por pantalla, en
		caso contrario, se muestra por pantalla un mensaje de error.
	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
	 * @sa macros.hpp, Provincia::escribirMunicipios()
	 */
	void mostrarMunicipiosDeProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/**
	 * @fn void modificarDatosDeProvincia(ed::Provincia & provincia)
	 * @brief Función que muestra un submenu en el que se puede elegir modificar el código o el nombre de la provincia además de poder modificar los municipos de la lista.
	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
	 * @sa macros.hpp, Provincia::setCodigo(), Provincia::setNombre(), ed::modificarDatosDeMunicipio()
	 */
	void modificarDatosDeProvincia(ed::Provincia & provincia);

	/**
	 * @fn void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia)
	 * @brief Función que borra todos los municipios de la lista
	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
	 * @sa macros.hpp, ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll()
	 */
	void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia);


	///////////////////////////////////////////////////////////////////

	/**
	 * @fn void consultarMunicipioDeProvincia(ed::Provincia & provincia)
	 * @note Para el correcto funcionamiento, el municipio debe de estar en la lista.
	 * @brief Función que pide por pantalla el nombre del municipio para consultar su información.
	 	Si se encuentra en la lista, se muestra su información, en el caso contrario, se muestra un mensaje de error.
	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
	 * @sa macros.hpp, Provincia::existeMunicipio(), Provincia::getMunicipio(), Municipio::escribirMunicipio()
	 */
	void consultarMunicipioDeProvincia(ed::Provincia & provincia);

	/**
	 * @fn void insertarMunicipioEnProvincia(ed::Provincia & provincia)
	 * @warning A la hora de introducir los datos del municipio, se muestra un mensaje que avisa de como introducirlo
	 * @brief Función que pide por pantalla los datos de un municipio. Si el municipio introducido no se encuentra en
	 	la lista, se procede a introducirlo. En el caso contrario, se avisa de ello y no se introduce nada.
	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
	 * @sa macros.hpp, Provincia::existeMunicipio(), Provincia::insertarMunicipio()
	 */
	void insertarMunicipioEnProvincia(ed::Provincia & provincia);

	/**
	 * @fn void borrarMunicipioDeProvincia(ed::Provincia & provincia)
	 * @brief Función que pide por pantalla el nombre del municipio para borrarlo de la lista.
	 	Si se encuentra en la lista, se procede a borrarlo, en el caso contrario, se muestra un mensaje de error.
	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
	 * @sa macros.hpp, Provincia::existeMunicipio(), Provincia::borrarMunicipio()
	 */
	void borrarMunicipioDeProvincia(ed::Provincia & provincia);
	/**
	 * @fn modificarDatosDeMunicipio(ed::Provincia & provincia, std::string & nombre_municipio)
	 * @brief Función que modifica los datos de un municipio de la lista.
	 *	@param provincia Objeto de la clase Provincia pasado por referencia.
	 * @param nombre_municipio String que contiene el nombre del municipio a modificar
	 * @sa macros.hpp, Provincia::insertarMunicipio(), Provincia::borrarMunicipio(), ed::modificarDatosDeProvincia()
	 */
	void modificarDatosDeMunicipio(ed::Provincia & provincia, std::string & nombre_municipio);

} // Fin del espacio de nombre de la asignatura: ed
// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
