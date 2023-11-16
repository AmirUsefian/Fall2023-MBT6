#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cmath>
using namespace std;

class FileWriter {
public:
    void writeNumbersToFile(const vector<int>& numbers, const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (int num : numbers) {
                outFile << num << " ";
            }
            outFile.close();
            cout << "Numbers have been written to " << filename << endl;
        } else {
            cout << "Unable to open file for writing" << endl;
        }
    }

    void measureTimeTaken() {
        auto start = chrono::high_resolution_clock::now();
        // Simulate some work being done
        for (int i = 0; i < 1000000; ++i) {
            int x = i * i;
            double y = sqrt(x); // Using math library function
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> timeTaken = end - start;
        cout << "Time taken to write numbers to a file and do some work: " << timeTaken.count() << " seconds" << endl;
    }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    FileWriter fileWriter;
    fileWriter.writeNumbersToFile(numbers, "numbers.txt");
    fileWriter.measureTimeTaken();

    return 0;
}
