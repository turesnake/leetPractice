/*
 * ====================== leet_912.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 912. 排序数组
 */
#include "innLeet.h"
#include <stack>



namespace leet_912 {//~


// 借用标准库函数 
std::vector<int> sortArray_1( std::vector<int>& nums ){

    if( nums.size()<2 ){ return nums; }
    std::sort( nums.begin(), nums.end() );
    return nums;
}


// 优化过得冒泡排序 [超时]
std::vector<int> sortArray_2( std::vector<int>& nums ){

    if( nums.size()<2 ){ return nums; } // do nothing

    int right = static_cast<int>(nums.size()) - 1;
    while( right > 0 ){
        int lastChange = -1;
        for( int i=0; i<right; i++ ){
            if( nums.at(i) > nums.at(i+1) ){
                std::swap( nums.at(i), nums.at(i+1) );
                lastChange = i+1;
            }
        }
        if( lastChange < 0 ){ break; } // already sorted
        right = lastChange;
    }
    return nums;
}


// 鸡尾酒排序 [超时]
std::vector<int> sortArray_3( std::vector<int> &nums ){

    if( nums.size()<2 ){ return nums; } // do nothing
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while( left < right ){
        int lastLeft = -1;
        int lastRight = -1;
        bool isChange {false};
        // left -> right
        for( int i=left; i<right; i++ ){
            if( nums.at(i) > nums.at(i+1) ){
                std::swap( nums.at(i), nums.at(i+1) );
                lastRight = i+1;
                isChange = true;
            }
        }
        if( !isChange ){ break; } // already sorted
        right = lastRight;
        // right -> left
        isChange = false;
        for( int i=right-1; i>left; i-- ){
            if( nums.at(i-1) > nums.at(i) ){
                std::swap( nums.at(i-1), nums.at(i) );
                lastLeft = i-1;
                isChange = true;
            }
        }
        if( !isChange ){ break; } // already sorted
        left = lastLeft;
    }
   return nums;
}



//======= 快速排序 ========
// 返回 中分元素idx
int partition( std::vector<int> &nums, int fst_, int lst_ ){
    int pivotIdx = fst_;
    int pivotVal = nums.at(pivotIdx);
    int left = fst_;
    int right = lst_;
    while( left < right ){
        while( left<right && nums.at(right)>=pivotVal ){ right--; }
        while( left<right && nums.at(left)<=pivotVal ){  left++; }
        if( left < right ){
            std::swap( nums.at(left), nums.at(right) );
        }
    }
    // now left == right
    std::swap( nums.at(pivotIdx), nums.at(left) );
    return left;
} 
void quicksort_inn( std::vector<int> &nums, int fst_, int lst_ ){
    if( fst_ < lst_ ){
        int pIdx = partition( nums, fst_, lst_ );
        if( fst_ < pIdx-1 ){ quicksort_inn( nums, fst_, pIdx-1 ); }
        if( pIdx+1 < lst_ ){ quicksort_inn( nums, pIdx+1, lst_ ); }
    }
}
std::vector<int> quicksort_1( std::vector<int> &nums ){
    if( nums.size()<2 ){ return nums; } // do nothing
    quicksort_inn( nums, 0, static_cast<int>(nums.size())-1 );
    return nums;
}





//=========================================================//
void main_(){

    /*
    std::vector<int> v { 5,2,3,1 };

    auto ret = sortArray_1( v );

    {//----------------//
        cout << "sort out:" << endl;
        for( const auto i : ret ){ cout << i << ", "; }
        cout << endl;
    }
    */


    debug::log( "\n~~~~ leet: 912 :end ~~~~\n" );
}
}//~
