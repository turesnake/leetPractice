/*
 * ====================== leet_270.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 270. 最接近的二叉搜索树值
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_270 {//~


// 递归 19%， 25%
class S{

    int left {INT_MIN};
    int right {INT_MAX};
    bool isLeftSet {false};
    bool isRightSet {false};
    double targetVal {};

    // tp 非空
    void work( TreeNode* tp ){
        double v = static_cast<double>(tp->val);
        if( targetVal < v ){// left
            isRightSet = true;
            right = std::min(right,tp->val);
            if(tp->left){ work(tp->left); }
        }else{//right
            isLeftSet = true;
            left = std::max(left,tp->val);
            if(tp->right){ work(tp->right); }
        }
    }

public:
    int closestValue( TreeNode* root, double target ){

        targetVal = target;
        work(root);
        if( !isLeftSet ){ return right; }
        if( !isRightSet ){ return left; }
        bool isLeftClose =  std::abs(static_cast<double>(left)-target) <
                            std::abs(static_cast<double>(right)-target);
        return isLeftClose ? left : right;
    }



};





//=========================================================//
void main_(){

    TreeNode *t = create_a_tree( { 0 } );


    cout<< S{}.closestValue( t, 2147483648.0 );


    

    debug::log( "\n~~~~ leet: 270 :end ~~~~\n" );
}
}//~
