/*
 * ====================== leet_201.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 201. 数字范围按位与
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_201 {//~


// 将，m,n 拆分成 32 个位
// 如果某一位，从m开始，到n，始终为1，此位才为1
// 否则，此位为0


//   7%   5%
class S{
public:
    // 0 <= m <= n <= 2147483647
    int rangeBitwiseAnd( int m, int n ){

        std::vector<int64_t> v (31,0);

        for( int64_t i=0,len=2; i<31; i++,len*=2 ){
            int64_t halfLen = len/2;
            int64_t tm = m/len;
            int64_t tn = n/len;
            int64_t top = tm*len;// 本区间首元素
            //cout<<"i:"<<i<<", len:"<<len<<", tm:"<<tm<<", tn:"<<tn<<", top:"<<top<<endl;
            if( tm==tn && 
                m > top+halfLen-1 &&
                n > top+halfLen-1 ){ // 本位为1
                v[i] = 1;
            }
        }
        //cout<<"show: ";for( int i : v ){cout<<i<<", ";}cout<<endl;
        int ans = 0;
        for( int64_t i=0,k=1; i<31; i++,k*=2 ){
            if( v[i]==1 ){ ans += k; }
        }
        return ans;

    }
};




//=========================================================//
void main_(){

    auto ret = S{}.rangeBitwiseAnd( 5,7 );
    cout<<"ret:"<<ret<<endl;

    

    debug::log( "\n~~~~ leet: 201 :end ~~~~\n" );
}
}//~
