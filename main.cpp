#include <iostream>
#include "Composite.h"

class Test : public Composite<Test> {
public:
   Test(std::string id) : id(std::move(id)) {}

   friend std::ostream& operator<<(std::ostream& os, const Test& t);

protected:
   std::string id;
};

std::ostream& operator<<(std::ostream& os, const Test& t) {
   os << t.id;
   return os;
}

int main() {
   int i = 0;
   int max_iterations = 10; // failsafe max iterations in case of infinite loops

   Test a("ScottPilgrim");
   Test b("RamonaFlowers");
   Test c("KnivesChau");
   Test d("GideonGraves");
   Test e("EnvyAdams");
   Test f("KimPine");
   Test g("StevenStills");

   a.add(&b);
   a.add(&c);

   b.add(&d);
   
   c.add(&f);

   d.add(&e);
   d.add(&g);

   std::cout << "== prefix iteration ====" << std::endl << "  ";
   Test::prefix_iterator pre_it;
   for (pre_it = a.begin(), i = 0; pre_it != a.end() && i < max_iterations; ++pre_it, ++i) {
      std::cout << *(*pre_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== const prefix iteration ====" << std::endl << "  ";
   Test::const_prefix_iterator c_pre_it;
   for (c_pre_it = a.begin(), i = 0; c_pre_it != a.end() && i < max_iterations; ++c_pre_it, ++i) {
      std::cout << *(*c_pre_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== postfix iteration ====" << std::endl << "  ";
   Test::postfix_iterator post_it;
   for (post_it = a.begin(), i = 0; post_it != a.end() && i < max_iterations; ++post_it, ++i) {
      std::cout << *(*post_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== breadth iteration ====" << std::endl << "  ";
   Test::breadth_iterator breadth_it;
   for (breadth_it = a.begin(), i = 0; breadth_it != a.end() && i < max_iterations; ++breadth_it, ++i) {
      std::cout << *(*breadth_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   return 0;
}
