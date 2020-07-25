/*
 * ====================== leet_164.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 164. 最大间距
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_164 {//~


// 用桶排序来实现 

// 代价就是，如果元素很多，跨度很大，那么会有很多浪费的 空桶

//   12%   12%
class S{
public:
    // 元素 非负， 且数值在 32 位有符号整数范围内
    // 时间空间 都要求 线性复杂度
    int maximumGap( std::vector<int>& nums ){


        if( nums.size()<2 ){ return 0; }
        int mmin=INT_MAX;
        int mmax=INT_MIN;
        for( int i : nums ){
            mmin = std::min( mmin, i );
            mmax = std::max( mmax, i );
        }
        if( mmax-mmin<2 ){ return mmax-mmin; }// 补丁
        int N = static_cast<int>(nums.size());

        int bs = (mmax-mmin)/(N-1);// 理想的桶容量，小于等于 元素平均间距
        if( bs==0 ){ bs=1; } // 补丁
        int Nbkt = (mmax-mmin+1)%bs==0 ? (mmax-mmin+1)/bs : (mmax-mmin+1)/bs+1;// 桶个数
        //cout<<"bs:"<<bs<<", Nb"<<Nbkt<<endl;

        std::vector<std::vector<int>> bkts (Nbkt, std::vector<int>{} );
        for( int num : nums ){
            auto &bkt = bkts[ (num-mmin)/bs ];
            if( bkt.empty() ){
                bkt.push_back( num );

            }else if( bkt.size()==1 ){
                if( num >= bkt[0] ){
                    bkt.push_back( num );
                }else{
                    bkt.insert( bkt.begin(), 1, num );// 存入前方
                }
            }else{
                bkt[0] = std::min( bkt[0], num );
                bkt[1] = std::max( bkt[1], num );
            }
        }
        //cout<<"bkts:"<<endl;
        //for( int j=0; j<Nbkt; j++ ){cout<<"["<<j<<"]: "; for(int i:bkts[j]){ cout<<i<<", ";}cout<<endl; }

        int outMax = INT_MIN;
        int l=bkts[0].back();
        for( int j=1; j<Nbkt; j++ ){
            if( bkts[j].empty() ){ continue; }
            outMax = std::max( outMax, bkts[j][0]-l );
            l = bkts[j].back();
        }
        return outMax;

    }
};



//=========================================================//
void main_(){

    std::vector<int> v { 2,3,4,5,6,7,8,9,10,11,12,15,21,22,23,24,25,30,101 };

    //std::vector<int> v { 1,1,1,1 };

    auto ret = S{}.maximumGap(v);
    cout<<"ret:"<<ret<<endl;


    
    debug::log( "\n~~~~ leet: 164 :end ~~~~\n" );
}
}//~
