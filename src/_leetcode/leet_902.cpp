/*
 * ====================== leet_902.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_902 {//~


// 用数学归纳法来实现:
// 4^3 + 4^2 + 4^1
// 以上方法仅仅适用于 N=10000 这种数字时。

// 当 N=12345 这种数字时，就需要，递归式地，一层一层比 



//    100%   100%
class S{
public:
    // D 是按排序顺序的数字 '1'-'9' 的 非空子集。
    // 1 <= N <= 10^9
    int atMostNGivenDigitSet( std::vector<std::string>& D, int N ){

        std::string vs {};
        std::string vn {};
        std::unordered_set<char> uset {};

        for( const auto &s : D ){
            vs.push_back( s[0] );
            uset.insert( s[0] );
        }
        for( int i=N; i>0; i/=10 ){
            vn.push_back( (i%10)+'0' );
        }
        std::reverse( vn.begin(), vn.end() );
        //---//
        int Ns = static_cast<int>(vs.size());
        int Nn = static_cast<int>(vn.size());
        int outSum {0};

        //=== 计算 [0,k0000] 区间 ===
        int headNum = 0;
        for( char c : vs ){
            if( c<vn[0] ){ headNum++; }
        }
        outSum = headNum * static_cast<int>(pow(Ns, Nn-1));
        for( int k=Nn-1; k>=1; k-- ){
            outSum += static_cast<int>(pow(Ns, k));
        }
        //cout<<" fst outSum:"<<outSum <<endl;

        //=== 计算 oth 区间 ===
        for( int l=0; l<Nn-1; l++ ){// [l],[l+1]
            int r=l+1;
            if( uset.count(vn[l])==0 ){ break; }// l位 不存在相等的值，剩余区间就不用查了
            //锁住 l 位，计算 [l000,lr00] 区间 合规元素个数
            int len = Nn-r;// 包含 r位
            headNum = 0;
            for( char c : vs ){
                if( c<vn[r] ){ headNum++; }
            }
            int tsum = headNum * static_cast<int>(pow(Ns, len-1));
            if( tsum==0 && uset.count(vn[r])==0 ){ break; } 
                        // 核心！！！
                        // 一方面，要查找 小于 "r000" 区间的 合适 元素
                        // 另一方面，当 [r] 也属于 合法字符时，也是可以 进入下一回合，继续查找的

            //cout<<" tsum:"<<tsum<<endl;
            outSum += tsum;
        }

        //=== 最后，N 值本身也可能是 合规的 ===
        bool isAllBitLegal = true;
        for( char c : vn ){
            if( uset.count(c)==0 ){
                isAllBitLegal = false;
                break;
            }
        }
        if( isAllBitLegal ){ outSum++; }
        //---//
        return outSum;
    }
};





//=========================================================//
void main_(){

    std::vector<std::string> D { "1","2","3","4","5","6","7","8","9" };

    auto ret = S{}.atMostNGivenDigitSet( D, 91243 );

    cout<<"ret:"<<ret<<endl;



    debug::log( "\n~~~~ leet: 902 :end ~~~~\n" );
}
}//~
