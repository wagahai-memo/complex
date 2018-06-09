#include <iostream>
#include "Complex.hpp"
#include "../rational/Rational.hpp"

template <typename T>
using C = math::complex::Complex<T>;

template <typename T>
using R = math::rational::Rational<T>;


int main()
{
  std::cout << C<R<int>>() << std::endl;
  return 0;
}
