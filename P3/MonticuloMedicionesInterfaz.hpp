/*!
	\file MonticuloMedicionesInterfaz.hpp
	\brief Se define la interfaz del TAD MonticuloMediciones.
	\author Daniel Ranchal Parrado
	\date 01-05-2018
*/
#ifndef _MONTICULO_MEDICIONES_INTERFAZ_HPP
#define _MONTICULO_MEDICIONES_INTERFAZ_HPP
#include "Medicion.hpp"
namespace ed{
	//!  Definición de la clase MonticuloMedicionesInterfaz
	class MonticuloMedicionesInterfaz	{
		public:
			/**
			 * @fn virtual bool isEmpty()
			 * @brief Comprueba si el montículo está vacio.
			 * @note Función de tipo const
			 * @note Función virtual pura que debe de ser redefinida en la clase heredera.
			 * @return Devuelve true si no tiene mediciones y false en el caso contrario.
			 */
			virtual bool isEmpty() const = 0;
			/**
			 * @fn virtual ed::Medicion top() const
			 * @brief Devuelve la cima del montículo
			 * @post isEmpty() == false
			 * @note Función de tipo const
			 * @note Función virtual pura que debe de ser redefinida en la clase heredera.
			 * @return Un objeto de la clase Medicion
			 */
			virtual ed::Medicion top() const = 0;
			/**
			 * @fn virtual void insert(ed::Medicion medicion)
			 * @brief Inserta una nueva medición en el montículo
			 * @param medicion Objeto de la clase Medicion
			 * @post isEmpty() == false
			 * @note Función virtual pura que debe de ser redefinida en la clase heredera.
			 * @return Nada
			 */
			virtual void insert(ed::Medicion medicion) = 0;
			/**
			 * @fn virtual void remove()
			 * @brief Borra la medición que ocupa la cima
			 * @post isEmpty() == false
			 * @note Función virtual pura que debe de ser redefinida en la clase heredera.
			 * @return Nada
			 */
			virtual void remove() = 0;
	}; // Clase MonticuloMedicionesInterfaz
} // Espacio de nombres ed
#endif //  _MONTICULO_MEDICIONES_INTERFAZ_HPP
