/*
 * ====================== leet_315.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 315. 计算右侧小于当前元素的个数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_315 {//~


// 官方：离散树状数组 法：
// 通过树状数组，可以边添加元素，边计算 前缀和/区间和
// 但是，当 元素值 不定时，无法直接使用树状数组
// 解决方法就是：
// -1- 先将 原始数组 排序去重。 每个元素获得一个 固定下标idx
// -2- 树状数组 存储的就是 下标值。 




//    69%    71%
class S{
public:


class Fenwick_Tree{
    std::vector<int> datas {};// [0] 空置
    int N {};
    int lowbit( int v ){ return v&(-v); }
public:
    Fenwick_Tree()=default;
    void init( int N_ ){
        datas.resize( N_+1, 0 );
        N = N_+1;
    }

    void update( int idx, int addVal ){
        idx++;// 外部基于0，内部跳过0
        while( idx < N ){
            datas.at(idx) += addVal;
            idx += lowbit(idx);
        }
    }

    int merge( int idx ){
        idx++;// 外部基于0，内部跳过0
        int sum = 0;
        while( idx>0 ){
            sum += datas.at(idx);
            idx -= lowbit(idx);
        }
        return sum;
    }
};


    Fenwick_Tree ftree {};
    std::unordered_map<int,int> umap {};


public:
    std::vector<int> countSmaller( std::vector<int>& nums ){

        if( nums.empty() ){ return {}; }
        if( nums.size()==1 ){ return {0}; }

        std::vector<int> idxs ( nums.begin(), nums.end() );
        std::sort( idxs.begin(), idxs.end() );
        idxs.erase( std::unique(idxs.begin(), idxs.end()), idxs.end() );
        // 每个元素，都有了自己的固定的 idx

        int Ni = static_cast<int>(idxs.size());
        int Nn = static_cast<int>(nums.size());
        
        for( int i=0; i<Ni; i++ ){
            umap.emplace(idxs[i], i);
        }
        
        ftree.init( Ni );

        std::vector<int> outs ( Nn, 0 );// [NN-1] 默认为 0

        ftree.update( umap.at(nums.back()), 1 );

        for( int i=Nn-2; i>=0; i-- ){// [i], [i+1]
            int idx = umap.at(nums[i]);
            ftree.update( idx, 1 );
            outs[i] = ftree.merge( idx-1 );
        }
        return outs;

    }
};






//=========================================================//
void main_(){

    
    std::vector<int> v { 1,2,3,4,5,6,7  };
    auto ret = S{}.countSmaller( v );
    cout<<"ret: ";
    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;
    




    /*
    std::vector<int> v { 1,2,3  };
    S::Fenwick_Tree ftree {};
    ftree.init( 3 );
    for( int i=0; i<3; i++ ){ ftree.update( i, v[i] ); }
    cout<<" merge(9):"<<ftree.merge(2)<<endl;
    */
    
    
    
    


    debug::log( "\n~~~~ leet: 315 :end ~~~~\n" );
}
}//~
