/*
 * ====================== leet_j66.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 66. 构建乘积数组
 */
#include "innLeet.h"


namespace leet_j66 {//~



//   40%  100%
class S{
public:
    // 所有元素乘积之和不会溢出 32 位整数
    // a.len <= 100000
    std::vector<int> constructArr( std::vector<int>& a ){

        if( a.empty() ){ return {}; }

        int N = static_cast<int>(a.size());
        std::vector<int> b ( N, 0 );

        b[0] = 1;
        for( int i=1; i<N; i++ ){// [i-1], [i]
            b[i] = b[i-1] * a[i-1];
        }

        //cout<<"b1: "; for(int i : b){ cout<<i<<", "; }cout<<endl;

        int rpdt = a.back();
        for( int i=N-2; i>=0; i-- ){// [i], [i+1]
            b[i] *= rpdt;
            rpdt *= a[i];
        }
        return b;

    }
};






//=========================================================//
void main_(){

    std::vector<int> v { 1,2,3,4,5 };

    auto ret = S{}.constructArr(v);

    cout<<"ret: "; for(int i : ret){ cout<<i<<", "; }cout<<endl;


    
    debug::log( "\n~~~~ leet: j66 :end ~~~~\n" );
}
}//~
