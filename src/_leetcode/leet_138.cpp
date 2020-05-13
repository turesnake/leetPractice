/*
 * ====================== leet_138.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.01.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 复制带随机指针的链表  
 */
#include "innLeet.h"


namespace leet_138 {//~


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};




Node* copyRandomList(Node* head) {

    std::unordered_map<Node*,size_t> oldNodePtrs {};
    std::vector<Node*> newNodePtrs {};

    Node *root  {nullptr};
    Node *p     {nullptr};

    Node *originP = head;

    size_t idx {0};
    while( originP ){

        Node* newP = new Node ( originP->val );

        oldNodePtrs.emplace( originP, idx );
        newNodePtrs.push_back( newP );

        if( originP == head ){
            root = newP;
            p = root;
        }else{
            p->next = newP;
            p = p->next;
        }

        //=======
        idx++;
        originP = originP->next;
    }

    p = root;
    originP = head;
    idx = 0;
    while( originP ){

        (originP->random) ?
            p->random = newNodePtrs.at( oldNodePtrs.find(originP->random)->second ) :
            p->random = nullptr;

        //=======
        idx++;
        originP = originP->next;
        p = p->next;
    }

    return root;
}





// pair <val, randIdx>
Node* create_node_list( std::vector<std::pair<int,int>> v_ ){

    // 每个 node 指针
    std::vector<Node*> nodePtrs {};

    Node *root  {nullptr};
    Node *p     {nullptr};

    size_t count {0};
    while ( count < v_.size() ){

        Node* newP = new Node ( v_.at(count).first );
        nodePtrs.push_back( newP );

        if( count == 0 ){
            root = newP;
            p = root;
        }else{
            p->next = newP;
            p = p->next;
        }
        //--
        count++;
    }

    p = root;
    count = 0;
    while ( count < v_.size() ){

        int randPIdx = v_.at(count).second;

        if( randPIdx < 0 ){
            p->random = nullptr;
        }else{
            p->random = nodePtrs.at( randPIdx );
        }
        //--
        p = p->next;
        count++;
    }

    return root;
}



void print_node_list( Node *list_, const std::string &str_ ){
    debug::log( "{}:", str_ );
    Node *p = list_;
    while( p ){
        debug::log( "    {}, {}, {}", 
            p->val,
            (uint64_t)p, 
            (uint64_t)p->random 
        );
        p = p->next;
    }
    debug::log( "\n" );
}



//=========================================================//
void main_(){

    
    Node *list_1 = create_node_list({
        {7,-1}, {13,0}, {11,4}, {10,2}, {1,0}
    });
    Node *list_2 = create_node_list({
        {1,1}, {2,1}
    });
    Node *list_3 = create_node_list({
        {3,-1}, {3,0},{3,-1}
    });
    Node *list_4 = create_node_list({
    });

    Node *list_1c = copyRandomList( list_1 );
    Node *list_2c = copyRandomList( list_2 );
    Node *list_3c = copyRandomList( list_3 );
    Node *list_4c = copyRandomList( list_4 );


    print_node_list( list_1, "list_1" );
    print_node_list( list_1c, "list_1c" );

    print_node_list( list_2, "list_2" );
    print_node_list( list_2c, "list_2c" );

    print_node_list( list_3, "list_3" );
    print_node_list( list_3c, "list_3c" );

    print_node_list( list_4, "list_4" );
    print_node_list( list_4c, "list_4c" );


    debug::log( "\n~~~~ leet :end ~~~~\n" );
}
}//~
