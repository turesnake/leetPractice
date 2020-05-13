/*
 * ======================= Selection_Sort.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "innSorts.h"


namespace sorts_selection_sort {//~


// 每次都遍历 待选数据窗口，找出最大值，与最后一个元素交换
// 因为存在随意的 元素交换，所以 选择排序是 不稳定的 
std::vector<int> selection_sort_1( std::vector<int> &v_ ){
    if( v_.size()<2 ){ return v_; } // do nothing    
    for( size_t right=v_.size()-1; right>0; right-- ){
        size_t maxIdx {0};
        for( size_t i=0; i<=right; i++ ){
            if( v_.at(i) > v_.at(maxIdx) ){
                maxIdx = i;
            }
        }
        std::swap( v_.at(maxIdx), v_.at(right) );
    }
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

    auto ret = selection_sort_1( v );

    {//----------------//
        cout << "sort out:" << endl;
        for( const auto i : ret ){ cout << i << ", "; }
        cout << endl;
    }

    debug::log( "\n~~~~ sorts: Selection_Sort :end ~~~~\n" );
}
}//~
