/*!
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica
*/
#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_
// Entrada y salida
#include <iostream>
#include <stdlib.h>
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
      ed::Fecha fecha_; //!< Objeto de tipo Fecha que representa la fecha de la medicion
      float precipitacion_; //!< Flotante no negativo que representa la cantidad de lluvia
   //! \name Funciones o métodos públicos de la clase Medicion
   public:
	//! \name Constructor de la clase Medicion
      /**
       * @fn inline Medicion(ed::Fecha fecha=Fecha(1,1,1), float precipitacion=0.0)
       * @brief Inicializa un objeto de la clase Medicion
       * @param fecha Objeto de tipo fecha cuyo valor por defecto es Fecha(1,1,1)
       * @param precipitacion Variable de tipo flotante cuyo valor por defecto es 0.0
       * @note Constructor de la clase Medicion
       * @note Función de tipo inline
       * @post getFecha() == fecha
       * @post getPrecipitacion() == precipitacion
       */
      inline Medicion(ed::Fecha fecha=Fecha(1,1,1), float precipitacion=0.0){
         this->setFecha(fecha);
         this->setPrecipitacion(precipitacion);

         #ifndef NDEBUG
         assert(getFecha()==fecha && abs(getPrecipitacion()-precipitacion)<=COTA_ERROR);
         #endif
      }
      /**
       * @fn inline Medicion(const ed::Medicion & medicion)
       * @brief Copia un objeto de tipo Medicion en otro
       * @param medicion Objeto de la clase Medicion
       * @note Constructor de copia de la clase Medicion
       * @note Función de tipo inline
       * @post getFecha() == medicion.getFecha()
       * @post getPrecipitacion() == medicion.getPrecipitacion()
       */
      inline Medicion(const ed::Medicion & medicion){
         this->setFecha(medicion.getFecha());
         this->setPrecipitacion(medicion.getPrecipitacion());

         #ifndef NDEBUG
         assert(getFecha()==medicion.getFecha() && abs(getPrecipitacion()-medicion.getPrecipitacion())<=COTA_ERROR);
         #endif
      }
   //! \name Observadores: funciones de consulta de la clase Medicion
      /**
       * @fn ed::Fecha getFecha() const
       * @brief Devuelve el atributo privado fecha_
       * @note Observador de la clase Medicion
       * @note Funcion de tipo const
       * @return Devuelbe un objeto de la clase Fecha
       */
      ed::Fecha getFecha() const{return fecha_;}
      /**
       * @fn float getPrecipitacion() const
       * @brief Devuelve el atributo privado precipitacion_
       * @note Observador de la clase Medicion
       * @note Funcion de tipo const
       * @return Devuelve una variable de tipo Float
       */
      float getPrecipitacion() const{return precipitacion_;}
	//! \name Funciones de modificación de la clase Medicion
      /**
       * @fn void setFecha(ed::Fecha fecha)
       * @brief Modifica el atributo privado fecha_
       * @param fecha El nuevo valor del atributo privado fecha_
       * @note Modificador de la clase Medicion
       * @post getFecha() == fecha
       */
      void setFecha(ed::Fecha fecha);
      /**
       * @fn void setPrecipitacion(float precipitacion)
       * @brief Modifica el atributo privado precipitacion_
       * @param precipitacion El nuevo valor del atributo privado precipitacion_
       * @note Modificador de la clase Medicion
       * @post getPrecipitacion() == precipitacion
       */
      void setPrecipitacion(float precipitacion);
	//! \name Operadores
      /**
       * @fn bool operator==(ed::Medicion const medicion) const
       * @brief Compara la fechas de las mediciones
       * @param medicion Objeto de la clase Medicion
       * @note Operador sobrecargado de la clase Medicion
       * @post valorDevuelto == (getFecha() == medicion.getFecha())
       * @return Devuelve true si las fechas son iguales,y false en el caso contrario
       */
      bool operator==(ed::Medicion const medicion) const;
      /**
       * @fn ed::Medicion &operator=(ed::Medicion const &medicion)
       * @brief Iguala el objeto *this al objeto pasado por argumentos
       * @param medicion Objeto de la clase Medicion
       * @note Operador sobrecargado de la clase Medicion
       * @post getFecha() == medicion.getFecha()
       * @post getPrecipitacion() == medicion.getPrecipitacion()
       * @return Devuelve un objeto de la clase Medicion
       */
      ed::Medicion &operator=(ed::Medicion const &medicion);
	//! \name Funciones de lectura y escritura de la clase Medicion
      /**
       * @fn void leerMedicion()
       * @brief Lee una medida por teclado
       */
      void leerMedicion();
      /**
       * @fn void escribirMedicion()
       * @brief Escribe la medicion en pantalla
       * @warning Se escribe con el siguiente formato dia-mes-año precipitacion
       */
      void escribirMedicion();
}; // Fin de la definición de la clase Medicion
   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo
      /**
       * @fn ostream &operator<<(ostream &stream, ed::Medicion const &medicion)
       * @brief Operador para mostrar por pantalla un objeto de tipo Medicion
       * @param stream Objeto de la clase ostream
       * @param medicion Objeto de la clase Medicion pasado por referencia
       * @note Operador << sobrecargado de la clase Medicion
       * @return Devuelve un objeto de la clase ostream
       */
      ostream &operator<<(ostream &stream, ed::Medicion const &medicion);
      /**
       * @fn istream &operator>>(istream &stream, ed::Medicion &medicion)
       * @brief Operador para introducir por pantalla un objeto de tipo Medicion
       * @param stream Objeto de la clase istream
       * @param medicion Objeto de la clase Medicion pasado por referencia
       * @note Operador >> sobrecargado de la clase Medicion
       * @return Devuelve un objeto de la clase istream
       */
      istream &operator>>(istream &stream, ed::Medicion &medicion);
} // \brief Fin de namespace ed.
#endif //  _MEDICION_HPP_
