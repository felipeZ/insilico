#ifndef FUNTOOLS_H_
#define FUNTOOLS_H_


// Variadic template for currying
template<typename Func, typename... Args>
auto curry(Func func, Args... args){
  return [=](auto... lastParam)
	 {return func(args..., lastParam...);
	 };
}
#endif // FUNTOOLS_H_
