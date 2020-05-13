/*
 * ====================== Bubble_Sort.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innSorts.h"


namespace sorts_bubble_Sort {//~


// 最简单实现，不做任何优化
// 两层循环，每执行一层，就将一个最大元素沉淀到尾部，然后缩小遍历窗口
std::vector<int> bubble_Sort_1( std::vector<int> &v_ ){

    if( v_.size()<2 ){ return v_; } // do nothing
    for( auto right=v_.end()-1; right!=v_.begin(); right-- ){
        for( auto it=v_.begin(); it!=right; it++ ){
            if( *it > *(it+1) ){
                std::swap( *it, *(it+1) );
            }
        }
    }
   return v_;
}


// 优化：
// 记录每次排序 最后一个交换位置，从而加速缩短 下一次 待排序区
std::vector<int> bubble_Sort_2( std::vector<int> &v_ ){

    if( v_.size()<2 ){ return v_; } // do nothing

    int right = static_cast<int>(v_.size()) - 1;
    while( right > 0 ){
        int lastChange = -1;
        for( int i=0; i<right; i++ ){
            if( v_.at(i) > v_.at(i+1) ){
                std::swap( v_.at(i), v_.at(i+1) );
                lastChange = i+1;
            }
        }
        if( lastChange < 0 ){ break; } // already sorted
        right = lastChange;
    }
   return v_;
}



// 鸡尾酒排序
std::vector<int> bubble_Sort_3( std::vector<int> &v_ ){

    if( v_.size()<2 ){ return v_; } // do nothing

    int left = 0;
    int right = static_cast<int>(v_.size()) - 1;
    
    while( left < right ){

        int lastLeft = -1;
        int lastRight = -1;
        bool isChange {false};
    
        // left -> right
        for( int i=left; i<right; i++ ){
            if( v_.at(i) > v_.at(i+1) ){
                std::swap( v_.at(i), v_.at(i+1) );
                lastRight = i+1;
                isChange = true;
            }
        }
        if( !isChange ){ break; } // already sorted
        right = lastRight;


        // right -> left
        isChange = false;
        for( int i=right-1; i>left; i-- ){
            if( v_.at(i-1) > v_.at(i) ){
                std::swap( v_.at(i-1), v_.at(i) );
                lastLeft = i-1;
                isChange = true;
            }
        }
        if( !isChange ){ break; } // already sorted
        left = lastLeft;
    }
   return v_;
}


//=========================================================//
void main_(){

    //std::vector<int> v { 5,8,1,3,0,7,2,9,4,6, };
    //std::vector<int> v { 0,1,2,3,4,5,6,7,8,9 };
    //std::vector<int> v { 3,0,4,2,1,5,6,7,8,9 };
    std::vector<int> v { 9,8,7,6,5,4,3,2,1,0 };

    {//----------------//
        cout << "origin datas:" << endl;
        for( const auto i : v ){ cout << i << ", "; }
        cout << endl;
    }

    auto ret = bubble_Sort_3( v );

    {//----------------//
        cout << "sort out:" << endl;
        for( const auto i : ret ){ cout << i << ", "; }
        cout << endl;
    }

    debug::log( "\n~~~~ sorts: bubble_Sort :end ~~~~\n" );
}
}//~
