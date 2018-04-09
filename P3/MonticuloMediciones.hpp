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
			ed::Medicion getElement(int i) const;
			void setElement(int i, Medicion medicion);
			int getLeftChild(int i) const;
			int getRightChild(int i) const;
			int getParent(int i) const;
			void shiftUp(int i);
			void shiftDown(int i);
			bool has(ed::Medicion medicion) const;
			/////////////////////////////////////////////////////////////////////////////////////

			//! \name Métodos públicos de la clase MonticuloMediciones
			public:
				//! \name Constructor
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
