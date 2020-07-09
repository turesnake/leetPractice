/*
 * ====================== leet_1134.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1134. 阿姆斯特朗数
 */
#include "innLeet.h"


namespace leet_1134 {//~



// 朴素法

// 官方好像也没啥 好办法

class S{
public:
    bool isArmstrong( int N ){

        std::multiset<int> mset {};
        for( int i=N; i>0; i/=10 ){
            mset.insert( i%10 );
        }
        int k = static_cast<int>(mset.size());
        int sum = 0;

        for( auto rit = mset.rbegin(); rit!=mset.rend(); rit++ ){
            int v = *rit;
            int pdt = v;
            for( int i=1; i<k; i++ ){
                pdt *= v;
            }
            sum += pdt;
            if( sum > N ){ return false; }
        }
        return sum==N;

    }
};



//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 1134 :end ~~~~\n" );
}
}//~
