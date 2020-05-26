/*
 * ====================== leet_513.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 513. 找树左下角的值
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_513 {//~





// bfs
class S{

    struct Elem{
        TreeNode    *tp {nullptr}; //
        int         deep {0};// 根节点为0
        int         wOff {0};// 本节点相对 root 的横向偏移值，最小的最左
    };

public:


    int findBottomLeftValue(TreeNode* root) {

        int maxDeep {INT_MIN};// 值越大，越深
        int minWOff {INT_MAX};// 值越小，越偏左
        int leftVal {0}; 

        std::deque<Elem> que {};
        que.push_back( Elem{root,0,0} );

        while( !que.empty() ){
            auto [tp,deep,wOff] = que.front();
            if( !tp->left && !tp->right ){//自己是 叶节点
                if( deep > maxDeep ){// 刷新深度
                    maxDeep = deep;
                    minWOff = wOff;
                    leftVal = tp->val;
                }else if( deep==maxDeep && wOff<minWOff ){// 与记录同深度
                    minWOff = wOff;
                    leftVal = tp->val;
                }
            }else{
                if( tp->left  ){ que.push_back( Elem{ tp->left,  deep+1, wOff-1 } ); }
                if( tp->right ){ que.push_back( Elem{ tp->right, deep+1, wOff+1 } ); }
            }
            que.pop_front();
        }
        return leftVal ;
    }

};





//=========================================================//
void main_(){

    TreeNode *t = create_a_tree( { 88,77, 9 } );
    print_a_tree( t );
    cout << endl;


    cout << "ret = " << S{}.findBottomLeftValue( t )<<endl;



    debug::log( "\n~~~~ leet: 513 :end ~~~~\n" );
}
}//~
