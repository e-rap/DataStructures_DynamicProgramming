#include <iostream>      // for std::cin, std::cout
#include <functional>    // for std::function
#include <vector>
#include <unordered_map>

using price = unsigned int;
using rod_prices = std::vector<price>;
using test_cases = std::vector<rod_prices>;

/// test case input processing function
/// @returns a vector containing test case data
test_cases process_inputs()
{
  size_t number_of_tests{};
  std::cin >> number_of_tests;
  test_cases tests{};
  for (size_t i{ 0 }; i < number_of_tests; ++i)
  {
    size_t rod_length{};
    std::cin >> rod_length;
    rod_prices prices{};
    for (size_t j{}; j < rod_length; ++j)
    {
      price value{};
      std::cin >> value;
      prices.push_back(value);
    }
    tests.push_back(prices);
  }
  return tests;
}

/// calculates the max price for cutting a rod based on given price per length
///
/// @param rod_length the length of the rod
/// @param prices a vector of prices for each length
/// @returns the max price possible for a given rod length
price rod_cutting(const price rod_length, const rod_prices& prices)
{
  std::unordered_map<price, price> answers{};
  answers[1] = prices[0]; // base case, rod of length 1
  std::function<price(const price)> f{ [&f, &prices, &answers](const price rod_length)
  {
    price max_price{}; // price with no cut
    if (answers.find(rod_length) != answers.cend())
    {
      max_price = answers.at(rod_length);
    }
    else // calculate the maximum price
    {
      max_price = prices[rod_length - 1]; // no cut
      for (size_t length{ 1 }; length <= (rod_length / 2); ++length)
      {
        price price = f(length) + f(rod_length - length);
        if (price > max_price)
        {
          max_price = price;
        }
      }
      answers[rod_length] = max_price;
    }
    return max_price;
  } };

  return f(rod_length);
}

int main()
{
  test_cases tests{ process_inputs() };
  for (const auto& test : tests)
  {
    std::cout << rod_cutting(test.size(), test) << "\n";
  }

  return 0;
}