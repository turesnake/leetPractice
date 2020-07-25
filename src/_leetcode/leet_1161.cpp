/*
 * ====================== leet_1161.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1161. 最大层内元素和
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1161 {//~


//   81%  100%
class S{

struct Elem{
    TreeNode* tp {};
    int       deep  {};// base on 0
};

public:
    // 返回值的层数 基于 1， 代码内部，基于0
    // 树中的节点数介于 1 和 10^4 之间
    // -10^5 <= node.val <= 10^5
    int maxLevelSum( TreeNode* root ){


        std::vector<int> layers {};
        std::deque<Elem> que { Elem{root,0} };

        while( !que.empty() ){
            auto [tp,deep] = que.front();
            que.pop_front();
            //---//
            if( layers.size() < static_cast<size_t>(deep+1) ){
                layers.push_back(0);
            }
            layers[deep] += tp->val;
            if( tp->left ){ que.push_back( Elem{tp->left, deep+1} ); }
            if( tp->right ){ que.push_back( Elem{tp->right, deep+1} ); }
        }

        int maxIdx = INT_MIN;
        int maxVal = INT_MIN;

        int N = static_cast<int>(layers.size());

        for( int i=0; i<N; i++ ){
            cout<<"i:"<<i<<", val:"<<layers[i]<<endl;
            if( layers[i] > maxVal ){
                maxIdx = i;
                maxVal = layers[i];
            }
        }
        return maxIdx+1;

    }
};




//=========================================================//
void main_(){





    
    debug::log( "\n~~~~ leet: 1161 :end ~~~~\n" );
}
}//~
