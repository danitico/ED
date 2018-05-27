#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include "clases/Graph.hpp"
namespace ed{
   void cargarVertices(ed::Graph & grafo, std::string fichero);
   ed::Graph prim_algorithm(ed::Graph & grafo);
   ed::Graph kruskal_algorithm(ed::Graph const & grafo);
}
#endif
