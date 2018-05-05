#include <vector>
#include "../clases/Vertex.hpp"
#include "gtest/gtest.h"

TEST(Vertex, ComprobarObservadoresyModificadores) {
   std::vector<float> v1;
   v1.push_back(2.1);
   v1.push_back(2.3);
   std::vector<float> v2;
   v2.push_back(3.1);
   v2.push_back(3.2);
   ed::Vertex a;
   ed::Vertex b;

  a.setData(v1);
  b.setData(v2);

  EXPECT_EQ(v1, a.getData());
  EXPECT_EQ(v2, b.getData());
  EXPECT_EQ(a==b, false);
  EXPECT_EQ(a!=b, true);

  a.setData(v2);

  EXPECT_EQ(v2, a.getData());
  EXPECT_EQ(a==b, true);
  EXPECT_EQ(a!=b, false);
}
