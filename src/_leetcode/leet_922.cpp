/*
 * ====================== leet_922.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 922. 按奇偶排序数组 II
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_922 {//~


// 朴素双指针 16%, 7%
// 数组个数一定是偶数
// 数组个数 >= 2
std::vector<int> sortArrayByParityII( std::vector<int>& A ){

    int N = static_cast<int>(A.size());
    // 只遍历到倒数第二位，如果之前的都正确，最后一位一定正确
    for( int l=0; l<N-1; l++ ){
        bool isError {};
        bool isNeedOdd {};
        if( l%2==0 && A.at(l)%2!=0 ){// 偶数位出错
            isError = true;
            isNeedOdd = false;
        }else if( l%2!=0 && A.at(l)%2==0 ){// 奇数位出错
            isError = true;
            isNeedOdd = true;
        }
        if( isError ){
            for( int r=l+1; r<N; r++ ){//不用担心 l+1 溢出。
                if( (isNeedOdd && r%2==0 && A.at(r)%2!=0) || 
                    (!isNeedOdd && r%2!=0 && A.at(r)%2==0) ){
                    std::swap( A.at(l), A.at(r) );
                    break;
                }
            }
        }
    }
    return A;
}


// 特种双指针：一个永指奇数位，一个永指偶数位 55% 7%
std::vector<int> sortArrayByParityII_2( std::vector<int>& A ){

    int N = static_cast<int>(A.size());
    int eve = 0;// 永指偶数位
    int odd = 1;// 永指奇数位
    while( eve<N && odd<N ){
        while( eve<N && A.at(eve)%2==0 ){ eve += 2; }
        while( odd<N && A.at(odd)%2!=0 ){ odd += 2; }
        if( eve<N && odd<N ){ std::swap(A.at(odd),A.at(eve)); }
    }
    return A;
}




//=========================================================//
void main_(){

    std::vector<int> v { 4,2,5,7 };
    //std::vector<int> v { 0,1,0,1,0,1 };
    //std::vector<int> v { 1,0,0,0,1,1 };
    //std::vector<int> v { 1,0};

    auto ret = sortArrayByParityII_2(v);
    for( int i : ret ){
        cout << i << ", ";
    }
    cout <<endl;
    




    debug::log( "\n~~~~ leet: 922 :end ~~~~\n" );
}
}//~
