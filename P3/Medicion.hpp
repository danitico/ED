/*!
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica
*/
#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_
// Entrada y salida
#include <iostream>
// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>
// Definición de la clase Fecha
#include "Fecha.hpp"
#include "macros.hpp"
// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;
#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales
// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {
//!  Definición de la clase Medicion
class Medicion{
  //! \name Atributos privados de la clase Medicion
   private:
      ed::Fecha fecha_;
      float precipitacion_;
   //! \name Funciones o métodos públicos de la clase Medicion
   public:
	//! \name Constructor de la clase Medicion
      inline Medicion(ed::Fecha fecha=Fecha(1,1,1), float precipitacion=0.0);
      inline Medicion(ed::Medicion const & medicion);
   //! \name Observadores: funciones de consulta de la clase Medicion
      ed::Fecha getFecha() const{return fecha_;}
      float getPrecipitacion() const{return precipitacion_;}
	//! \name Funciones de modificación de la clase Medicion
      void setFecha(ed::Fecha fecha);
      void setPrecipitacion(float precipitacion);
	//! \name Operadores
      bool operator==(ed::Medicion const medicion) const;
      ed::Medicion &operator=(ed::Medicion const &medicion);
	//! \name Funciones de lectura y escritura de la clase Medicion
      void leerMedicion();
      void escribirMedicion();
}; // Fin de la definición de la clase Medicion
   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo
      ostream &operator<<(ostream &stream, ed::Medicion const &medicion);
      istream &operator>>(istream &stream, ed::Medicion &medicion);
} // \brief Fin de namespace ed.
#endif //  _MEDICION_HPP_
