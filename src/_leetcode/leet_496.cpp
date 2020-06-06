/*
 * ====================== leet_496.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 496. 下一个更大元素 I
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_496 {//~


// 由于混合了 umap，实际实现起来，更繁琐了


// 单调栈 72% 50%
class S{
public:
    // nums1 是 nums2 的子集
    std::vector<int> nextGreaterElement( std::vector<int>& nums1, std::vector<int>& nums2 ){

        if( nums1.empty() ){ return {}; }
        int N1 = static_cast<int>(nums1.size());
        int N2 = static_cast<int>(nums2.size());

        std::vector<int> outs (N1, -1);
        std::unordered_map<int,int> umap {};// <val,idx> 存放 nums1 中元素
        for( int i=0; i<N1; i++ ){
            umap.emplace(nums1.at(i), i);
        }

        std::stack<int> stk {};// 递减单调栈，val
        for( int i=0; i<N2; i++ ){
            int curVal = nums2.at(i);
            if( stk.empty() && umap.find(curVal)!=umap.end() ){
                stk.push(curVal);
                continue;
            }
            while( !stk.empty() && curVal>stk.top() ){
                int topVal = stk.top();
                stk.pop();
                outs.at(umap.at(topVal)) = curVal;
                umap.erase(topVal);
            }
            // 仅当 curVal 属于 nums1 时，才被压入 stk
            if( umap.find(curVal)!=umap.end() ){// 存在 
                stk.push(curVal);
            }
        }
        // 最后，栈中剩余一些元素，它们找不到比自己更大的值，
        // 一律写 -1 
        return outs;
    }
};



//=========================================================//
void main_(){

    std::vector<int> n1 { 4,1,2 };
    std::vector<int> n2 { 1,3,4,2 };

    auto ret = S{}.nextGreaterElement( n1, n2 );

    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;

    
    debug::log( "\n~~~~ leet: 496 :end ~~~~\n" );
}
}//~
