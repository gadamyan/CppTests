#ifndef Fibonachi_h__
#define Fibonachi_h__

#include <iostream>


class Fibonachi
{
public:
    
    static void testFibonachi()
    {
        std::cout << recursiveFibonachi(5) << std::endl;
        std::cout << iterativeFibonachi(5) << std::endl;
    }
    
    static int recursiveFibonachi(const int number)
    {
        return if (number < 2) ? 1 : recursiveFibonachi(number - 1) + recursiveFibonachi(number - 2);
    }
    
    static int iterativeFibonachi(const int number)
    {
        if (number < 2)
        {
            return 1;
        }
        
        int prev = 1;
        int current = 1;
        for (int i = 1; i < n; ++i)
        {
            int temp = prev + current;
            prev = current;
            current = temp;
        }
        return current;
    }
};

#endif // Fibonachi_h__