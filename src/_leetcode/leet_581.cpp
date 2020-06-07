/*
 * ====================== leet_581.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 581. 最短无序连续子数组
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_581 {//~


// 单调栈
// 用逆序栈，记录一个 无序区间
// 当栈中元素，从2+ 变为 1个时，就说明，一个无序区间 被确定/清理 了


//    明天继续 ...


class S{

struct Elem{
    int val {};
    int idx {};
};

public:
    // 1<= len <= 10000
    // 包含重复元素，升序的意思是<=
    int findUnsortedSubarray( std::vector<int>& nums ){

        if( nums.size()<2 ){ return 0; }
        int N = static_cast<int>(nums.size());

        std::stack<Elem> stk {};

        int minL = INT_MAX;// idx
        int maxR = INT_MIN;// idx
        bool isLSet = false; // minL 只被设置一次 

        for( int i=0; i<N; i++ ){
            int curVal = nums.at(i);

            if( stk.empty() ){
                stk.push(Elem{curVal,i});
                continue;
            }

            
            while( !stk.empty() && curVal>=stk.top().val ){




            }

        }

        return 0;

    }




    // 简易法  11%, 6%
    // 使用了 sort， 性能很差
    int findUnsortedSubarray_2( std::vector<int>& nums ){

        if( nums.size()<2 ){ return 0; }
        int N = static_cast<int>(nums.size());
        std::vector<int> v2 (nums.begin(), nums.end());
        std::sort( v2.begin(), v2.end() );

        int l = 0;
        int r = N-1;
        for( ; l<N; l++ ){
            if( nums.at(l)!=v2.at(l) ){ break; }
        }
        if( l==N ){ return 0; }
        for( ; r>=0; r-- ){
            if( nums.at(r)!=v2.at(r) ){ break; }
        }
        cout<<"l:"<<l<<" r:"<<r<<endl;
        return r-l+1;
    }


};




//=========================================================//
void main_(){

    std::vector<int> v { 2,6,4,8,10,9,15 };

    cout<<S{}.findUnsortedSubarray_2(v)<<endl;

    
    debug::log( "\n~~~~ leet: 581 :end ~~~~\n" );
}
}//~
