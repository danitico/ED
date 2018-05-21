#include <vector>
#include "../clases/Vertex.hpp"
#include "../clases/Edge.hpp"
#include "../clases/Punto.hpp"
#include "gtest/gtest.h"
TEST(Vertex, ComprobarObservadoresyModificadores) {
   // std::vector<float> v1;
   // v1.push_back(2.1);
   // v1.push_back(2.3);
   // std::vector<float> v2;
   // v2.push_back(3.1);
   // v2.push_back(3.2);
   ed::Punto a1(2.1, 2.3);
   ed::Punto b1(3.1, 3.2);

   ed::Vertex a;
   ed::Vertex b;

   a.setData(a1);
   b.setData(b1);

   EXPECT_EQ(a1, a.getData());
   EXPECT_EQ(b1, b.getData());
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

   // std::vector<float> v1;
   // v1.push_back(2.1);
   // v1.push_back(2.3);
   // std::vector<float> v2;
   // v2.push_back(3.1);
   // v2.push_back(3.2);
   // std::vector<float> v3;
   // v3.push_back(4.1);
   // v3.push_back(4.2);
   // std::vector<float> v4;
   // v4.push_back(5.1);
   // v4.push_back(5.2);
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
