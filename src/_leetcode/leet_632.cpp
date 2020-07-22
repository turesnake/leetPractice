/*
 * ====================== leet_632.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 632. 最小区间
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_632 {//~


// 非常特殊的 题目 和思路

// 参考来的思路：
// 将所有 数据 绑定自己所属的 组id，然后放入一个巨型 数组中，并且是排好序的
// 可以通过 小顶堆 来实现

// 针对这个 巨型数组，做 滑动窗口 操作，保证每个 有效窗口内，都涵盖了 [0,k-1] 每个数组的元素
// 然后在 所有有效窗口中，选出 区间最小且最左 的那个


// 第一份实现使用的 堆排序，没有 std::sort 快

//   13%   100%
class S{

struct Elem{
    int val {};
    int idx {};
};

struct EGreater{
    bool operator()( const Elem &a, const Elem &b ){
        return a.val >= b.val;
    }
};

public:
    // 给定的列表可能包含重复元素，所以在这里升序表示 >=
    // 1 <= k <= 3500
    // -10^5 <= 元素的值 <= 10^5
    // 按照题意，所有 有序数组，都是非空的
    std::vector<int> smallestRange( std::vector<std::vector<int>>& nums ){

        size_t sK = nums.size();
        int K = static_cast<int>(sK);

        //== 将所有元素 放入一个 巨型数组 ==//
        std::vector<Elem> elems {};
        std::priority_queue<Elem,std::vector<Elem>,EGreater> minHeap {};
        for( int j=0; j<K; j++ ){
            for( int i : nums[j] ){
                minHeap.push( Elem{ i, j } );
            }
        }
        while( !minHeap.empty() ){
            elems.push_back( minHeap.top() );
            minHeap.pop();
        }

        int Ne = static_cast<int>(elems.size());

        //== 滑动窗口 ==//
        std::unordered_map<int,int> umap {};//<idx,num> 收集窗口 idxs

        int tgtL = elems.back().val;
        int tgtR = tgtL;
        int minOff = INT_MAX;


        int l=0;
        int r=0;
        for(; r<Ne; r++ ){
            umap[elems[r].idx]++; 

            while( umap.size()==sK ){
                // 现在，获得一个 有效窗口，
                int tlv = elems[l].val;
                int trv = elems[r].val;
                int tOff = trv-tlv;

                if( (tOff<minOff) ||
                    (tOff==minOff && tlv<tgtL) ){
                    tgtL = tlv;
                    tgtR = trv;
                    minOff = tOff;
                }
                //---//
                int lidx = elems[l].idx;
                umap[lidx]--;
                if( umap[lidx]==0 ){ umap.erase(lidx); }
                l++;
            }
        }
        return { tgtL, tgtR };



    }
};




//  测试 快排   90%，  100%
class S2{

struct Elem{
    int val {};
    int idx {};
};

struct ELess{
    bool operator()( const Elem &a, const Elem &b ){
        return a.val < b.val; // 不能写 等于号！！！
    }
};

public:
    // 给定的列表可能包含重复元素，所以在这里升序表示 >=
    // 1 <= k <= 3500
    // -10^5 <= 元素的值 <= 10^5
    // 按照题意，所有 有序数组，都是非空的
    std::vector<int> smallestRange( std::vector<std::vector<int>>& nums ){

        size_t sK = nums.size();
        int K = static_cast<int>(sK);

        //== 将所有元素 放入一个 巨型数组 ==//
        std::vector<Elem> elems {};
        for( int j=0; j<K; j++ ){
            for( int i : nums[j] ){
                elems.push_back( Elem{ i, j } );
            }
        }
        std::sort( elems.begin(), elems.end(), ELess{} );

        int Ne = static_cast<int>(elems.size());

        //== 滑动窗口 ==//
        std::unordered_map<int,int> umap {};//<idx,num> 收集窗口 idxs

        int tgtL = elems.back().val;
        int tgtR = tgtL;
        int minOff = INT_MAX;


        int l=0;
        int r=0;
        for(; r<Ne; r++ ){
            umap[elems[r].idx]++; 

            while( umap.size()==sK ){
                // 现在，获得一个 有效窗口，
                int tlv = elems[l].val;
                int trv = elems[r].val;
                int tOff = trv-tlv;

                if( (tOff<minOff) ||
                    (tOff==minOff && tlv<tgtL) ){
                    tgtL = tlv;
                    tgtR = trv;
                    minOff = tOff;
                }
                //---//
                int lidx = elems[l].idx;
                umap[lidx]--;
                if( umap[lidx]==0 ){ umap.erase(lidx); }
                l++;
            }
        }
        return { tgtL, tgtR };



    }
};





//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 632 :end ~~~~\n" );
}
}//~
