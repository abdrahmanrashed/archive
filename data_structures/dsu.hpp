#include <vector>
#include <numeric>

/**
    @brief Disjoined set union offers fast merging
    and look up of disjoined sets of elements.
    This is a standard implementation using path compression
    and merge by rank.
    @tparam T Type of elements.
*/
template<class T = unsigned>
class dsu{
    static_assert(std::is_integral<T>(), "Type must be integral");
protected:
    size_t dis;    //number of disjoined sets
    mutable std::vector<T> rt;  //root node of a joined set
    std::vector<T> rk;   //rank of a joined set
public:
    /**
        @brief Creates a dsu with no elements.
    */ 
    dsu() = default;
    /**
        @brief Creates a dsu with @a n elements.
        @param n The number of elements.
    */
    dsu(const size_t& n) { assign(n); }
    /**
        @brief Fills the dsu with @a n new disjoined elements.
        Note that this assignment completely erases the old elements.
        @param n The number of elements.
    */
    void assign(const size_t& n) {
        dis = n;
        rt.assign(n, (T)0);
        rk.assign(n, (T)0);
        iota(rt.begin(), rt.end(), (T)0);
    }
    /**
        @brief Adds an additional element to the dsu.
    */
    void insert() {
        ++dis;
        rt.push_back(rt.size());
        rk.push_back(0);
    }
    /**
        @brief Adds @a n additional elements to the dsu.
    */
    void insert(const size_t& n) {
        dis += n;
        for(auto i = n; i; --i){
            rt.push_back(rt.size());
            rk.push_back(0);
        }
    }
    /**
        @brief Finds the root node of the set of an element.
        @param x The specified element.
        @return The root node of the set of @a x.
    */
    T find(const T& x) const {
        if(x == rt[x]) return x;
        //compress path.
        return rt[x] = find(rt[x]);
    }
    /**
        @brief Checks whether 2 elements are in disjoined sets or same set.
        @param x The first element.
        @param y The second element.
        @return True if they are in disjoined sets. False otherwise.
    */
    bool disjoined(const T& x, const T& y) const {
        return find(x) != find(y);
    }
    /**
        @brief Merges 2 sets in constant time.
        @param x An element in the first set.
        @param y An element in the second set.
        @return True if the sets were merged. False if the elements were
        in the same set to begin with.
    */
    bool merge(T x, T y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rk[x] > rk[y]) std::swap(x, y);
        rk[y] += rk[x] == rk[y];
        rt[x] = y;
        --dis;
        return true;
    }
    /**
        @brief Returns the number of elements in dsu.
        @return The number of elements.
    */
    size_t size() const {
        return rt.size();
    }
    /**
        @brief Returns the number of disjoined elements in dsu.
        @return The number of disjoined elements.
    */
    size_t size_dis() const {
        return dis;
    }
};

/**
    @brief Similar to standard dsu but offers the ability to undo merges
    at the cost of not having path compression.
    The @a roll_back() is added to undo merges.
    @tparam T Type of elements.
*/
template<class T = unsigned>
class dsu_rb : public dsu<T>{
    using dsu<T>::rt;
    using dsu<T>::rk;
    using dsu<T>::dis;
    //Merges done on the dsu.
    std::vector<std::pair<T, bool>> merges;
public:
    using dsu<T>::dsu; 
    /**
        @brief Finds the root node of the set of an element.
        @param x The specified element.
        @return The root node of the set of @a x.
    */
    T find(T x) const {
        while(x != rt[x]) x = rt[x];
        return x;
    }
    /**
        @brief Merges 2 sets in constant time.
        @param x An element in the first set.
        @param y An element in the second set.
        @return True the sets were merged. False if the elements were
        in the same set to begin with.
    */
    bool merge(T x, T y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rk[x] > rk[y]) std::swap(x, y);
        bool inc = rk[x] == rk[y];
        merges.push_back({x, inc});
        rk[y] += inc;
        rt[x] = y;
        --dis;
        return true;
    }
    /**
        @brief Undos the last merge operation done on the dsu.
        Does nothing if no merges have happened.
    */
    void roll_back(){
        if(merges.empty()) return;
        auto& [x, inc] = merges.back();
        rk[rt[x]] -= inc;
        rt[x] = x;
        merges.pop_back(); 
    }
};