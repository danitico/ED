#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include "clases/Graph.hpp"
namespace ed{
   void cargarVertices(Graph & grafo, std::string fichero);
   Graph prim_algorithm(Graph & grafo, float & coste_total);
   Graph kruskal_algorithm(Graph const & grafo);
}
#endif
