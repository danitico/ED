#include <iostream>
#include "./clases/Graph.hpp"
#include "funcionesAuxiliares.hpp"
int main(){
   ed::Graph a,b;
   ed::cargarVertices(a, "vertices.txt");

   b=ed::prim_algorithm(a);
}
