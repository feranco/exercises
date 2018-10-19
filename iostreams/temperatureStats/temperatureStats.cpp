#include <fstream>
#include <random>
#include <stdexcept>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

void storeTemps (const std::string& fileName, unsigned int readings) {
  unsigned int hours = 0;
  std::random_device rd{};
  std::default_random_engine e{rd()};
  std::normal_distribution<double> d{70.0, 1.0}; //70.0 mean, 1.0 std dev  
  
  std::ofstream outputFile{fileName, std::ios::trunc};

  if (!outputFile) throw std::runtime_error("cannot open output file \n");
  
  for (; readings > 0; --readings) {
    outputFile << hours << " " << d(e) << "\n";
    if (++hours > 23) hours = 0;
  }
}

template <typename T>
T getMedian(std::vector<T>& temperatures) {
  
  double median = 0.0;
  int readings = temperatures.size(), medianIndex = readings/2;

  std::sort(temperatures.begin(), temperatures.end());
  
  if (readings & 0x1) {
    //readings is odd
    median = temperatures[medianIndex];
  }
  else {
    //reading is even
    median = (temperatures[medianIndex-1] + temperatures[medianIndex]) / 2;
  }

  return median;
}

void tempStats (const std::string& fileName) {
  std::ifstream inputFile{fileName};
  if (!inputFile) throw std::runtime_error("cannot open input file\n");
  
  int hours;
  double temp;
  std::vector<double> temperatures;

  while (inputFile >> hours >> temp) {
    temperatures.emplace_back(temp);
  }

  double mean = std::accumulate(temperatures.begin(), temperatures.end(),0.0) / temperatures.size();
  double median = getMedian<double>(temperatures);

  std::cout << "Mean is " << mean << " Median is " << median << "\n";
}

int main (int argc, char* argv[]) {

  unsigned int readings = 50;
  if (argc > 1) readings = atoi(argv[1]);
  try {
    storeTemps("raw_temps.txt", readings);
    tempStats("raw_temps.txt");
  }
  catch(std::runtime_error& e) {
    std::cout << "Cannot comput stats: " << e.what() << "\n";
  }  
}
