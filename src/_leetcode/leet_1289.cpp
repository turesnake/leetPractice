/*
 * ====================== leet_1289.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1289. 下降路径最小和  II
 */
#include "innLeet.h"


namespace leet_1289 {//~



// 尝试直接在 原始数据上修改 

// 其实不完全算 动态规划
// 一个难点是，取每一行的 最小值和次小值，用 大顶堆 来实现


//   53%   100%
class S{

struct Elem{
    int val {};
    int idx {};// w idx
};

struct ElemLess{
    bool operator()( Elem &a, Elem &b ){
        return a.val<b.val;
    }
};

    int H {};
    int W {};

    std::priority_queue<Elem,std::vector<Elem>,ElemLess> maxHeap {};

    // 只存储 最小的两个 元素
    void collect( std::vector<int> &v ){

        while( !maxHeap.empty() ){ maxHeap.pop(); }
        // fst 2
        maxHeap.push(Elem{ v[0], 0 });
        maxHeap.push(Elem{ v[1], 1 });
        // oth
        for( int i=2; i<W; i++ ){
            if( v[i] < maxHeap.top().val ){
                maxHeap.push(Elem{ v[i], i });
            }
            while( maxHeap.size()>2 ){
                maxHeap.pop();
            }
        }
    }


public:
    // 1 <= arr.len == arr[i].len <= 200
    // -99 <= arr[i][j] <= 99
    int minFallingPathSum( std::vector<std::vector<int>>& arr ){

        H = static_cast<int>(arr.size());
        W = static_cast<int>(arr.at(0).size());
        if( W==1 ){ return 0; } // 测试标明，不存在此情况 
        // [0]
        collect( arr.at(0) );
        // [h]
        for( int h=1; h<H; h++ ){// each lvl
            Elem secMinE = maxHeap.top();
            maxHeap.pop();
            Elem fstMinE = maxHeap.top();
            for( int w=0; w<W; w++ ){
                arr[h][w] += (w==fstMinE.idx) ? secMinE.val : fstMinE.val;
            }
            //---
            collect( arr.at(h) );
        }
        //cout<<"dp:"<<endl;
        //for( auto &c : arr ){ for( int i : c ){ cout<<i<<", "; }cout<<endl; }
        maxHeap.pop();
        return maxHeap.top().val;

    }
};




//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {1,2,3}
    };

    auto ret = S{}.minFallingPathSum(v);
    cout<<"ret:"<<ret<<endl;

    
    debug::log( "\n~~~~ leet: 1289 :end ~~~~\n" );
}
}//~
