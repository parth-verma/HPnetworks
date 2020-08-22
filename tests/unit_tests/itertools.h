//
// Created by Parth Verma on 19/08/20.
//

#ifndef GRAPHS_ITERTOOLS_H
#define GRAPHS_ITERTOOLS_H

#include<iterator>
#include <algorithm>
#include <numeric>

template<class InputIterator>
class Combinations{
    typedef  typename std::iterator_traits<InputIterator>::value_type base_value;
    InputIterator base,end;
    std::vector<int> ans;
//    base_value current;
int n, r,i;
public:
    explicit Combinations(InputIterator begin,InputIterator end, int r) :base(begin),end(end),r(r),i(r-1){
        ans.resize(r);
        n = end-begin;
        std::iota(ans.begin(),ans.end(),0);
        while (i > 0 && ans[i] == n - r + i) {
            i--;
        }
    }
//    Accumulate begin(){
//        return Accumulate(base);
//    }
    bool has_next(){return ans.front() < n-r+1;}
    Combinations& operator++(){
        ans[i]++;
        while (i < r - 1) {
            ans[i + 1] = ans[i] + 1;
            i++;
        }
        while (i > 0 && ans[i] == n - r + i) {
            i--;
        }
        return *this;
    }


//    bool operator==(const Accumulate &rhs) const {
//        return base == rhs.base;
//    }

//    bool operator!=(const Accumulate &rhs) const {
//        return !(rhs == *this);
//    }
    std::vector<base_value> operator*(){
        std::vector<base_value> comb;
        for(auto q: ans){
            comb.push_back(*(base+q));
        }
        return comb;
    }
};
class CombinationsWithReplacement{};

template<class InputIterator>
class Accumulate{
    typedef  typename std::iterator_traits<InputIterator>::value_type base_value;
    InputIterator base,end,curr;
    base_value current;
public:
    explicit Accumulate(InputIterator begin,InputIterator end) :base(begin),end(end){
        current = *begin;
        curr = begin;
    }
//    Accumulate begin(){
//        return Accumulate(base);
//    }
    bool has_next(){return curr!=end;}
    Accumulate& operator++(){
        curr++;
        current += *curr;
        return *this;
    }

//    bool operator==(const Accumulate &rhs) const {
//        return base == rhs.base;
//    }

//    bool operator!=(const Accumulate &rhs) const {
//        return !(rhs == *this);
//    }
    base_value operator*(){return current;}




};

template<class InputIterator>
class Pairwise{
    typedef  typename std::iterator_traits<InputIterator>::value_type base_value;
    InputIterator base,end,curr;
public:
    explicit Pairwise(InputIterator begin,InputIterator end) :base(begin),end(end),curr(begin){

    }
//    Accumulate begin(){
//        return Accumulate(base);
//    }
    bool has_next(){return (curr+1)!=end;}
    Pairwise& operator++(){
        curr++;
        return *this;
    }

//    bool operator==(const Accumulate &rhs) const {
//        return base == rhs.base;
//    }

//    bool operator!=(const Accumulate &rhs) const {
//        return !(rhs == *this);
//    }
    std::pair<base_value,base_value> operator*(){
        auto a = *curr;
        auto b = *(curr+1);
        return std::make_pair(a,b);
    }
};

template<typename InputIterator>
class Product{
    typedef  typename std::iterator_traits<InputIterator>::value_type base_value;
    InputIterator base,end,curr;
    Product* next = nullptr;
    void reset(){
        curr = base;
        if(next){
            next->reset();
        }
    }
public:
    template<typename ...InputIterators>
    explicit Product(InputIterator begin,InputIterator end,InputIterators... args) :base(begin),end(end),curr(begin){
        next = new Product(args...);
    }
    explicit Product(InputIterator begin,InputIterator end):base(begin),end(end),curr(begin){
    }
    bool has_next(){
        if (!next){
            return curr+1!=end;
        }
        return next->has_next() || (curr+1)!=end;
    }
    bool is_valid(){
        if(!next){
            return curr!=end;
        }
        return next->is_valid() && curr!=end;
    }
    Product& operator++(){
        if(!has_next()){
            curr = end;
        return *this;}
        if (!next ){
            curr++;
            return *this;
        }
        if(!next->has_next()){
            curr++;
            next->reset();
            return *this;
        }
        ++(*next);
        return *this;
    }

//    bool operator==(const Accumulate &rhs) const {
//        return base == rhs.base;
//    }

//    bool operator!=(const Accumulate &rhs) const {
//        return !(rhs == *this);
//    }
    std::vector<base_value> operator*(){
        if(!next){
            return std::vector<base_value>({*curr});
        }
        std::vector<base_value> ans = *(*next);
        ans.insert(ans.begin(),*curr);
        return ans;
    }



};

#endif //GRAPHS_ITERTOOLS_H
