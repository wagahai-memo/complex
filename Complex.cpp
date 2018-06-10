#include <iostream>
#include "Complex.hpp"
#include "../rational/Rational.hpp"

template <typename T>
using C = math::complex::Complex<T>;

template <typename T>
using R = math::rational::Rational<T>;

class Test {
public:
  //constexpr Test(int x) { throw 0; }
  constexpr Test(int x) {}
  constexpr Test(const Test& other) { throw 0; };
};


int main()
{
  std::cout << C<int>() << std::endl;
  std::cout << C<R<int>>(R<int>(1, 2)) << std::endl;
  std::cout << C<int>(1, 2) << std::endl;
  static_assert(C<R<int>>() == C<R<int>>(0), "");
  static_assert(C<int>(2) == C<int>(2, 0), "");
  //static_assert(!noexcept(C<Test>()), "");
  //static_assert(noexcept(C<R<int>>()), "");
  static_assert(!noexcept(C<Test>(3)), "");
  static_assert(noexcept(C<R<int>>(3)), "");
  static_assert(!noexcept(C<Test>(3, 5)), "");
  static_assert(noexcept(C<R<int>>(R<int>(3), R<int>(5))), "");
  return 0;
}
