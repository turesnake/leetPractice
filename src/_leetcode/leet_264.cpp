/*
 * ====================== leet_264.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 264. 丑数 II
 */
#include "innLeet.h"


namespace leet_264 {//~


// 辅助用
// 如果目标数是丑数，打印它的信息
int count {0};
void print_ugly( int num ){
    int n = num;
    if( n<1 ){ return; }
    int x {0};
    int y {0};
    int z {0};
    while( n%2==0 ){ n /= 2; x++; }
    while( n%3==0 ){ n /= 3; y++; }
    while( n%5==0 ){ n /= 5; z++; }
    if( n == 1 ){
        cout << count++ << " - "
            << num << ": { " << x 
            << ", " << y 
            << ", " << z
            << "}" << endl;
    }
}



int nthUglyNumber( int n ){

    if( n<1 ){ return 0; }// 无意义
    std::vector<int> nums { 0,1 };//[0]号位空置
    int l2 = 1;
    int l3 = 1;
    int l5 = 1;
    for( int i=2; i<=n; i++ ){
        int v2 = nums.at(l2)*2;
        int v3 = nums.at(l3)*3;
        int v5 = nums.at(l5)*5;
        int mmin = std::min(std::min(v2,v3),v5);
        if( v2==mmin ){ l2++; }
        if( v3==mmin ){ l3++; }
        if( v5==mmin ){ l5++; }
        nums.push_back( mmin );
    }
    return nums.at(n);
}





//=========================================================//
void main_(){

    
    for( int i=0; i<100; i++ ){
        print_ugly( i );
    }
    cout << "========" << endl;
    cout << nthUglyNumber( 1 ) << endl;
    


    debug::log( "\n~~~~ leet: 264 :end ~~~~\n" );
}
}//~
