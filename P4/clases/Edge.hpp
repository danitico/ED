/*!
   \file Edge.hpp
   \brief Fichero de la clase Edge
   \author Daniel Ranchal Parrado
   \date
*/
#ifndef EDGE_HPP
#define EDGE_HPP
#include "Vertex.hpp"
namespace ed{
   class Edge{
      //! @name Atributos de la clase Edge
      private:
         float distancia_;//!< Variable flotante que representa la distancia entre dos vertices
         Vertex inicio;//!< Primer vertice del segmento
         Vertex fin;//!< Segundo vertice del segmento
      //! @name Métodos públicos de la clase Edge
      public:
         //! @name Observadores de la clase Edge
         /**
          * @fn inline float getData() const
          * @brief Devuelve el atributo privado distancia_
          * @note Observador de la clase Edge
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve la distancia entre los dos vertices
          */
         inline float getData() const{return distancia_;}
         /**
          * @fn bool has(Vertex u) const
          * @brief Dice si el objeto Vertex se encuentra en el lado
          * @note Observador de la clase Edge
          * @note Funcion de tipo const
          * @return Devuelve true si el parametro es uno de los vertices, y false en el caso contrario
          */
         bool has(Vertex u) const;
         Vertex other(Vertex u) const;
         inline Vertex first() const;
         inline Vertex second() const;
         //! @name Modificadores de la clase Edge
         inline void setData(float distancia){distancia_=distancia}
         
   }
}
