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
  constexpr Test(Test&&) = delete;
  //constexpr Test(const Test& other) { throw 0; };
};

class IntConstThrow {
public:
  constexpr IntConstThrow(int x) { throw 0; }
};

class CopyConstThrow {
public:
  constexpr CopyConstThrow(int x) noexcept {}
  constexpr CopyConstThrow(const CopyConstThrow& other) { throw 0; }
};


int main()
{
  // デフォルトコンストラクタのテスト。
  std::cout << C<int>() << std::endl;
  static_assert(!noexcept(C<IntConstThrow>()), "");
  static_assert(noexcept(C<R<int>>()), "");

  // 要素型コンストラクタのテスト。
  static_assert(!noexcept(C<IntConstThrow>(3)), "");
  static_assert(!noexcept(C<CopyConstThrow>(3)), "");
  static_assert(noexcept(C<R<int>>(3)), "");
  std::cout << C<R<int>>(R<int>(1, 2)) << std::endl;

  static_assert(!noexcept(C<IntConstThrow>(3, 5)), "");
  static_assert(!noexcept(C<CopyConstThrow>(3, 5)), "");
  static_assert(noexcept(C<R<int>>(R<int>(3), R<int>(5))), "");
  std::cout << C<int>(1, 2) << std::endl;

  static_assert(C<R<int>>() == C<R<int>>(0), "");
  static_assert(C<int>(2) == C<int>(2, 0), "");

  //static_assert(!noexcept(C<Test>(C<Test>(0))), "");
  return 0;
}
