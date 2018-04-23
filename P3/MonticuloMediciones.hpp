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
	//!  Definición de la clase MonticuloMediciones
	class MonticuloMediciones : public MonticuloMedicionesInterfaz{
		private:
			//! \name Atributos privados de la clase MonticuloMediciones
			std::vector<Medicion> v_; //!< Vector de la STL que representa un monticulo
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
			ed::Medicion getElement(int i) const;//ok
			/**
	       * @fn void setElement(int i, Medicion medicion)
			 * @param i Variable entera que representa la posicion en el vector
			 * @param medicion Objeto introducido en el monticulo
	       * @brief Modifica el elemento que ocupa la posicion i en el vector que almacena el montículo
	       * @note Modificador privado de la clase MonticuloMediciones
			 * @pre i>=0
			 * @pre i<MonticuloMediciones::size()
			 */
			void setElement(int i, Medicion medicion);//not okxd
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
			int getLeftChild(int i) const;//ok
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
			int getRightChild(int i) const;//ok
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
			int getParent(int i) const;//ok
			/**
	       * @fn void shiftUp(int i)
			 * @param i Variable entera que representa la posicion en el vector
	       * @brief El elemento indicado por el indice es subido en el montivulo hasta que se verifica la ordenacion de maximos
	       * @note Modificador privado de la clase MonticuloMediciones
			 * @pre i>=0
			 * @pre i<MonticuloMediciones::size()
			 * @post Si top()!=getElement(i) entonces getElement(i)<=getElement(getParent(i))
			 * @post Si getLeftChild(i)!=-1 && getLeftChild(i)!=-2 entonces getElement(i)>=getElement(getLeftChild(i))
			 * @post Si getRightChild(i)!=-1 && getRightChild(i)!=-2 entonces getElement(i)>=getElement(getRightChild(i))
	       */
			void shiftUp(int i);//ok
			/**
	       * @fn void shiftDown(int i)
			 * @param i Variable entera que representa la posicion en el vector
	       * @brief El elemento indicado por el indice es bajado en el montivulo hasta que se verifica la ordenacion de maximos
	       * @note Modificador privado de la clase MonticuloMediciones
			 * @pre i>=0
			 * @pre i<MonticuloMediciones::size()
			 * @post Si top()!=getElement(i) entonces getElement(i)<=getElement(getParent(i))
			 * @post Si getLeftChild(i)!=N ULL entonces getElement(i)>=getElement(getLeftChild(i))
			 * @post Si getRightChild(i)!=NULL entonces getElement(i)>=getElement(getRightChild(i))
	       */
			void shiftDown(int i);//ok
			/**
	       * @fn bool has(ed::Medicion medicion) const
			 * @param medicion Objeto de la clase Medicion
	       * @brief Se comprueba si la medicion esta incluida en el monticulo
	       * @note Observador privado de la clase MonticuloMediciones
	       * @note Funcion de tipo const
	       * @return Devuelve true si medicion se encuentra en el montículo. False en el caso contrario
	       */
			bool has(ed::Medicion medicion) const;//ok
			/////////////////////////////////////////////////////////////////////////////////////

			//! \name Métodos públicos de la clase MonticuloMediciones
		public:
			//! \name Constructor
			/**
			 * @fn inline MonticuloMediciones()
			 * @brief Inicializa un objeto de la clase MonticuloMediciones
			 * @note Constructor de la clase MonticuloMediciones sin argumentos
			 * @note Función de tipo inline
			 * @post isEmpty() == true
			 */
			inline MonticuloMediciones(){
				v_.resize(0, ed::Medicion(ed::Fecha(1,1,1), 0.0));
				#ifndef NDEBUG
				assert(isEmpty());
				#endif
			}
			//! \name Observadores
			/**
			 * @fn bool isEmpty() const
			 * @brief Comprueba si el montículo está vacio.
			 * @note Observador publico de la clase MonticuloMediciones
			 * @note Funcion de tipo const
			 * @post valorDevuelto == (size() == 0)
			 */
			bool isEmpty() const;//ok
			/**
			 * @fn int size() const
			 * @brief Devuelve el número de mediciones en el montículo
			 * @note Observador publico de la clase MonticuloMediciones
			 * @note Funcion de tipo const
			 * @post valorDevuelto == (size() == 0)
			 */
			int size() const;//ok
			/**
			 * @fn ed::Medicion top() const
			 * @brief Devuelve la cima del montículo
			 * @note Observador publico de la clase MonticuloMediciones
			 * @note Funcion de tipo const
			 * @pre isEmpty() == false
			 * @post valorDevuelto == getElement(0)
			 * @return Devuelve un objeto de la clase Medicion
			 */
			ed::Medicion top() const;//ok
			////////////////////////////////////////////////////////////
			//! \name Operaciones de modificación
			/**
			 * @fn void insert(ed::Medicion medicion)
			 * @brief Inserta una nueva medicion en el monticulo
			 * @param medicion Objeto de la clase Medicion a insertar
			 * @note Modificador publico de la clase MonticuloMediciones
			 * @post isEmpty() == false
			 * @post has(medicion) == true
			 */
			void insert(ed::Medicion medicion);//ok
			/**
			 * @fn void remove()
			 * @brief Borra la medicion que ocupa la cima
			 * @note Modificador publico de la clase MonticuloMediciones
			 * @pre isEmpty() == false
			 */
			void remove();//ok
			/**
			 * @fn void removeMedition(int indice)
			 * @brief Borra la medicion que ocupa la posicion que se le ha pasado por argumentos
			 * @note Modificador publico de la clase MonticuloMediciones
			 * @pre isEmpty() == false
			 * @pre has(getElement(indice))
			 */
			void removeMedition(int indice);
			/**
			 * @fn void removeAll()
			 * @brief Borra todas las mediciones del montículo
			 * @note Modificador publico de la clase MonticuloMediciones
			 * @post isEmpty() == true
			 */
			void removeAll();//ok
			/**
			 * @fn void modify(ed::Medicion medicion)
			 * @brief Modifica la medicion que ocupa la cima y actualiza el monticulo para que este ordenado
			 * @param medicion Objeto de la clase Medicion a insertar en la cima
			 * @note Modificador publico de la clase MonticuloMediciones
			 * @pre isEmpty() == false
			 * @post has(medicion) == true
			 */
			void modify(ed::Medicion medicion);//ok
			/**
			 * @fn void modificarMedicion(int indice, ed::Medicion medicion)
			 * @brief Modifica la medicion que ocupa la cima y actualiza el monticulo para que este ordenado
			 * @param indice Posicion en la que se encuentra la medicion a modificar
			 * @param medicion Objeto de la clase Medicion que sustituye al que se encuentre en la posicion indice
			 * @note Modificador publico de la clase MonticuloMediciones
			 */
			void modificarMedicion(int indice, ed::Medicion medicion);
			/**
			 * @fn int busquedaMedicion(std::Fecha const & fecha)
			 * @brief Localiza la medicion con la fecha pasada por argumento
			 * @param fecha Fecha de la medicion
			 * @note Observador publico de la clase MonticuloMediciones
			 * @post Si valorDevuelto < 0 entonces has(medicion(fecha)) == false
			 * @post Si valorDevuelto >= 0 entonces has(medicion(fecha)) == true
			 */
			int busquedaMedicion(ed::Fecha const & fecha) const;
			/**
			 * @fn ed::Medicion obtenerElemento(int const & indice) const
			 * @brief Devulve un elemento del heap
			 * @param indice Indice en el que se encuentra el elemento
			 * @note Observador publico de la clase MonticuloMediciones
			 * @return Un objeto de la clase Medicion
			 */
			ed::Medicion obtenerElemento(int const & indice) const;
			//! \name Operadores
			/**
			 * @fn ed::MonticuloMediciones& operator=(ed::MonticuloMediciones & const m)
			 * @brief Devuelve el monticulo actual que ha sido modificado con las mediciones del monticulo m
			 * @param m Objeto de la clase MonticuloMediciones con el que se quiere igualar
			 * @note Operador sobrecargado de la clase MonticuloMediciones
			 * @pre *this != m
			 * @return Devuelve un objeto de la clase MonticuloMediciones
			 */
			ed::MonticuloMediciones& operator=(ed::MonticuloMediciones & m);//ok
			////////////////////////////////////////////////////////////////////
			//! \name Función de escritura
			/**
			 * @fn void print() const
			 * @brief Escribe las mediciones tal y como están almacenadas en el vector que representa el montículo
			 * @note Funcion de escritura pública de la clase MonticuloMediciones
			 * @note Funcion de tipo const
			 */
			void print() const;
	}; // Clase MonticuloMediciones
} // Espacio de nombres ed
#endif // _MONTICULO_MEDICIONES_HP
