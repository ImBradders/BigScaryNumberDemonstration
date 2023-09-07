#include <climits>
#include <iostream>
#include <chrono>
#include <ctime>

//note - the largest number that we can go to in CPP is ULLONG_MAX - no where near as large as we can go in C# or python
//it could be achieve with a custom data type but for the sake of this demo, I didnt bother making one.

unsigned long long int Factorial(unsigned long long int n);
void PrintValues(unsigned long long int n);
long double GetFunctionRuntime(unsigned long long int n);

unsigned long long int Factorial(unsigned long long int n) {
  if (n == 1)
    return n;

  return n * Factorial(n - 1);
}

void PrintValues(unsigned long long int n) {
  unsigned long long int counter = 0;
  while (counter < n) {
    std::cout << counter;
    std::cout << std::endl;
    counter++;
  }
}

long double GetFunctionRuntime(unsigned long long int n) {
  auto start = std::chrono::system_clock::now();

  PrintValues(n);

  auto end = std::chrono::system_clock::now();
  auto difference = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  long double seconds = difference.count() / (double)1000;
  return seconds;
}

int main()
{
  std::cout << "Ran for ";
  std::cout << GetFunctionRuntime(Factorial(8));
  std::cout << " seconds.";
  std::cout << std::endl;
}