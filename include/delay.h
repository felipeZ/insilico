#ifndef INSILICO_DELAY_H_
#define INSILICO_DELAY_H_

template<class T> class Delay {
 private:
  function<T()> m_func;

 public:
 Delay(function<T()> func) : m_func(func) {}

  T Fetch() {
    return m_func();
  }
};

#endif // INSILICO_DELAY_H_
