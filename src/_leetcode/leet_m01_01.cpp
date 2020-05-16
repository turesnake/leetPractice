/*
 * ====================== leet_m01_01.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 10.01. 合并排序的数组
 */
#include "innLeet.h"


namespace leet_m01_01 {//~



// 从尾部开始排
void merge( std::vector<int>& A, int m, std::vector<int>& B, int n ){

    if( n<=0 ){ return; }

    int a = m-1;
    int b = n-1;
    int lst = m+n-1;

    if( a<0 && b>=0 ){ 
        while( b>=0 ){ A.at(lst--) = B.at(b--); }
        return;
    }

    while( a>=0 && b>=0 ){
        ( A.at(a) >= B.at(b) ) ?
            A.at(lst--) = A.at(a--) :
            A.at(lst--) = B.at(b--);
        if( a<0 ){ while( b>=0 ){ A.at(lst--) = B.at(b--); }}
        if( b<0 ){ while( a>=0 ){ A.at(lst--) = A.at(a--); }}
    }
}





//=========================================================//
void main_(){

    std::vector<int> v1 { 0,0,0 };
    //std::vector<int> v1 { 4,6,8,0,0,0 };


    std::vector<int> v2 { 2,5,6 };


    merge( v1, 0, v2, 3 );

    for( const int i : v1 ){
        cout << i << ", ";
    }
    cout << endl;



    debug::log( "\n~~~~ leet: m01_01 :end ~~~~\n" );
}
}//~
