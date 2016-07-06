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
   int max_iterations = 100; // failsafe max iterations in case of infinite loops

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

   std::cout << "== (shallow) iteration ====" << std::endl << "  ";
   Test::iterator it;
   for (it = a.begin(), i = 0; it != a.end() && i < max_iterations; ++it, ++i) {
      std::cout << *(*it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== const (shallow) iteration ====" << std::endl << "  ";
   Test::const_iterator c_it;
   for (c_it = a.begin(), i = 0; c_it != a.end() && i < max_iterations; ++c_it, ++i) {
      std::cout << *(*c_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== reverse (shallow) iteration ====" << std::endl << "  ";
   Test::reverse_iterator r_it;
   for (r_it = a.rbegin(), i = 0; r_it != a.rend() && i < max_iterations; ++r_it, ++i) {
      std::cout << *(*r_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== const reverse (shallow) iteration ====" << std::endl << "  ";
   Test::const_reverse_iterator c_r_it;
   for (c_r_it = a.rbegin(), i = 0; c_r_it != a.rend() && i < max_iterations; ++c_r_it, ++i) {
      std::cout << *(*c_r_it) << ' ';
   }
   std::cout << std::endl << std::endl;

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

   std::cout << "== reverse prefix iteration ====" << std::endl << "  ";
   Test::reverse_prefix_iterator r_pre_it;
   for (r_pre_it = a.rbegin(), i = 0; r_pre_it != a.rend() && i < max_iterations; ++r_pre_it, ++i) {
      std::cout << *(*r_pre_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== const reverse prefix iteration ====" << std::endl << "  ";
   Test::const_reverse_prefix_iterator c_r_pre_it;
   for (c_r_pre_it = a.rbegin(), i = 0; c_r_pre_it != a.rend() && i < max_iterations; ++c_r_pre_it, ++i) {
      std::cout << *(*c_r_pre_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== postfix iteration ====" << std::endl << "  ";
   Test::postfix_iterator post_it;
   for (post_it = a.begin(), i = 0; post_it != a.end() && i < max_iterations; ++post_it, ++i) {
      std::cout << *(*post_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== const postfix iteration ====" << std::endl << "  ";
   Test::const_postfix_iterator c_post_it;
   for (c_post_it = a.begin(), i = 0; c_post_it != a.end() && i < max_iterations; ++c_post_it, ++i) {
      std::cout << *(*c_post_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== reverse postfix iteration ====" << std::endl << "  ";
   Test::reverse_postfix_iterator r_post_it;
   for (r_post_it = a.rbegin(), i = 0; r_post_it != a.rend() && i < max_iterations; ++r_post_it, ++i) {
      std::cout << *(*r_post_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== const reverse postfix iteration ====" << std::endl << "  ";
   Test::const_reverse_postfix_iterator c_r_post_it;
   for (c_r_post_it = a.rbegin(), i = 0; c_r_post_it != a.rend() && i < max_iterations; ++c_r_post_it, ++i) {
      std::cout << *(*c_r_post_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== breadth iteration ====" << std::endl << "  ";
   Test::breadth_iterator breadth_it;
   for (breadth_it = a.begin(), i = 0; breadth_it != a.end() && i < max_iterations; ++breadth_it, ++i) {
      std::cout << *(*breadth_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== const breadth iteration ====" << std::endl << "  ";
   Test::const_breadth_iterator c_breadth_it;
   for (c_breadth_it = a.begin(), i = 0; c_breadth_it != a.end() && i < max_iterations; ++c_breadth_it, ++i) {
      std::cout << *(*c_breadth_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== reverse breadth iteration ====" << std::endl << "  ";
   Test::reverse_breadth_iterator r_breadth_it;
   for (r_breadth_it = a.rbegin(), i = 0; r_breadth_it != a.rend() && i < max_iterations; ++r_breadth_it, ++i) {
      std::cout << *(*r_breadth_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   std::cout << "== const reverse breadth iteration ====" << std::endl << "  ";
   Test::const_reverse_breadth_iterator c_r_breadth_it;
   for (c_r_breadth_it = a.rbegin(), i = 0; c_r_breadth_it != a.rend() && i < max_iterations; ++c_r_breadth_it, ++i) {
      std::cout << *(*c_r_breadth_it) << ' ';
   }
   std::cout << std::endl << std::endl;

   return 0;
}
