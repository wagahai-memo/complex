#ifndef MATH_COMPLEX_HPP_
#define MATH_COMPLEX_HPP_
#include <ostream>


namespace math {
namespace complex {

template <typename T>
class Complex {
public:
  friend std::ostream& operator <<(std::ostream& os, const Complex& x) {
    return os << x.real << "+" << x.imag << "i";
  }


public:
  //------------------------------
  //
  //  コンストラクタ
  //
  //------------------------------
  //デフォルトコンストラクタ。要素型の零を引数にとるコンストラクタがnoexceptなら、noexcept。
  constexpr Complex() noexcept(noexcept(T(0))) {}
  //コンストラクタ。要素型のコピーコンストラクタがnoexceptならnoexcept。
  constexpr Complex(T r) noexcept(noexcept(T(T(0)))) : real(r) {}
  constexpr Complex(T r, T i) noexcept(noexcept(T(T(0)))) : real(r), imag(i) {}
  //コピーコンストラクタ。
  constexpr Complex(const Complex& other) noexcept = default;


public:
  //------------------------------
  //
  //  論理演算子
  //
  //------------------------------
  constexpr bool operator ==(const Complex& rhs) const {
    return real == rhs.real && imag == rhs.imag;
  }

  constexpr bool operator !=(const Complex& rhs) const {
    return !(*this == rhs);
  }


protected:
  T real = static_cast<T>(0);
  T imag = static_cast<T>(0);
};

};  //namespace complex
};  //namespace math
#endif
