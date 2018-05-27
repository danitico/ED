#include <vector>
#include "../clases/Vertex.hpp"
#include "../clases/Edge.hpp"
#include "../clases/Punto.hpp"
#include "../clases/Graph.hpp"
#include "../funcionesAuxiliares.hpp"
#include "gtest/gtest.h"
TEST(Vertex, ComprobarObservadoresyModificadores) {
   ed::Punto a1(2.1, 2.3);
   ed::Punto b1(3.1, 3.2);

   ed::Vertex a;
   ed::Vertex b;

   a.setData(a1);
   b.setData(b1);

   EXPECT_EQ(a1, a.getData());
   EXPECT_EQ(b1, b.getData());
   EXPECT_EQ(a.getData()==b.getData(), false);
   EXPECT_EQ(a==b, false);
   EXPECT_EQ(a!=b, true);

   a.setData(b1);

   EXPECT_EQ(b1, a.getData());
   EXPECT_EQ(a==b, true);
   EXPECT_EQ(a!=b, false);
}

TEST(Edge, ObservadoresyModificadores) {
   ed::Edge e1;
   ed::Edge e2;

   ed::Punto v1(2.1, 2.3);
   ed::Punto v2(3.1, 3.2);
   ed::Punto v3(4.1, 4.2);
   ed::Punto v4(5.1, 5.2);

   ed::Vertex a; a.setData(v1); a.setLabel(1);
   ed::Vertex b; b.setData(v2); b.setLabel(2);
   ed::Vertex c; c.setData(v3); c.setLabel(3);
   ed::Vertex d; d.setData(v4); d.setLabel(4);


   e1.setData(200); e1.setFirstVertex(a); e1.setSecondVertex(b);
   EXPECT_EQ(e1.getData(), 200);
   EXPECT_EQ(e1.first(), a);
   EXPECT_EQ(e1.second(), b);
   EXPECT_EQ(e1.has(a), true);
   EXPECT_EQ(e1.has(b), true);
   EXPECT_EQ(e1.other(a)==b, true);
   EXPECT_EQ(e1.other(b)==a, true);
   EXPECT_EQ(e1.other(e1.other(a))==a, true);
   EXPECT_EQ(e1.other(e1.other(b))==b, true);

   e2.setData(150); e2.setFirstVertex(c); e2.setSecondVertex(d);
   EXPECT_EQ(e2.getData(), 150);
   EXPECT_EQ(e2.first()==c, true);
   EXPECT_EQ(e2.second()==d, true);
   EXPECT_EQ(e2.has(c), true);
   EXPECT_EQ(e2.has(d), true);
   EXPECT_EQ(e2.other(c)==d, true);
   EXPECT_EQ(e2.other(d)==c, true);
   EXPECT_EQ(e2.other(e2.other(c))==c, true);
   EXPECT_EQ(e2.other(e2.other(d))==d, true);
}

TEST(Graph, Constructor){
   ed::Graph a;

   EXPECT_EQ(a.isEmpty(), true);
}

TEST(Graph, VertexStuff){
   ed::Graph a;

   a.addVertex(ed::Punto(0.0, 0.0));
   a.addVertex(ed::Punto(0.0, 1.0));
   a.addVertex(ed::Punto(3.0, 1.0));
   a.addVertex(ed::Punto(3.0, 3.0));
   a.addVertex(ed::Punto(8.0, 1.0));

   EXPECT_EQ(a.getVertexVector().size(), 5);
   for(int i=0; i<5; i++){
      EXPECT_EQ(a.getVertexVector()[i].getLabel(), i);
   }

   EXPECT_EQ(a.getVertexVector()[0].getData(), ed::Punto(0.0, 0.0));
   EXPECT_EQ(a.getVertexVector()[1].getData(), ed::Punto(0.0, 1.0));
   EXPECT_EQ(a.getVertexVector()[2].getData(), ed::Punto(3.0, 1.0));
   EXPECT_EQ(a.getVertexVector()[3].getData(), ed::Punto(3.0, 3.0));
   EXPECT_EQ(a.getVertexVector()[4].getData(), ed::Punto(8.0, 1.0));

   EXPECT_EQ(a.getCurrentVertex(), 4);
   EXPECT_EQ(a.hasCurrVertex(), true);
   EXPECT_EQ(a.currVertex(), a.getVertexVector()[4]);
}

TEST(Graph, EdgeStuff){
   ed::Graph a;

   ed::cargarVertices(a, "vertices.txt");

   int suma=0;
   for(int i=1; i<5; i++){
      suma+=(5-i);
   }

   EXPECT_EQ(a.getEdgeVector().size(), suma);
   EXPECT_EQ(a.getMatrix().size(), 5);
   for(int i=0; i<5; i++){
      EXPECT_EQ(a.getMatrix()[i].size(), 5);
   }

   EXPECT_EQ(a.isDirected(), false);
   // for(int i=0; i<5; i++){
   //    for(int j=0; j<5; j++){
   //       std::cout<<a.getMatrix()[i][j]<<" ";
   //    }
   //    std::cout<<'\n';
   // }

   for(int i=0; i<5; i++){
      for(int j=i+1; j<5; j++){
         EXPECT_EQ(a.adjacent(a.getVertexVector()[i], a.getVertexVector()[j]), true);
         EXPECT_EQ(a.adjacent(a.getVertexVector()[j], a.getVertexVector()[i]), true);
      }
   }
}

TEST(Graph, BorrarVertice){
   ed::Graph a;

   a.addVertex(ed::Punto(0.0, 0.0));
   a.addVertex(ed::Punto(0.0, 1.0));
   a.addVertex(ed::Punto(3.0, 1.0));
   a.addVertex(ed::Punto(3.0, 3.0));
   a.addVertex(ed::Punto(8.0, 1.0));

   for(int i=0; i<5; i++){
      for(int j=i+1; j<5; j++){
         a.addEdge(a.getVertexVector()[i], a.getVertexVector()[j], ed::distancia(a.getVertexVector()[i].getData(), a.getVertexVector()[j].getData()));
      }
   }

   a.removeVertex();
   EXPECT_EQ(a.getVertexVector().size(), 4);
   EXPECT_EQ(a.getEdgeVector().size(), 6);
   EXPECT_EQ(a.getMatrix().size(), 4);
   EXPECT_EQ(a.getEtiquetas(), 4);
   EXPECT_EQ(a.getCurrentVertex(), 3);

   ed::Graph b;

   b.addVertex(ed::Punto(0.0, 0.0));
   b.addVertex(ed::Punto(0.0, 1.0));
   b.addVertex(ed::Punto(3.0, 1.0));

   for(int i=0; i<3; i++){
      for(int j=i+1; j<3; j++){
         b.addEdge(b.getVertexVector()[i], b.getVertexVector()[j], ed::distancia(b.getVertexVector()[i].getData(), b.getVertexVector()[j].getData()));
      }
   }

   ed::Vertex c;
   c.setData(ed::Punto(0.0, 1.0));
   b.gotoVertex(c);

   b.removeVertex();
   EXPECT_EQ(b.getVertexVector().size(), 2);
   EXPECT_EQ(b.getEdgeVector().size(), 1);
   EXPECT_EQ(b.getMatrix().size(), 2);
   EXPECT_EQ(b.getEtiquetas(), 2);
   EXPECT_EQ(b.getCurrentVertex(), 1);
}

TEST(Graph, BorrarLado){
   ed::Graph b;

   b.addVertex(ed::Punto(0.0, 0.0));
   b.addVertex(ed::Punto(0.0, 1.0));
   b.addVertex(ed::Punto(3.0, 1.0));

   for(int i=0; i<3; i++){
      for(int j=i+1; j<3; j++){
         b.addEdge(b.getVertexVector()[i], b.getVertexVector()[j], ed::distancia(b.getVertexVector()[i].getData(), b.getVertexVector()[j].getData()));
      }
   }

   ed::Vertex c,d;
   c.setData(ed::Punto(0.0, 0.0));
   d.setData(ed::Punto(0.0, 1.0));
   b.gotoEdge(c, d);

   b.removeEdge();
   EXPECT_EQ(b.getVertexVector().size(), 3);
   EXPECT_EQ(b.getEdgeVector().size(), 2);
   EXPECT_EQ(b.getMatrix().size(), 3);
   EXPECT_EQ(b.getEtiquetas(), 3);
   EXPECT_EQ(b.getCurrentEdge(), -1);

   // for(int i=0; i<3; i++){
   //    for(int j=0; j<3; j++){
   //       std::cout<<b.getMatrix()[i][j]<<" ";
   //    }
   //    std::cout<<'\n';
   // }
}

TEST(Graph, CursorVertice){
   ed::Graph a;

   a.addVertex(ed::Punto(0.0, 0.0));
   a.addVertex(ed::Punto(0.0, 1.0));
   a.addVertex(ed::Punto(3.0, 1.0));
   a.addVertex(ed::Punto(3.0, 3.0));
   a.addVertex(ed::Punto(8.0, 1.0));

   ed::Vertex b;

   b.setData(ed::Punto(0.0, 0.0));
   a.gotoVertex(b);
   EXPECT_EQ(a.getCurrentVertex(), 0);

   b.setData(ed::Punto(0.0, 1.0));
   a.gotoVertex(b);
   EXPECT_EQ(a.getCurrentVertex(), 1);

   b.setData(ed::Punto(3.0, 1.0));
   a.gotoVertex(b);
   EXPECT_EQ(a.getCurrentVertex(), 2);

   b.setData(ed::Punto(3.0, 3.0));
   a.gotoVertex(b);
   EXPECT_EQ(a.getCurrentVertex(), 3);

   b.setData(ed::Punto(8.0, 1.0));
   a.gotoVertex(b);
   EXPECT_EQ(a.getCurrentVertex(), 4);

   b.setData(ed::Punto(8.0, 17.0));
   a.gotoVertex(b);
   EXPECT_EQ(a.getCurrentVertex(), -1);

   a.goToFirstVertex();
   EXPECT_EQ(a.getVertexVector()[0], a.getVertexVector()[a.getCurrentVertex()]);
   EXPECT_EQ(a.getCurrentVertex(), 0);

   for(int i=0; i<5; i++){
      if(i==4){
         a.nextVertex();
         EXPECT_EQ(a.getCurrentVertex(), -1);
      }
      else{
         a.nextVertex();
         EXPECT_EQ(a.getCurrentVertex(), i+1);
      }
   }
}

TEST(Graph, CursoLados){
   ed::Vertex b, c, d;
   b.setData(ed::Punto(0.0, 0.0));
   c.setData(ed::Punto(0.0, 1.0));
   d.setData(ed::Punto(3.0, 1.0));
   ed::Graph a;

   a.addVertex(ed::Punto(0.0, 0.0));
   a.addVertex(ed::Punto(0.0, 1.0));
   a.addVertex(ed::Punto(3.0, 1.0));

   for(int i=0; i<3; i++){
      for(int j=i+1; j<3; j++){
         a.addEdge(a.getVertexVector()[i], a.getVertexVector()[j], ed::distancia(a.getVertexVector()[i].getData(), a.getVertexVector()[j].getData()));
      }
   }

   a.gotoEdge(b, c);
   EXPECT_EQ(a.getCurrentEdge(), 0);

   a.gotoEdge(b, d);
   EXPECT_EQ(a.getCurrentEdge(), 1);

   a.gotoEdge(c, d);
   EXPECT_EQ(a.getCurrentEdge(), 2);

   a.goToFirstEdge();
   EXPECT_EQ(a.getCurrentEdge(), 0);

   for(int i=0; i<3; i++){
      if(i==2){
         a.nextEdge();
         EXPECT_EQ(a.getCurrentEdge(), -1);
      }
      else{
         a.nextEdge();
         EXPECT_EQ(a.getCurrentEdge(), i+1);
      }
   }
}

TEST(Graph, Prim){
   ed::Graph a,b;

   ed::cargarVertices(a, "vertices.txt");

   for(int i=0; i<5; i++){
      a.getVertexVector()[i].getData().escribirPunto();
   }

   //b=ed::prim_algorithm(a);


}
