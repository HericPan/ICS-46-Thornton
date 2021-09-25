#include <algorithm>
#include "ArrayList.hpp"


ArrayList::ArrayList(ArrayList&& a)
{
    std::swap(items, a.items);
    std::swap(sz, a.sz);
    std::swap(cap, a.cap);
}

ArrayList& ArrayList::operator=(ArrayList&& a)
{
    std::swap(items, a.items);
    std::swap(sz, a.sz);
    std::swap(cap, a.cap);

    return *this;
}