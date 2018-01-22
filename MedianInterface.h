#ifndef MEDIANINTERFACE_H_
#define MEDIANINTERFACE_H_

class MedianInterface
{
public:
    virtual ~MedianInterface() {};
    virtual void add(const int val) = 0;
    virtual double getMedian() const = 0;
    virtual void clear() = 0;
};

#endif /* MEDIANINTERFACE_H_ */
