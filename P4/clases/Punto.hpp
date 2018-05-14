/*!
   \file Punto.hpp
   \brief Fichero de la clase Punto
   \author Daniel Ranchal Parrado
   \date
*/
#ifndef PUNTO_HPP
#define PUNTO_HPP
#include <cmath>
using std::istream;
using std::ostream;
#define COTA_ERROR 1.0e-6
namespace ed{
   class Punto{
      //! @name Atributos de la clase Punto
      private:
         float x_;
         float y_;
      //! @name Funciones o metodos publicos de la clase Punto
      public:
         //! @name Constructores de la clase Punto
         Punto(float x=0.0, float y=0.0){
            this->setX(x);
            this->setY(y);
         }
         Punto(Punto const &p){
            this->setX(p.getX());
            this->setY(p.getY());
         }
         //! @name Observadores de la clase Punto
         inline float getX() const{return x_;}
         inline float getY() const{return y_;}
         //! @name Modificadores de la clase Punto
         inline void setX(float const &x){x_=x;}
         inline void setY(float const &y){y_=y;}
         //! @name Operadores
         Punto & operator=(Punto const &p);
         bool operator==(Punto const &p);
         void leerPunto();
         void escribirPunto();
   };
   float distancia(Punto const &p1, Punto const &p2);
}
#endif
