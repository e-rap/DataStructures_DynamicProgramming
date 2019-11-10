#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <numeric>

using price = unsigned int;
using rod_prices = std::vector<price>;
using test_cases = std::vector<rod_prices>;

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

price rod_cutting(const price rod_length, const rod_prices& prices)
{
  std::unordered_map<price, price> answers{};
  answers[1] = prices[0]; // base case, rod of length 1
  std::function<price(const price)> f{ [&f,&prices, &answers](const price rod_length)
  {
    price max_price{prices[rod_length - 1]};

    // check if answer exists
    if (answers.find(rod_length) != answers.cend())
    {
      max_price = answers.at(rod_length);
    }
    else // calculate the maximum price
    {
      max_price = prices[rod_length - 1]; // no cut
      for (size_t digit{ 1 }; digit <= (rod_length / 2); ++digit)
      {
        size_t other = (rod_length) - digit;
        price price = f(digit) + f(other);
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