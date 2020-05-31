/*
 * ====================== leet_m04_04.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 04.04. 检查平衡性
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m04_04 {//~


class S{

    struct Elem{
        int  deep {0};
        bool isB  {true};
    };

    //<deep,bl>
    Elem work( TreeNode* tp ){
        Elem l = (tp->left) ? work(tp->left) : Elem{0,true};
        if( !l.isB ){ return Elem{0,false}; }
        Elem r = (tp->right) ? work(tp->right) : Elem{0,true};
        if( !r.isB || std::abs(l.deep-r.deep)>1 ){ return Elem{0,false}; }
        return Elem{std::max(l.deep,r.deep)+1, true};
    }

public:
    bool isBalanced( TreeNode* root ){
        if( !root ){ return true; }
        return work(root).isB;
    }
};




//=========================================================//
void main_(){


    

    debug::log( "\n~~~~ leet: m04_04 :end ~~~~\n" );
}
}//~
