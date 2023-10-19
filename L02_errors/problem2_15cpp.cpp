#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
    int fq = 20;
    int pFq = 192000;
    int sAngle = 0;
    int iterations = 20000;

    double omega = 2 * M_PI * (double(fq) / double(pFq));
    double a = 2 * cos(omega);

    std::ofstream outputFile("/home/maciek/AGH/semestr3/menu/data/L02_errors/data.txt");

    double x = omega;
    double y0 = sin(sAngle + omega);
    double y1 = sin(sAngle + 2 * omega);

    for (int i = 0; i < iterations; i++)
    {
        double y = a * y1 - y0;
        y0 = y1;
        y1 = y;
        x += omega;

        outputFile << x << " " << y << std::endl;
    }

    outputFile.close();

    return 0;
}