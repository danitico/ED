/*!
	\file MonticuloMediciones.hpp
	\brief Se define el TAD MonticuloMediciones.
	\author Daniel Ranchal Parrado
	\date
*/
#ifndef _MONTICULO_MEDICIONES_HPP
#define _MONTICULO_MEDICIONES_HPP
#include <vector>
#include <cassert>
#include "Medicion.hpp"
#include "MonticuloMedicionesInterfaz.hpp"
// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN
namespace ed{
// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN
	class MonticuloMediciones : public MonticuloMedicionesInterfaz{
		private:
			//! \name Atributos privados de la clase MonticuloMediciones
			std::vector<Medicion> v;
			//! \name Métodos privados de la clase MonticuloMediciones
			/**
	       * @fn ed::Medicion getElement(int i) const
			 * @param i Variable entera que representa la posicion en el vector
	       * @brief Devuelve el elemento que ocupa la posicion i en el vector que almacena el monticulo
	       * @note Observador privado de la clase MonticuloMediciones
	       * @note Funcion de tipo const
			 * @pre i>=0
			 * @pre i<MonticuloMediciones::size()
			 * @post Si v[i]==0 return NULL
			 * @return Devuelve un objeto de la clase Medicion o NULL si no existe
	       */
			ed::Medicion getElement(int i) const;
			/**
	       * @fn void setElement(int i, Medicion medicion)
			 * @param i Variable entera que representa la posicion en el vector
			 * @param medicion Objeto introducido en el monticulo
	       * @brief Modifica el elemento que ocupa la posicion i en el vector que almacena el montículo
	       * @note Modificador privado de la clase MonticuloMediciones
			 * @pre i>=0
			 * @pre i<MonticuloMediciones::size()
			 * @post MonticuloMediciones::getElement(i)==medicion
	       */
			void setElement(int i, Medicion medicion);
			/**
	       * @fn int getLeftChild(int i) const
			 * @param i Variable entera que representa la posicion en el vector
	       * @brief Devuelve el índice del hijo izquierdo del índice recibido
	       * @note Observador privado de la clase MonticuloMediciones
	       * @note Funcion de tipo const
			 * @pre i>=0
			 * @post Si getElement(2*i+1)==NULL entonces return -1
			 * @post Si getElement(2*i+1)!=NULL entonces return 2*i+1
	       * @return Devuelve un entero que representa la posicion del hijo izquierdo
	       */
			int getLeftChild(int i) const;
			/**
	       * @fn int getRightChild(int i) const
			 * @param i Variable entera que representa la posicion en el vector
	       * @brief Devuelve el índice del hijo derecho del índice recibido
	       * @note Observador privado de la clase MonticuloMediciones
	       * @note Funcion de tipo const
			 * @pre i>=0
			 * @post Si getElement(2*i+2)==NULL entonces return -1
			 * @post Si getElement(2*i+2)!=NULL entonces return 2*i+2
	       * @return Devuelve un entero que representa la posicion del hijo derecho
	       */
			int getRightChild(int i) const;
			/**
	       * @fn int getParent(int i) const
			 * @param i Variable entera que representa la posicion en el vector
	       * @brief Devuelve el índice del padre del índice recibido
	       * @note Observador privado de la clase MonticuloMediciones
	       * @note Funcion de tipo const
			 * @pre i>=0
			 * @post valorDevuelto==(i-1)/2
	       * @return Devuelve un entero que representa la posicion del padre
	       */
			int getParent(int i) const;
			/**
	       * @fn void shiftUp(int i)
			 * @param i Variable entera que representa la posicion en el vector
	       * @brief El elemento indicado por el indice es subido en el montivulo hasta que se verifica la ordenacion de maximos
	       * @note Modificador privado de la clase MonticuloMediciones
			 * @pre i>=0
			 * @pre i<MonticuloMediciones::size()
			 * @post Si top()!=getElement(i) entonces getElement(i)<=getElement(getParent(i))
			 * @post Si getLeftChild(i)!=NULL entonces getElement(i)>=getElement(getLeftChild(i))
			 * @post Si getRightChild(i)!=NULL entonces getElement(i)>=getElement(getRightChild(i))
	       */
			void shiftUp(int i);
			/**
	       * @fn void shiftDown(int i)
			 * @param i Variable entera que representa la posicion en el vector
	       * @brief El elemento indicado por el indice es bajado en el montivulo hasta que se verifica la ordenacion de maximos
	       * @note Modificador privado de la clase MonticuloMediciones
			 * @pre i>=0
			 * @pre i<MonticuloMediciones::size()
			 * @post Si top()!=getElement(i) entonces getElement(i)<=getElement(getParent(i))
			 * @post Si getLeftChild(i)!=NULL entonces getElement(i)>=getElement(getLeftChild(i))
			 * @post Si getRightChild(i)!=NULL entonces getElement(i)>=getElement(getRightChild(i))
	       */
			void shiftDown(int i);
			/**
	       * @fn bool has(ed::Medicion medicion) const
			 * @param medicion Objeto de la clase Medicion
	       * @brief Se comprueba si la medicion esta incluida en el monticulo
	       * @note Observador privado de la clase MonticuloMediciones
	       * @note Funcion de tipo const
	       * @return Devuelve true si medicion se encuentra en el montículo. False en el caso contrario
	       */
			bool has(ed::Medicion medicion) const;
			/////////////////////////////////////////////////////////////////////////////////////

			//! \name Métodos públicos de la clase MonticuloMediciones
		public:
			//! \name Constructor
			/**
			 * @fn inline MonticuloMediciones()
			 * @brief Inicializa un objeto de la clase MonticuloMediciones
			 * @note Constructor de la clase MonticuloMediciones
			 * @note Función de tipo inline
			 * @post isEmpty() == true
			 */
			inline MonticuloMediciones(){
				#ifndef NDEBUG
				assert(isEmpty());
				#endif
			}
			//! \name Observadores
			bool isEmpty() const;
			int size() const;
			ed::Medicion top() const;
			////////////////////////////////////////////////////////////
			//! \name Operaciones de modificación
			void insert(ed::Medicion medicion);
			void remove();
			void removeAll();
			void modify(ed::Medicion medicion);
			//! \name Operadores
			ed::MonticuloMediciones& operator=(ed::MonticuloMediciones & const m);
			////////////////////////////////////////////////////////////////////
			//! \name Función de escritura
			void print() const;
	}; // Clase MonticuloMediciones
} // Espacio de nombres ed
#endif // _MONTICULO_MEDICIONES_HP
