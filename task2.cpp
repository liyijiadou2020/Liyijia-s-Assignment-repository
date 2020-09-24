#include <fstream>
#include <memory>

#include "statement.hpp"

void task2(const char *filename)
{
  std::ifstream inputfile(filename, std::ios_base::binary);

  if (inputfile.good() == 0)
  {
    throw std::invalid_argument("Wrong filename for task 2.");
  }

  size_t size = 0;
  size_t contentCapacity = 64;
  std::unique_ptr<char[], decltype(&free)> contents(static_cast<char *>(malloc(contentCapacity)), free);

  while (inputfile)
  {
    inputfile.read(&contents[size], contentCapacity - size);
    size += inputfile.gcount();

    if (size == contentCapacity)
    {
      contentCapacity *= 2;
      auto temp_content = contents.release();
      contents.reset(static_cast<char *>(std::realloc(temp_content, contentCapacity)));

      if (!contents) {
        throw std::runtime_error("Error allocate memory!");
      }
    }
  }

  inputfile.close();

  if (inputfile.is_open())
  {
    throw std::ios_base::failure("Wrong to close file!!");
  }

  std::vector<char> vector(&contents[0], &contents[size]);

  for (char &it : vector)
  {
    std::cout << it;
  }
}