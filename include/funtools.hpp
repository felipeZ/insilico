#ifndef FUNTOOLS_H_
#define FUNTOOLS_H_

#include <functional>
using std::function;

namespace insilico {

// Variadic template for currying
template<typename Func, typename... Args>
auto curry(Func func, Args... args){
  return [=](auto... lastParam)
	 {return func(args..., lastParam...);
	 };
}

// function composition
template <typename A, typename B, typename C>
  function<C(A)> compose(function<C(B)> f, function<B(A)> g) {
  return [f,g](A x) {
    return f(g(x));
  };
}

} // end namespace
#endif // FUNTOOLS_H_
