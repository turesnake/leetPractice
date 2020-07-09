/*
 * ====================== leet_378.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 378. 有序矩阵中第K小的元素
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_378 {//~


// 需要借用 有序矩阵的 左下角逐格遍历法

// 首先求出 mid=(min+max)/2 理想的 中位数
// 计算出 小于等于 中位数的 元素个数 num
// 然后与 k 比较，再调整 mid 


// 注意，此题中的 左下角遍历法， 和 j04 中的 遍历法是不一样的 
// j04 题遍历的目的，是遍历所有 <=tgt 的边界值，从而找到 tgt 是否存在
// 本题 遍历的目的，是统计 所有 <=tgt 值 的元素个数
// 以至于，本题并不需要 让 遍历指针 时刻位于 <=tgt 区间内
// 而是可以临时性地出去，最后整个 统计过程 反而变简单了


//   76%   20%
class S{

    std::vector<std::vector<int>> *mp {nullptr};
    int H {};
    int W {};
    int kk {};

    // 计算 <=mid 的元素个数，检测 个数 是否 大于等于 kk
    bool check( int mid ){
        int w=0;
        int h=H-1;
        int sum = 0;
        while( w<W && h>=0 ){ // 注意这个算法
            if( (*mp)[h][w] <= mid ){
                sum += h+1; // 累加的是 列元素
                w++;
            }else{
                h--;
            }
        }
        //cout<<" mid:"<<mid<<", sum:"<<sum<<endl;
        return sum >= kk;
    }

public:
    // 假设 k 永远有效: 1 ≤ k ≤ n2
    // 顺带也意味着， 矩阵非空
    int kthSmallest( std::vector<std::vector<int>>& matrix, int k ){

        H = static_cast<int>(matrix.size());
        W = static_cast<int>(matrix[0].size());
        mp = &matrix;
        kk = k;

        int l = matrix[0][0];
        int r = matrix.back().back();
        while( l<=r ){
            if( l==r ){ return l; }// 一定会被收敛到 一个元素
            int mid = l+(r-l)/2;// mid-left
            if( check(mid) ){// midNum >= k;
                r = mid;// 保留到 下一回合
            }else{
                l = mid+1;// 坚决剔除
            }
        }
        return -99;// never reach

    }
};



//=========================================================//
void main_(){

    // 足够稀疏的矩阵，确保找到的一定是 目标元素，而不是某个不存在的 值
    /*
    std::vector<std::vector<int>> m {
        {1,2,15},
        {3,10,20},
        {7,13,30}
    };
    */

    std::vector<std::vector<int>> m {
        {1,5,9},
        {10,11,13},
        {12,13,15}
    };

    auto ret = S{}.kthSmallest( m, 8 );

    cout<<"ret:"<<ret<<endl;

    


    debug::log( "\n~~~~ leet: 378 :end ~~~~\n" );
}
}//~
