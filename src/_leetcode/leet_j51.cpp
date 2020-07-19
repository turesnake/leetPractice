/*
 * ====================== leet_j51.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 51. 数组中的逆序对
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_j51 {//~


// 已经学会的方法1:
// 树状数组(前缀和) + 元素索引


//   28%   100%
class S{

class Trie{
    std::vector<int> v {};// [0]空置
    int N {};
    int lowbit( int v ){ return v&(-v); }
public:
    Trie()=default;

    void init( int n ){
        N = n+1;
        v.resize(N,0);
    }

    void add( int idx, int addval ){
        idx++;
        while( idx<N ){
            v[idx] += addval;
            idx += lowbit(idx);
        }
    }

    // 前缀和，但不包含自身元素
    int merge( int idx ){
        idx++;
        int sum = 0;
        while( idx>0 ){
            sum += v[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }
};

    Trie trie {};


public:
    // 0 <= 数组长度 <= 50000
    int reversePairs( std::vector<int>& nums) {


        if( nums.empty() ){ return 0; }

        std::set<int> sset ( nums.begin(), nums.end() );
        std::vector<int> elems ( sset.begin(), sset.end() );

        std::unordered_map<int,int> umap {};//<val,idx>
        
        int Ne = static_cast<int>(elems.size());
        for( int i=0; i<Ne; i++ ){
            umap.emplace(elems[i], i);
        }
        trie.init( Ne );

        int sum = 0;
        int Nn = static_cast<int>(nums.size());
        trie.add( umap.at(nums[Nn-1]), 1 );
        
        for( int i=Nn-2; i>=0; i-- ){
            int idx = umap.at(nums[i]);
            if( idx>0 ){
                sum += trie.merge( idx-1 );
            }
            trie.add( idx, 1 );
        }
        return sum;



    }
};



//=========================================================//
void main_(){

    
    std::vector<int> v {  7,5,6,4 };
    auto ret = S{}.reversePairs(v);
    cout<<"ret:"<<ret<<endl;





    debug::log( "\n~~~~ leet: j51 :end ~~~~\n" );
}
}//~
