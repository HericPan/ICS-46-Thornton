// expmain.cpp
//
// Do whatever you'd like here.  This is intended to allow you to experiment
// with the code in the "app" directory or with any additional libraries
// that are part of the project, outside of the context of the main
// application or Google Test.

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <algorithm>
#include <cmath>
#include <memory>

template <int Column>
void func1(int x[Column][2][2])
{
    std::cout << "func1" << std::endl;
    for (int i = 0; i < Column; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k ++)
            {
                std::cout << x[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
    }
}


int main()
{
    int a[3][2][2] = {
        {{0, 1},
        {10, 11}},
        {{100, 101},
        {110, 111}},
        {{200, 201},
        {210, 211}},
    };

    func1<3>(a);

    

}