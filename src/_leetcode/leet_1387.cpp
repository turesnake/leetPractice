/*
 * ====================== leet_1387.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.24
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1387. 将整数按权重排序
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1387 {//~




//  48%  100%
class S{


struct Elem{
    int num {};
    int val {};
};


struct ELess{
    bool operator()( const Elem &a, const Elem &b ){
        if( a.num == b.num ){
            return a.val < b.val; 
        }else{
            return a.num < b.num;
        }
    }
};


    std::unordered_map<int,int> dp { {1,0} };//<val,num>

    int calc( int v ){

        if( dp.count(v)>0 ){ return dp[v]; }
        int next = (v&1)==0 ? v/2 : v*3+1;
        int ret = calc(next)+1;
        if( dp.count(v)==0 ){ dp[v]=ret; }
        return ret;
    }


public:
    // 1 <= lo <= hi <= 1000
    // 1 <= k <= hi - lo + 1
    int getKth(int lo, int hi, int k) {

        size_t N = k;
        std::priority_queue<Elem,std::vector<Elem>,ELess> minHeap {};

        for( int i=lo; i<=hi; i++ ){
            Elem e { calc(i), i };
            if( minHeap.size()<N ){
                minHeap.push( e );
                continue;
            }
            if( (e.num<minHeap.top().num ) ||
                (e.num==minHeap.top().num && e.val<minHeap.top().val ) ){
                minHeap.push( e );
            }
            while( minHeap.size() > N ){
                minHeap.pop();
            }
        }
        return minHeap.top().val;


    }
};







//=========================================================//
void main_(){


    auto ret = S{}.getKth( 1,1000,107 );
    cout<<"ret:"<<ret<<endl;

    /*
    S obj {};
    auto ret = obj.calc( 12 );
    cout<<"ret:"<<ret<<endl;
    */


    
    debug::log( "\n~~~~ leet: 1387 :end ~~~~\n" );
}
}//~
