/*
 * ====================== Quicksort.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innSorts.h"


namespace sorts_quicksort {//~


// 返回 中分元素idx
int partition( std::vector<int> &v_, int fst_, int lst_ ){

    int pivotIdx = fst_;
    int pivotVal = v_.at(pivotIdx);
    int left = fst_;
    int right = lst_;
    while( left < right ){
        while( left<right && v_.at(right)>=pivotVal ){ right--; }
        while( left<right && v_.at(left)<=pivotVal ){  left++; }
        if( left < right ){
            std::swap( v_.at(left), v_.at(right) );
        }
    }
    // now left == right
    std::swap( v_.at(pivotIdx), v_.at(left) );
    return left;
}


// 
void quicksort_inn( std::vector<int> &v_, int fst_, int lst_ ){
    if( fst_ < lst_ ){
        int pIdx = partition( v_, fst_, lst_ );
        if( fst_ < pIdx-1 ){ quicksort_inn( v_, fst_, pIdx-1 ); }
        if( pIdx+1 < lst_ ){ quicksort_inn( v_, pIdx+1, lst_ ); }
    }
}


std::vector<int> quicksort_1( std::vector<int> &v_ ){
    if( v_.size()<2 ){ return v_; } // do nothing
    quicksort_inn( v_, 0, static_cast<int>(v_.size())-1 );
    return v_;
}




//=========================================================//
void main_(){

    //std::vector<int> v { 5,8,1,3,0,7,2,9,4,6, };
    //std::vector<int> v { 0,1,2,3,4,5,6,7,8,9 };
    //std::vector<int> v { 3,0,4,2,1,5,6,7,8,9 };
    //std::vector<int> v { 9,8,7,6,5,4,3,2,1,0 };
    std::vector<int> v { 5,1,2 };

    std::swap( *v.begin(), *v.begin() );

    {//----------------//
        cout << "origin datas:" << endl;
        for( const auto i : v ){ cout << i << ", "; }
        cout << endl;
    }

    auto ret = quicksort_1( v );

    {//----------------//
        cout << "sort out:" << endl;
        for( const auto i : ret ){ cout << i << ", "; }
        cout << endl;
    }

    debug::log( "\n~~~~ sorts: quick_Sort :end ~~~~\n" );
}
}//~
