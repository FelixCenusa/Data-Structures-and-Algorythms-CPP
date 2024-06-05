#ifndef DISJOINTSETS_HPP
#define DISJOINTSETS_HPP

#include <stdexcept>
#include <unordered_map>
using namespace std;

template <class T>
class DisjointSets {
private:
    // To be filled.
    unordered_map <T, T> sets;
public:
    DisjointSets();
    ~DisjointSets();
    DisjointSets(const DisjointSets &other) = delete;
    DisjointSets& operator=(const DisjointSets &other) = delete;
    int size();
    void makeSet(T u);
    T findSet(T u);
    void unionSet(T u, T v);
};
template <class T>
DisjointSets<T>::DisjointSets() //empty
{

}
template <class T>
DisjointSets<T>::~DisjointSets() //empty
{

}
template <class T>
int DisjointSets<T>::size()
{
    return sets.count();
}
template <class T>
void DisjointSets<T>::makeSet(T u)
{
    sets[u] = u;
}
template <class T>
T DisjointSets<T>::findSet(T u) //find upmost parent
{
    if (sets.count(u) == 0)
    {
        throw exception("Vertex / set / element does not exsist");
    }
    while (u != sets[u])
    {
        u = sets[u];
    }
    return u;
}
template <class T>
void DisjointSets<T>::unionSet(T u, T v) //unite if not loop
{
    T root_u = findSet(u);
    T root_v = findSet(v);
    if (root_u != root_v) // if they dont have the same master parent its safe to merge. Possibly wrong. !!!!!!!!!
    {
        sets[root_v] = root_u;
    }
}
#endif