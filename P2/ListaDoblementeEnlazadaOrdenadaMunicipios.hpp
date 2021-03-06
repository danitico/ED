/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.hpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author Daniel Ranchal Parrado
	\date   26/03/2018
	\version 1.0
*/
#ifndef __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
#define __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
// Para comprobar las pre y post-condiciones
#include <cassert>
#include "ListaOrdenadaMunicipiosInterfaz.hpp"
#include "NodoDoblementeEnlazadoMunicipio.hpp"
#include "Municipio.hpp"
/*!
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{
/*!
  \class ListaDoblementeEnlazadaOrdenadaMunicipios
  \brief Definición de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
	  	\n Lista doblemente enlazada de nodos de municipios ordenados alfabéticamente de forma ascendente
*/
  class ListaDoblementeEnlazadaOrdenadaMunicipios: public ed::ListaOrdenadaMunicipiosInterfaz{
	//! \name  Atributos y métodos privados
	private:
		ed::NodoDoblementeEnlazadoMunicipio *_head;    //!< \brief puntero al primer nodo de la lista
		ed::NodoDoblementeEnlazadoMunicipio *_current; //!< \brief puntero al nodo current de la lista
		int _nitems; //!< \brief Contador de los elemen

    // \name Observadores privados

		inline ed::NodoDoblementeEnlazadoMunicipio * getHead() const{
			return this->_head;
		}

		inline ed::NodoDoblementeEnlazadoMunicipio * getCurrent() const{
			return this->_current;
		}

    //! \name Modificadores privados 4

		inline void setHead(ed::NodoDoblementeEnlazadoMunicipio *head){
			this->_head = head;

			#ifndef NDEBUG
				// Se comprueba la postcondición
				assert(this->getHead() == head);
			#endif //NDEBUG
		}

		inline void setCurrent(ed::NodoDoblementeEnlazadoMunicipio *current){
		this->_current = current;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getCurrent() == current);
		#endif //NDEBUG
		}
	//! \name  Métodos públicos
	public:
		//! \name Constructores

		/*!
		\brief Construye una lista vacía
		\note  Función inline
		\post  isEmpty() == true
		*/
		inline ListaDoblementeEnlazadaOrdenadaMunicipios(){
			setHead(NULL);
			setCurrent(NULL);
			_nitems=0;

			#ifndef NDEBUG
			assert(isEmpty());
			#endif
		}
	//! \name Destructor

		/*!
		\brief Destruye una lista liberando la memoria de sus nodos
		\note Función codificada en el fichero cpp
		\post isEmpty() == true
		*/
		~ListaDoblementeEnlazadaOrdenadaMunicipios(){
			if(getHead()!=NULL){
				setCurrent(_head->getNext());
				_head=NULL;
				while(_current){
					delete _current->getPrevious();
					setCurrent(_current->getNext());
				}
			}

			#ifndef NDEBUG
			assert(isEmpty());
			#endif
		}

	//! \name Observadores públicos
		bool isEmpty() const;
      inline int nItems() const{return _nitems;}
      bool isFirstItem() const;
      bool isLastItem() const;
      ed::Municipio const & getCurrentItem() const;
		ed::Municipio const & getPreviousItem() const;
		ed::Municipio const & getNextItem() const;

		//! \name Modificadores públicos

		void gotoHead();
		void gotoLast();
		void gotoPrevious();
		void gotoNext();
      /**
       * @fn void setNewCurrent(ed::Municipio const & item)
       * @brief Sustituye el _item de _current por item
       * @post getCurrentItem()==item
       * @sa getCurrent(), setItem()
       */
      void setNewCurrent(ed::Municipio const & item);
		bool find(ed::Municipio const & item);
		void insert(ed::Municipio const & item);
		void remove();
      /**
       * @fn void removeAll()
       * @brief Borra todos los nodos de la lista
       * @post isEmpty()==true
       */
		void removeAll();
}; // Fin de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
} //namespace ed
#endif // __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
