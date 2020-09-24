#ifndef STATEMENT_HPP
#define STATEMENT_HPP
#include <iostream>
#include <vector>
#include <forward_list>
#include <cstring>

void task1(const char* sort_type);
void task2(const char* filename);
void task3();
void task4(const char* sort_type, const char* array_size);

namespace detail
{
  template <typename T>
  bool more(T a, T b)
  {
    return a > b;
  }

  template <typename T>
  bool less(T a, T b)
  {
    return a < b;
  }

  template <typename C>
  struct bracketAccess
  {
    typedef std::size_t indexType;
    static typename C::reference getElement(C& cont, indexType i)
    {
      return cont[i];
    };
    static indexType getBegin(const C&)
    {
      return 0;
    };
    static indexType getEnd(const C& cont)
    {
      return cont.size();
    };
  };

  template <typename C>
  struct atAccess
  {
    typedef typename C::size_type indexType;
    static typename C::reference getElement(C& cont, indexType i)
    {
      return cont.at(i);
    };
    static indexType getBegin(C&)
    {
      return 0;
    };
    static indexType getEnd(const C& cont)
    {
      return cont.size();
    };
  };

  template <typename C>
  struct iteratorAccess
  {
    typedef typename C::iterator indexType;
    static typename C::reference getElement(C&, indexType i)
    {
      return *i;
    };
    static indexType getBegin(C& cont)
    {
      return cont.begin();
    };
    static indexType getEnd(C& cont)
    {
      return cont.end();
    };
  };

  template <template <typename C> class Traits, typename C>
  void sort(C& cont, bool(*compare)(typename C::value_type&, typename C::value_type&))
  {
    typedef typename Traits<C>::indexType index;
    for (index i = Traits<C>::getBegin(cont); i != Traits<C>::getEnd(cont); i++)
    {
      for (index j = i; j != Traits<C>::getEnd(cont); j++)
      {
        if (compare(Traits<C>::getElement(cont, i), Traits<C>::getElement(cont, j)))
        {
          std::swap(Traits<C>::getElement(cont, i), Traits<C>::getElement(cont, j));
        }
      }
    }
  }

  template <typename C>
  void printCont(const C& cont)
  {
    for (typename C::const_iterator it = cont.begin(); it != cont.end(); it++)
    {
      std::cout << *it << " ";
    }
    std::cout << "\n";
  }
}
#endif