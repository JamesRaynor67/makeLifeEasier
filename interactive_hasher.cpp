#include <iostream>
#include "picosha2.h"

int main(int argc, char* argv[])
{
  std::cout << "Input freely." << std::endl;
  picosha2::hash256_one_by_one hasher;
  while(true){
	std::string base;
	std::string salt;
	std::string line;
	std::string hex_str;

	std::cout << "Base: ";
	std::getline(std::cin, base);
	std::cout << "Salt: ";
	std::getline(std::cin, salt);
	line = base + salt;

    hasher.init(); //reset hasher state
    hasher.process(line.begin(), line.end());
    hasher.finish();
    picosha2::get_hash_hex_string(hasher, hex_str);
    std::cout << hex_str << std::endl;
  }
  return 0;
}

