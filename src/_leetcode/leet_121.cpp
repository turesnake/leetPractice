/*
 * ====================== leet_121.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 121. 买卖股票的最佳时机
 */
#include "innLeet.h"


namespace leet_121 {//~


// 获得最大利润
int maxProfit_2( std::vector<int>& prices) {

    int out {0};
    int maxRightVal {0};

    for( int right = prices.size()-1; right>0; right-- ){

        int curRightVal = prices.at(right);
        if( curRightVal <= maxRightVal ){ continue; }
        maxRightVal = curRightVal;
        
        for( int left = 0; left < right; left++ ){

            int off = curRightVal - prices.at(left);
            if( off > out ){
                out = off;
            }
        }
    }
    return out;
}



int maxProfit_3( std::vector<int>& prices) {

    std::multimap<int,int> mmap {}; // {val, idx}
    for( int i=0; i< static_cast<int>(prices.size()); i++ ){
        mmap.emplace( prices.at(i), i );
    }

    int out {0};
    int maxRightVal {0};

    for( int right = prices.size()-1; right>0; right-- ){

        int curRightVal = prices.at(right);
        if( curRightVal <= maxRightVal ){ continue; }
        maxRightVal = curRightVal;

        for( auto it=mmap.begin(); it->first<curRightVal; it++ ){
            if( it->second < right ){
                int off = curRightVal - it->first;
                if( off > out ){
                    out = off;
                }
                break;
            }
        }

        auto rSize = mmap.count(curRightVal);
        auto rit = mmap.find(curRightVal);
        while( rSize > 0 ){
            if( rit->second == right ){
                break;
            }
            rit++;
            rSize--;
        }
        mmap.erase( rit );

    }
    return out;
}



int maxProfit( std::vector<int>& prices) {

    int minprice = 0x7fffffff; // 目前为止，最小价位
    int maxOff = 0; // 与当前价的最大差值

    for (auto price : prices){
        int off = price - minprice; // 在本价卖出，最大利润
        maxOff = std::max(maxOff, off);
        minprice = std::min(minprice, price);
    }

    return maxOff;
}





//=========================================================//
void main_(){

    //std::vector<int> v { 1,4 };
    //std::vector<int> v { 4,1 };
    //std::vector<int> v { 7,6,4,3,1 };
    std::vector<int> v { 7, 1, 5, 3, 6, 4 };

    int rrret = maxProfit( v );

    cout << "rrret = " << rrret << endl;


    int minprice = int(1e9);


    cout << "minprice = " << minprice << endl;
    


    debug::log( "\n~~~~ leet: 121 :end ~~~~\n" );
}
}//~
