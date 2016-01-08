#include <functional>

#ifndef CONTAINERUSAGE_HASH_UTIS_H
#define CONTAINERUSAGE_HASH_UTIS_H

template <class T>
inline void hash_combine(size_t& seed, const T& v)
{
    // Just a copy of boost's hash_combine
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

namespace std
{

template<> struct hash<pair<int,int>>
{
    size_t operator()(const pair<int,int>& value) const
    {
        size_t hash_value = 0;
        hash_combine(hash_value, value.first);
        hash_combine(hash_value, value.second);
        return hash_value;
    }
};

}
#endif //CONTAINERUSAGE_HASH_UTIS_H
