#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using RodPrices = std::vector<unsigned int>;
using TestCases = std::vector<RodPrices>;

TestCases process_inputs()
{
  size_t number_of_tests{};
  std::cin >> number_of_tests;
  TestCases tests{};
  for (size_t i{ 0 }; i < number_of_tests; ++i)
  {
    size_t rod_length{};
    std::cin >> rod_length;
    RodPrices prices{};
    for (size_t j{}; j < rod_length; ++j)
    {
      unsigned int value{};
      std::cin >> value;
      prices.push_back(value);
      std::cout << prices.back() << "\n";
    }
    tests.push_back(prices);
  }
  return tests;
}

unsigned int rod_cutting(const RodPrices& rod_prices, unsigned int rod_length)
{
  std::unordered_map<unsigned int, unsigned int> solved_cases{};
  solved_cases[1] = rod_prices[0];
  auto inner_function = [&rod_prices, &solved_cases](unsigned int rod_length)
  {
    unsigned int ret_val{0};
    if (solved_cases.find(rod_length) != solved_cases.cend())
    {
      ret_val = solved_cases.at(rod_length);
    }
    else
    {
      for (size_t digit{ 1 }; digit < (rod_length / 2); ++digit)
      {

      }
    }
    return ret_val;
  };

  return inner_function(rod_length);
}

int main()
{
  TestCases tests{ process_inputs() };
  for (const auto& test : tests)
  {
    std::cout << rod_cutting(test) << "\n";
  }

  return 0;
}