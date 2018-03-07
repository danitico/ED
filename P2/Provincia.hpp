/*!	
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author Daniel Ranchal Parrado
	\date  
	\version 

*/
#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_
// Para comprobar las pre y post condiciones
#include <cassert>
#include <string>
#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
// DEBES COMPLETAR O MODIFICAR EL CÓDIGO DE LA CLASE Provincia
// DEBES COMPLETAR LOS COMENTARIOS DE DOXYGEN
// IMPORTANTE
// Se incluyen los prototipos de las funciones virtuales que hay que redefinir
// Hay que incluir los prototipos de las demás funciones
/*!	
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos
*/
namespace ed{
/*!	
  \class Provincia
  \brief Definición de la clase Provincia
*/
class Provincia{
	//!	\name Métodos públicos de la clase Provincia
	private:
		std::string _nombre;//!<  \brief Nombre de la Provincia
		int         _codigo;//!<  \brief Código de la Provincia
	  	ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios;//!<  \brief Lista de municipios de la Provincia
	//!	\name  Métodos públicos de la clase Provincia
	public: 

	//!	\name Constructor
		Provincia(std::string nombre="", int codigo=0){
			_nombre=nombre;
			_codigo=codigo;

			#ifndef NDEBUG
			assert(getNombre()==nombre && getCodigo()==codigo && hayMunicipios()==true);
			#endif
		}

	//!	\name Observadores
		inline std::string getNombre() const{return _nombre;}
		inline int getCodigo() const{return _codigo;}
		bool hayMunicipios() const{return true;}
		int getNumeroMunicipios() const;
		bool existeMunicipio(std::string nombre);
		Municipio getMunicipio(std::string nombre);
		int getTotalHombres() const;
		int getTotalMujeres() const;
		int getTotalHabitantes() const;
	
	//!	\name Modificadores
		void setNombre(std::string nombre);


	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia



	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros


}; //Fin de la clase  Provincia
} // Fin del espacio de nombres ed
#endif // _PROVINCIA_HPP_
