#include <cassert>
#include <iostream>

#include "cord-utilities.hpp"
#include "cord.hpp"

int main() {
  std::shared_ptr<Cord> cord_1 = std::make_shared<Cord>("CS12");
  std::shared_ptr<Cord> cord_2 = std::make_shared<Cord>("8 is awe");
  std::shared_ptr<Cord> cord_3 = std::make_shared<Cord>("some");
  std::shared_ptr<Cord> cord_4 = std::make_shared<Cord>(cord_2, cord_3);
  std::shared_ptr<Cord> cord_5 = std::make_shared<Cord>(cord_1, cord_4);

  // ToString test
  std::cout << cord_5->ToString() << std::endl;

  // SubString tests
  std::cout << cord_1->SubString(0, 4)->ToString() << std::endl;
  std::cout << cord_2->SubString(0, 1)->ToString() << std::endl;
  std::cout << cord_5->SubString(0, 4)->ToString() << std::endl;
  std::shared_ptr<Cord> sub = cord_5->SubString(0, 16);
  std::cout << sub->ToString() << std::endl;

  // concat tests
  std::cout << ConcatCords(ConcatCords(cord_1, cord_2), cord_3)->ToString()
            << std::endl;
  std::shared_ptr<Cord> cord_6 = std::make_shared<Cord>(cord_1, nullptr);
  std::cout << ConcatCords(ConcatCords(cord_6, cord_2), cord_3)->ToString()
            << std::endl;

  std::cout << "Placeholder" << std::endl;
}
