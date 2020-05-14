/*
 * ====================== leet_7.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 7. 整数反转
 */
#include "innLeet.h"


namespace leet_7 {//~


int reverse( int x ) {

    bool isNegative = x < 0;
    x = std::abs(x);

    std::vector<int> minV { 7,4,6,3,8,4,7,4,1,2 }; // -
    std::vector<int> maxV { 8,4,6,3,8,4,7,4,1,2 }; // +

    std::deque<int> que {};

    while ( x > 0 ){
        que.push_back( x%10 );
        x = x / 10;
    }

    bool iSNeedCheckFlow = que.size() >= minV.size();

    int out {0};
    while( !que.empty() ){
        int v = que.front();
        que.pop_front();
        int queSize = static_cast<int>(que.size());

        if( iSNeedCheckFlow ){
            // check overflow
            if( !isNegative ){ // +
                if( v > maxV.at(queSize) ){
                    return 0;
                }else if( v < maxV.at(queSize) ){
                    iSNeedCheckFlow = false;
                }
            }else{ // -
                if( v > minV.at(queSize) ){
                    return 0;
                }else if( v < minV.at(queSize) ){
                    iSNeedCheckFlow = false;
                }
            }
        }

        if( v > 0 ){
            out += v * std::pow( 10, que.size() );
        }
    }
    return isNegative ? -out : out;
}



// 官方答案
int reverse_2( int x ) {

    int out {0};
    int mmin = INT_MIN/10;
    int mmax = INT_MAX/10;

    while( x != 0 ){
        int mod = x % 10;
        x = x / 10;
        if( (out>mmax) || (out==mmax && mod>7) ){ return 0; }
        if( (out<mmin) || (out==mmin && mod<-8) ){ return 0; }
        out = out * 10 + mod;
    }
    return out;
}



//=========================================================//
void main_(){

    auto ret = reverse_2( 3847412 );

    cout << "ret = " << ret << endl;



    debug::log( "\n~~~~ leet: 7 :end ~~~~\n" );
}
}//~
