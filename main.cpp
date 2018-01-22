#include <iostream>
#include "MedianBuilder.h"

int main()
{
    MedianInterface * medianObj = MedianBuilder::createMedianInstance();
    if (medianObj)
    {
        int input;
        while (true)
        {
            std::cin >> input;
            medianObj->add(input);
            std::cout << medianObj->getMedian() << std::endl;
        }
    }
    return 0;
}
