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

protected:
  T real = static_cast<T>(0);
  T imag = static_cast<T>(0);
};

};  //namespace complex
};  //namespace math
#endif
