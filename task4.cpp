#include <random>
#include <ctime>
#include <string>

#include "statement.hpp"

void fillRandom(double *array, int size)
{
  std::mt19937 Rng(time(0));
  std::uniform_real_distribution<double> distr(-1.0, 1.0);
  for (int i = 0; i < size; i++)
  {
    array[i] = distr(Rng);
  }
}

void task4(const char* sort_type, const char* array_size)
{
  int size = atoi(array_size);
  if (size == 0)
  {
    throw std::invalid_argument("Wrong size of this array !");
  }

  std::vector<double> vec(size);
  fillRandom(&vec[0], size);

  bool(*comp) (double&, double&) = nullptr;
  if (std::strcmp(sort_type, "ascending") == 0)
  {
    comp = detail::more;
  }
  else if (std::strcmp(sort_type, "descending") == 0)
  {
    comp = detail::less;
  }
  else
  {
    throw std::invalid_argument("Wrong sort type parameter.");
  }

  detail::printCont<std::vector<double> >(vec);
  detail::sort<detail::bracketAccess, std::vector<double> >(vec, comp);
  detail::printCont<std::vector<double> >(vec);
}