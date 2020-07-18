/*
 * ====================== leet_m08_13.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 08.13. 堆箱子
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m08_13 {//~

// dp题
// 每个元素都只记录，当包含自己时，能合成的 最大值
// 计算每个 dp[i] 时，都要向前遍历所有元素，找出 最优方案

// 本实现，使用一个 mmap 来代替 vector-dp，但是 运行时间上 并不好看
//   5%   100%
class S{
public:
    // 箱子的数目不大于3000个
    int pileBox(std::vector<std::vector<int>>& box) {

        if( box.empty() ){ return 0; }

        int N = static_cast<int>(box.size());

        std::sort( box.begin(), box.end() );// 依次按照 元素排序

        std::multimap<int,int> mmap {};//<high,idx>
        mmap.emplace( box[0][2], 0 );

        for( int i=1; i<N; i++ ){
            int inVal = box[i][2];
            for( auto it=mmap.rbegin(); it!=mmap.rend(); it++ ){
                auto &tbox = box[it->second];
                if( box[i][0]>tbox[0] && box[i][1]>tbox[1] && box[i][2]>tbox[2] ){
                    inVal += it->first;
                    break;
                }
            }  
            mmap.emplace( inVal, i );// 只登记 包含本元素的方案         
        }
        //cout<<"mmap:"<<endl;
        //for( auto [h,i] : mmap ){ cout<<" h:"<<h<<", i:"<<i<<endl; }cout<<"-----"<<endl;
        return mmap.rbegin()->first;
    }
};


// 尝试 vector 版 dp   72%   100%
class S2{
public:
    // 箱子的数目不大于3000个
    int pileBox(std::vector<std::vector<int>>& box) {

        if( box.empty() ){ return 0; }

        int N = static_cast<int>(box.size());

        std::sort( box.begin(), box.end() );// 依次按照 元素排序

        std::vector<int> dp (N, 0);
        dp[0] = box[0][2];
        // dp[i]. i>0
        for( int i=1; i<N; i++ ){
            int mmax = 0;
            for( int k=i-1; k>=0; k-- ){
                if( box[i][0]>box[k][0] && box[i][1]>box[k][1] && box[i][2]>box[k][2] ){
                    mmax = std::max( mmax, dp[k] );
                }
            }
            dp[i] = box[i][2] + mmax;       
        }
        //---//
        int out = 0;
        for( int i : dp ){
            out = std::max( out, i );
        }
        return out;

    }
};





//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        
        {2,6,7},
        {3,1,3},
        {5,4,5}
    };

    /*
    std::sort( v.begin(), v.end() );
    cout<<"v:"<<endl;
    for( auto &c : v ){
        for( int i : c ){
            cout<<i<<", ";
        }cout<<endl;
    }
    */

    auto ret = S{}.pileBox( v );
    cout<<"ret:"<<ret<<endl;





    debug::log( "\n~~~~ leet: m08_13 :end ~~~~\n" );
}
}//~
