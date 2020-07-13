/*
 * ====================== leet_938.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 617. 合并二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_938 {//~



// 这题的实现 其实挺简单，但是不应该使用 中序遍历 这么复杂的思路
// 单纯去 递归思路去解就行了 



// 递归实现 
class S1{

    int sum {0};
    int LL {};
    int RR {};

    // tp 一定非空
    void work( TreeNode *tp ){
        int v = tp->val;
        if( v < LL ){
            // 无需检查 tp->left
            if( tp->right ){ work(tp->right); }
        }else if( v > RR ){
            // 无需检查 tp->right
            if( tp->left ){ work(tp->left); }
        }else{
            // tp->val 自己就在区间内
            sum += v;
            if( tp->left ){ work(tp->left); }
            if( tp->right ){ work(tp->right); }
        }
    }
public:
    int rangeSumBST( TreeNode* root, int L, int R ){
        if( !root || L>R ){ return 0; }
        LL=L;
        RR=R;
        work(root);
        return sum;
    }
};


// bfs 72%, 9%
class S2{
public:
    int rangeSumBST( TreeNode* root, int L, int R ){

        if( !root || L>R ){ return 0; }
        int sum = 0;
        std::deque<TreeNode*> que { root };

        while( !que.empty() ){
            TreeNode *tp = que.front();
            que.pop_front();
            int v = tp->val;
            if( v < L ){
                if( tp->right ){ que.push_back(tp->right); }
            }else if( v > R ){
                if( tp->left ){ que.push_back(tp->left); }
            }else{
                sum += v;
                if( tp->left ){ que.push_back(tp->left); }
                if( tp->right ){ que.push_back(tp->right); }
            }
        }
        return sum;
    }
};





// 迭代实现，思路好像不对
class S_old{
public:

    // 暂未实现
    int rangeSumBST( TreeNode* root, int L, int R ){

        std::stack<TreeNode*> stk {};// 搜索链
        //=== 找到 大于等于 L 的最小值 ===//
        stk.push(root);
        // 确保在退出循环时，目标指针在 stk top 处
        while( !stk.empty() ){
            TreeNode *tp = stk.top();
            if( L==tp->val ){ break; }
            if( L<tp->val ){// 搜索 left
                if( !tp->left ){ break; }// 本元素 就是大于L的最小值
                stk.push(tp->left);
            }else{// 搜索 right
                if( !tp->right ){ 
                    // 从父元素链表记录中，找到第一个 大于L的值
                    while( !stk.empty() && stk.top()->val<L ){ stk.pop(); }
                    break; 
                }
                stk.push(tp->right);
            }
        }
        if( stk.empty() ){ return 0; }// L 比 bst 中最大值还要大
                /*
                cout << "stk.size() = " << stk.size()<<endl;
                while( !stk.empty() ){
                    cout << "  " << stk.top()->val<<", ";
                    stk.pop();
                }cout<<endl;
                */
        int sum = 0;
        //...
        return sum;
    }


    // 模仿中序遍历的方式去实现 
    /*
    int rangeSumBST_2( TreeNode* root, int L, int R ){

        std::stack<TreeNode*> stk {};// 搜索链

        //=== 找到 大于等于 L 的最小值 ===//
        TreeNode *ptr = root; 

        while( ptr || stk.empty() ){

            if( ptr ){
                
                if( L == ptr->val ){
                    stk.push(ptr);
                    break; // L 就是本值

                }else if( L < ptr->val ){// find left


                }else{// find right


                }





                stk.push(ptr);
                ptr=ptr->left;

            }else{

                // visit stk.top()->val

                ptr = stk.top();
                stk.pop();
                ptr = ptr->right;
            }

        }


    }
    */


};










//=========================================================//
void main_(){


    std::vector<int> v { 10,5,15,3,7,niln,18 };

    TreeNode *t = create_a_tree( v );

    cout << S2{}.rangeSumBST( t, 7, 15 ) << endl;


 
    



    debug::log( "\n~~~~ leet: 938 :end ~~~~\n" );
}
}//~
