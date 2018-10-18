#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>

int main(int argc, char*argv[]) {
  int numbers = 10;
  if (argc > 1) numbers = atoi(argv[1]);

  std::random_device rdev{};
  std::default_random_engine e{rdev()};
  std::uniform_int_distribution<int> d{0, 100};

  std::string filename{"numbers.txt"};

#if 1
  
  if (auto writeStream = std::ofstream{filename, std::ios::trunc}) {
    for (int i = 0; i < numbers; ++i) {
      writeStream << d(e) << " ";
    }
  }
  else {
    throw std::runtime_error("file " + filename + " not opened\n");
  }//no need to flush or close; the ofstream has bracket scope
  
#else
  
  std::ofstream writeStream{filename, std::ios::trunc};
  if (!writeStream) throw std::runtime_error("file " + filename + " not opened\n"); 
  for (int i = 0; i < numbers; ++i) {
    writeStream << d(e) << " ";
  }

  writeStream.flush();  //also writeStream.close() because it force the flush

#endif

  std::ifstream readStream{filename};
  if (!readStream) throw std::runtime_error("file " + filename + " not opened\n");
  int sum = 0;
  for (int num = 0; readStream >> num;) {
    sum += num;
  }

  std::cout << "Sum is: " << sum << std::endl;
  
}
