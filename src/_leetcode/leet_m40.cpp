/*
 * ====================== leet_m40.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题40. 最小的k个数
 */
#include "innLeet.h"


namespace leet_m40 {//~


// 最大堆，在速度排名上居然靠后？？？
std::vector<int> getLeastNumbers( std::vector<int>& arr, int k ) {

    std::vector<int> outs {};
    if( k==0 ){ return outs; }
    if( k>=static_cast<int>(arr.size()) ){ return arr; }

    std::priority_queue<int> maxHeap {};
    int i = 0;
    for( ; i<static_cast<int>(arr.size()); i++ ){
        int elem = arr.at(i);
        if( i<k ){
            maxHeap.push( elem );
        }else{
            if( elem <= maxHeap.top() ){
                maxHeap.push( elem );
            }
            while( static_cast<int>(maxHeap.size()) > k ){
                maxHeap.pop();
            }
        }
    }

    while( !maxHeap.empty() ){
        outs.push_back( maxHeap.top() );
        maxHeap.pop();
    }
    return outs;
}





//=========================================================//
void main_(){

    std::vector<int> v { 0,0,1,2,4,2,2,3,1,4 };

    auto ret = getLeastNumbers( v, 8 );

    for( const auto i : ret ){
        cout << i << ", ";
    }
    cout << endl;
    


    debug::log( "\n~~~~ leet: m40 :end ~~~~\n" );
}
}//~
