/*
 * ====================== leet_116.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 116. 填充每个节点的下一个右侧节点指针
 */
#include "innLeet.h"
//#include "TreeNode1.h"


namespace leet_116 {//~



// 额外存在 next 节点
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};



// bfs 27% 100%
class S{
struct Elem{
    Node *tp {};
    int deep {0};//based on 0 
};

public:
    Node* connect( Node* root ){
        if(!root){ return nullptr; }
        int lstDeep {-1};
        Node *ptr {nullptr}; 
        std::deque<Elem> que {Elem{root,0}};
        while( !que.empty() ){
            auto [tp,deep] = que.front();
            que.pop_front();
            if( deep != lstDeep ){// new lvl
                lstDeep = deep;
                ptr = tp;
            }else{
                tp->next = ptr;
                ptr = tp;
            }
            if(tp->right){ que.push_back(Elem{tp->right,deep+1}); }
            if(tp->left){ que.push_back(Elem{tp->left,deep+1}); }
        }
        return root;
    }
};





//=========================================================//
void main_(){

    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n2 = new Node(2,n4,n5,nullptr);
    Node *n3 = new Node(3,n6,n7,nullptr);
    Node *n1 = new Node(1,n2,n3,nullptr);

    Node *ret = S{}.connect( n1 );




    

    debug::log( "\n~~~~ leet: 116 :end ~~~~\n" );
}
}//~
