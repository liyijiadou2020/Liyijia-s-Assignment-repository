#include <iostream>
#include <stdexcept>
#include "statement.hpp"

int main(int args, char **argv)
{
  try
  {
    if ((args < 2) || (args >=5))

    {
      throw std::invalid_argument("Incorrect number argument.");
      return 1;
    }

    switch (*argv[1])
    {
    case '1':
      if (args == 3)
      {
        task1(argv[2]);
      }
      else
      {
        throw std::invalid_argument("Wrong input parameters.");
      }
      break;

    case '2':
      if (args == 3)
      {
        task2(argv[2]);
      }
      else
      {
        throw std::invalid_argument("Wrong input parameters.");
      }
      break;

    case '3':
      if (args == 2)
      {
        task3();
      }
      else
      {
        throw std::invalid_argument("Wrong input parameters.");
      }
      break;

    case '4':
      if (args == 4)
      {
        task4(argv[2], argv[3]);
      }
      else
      {
        throw std::invalid_argument("Wrong input parameters.");
      }
      break;

    default:
      throw std::invalid_argument("Invalid task number argument!");
      break;
    }
  }

  catch (std::exception & e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}