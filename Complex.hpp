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

  //デストラクタ。
  ~Complex() = default;
  //コピーコンストラクタとムーブコンストラクタ。
  constexpr Complex(const Complex& other) noexcept(noexcept(T(T(0)))) = default;
  //constexpr Complex(Complex&& other) noexcept = default;


public:
  //------------------------------
  //
  //  コピー代入演算子
  //
  //------------------------------
  constexpr Complex& operator =(const Complex& other) & noexcept {
    Complex<T> tmp(other);
    swap(tmp);
    return *this;
  }

  constexpr Complex&& operator =(const Complex& other) && noexcept = delete;


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


private:
  //------------------------------
  //
  //  swap関数
  //
  //------------------------------
  void swap(Complex& other) noexcept {
    using std::swap;
    swap(real, other.real);
    swap(imag, other.imag);
  }


protected:
  T real = static_cast<T>(0);
  T imag = static_cast<T>(0);
};

};  //namespace complex
};  //namespace math
#endif
