#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include "clases/Graph.hpp"
namespace ed{
   int menu();
   void cargarVertices(Graph & grafo, std::string fichero);
   void mostrarGrafo(Graph & grafo);
   void borrarGrafo(Graph & grafo);
   void BorrarVertice(Graph & grafo, Vertex a);
   void borrarLado(Graph & grafo, Vertex a, Vertex b);
   void modificarCosteConexion(Graph & grafo, Vertex a, Vertex b);
   void agnadirVertice(Graph & grafo, Punto & a);
   void caminoMasCorto(Graph & grafo, Punto & origen, Punto & destino);
   Graph prim_algorithm(Graph & grafo, float & coste_total);
   Graph kruskal_algorithm(Graph const & grafo, float & coste_total);
   void Dijkstra(ed::Graph & grafo, ed::Vertex comienzo, std::vector<float> & distancias, std::vector<int> & predecesor);
}
#endif
