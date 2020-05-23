/*
 * ====================== leet_374.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 374. 猜数字大小
 */
#include "innLeet.h"


namespace leet_374 {//~


// 这题 很奇怪， 
// 自己机器上就是对的 
// 提交后就是错的 

// 系统定义的函数接口 此处没有真的实现
int guess(int num){
    if( num > 1 ){ return 1; }
    if( num == 1 ){ return 0; }
    return -1;
}


int work( int a, int b ){

    if( a==b ){ return (guess(a)==0) ? a : -1; } // 万一区间不对
    int N = b-a+1;
    int mid = a + N/2; // 中间元素
    int ret = guess(mid);
    if( ret==0 ){ return mid; }
    if( ret<0 ){ return work(mid+1, b); }
    return work(a, mid-1);
}


int guessNumber(int n) {
    return work( 1, n );
}


//================================================//


// 真正意义上的 二分查找
int guessNumber_2(int n) {
        int l = 1, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == 1){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
}



//=========================================================//
void main_(){

    cout << guessNumber_2( 2 ) << endl;

    

    debug::log( "\n~~~~ leet: 374 :end ~~~~\n" );
}
}//~
