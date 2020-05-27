/*
 * ====================== leet_m04_03.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"



namespace leet_m04_03 {//~



class S{

struct Elem{
    TreeNode    *tp {nullptr};
    int         deep {0};// based on 0
};

public:

    // bfs
    std::vector<ListNode*> listOfDepth( TreeNode* tree ){

        if( !tree ){ return {}; }

        std::vector<ListNode*> lists {};
        std::deque<Elem> que { Elem{tree,0} };

        while( !que.empty() ){
            auto [tp,deep] = que.front();
            que.pop_front();
            //---//
            ListNode *newL = new ListNode(tp->val);
            if( static_cast<int>(lists.size()) < deep+1 ){
                lists.push_back( newL );
            }else{
                ListNode *p = lists.at(deep);
                while( p->next ){ p = p->next; }
                p->next = newL;
            }
            //---//
            if( tp->left ){  que.push_back( Elem{tp->left,deep+1} ); }
            if( tp->right ){ que.push_back( Elem{tp->right,deep+1} ); }
        }
        return lists;
    }

};



//=========================================================//
void main_(){

    //TreeNode *t = create_a_tree( {1,2,3,4,5,niln,7,8 } );
    TreeNode *t = create_a_tree( { } );

    auto ret = S{}.listOfDepth(t);
    for( ListNode *p : ret ){

        print_list( p, "  " );
        cout << endl;

    }

    

    debug::log( "\n~~~~ leet: m04_03 :end ~~~~\n" );
}
}//~
