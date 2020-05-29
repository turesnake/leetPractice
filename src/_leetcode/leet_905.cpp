/*
 * ====================== leet_905.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 905. 按奇偶排序数组
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_905 {//~


// 双指针交换
std::vector<int> sortArrayByParity( std::vector<int>& A ){

    int N = static_cast<int>(A.size());
    int l=0;
    int r=N-1;
    while( l<r ){
        while( l<r && A.at(l)%2==0 ){ l++; }
        while( l<r && A.at(r)%2!=0 ){ r--; }
        if( l<r ){ std::swap(A.at(l),A.at(r)); }
    }
    return A;
}



//=========================================================//
void main_(){

    std::vector<int> v { 2,3 };

    auto ret = sortArrayByParity(v);
    for( int i : ret ){
        cout << i << ", ";
    }
    cout <<endl;




    debug::log( "\n~~~~ leet: 905 :end ~~~~\n" );
}
}//~
