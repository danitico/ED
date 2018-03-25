/*!
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author Daniel Ranchal Parrado
	\date 26/03/2018
	\version 2.0

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
	/**
		@brief     Constructor parametrizado con valores por defecto
		@attention Función sobrecargada
		@param     nombre: valor por defecto ""
		@param     codigo: valor por defecto 0.0
		@pre       Ninguna
		@post      getNombre()==nombre && getCodigo()==codigo && hayMunicipios()==false
	*/
		Provincia(std::string nombre="", int codigo=0){
			_nombre=nombre;
			_codigo=codigo;

			#ifndef NDEBUG
			assert(getNombre()==nombre && getCodigo()==codigo && hayMunicipios()==false);
			#endif
		}

	//!	\name Observadores
		/**
		* @fn std::string getNombre()
		* @brief Observador de la clase Provincia
		* @note Función inline
		* @return Devuelve _nombre
		*
		* Este observador devuelve el atributo privado _nombre de la clase Provincia
		*/
		inline std::string getNombre() const{return _nombre;}
		/**
		* @fn int getCodigo()
		* @brief Observador de la clase Provincia
		* @note Función inline
		* @return Devuelve _codigo
		*
		* Este observador devuelve el atributo privado _codigo de la clase Provincia
		*/
		inline int getCodigo() const{return _codigo;}
		/**
		* @fn bool hayMunicipios() const
		* @brief Observador de la clase Provincia
		* @sa ListaDoblementeEnlazadaOrdenadaMunicipios::isEmpty()
		* @return Devuelve un valor booleano.
		*
		* Este observador devuelve true en el caso que _listaMunicipios no está vacía y false si está vacía.
		*/
		bool hayMunicipios() const;
		/**
		* @fn getNumeroMunicipios() const
		* @brief Observador de la clase Provincia
		* @sa ListaDoblementeEnlazadaOrdenadaMunicipios::nItems()
		* @return Devuelve el atributo _nitems de la Clase ListaDoblementeEnlazadaOrdenadaMunicipios
		*
		* Esta observador devuelve el número de municipios de la lista _listaMunicipios
		*/
		int getNumeroMunicipios() const;
		/**
		* @fn bool existeMunicipio(std::string nombre)
		* @brief Observador de la clase Provincia
		* @param nombre Nombre del municipio a buscar
		* @sa ListaDoblementeEnlazadaOrdenadaMunicipios::find()
		* @return Devuelve un valor booleano
		*
		* Esta observador devuelve true si el Municipio se encuentra en _listaMunicipios y false en el caso contrario
		*/
		bool existeMunicipio(std::string nombre);
		/**
		* @fn Municipio getMunicipio(std::string nombre)
		* @param nombre Nombre del municipio a consultar
		* @brief Observador de la clase Provincia
		* @sa existeMunicipio(), ListaDoblementeEnlazadaOrdenadaMunicipios::getCurrentItem()
		* @pre existeMunicipio()==true
		* @return Devuelve el municipio con el nombre indicado
		*
		* Esta observador devuelve true si el Municipio se encuentra en _listaMunicipios y false en el caso contrario
		*/
		Municipio getMunicipio(std::string nombre);
		/**
		* @fn int getTotalHombres()
		* @brief Observador de la clase Provincia
		* @sa ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead(), ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem(), ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext(), ListaDoblementeEnlazadaOrdenadaMunicipios::getCurrentItem(), Municipio::getHombres()
		* @return Devuelve un entero
		*
		* Devuelve el número total de hombres de la provincia
		*/
		int getTotalHombres();
		/**
		* @fn int getTotalMujeres()
		* @brief Observador de la clase Provincia
		* @sa ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead(), ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem(), ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext(), ListaDoblementeEnlazadaOrdenadaMunicipios::getCurrentItem(), Municipio::getMujeres()
		* @return Devuelve un entero
		*
		* Devuelve el número total de mujeres de la provincia
		*/
		int getTotalMujeres();
		/**
		* @fn int getTotalHabitantes()
		* @brief Observador de la clase Provincia
		* @sa getTotalMujeres(), getTotalHombres()
		* @post valorDevuelto==(getTotalMujeres() + getTotalHombres())
		* @return Devuelve un entero
		*
		* Devuelve el número total de habitantes de la provincia
		*/
		int getTotalHabitantes();

	//!	\name Modificadores
		/**
		* @fn void setNombre(std::string nombre)
		* @brief Modificador de la clase Provincia
		* @param nombre El nuevo nombre de la provincia
		* @post getNombre()==nombre
		*
		* Asigna un nuevo nombre a la provincia
		*/
		void setNombre(std::string nombre);
		/**
		* @fn void setCodigo(int numero)
		* @brief Modificador de la clase Provincia
		* @param numero El nuevo código de la provincia
		* @post getCodigo()==numero
		*
		* Asigna un nuevo código a la provincia
		*/
		void setCodigo(int numero);
		/**
		* @fn void insertarMunicipio(Municipio municipio)
		* @brief Modificador de la clase Provincia
		* @sa ListaDoblementeEnlazadaOrdenadaMunicipios::insert()
		* @param municipio El nuevo municipio a insertar
		* @pre existeMunicipio(municipio.getNombre())==false
		* @post existeMunicipio(municipio.getNombre())==true
		* @post getNumeroMunicipios()==old.getNumeroMunicipios()+1
		*
		* Insertar un objeto de la clase Municipio en la Provincia
		*/
		void insertarMunicipio(Municipio municipio);
		/**
		* @fn void borrarMunicipio(std::string cadena)
		* @brief Modificador de la clase Provincia
		* @sa ListaDoblementeEnlazadaOrdenadaMunicipios::find(), ListaDoblementeEnlazadaOrdenadaMunicipios::remove()
		* @param cadena Nombre del municipio a borrar
		* @pre existeMunicipio(municipio.getNombre())==true
		* @post existeMunicipio(municipio.getNombre())==false
		* @post getNumeroMunicipios()==old.getNumeroMunicipios()-1
		*
		* Borra de la provincia el municipio con el nombre indicado
		*/
		void borrarMunicipio(std::string cadena);
		/**
		* @fn void borrarTodosLosMunicipios()
		* @brief Modificador de la clase Provincia
		* @sa ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll()
		* @post hayMunicipios()==false
		*
		* Borra todos los municipios de la provincia
		*/
		void borrarTodosLosMunicipios();

	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia
		/**
		* @fn void escribirMunicipios()
		* @brief Función de escritura de la clase Provincia
		* @sa getCodigo(), getNombre(), ListaDoblementeEnlazadaOrdenadaMunicipios::isEmpty(), ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead(), ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext(), ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem(), ListaDoblementeEnlazadaOrdenadaMunicipios::getCurrentItem(), Municipio::escribirMunicipio()
		*
		* Escribe por pantalla la información de la provincia
		*/
		void escribirMunicipios();

	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros
		/**
		* @fn bool cargarFichero(std::string archivo)
		* @brief Operación para cargar un fichero
		* @param archivo Nombre del archivo a cargar
		* @return Devuelve un valor booleano
		*
		* Carga la información del fichero en un objeto de la clase Provincia. Devuelve true si se ha cargado correctamente, false en el caso contrario.
		*/
		bool cargarFichero(std::string archivo);
		/**
		* @fn bool grabarFichero(std::string archivo)
		* @brief Operación para guardar información en un fichero
		* @param archivo Nombre del archivo en donde se quiere guardar la información
		* @return Devuelve un valor booleano
		*
		* Guarda la información de un objeto de la clase Provincia en un fichero. Devuelve true si se ha guardado correctamente, false en el caso contrario.
		*/
		bool grabarFichero(std::string archivo);

}; //Fin de la clase  Provincia
} // Fin del espacio de nombres ed
#endif // _PROVINCIA_HPP_º
