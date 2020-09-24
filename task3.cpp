#include "statement.hpp"

void task3()
{
  std::vector<int> vec;
  int n = 1;

  while (std::cin >> n)
  {
    vec.push_back(n);
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::invalid_argument("Wrong input, because type must be integer.");
  }

  if (vec.empty())
  {
    exit(0);
  }

  if (vec.back() != 0)
  {
    throw std::invalid_argument("Wrong input - expected zero before end of the input !");
  }
  else
  {
    vec.pop_back();
  }

  std::vector<int>::iterator iter = vec.begin();

  if (vec.back() == 1)
  {
    while (iter < vec.end())
    {
      if (*iter % 2 == 0)
      {
        iter = vec.erase(iter);
      }
      else
      {
        iter++;
      }
    }
  }
  else if (vec.back() == 2)
  {
    while (iter < vec.end())
    {
      if (*iter % 3 == 0)
      {
        iter = vec.insert(++iter, 3, 1);
        iter += 2;
      }
      iter++;
    }
  }

  detail::printCont(vec);
}