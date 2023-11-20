#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cmath>
#include <random>
#include <string>

using namespace std;

struct Config
{
    int randomNumbers = 30;
    int minRandom = 20;
    int maxRandom = 11111;
};

class FileWriter
{
public:
    vector<int> generateRandomNumbers(vector<int> &numbers, int nums, int min = 0, int max = 1000)
    {
        // Create a random number generator engine
        random_device rd;
        mt19937 gen(rd()); // Mersenne Twister engine

        // Create a distribution for the random numbers
        uniform_int_distribution<int> distribution(min, max);

        // Generate and append 'nums' random numbers to the vector
        for (int i = 0; i < nums; ++i)
        {
            int random_number = distribution(gen);
            numbers.push_back(random_number);
        }
        return numbers;
    }

    void writeNumbersToFile(const vector<int> &numbers, const string &filename)
    {

        ofstream outFile(filename);
        if (outFile.is_open())
        {
            for (int num : numbers)
            {
                outFile << num << endl;
            }
            outFile.close();
            cout << "Numbers have been written to " << filename << endl;
        }
        else
        {
            cerr << "Unable to open file for writing" << endl;
        }
    }

    void measureTimeTaken()
    {
        // Simulate some work being done
        for (int i = 0; i < 1000000; ++i)
        {
            int x = i * i;
            double y = sqrt(x); // Using math library function
        }
    }

    std::chrono::high_resolution_clock::time_point Record(){
        return std::chrono::high_resolution_clock::now();
    }

    void timeTaken(auto start, auto end, string description){
        chrono::duration<double> duration = end - start;
        cout << "Time taken to " << description << ": " << duration.count() << " seconds" << endl;
    }
};

int main()
{
    Config cfg;

    std::vector<int> numbers;
    FileWriter fileWriter;

    auto start = fileWriter.Record();
    numbers = fileWriter.generateRandomNumbers(numbers, cfg.randomNumbers, cfg.minRandom, cfg.maxRandom);

    fileWriter.writeNumbersToFile(numbers, "numbers.txt");
    fileWriter.measureTimeTaken();

    auto end = fileWriter.Record();
    fileWriter.timeTaken(start, end, "woring all all methods");
    return 0;
}
