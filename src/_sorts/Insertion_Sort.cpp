/*
 * ======================= Insertion_Sort.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "innSorts.h"


namespace sorts_insertion_sort {//~


// 在数组头部维护一个 “有序区”
// 每次都从 “有序区” 尾后提取一个元素，拿出来和 倒序遍历有序区，对比每个区内元素
// 找到正确的插入位置
// 执行插入
std::vector<int> insertion_sort_1( std::vector<int> &v_ ){
    if( v_.size()<2 ){ return v_; } // do nothing 

    for( size_t rangeEnd=1; rangeEnd<v_.size(); rangeEnd++ ){ // 有序区 尾后元素
        int val = v_.at(rangeEnd);
        for( int i=static_cast<int>(rangeEnd)-1; i>=0; i-- ){
            if( val >= v_.at(i) ){
                v_.at(i+1)= val;
                break;
            }
            v_.at(i+1) = v_.at(i); // 元素后移
            if( i == 0 ){
                v_.at(i) = val;
            }
        }
    }
    return v_;
}


// 针对内循环做了点优化
std::vector<int> insertion_sort_2( std::vector<int> &v_ ){
    if( v_.size()<2 ){ return v_; } // do nothing 

    for( size_t rangeEnd=1; rangeEnd<v_.size(); rangeEnd++ ){ // 有序区 尾后元素
        int val = v_.at(rangeEnd);
        int i=static_cast<int>(rangeEnd)-1;
        for( ; i>=0 && val<v_.at(i); i-- ){
            v_.at(i+1) = v_.at(i); // 元素后移   
        }
        v_.at(i+1)= val; // i可能为-1，i+1 就是 0
    }

    return v_;
}



//=========================================================//
void main_(){

    //std::vector<int> v { 5,8,1,3,0,7,2,9,4,6, };
    //std::vector<int> v { 0,1,2,3,4,5,6,7,8,9 };
    std::vector<int> v { 3,0,4,2,1,5,6,7,8,9 };
    //std::vector<int> v { 9,8,7,6,5,4,3,2,1,0 };
    //std::vector<int> v { 5,1,2 };

    std::swap( *v.begin(), *v.begin() );

    {//----------------//
        cout << "origin datas:" << endl;
        for( const auto i : v ){ cout << i << ", "; }
        cout << endl;
    }

    auto ret = insertion_sort_1( v );

    {//----------------//
        cout << "sort out:" << endl;
        for( const auto i : ret ){ cout << i << ", "; }
        cout << endl;
    }

    debug::log( "\n~~~~ sorts: Selection_Sort :end ~~~~\n" );
}
}//~
