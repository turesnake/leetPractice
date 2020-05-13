/*
 * ======================= Heapsort.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "innSorts.h"


namespace sorts_heapsort {//~



// 借用 标准库 现成的工具
std::vector<int> heapsort_1( std::vector<int> &v_ ){
    if( v_.size()<2 ){ return v_; } // do nothing
    std::make_heap( v_.begin(), v_.end() );
    std::sort_heap( v_.begin(), v_.end() );
    return v_;
}




//=========================================================//
void main_(){

    //std::vector<int> v { 5,8,1,3,0,7,2,9,4,6, };
    //std::vector<int> v { 0,1,2,3,4,5,6,7,8,9 };
    //std::vector<int> v { 3,0,4,2,1,5,6,7,8,9 };
    std::vector<int> v { 9,8,7,6,5,4,3,2,1,0 };
    //std::vector<int> v { 5,1,2 };

    std::swap( *v.begin(), *v.begin() );

    {//----------------//
        cout << "origin datas:" << endl;
        for( const auto i : v ){ cout << i << ", "; }
        cout << endl;
    }

    auto ret = heapsort_1( v );

    {//----------------//
        cout << "sort out:" << endl;
        for( const auto i : ret ){ cout << i << ", "; }
        cout << endl;
    }

    debug::log( "\n~~~~ sorts: heap_Sort :end ~~~~\n" );
}
}//~
