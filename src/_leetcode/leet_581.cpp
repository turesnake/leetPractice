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


// -- 单调栈
// -- 双向遍历法
// -- 简易排序法


class S{

struct Elem{
    int val {};
    int idx {};
};


public:

    // 单调栈：双栈：递增栈+递减栈 32%， 6%
    // 分别检测 左右边界 
    // 1<= len <= 10000
    // 包含重复元素，升序的意思是<=
    int findUnsortedSubarray_3( std::vector<int>& nums ){

        if( nums.size()<2 ){ return 0; }
        int N = static_cast<int>(nums.size());
        std::stack<Elem> rise {};// 递增栈
        std::stack<Elem> down {};// 递减栈
        int minL = INT_MAX;// idx
        int maxR = INT_MIN;// idx
        bool isFind = false; // 是否找到 无序区间

        for( int i=0; i<N; i++ ){
            int curVal = nums.at(i);
            //=== rise ===//
            if( rise.empty() ){
                rise.push(Elem{curVal,i});
            }else{
                if( curVal > rise.top().val ){
                    rise.push(Elem{curVal,i});

                }else if( curVal < rise.top().val ){
                    while( !rise.empty() && curVal<rise.top().val ){
                        isFind = true;
                        minL = std::min(minL, rise.top().idx);
                        rise.pop();
                    }
                    rise.push(Elem{curVal,i});
                }// 值相等时，不做操作 
            }
            //=== down ===//
            if( down.empty() ){
                down.push(Elem{curVal,i});
            }else{
                if( curVal < down.top().val ){
                    down.push(Elem{curVal,i});

                }else if( curVal > down.top().val ){
                    bool isStkMulti = down.size()>1;// 执行清洗之前，栈元素是否为2个或以上
                    while( !down.empty() && curVal>=down.top().val ){
                        down.pop();
                    }// 可能会把整个栈删空
                    if( down.empty() && isStkMulti ){// 原有的逆序区间 被彻底清楚了
                        maxR = std::max( maxR, i-1);
                    }
                    down.push(Elem{curVal,i});
                }// 相等时，不做操作
            }
        }
        if( down.size()>1 ){//仍有逆序区 没有被消除 
            //cout<<"NN"<<endl;
            maxR = N-1;
        }
        //cout<<"l:"<<minL << "  r:"<<maxR<<endl;
        return isFind ? (maxR-minL+1) : 0;
    }



    // 简易排序法  11%, 6%
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


    // 双向遍历法 68%, 6%
    // 正序遍历，维护当前找到的最大值，确定无序区间右边界
    // 反向遍历，维护当前找到的最小值，确定无序区间左边界
    int findUnsortedSubarray_4( std::vector<int>& nums ){

        if( nums.size()<2 ){ return 0; }
        int N = static_cast<int>(nums.size());
        int l = 0;
        int r = 0;
        bool isFind = false; // 是否找到无序区间
        int mmax = nums.at(0); // 当前找到的最大值
        for( int i=1; i<N; i++ ){
            int curVal = nums.at(i);
            if( curVal > mmax ){
                mmax = curVal;
            }else if( curVal < mmax ){
                isFind = true;
                r = i;
            }
        }
        if( !isFind ){ return 0; }
        int mmin = nums.at(N-1); // 当前找到的最小值
        for( int i=N-2; i>=0; i-- ){
            int curVal = nums.at(i);
            if( curVal < mmin ){
                mmin = curVal;
            }else if( curVal > mmin ){
                l = i;
            }
        }
        return r-l+1;
    }

};




//=========================================================//
void main_(){

    std::vector<int> v { 1,3,2,3,3 };
    //std::vector<int> v { 1,2,3,4 };
    //std::vector<int> v { 1,2,4,5,3 };
    //std::vector<int> v { 2,6,4,8,10,9,15 };
    //std::vector<int> v { 2,6,6,6,4,8,10,9,15 };


    cout<<S{}.findUnsortedSubarray_4(v)<<endl;

    
    debug::log( "\n~~~~ leet: 581 :end ~~~~\n" );
}
}//~
