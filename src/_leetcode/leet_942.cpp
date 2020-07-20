/*
 * ====================== leet_942.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 942. 增减字符串匹配
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_942 {//~


// 第一个元素设为0，然后根据 是 'I',还是 'D'
// 机械地递增递减，以此获得最初地 数组
// -2-
// 然后按照 上面分配的值，将元素 从大到小排序，
// 然后把 [0,N] 元素，逐个分配进去 

// 这个方法的缺陷是，存在一次排序
// 不管是用 vector，还是 mmap 排序，结果都是一样的

//     7%,  100%
class S{
public:
    // 1 <= S.length <= 10000
    // S 只包含字符 "I" 或 "D"
    std::vector<int> diStringMatch( std::string S ){

        int Ns = static_cast<int>(S.size());

        std::vector<std::pair<int,int>> pv { {0,0} };//<val,idx>
        for( int i=1; i<=Ns; i++ ){// [i-1],[i]
            if( S[i-1]=='I' ){
                pv.emplace_back( pv[i-1].first+1, i );
            }else{
                pv.emplace_back( pv[i-1].first-1, i );
            }
        }
        std::sort( pv.begin(), pv.end() );

        std::vector<int> outs ( Ns+1, 0 );
        int idx=0;//[0,Ns]
        for( auto [v,i]: pv ){
            outs[i] = idx;
            idx++;
        }
        return outs;

    }
};




// 官方思路：一种特殊的，收缩区间的 方法
// 用 l/r 指向区间两端，
// 遍历 字符，
// 如果是 'I', 说明是 递增，将 l 分配给它，同时 l++
// 如果是 'D', 说明是 递减，将 r 分配给它，同时 r--;



//   98%   100%
class S2{
public:
    // 1 <= S.length <= 10000
    // S 只包含字符 "I" 或 "D"
    std::vector<int> diStringMatch( std::string S ){

        int Ns = static_cast<int>(S.size());
        int l=0;
        int r=Ns;
        std::vector<int> outs (Ns+1, 0);

        for( int i=0; i<Ns; i++ ){
            if( S[i]=='I' ){
                outs[i] = l++;
            }else{
                outs[i] = r--;
            }
        }
        // 补上最后一个元素，此时，l==r
        outs[Ns] = l;
        return outs;

    }

};






//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 942 :end ~~~~\n" );
}
}//~
