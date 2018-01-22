#ifndef MEDIANMAPV2_H_
#define MEDIANMAPV2_H_

#include <map>
#include "MedianInterface.h"

class MedianMapV2: public MedianInterface
{
public:
    MedianMapV2();
    void add(const int val);
    double getMedian() const;
    void clear();

private:
    typedef std::multimap<int, int> containerType;
    containerType m_container;
    containerType::iterator m_medianIterator;
    double m_median;
};

#endif /* MEDIANMAPV2_H_ */
