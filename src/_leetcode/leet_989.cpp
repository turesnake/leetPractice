/*
 * ====================== leet_989.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 989. 数组形式的整数加法
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_989 {//~





std::vector<int> addToArrayForm( std::vector<int>& A, int K ){

    int Na = static_cast<int>(A.size());
    std::deque<int> que {};
    int carry = 0;

    for( int a=Na-1; a>=0 || K>0; a--, K=K/10 ){
        int va = (a>=0) ? A.at(a) : 0;
        int vk = K%10;
        int tmp = va + vk + carry;
        carry = tmp/10;
        que.push_front( tmp%10 );
    }
    if( carry>0 ){ que.push_front(1); }
    return std::vector<int>(que.begin(), que.end());
}




//=========================================================//
void main_(){

    std::vector<int> a { 1,2,3,4,5 };

    auto ret = addToArrayForm( a, 0 );

    cout <<"ret:"<<endl;
    for( int i : ret ){ cout <<i<<", "; }
    cout << endl;

    

    debug::log( "\n~~~~ leet: 989 :end ~~~~\n" );
}
}//~
