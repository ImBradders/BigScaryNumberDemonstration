using System.Numerics;

// C# doesn't have an inbuilt factorial function so I made one
BigInteger Factorial(BigInteger n)
{
    if (n == 1)
        return n;

    return n * Factorial(n - 1);
}

void PrintValues(BigInteger n)
{
    BigInteger counter = 0;
    while (counter < n)
    {
        Console.WriteLine(counter);
        counter++;
    }
}

double GetFunctionRuntime(BigInteger n)
{
    double start = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
    PrintValues(Factorial(n));
    double end = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
    double differenceAsSeconds = (end - start) / 1000;
    return differenceAsSeconds;
}

Console.WriteLine("Ran for " + GetFunctionRuntime(8) + " seconds.");

