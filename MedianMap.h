#ifndef MEDIANMAP_H_
#define MEDIANMAP_H_

#include <map>
#include "MedianInterface.h"

class MedianMap: public MedianInterface
{
public:
    MedianMap();

    void add(const int val);
    double getMedian() const;
    void clear();

private:
    typedef std::multimap<int, int> containerType;
    containerType m_container;
    double m_median;

    containerType::iterator getIterByIndex(size_t index);
};

#endif /* MEDIANMAP_H_ */
