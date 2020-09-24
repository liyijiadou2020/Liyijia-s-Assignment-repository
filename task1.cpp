#include <forward_list>

#include "statement.hpp"

void task1(const char *sort_type)
{
  std::vector<int> vector1;
  int n = 0;
  while (std::cin >> n)
  {
    vector1.push_back(n);
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::ios_base::failure("Wrong input - expected integer type!");
  }

  std::vector<int> vector2 = vector1;
  std::forward_list<int> list1(vector1.begin(), vector1.end());

  bool(*comp) (int&, int&) = nullptr;

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
    throw std::invalid_argument("Wrong sort type parameter!");
  }

  detail::sort <detail::bracketAccess, std::vector<int> >(vector1, comp);
  detail::printCont<std::vector<int> >(vector1);

  detail::sort <detail::atAccess, std::vector<int> >(vector2, comp);
  detail::printCont<std::vector<int> >(vector2);

  detail::sort <detail::iteratorAccess, std::forward_list<int> >(list1, comp);
  detail::printCont<std::forward_list<int> >(list1);
}