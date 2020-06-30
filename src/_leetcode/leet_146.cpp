/*
 * ====================== leet_146.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 146. LRU缓存机制
 */
#include "innLeet.h"


namespace leet_146 {//~



// 双向指针，实现队列



//     未完工...



class LRUCache{


struct Node{
    Node()=default;
    Node( int k_, int v_, Node *l_, Node *r_ ):key(k_),val(v_),left(l_),right(r_){}
    int key {0};
    int val {0};
    Node *left {nullptr};
    Node *right {nullptr};
};


    std::unordered_map<int, Node> umap {};
    size_t N {};

    Node *queFront {nullptr}; // use right
    Node *queBack  {nullptr};  // use left


    // 将目标node，更新到 尾端
    void update( Node &node ){
        if( node.right == queBack  ){ return; }// 已经在尾部

        if( node.left != nullptr ){
            node.left->right = node.right;
            node.right->left = node.left;
        }

        Node &newLeft = *(queBack->left);

        newLeft.right = &node;
        queBack->left = &node;

        node.left = &newLeft;
        node.right = queBack;
    }


public:
    LRUCache(int capacity) {

        queFront = new Node( -77, 0, nullptr, nullptr );
        queBack  = new Node( -99, 0, nullptr, nullptr );
        N = capacity;
        assert( N>0 );
    }
    
    int get(int key) {
        if( umap.count(key)==0 ){ return -1; }
        int tgtVal = umap[key].val;
        update( umap[key] );
        return tgtVal;
    }
    


    void put(int key, int value) {
        
        // 仅仅是 数据更新
        if( !umap.empty() && umap.count(key)>0 ){// find
            umap[key].val = value;
            update( umap[key] );
            return;
        }

        // 需要当成新元素 添加
        if( umap.empty() || N==1 ){
            umap.clear();
            auto [it,bl] = umap.emplace( key, Node{ key, value, queFront, queBack } );
            queFront->right = &it->second;
            queBack->left = &it->second;

        }else{
            // 删除
            if( umap.size() == N ){
                cout<<"-1- key:"<<key<<endl;
                Node &newFrontNode = *(queFront->right->right);
                cout<<"-2- key:"<<key<<endl;

                int delKey = queFront->right->key;
                cout<<"delkey:"<<delKey<<endl;

                queFront->right = &newFrontNode;
                cout<<"--a--"<<endl;

                newFrontNode.left = queFront;

                cout<<"--aa--"<<endl;

                umap.erase(delKey);
            }
            // 添加
            auto [it,bl] = umap.emplace( key, Node{ key, value, queFront, queBack } );
            update( it->second );
        }

    }
};





//=========================================================//
void main_(){

    LRUCache cc {2};

    cc.put( 1,1 );
    cc.put( 2,2 );
    cc.get( 1 );
    cc.put( 3,3 );
    cc.get( 2 );
    cc.put( 4,4 );
    //cc.get( 1 );
    //cc.get( 3 );
    //cc.get( 4 );







    
    debug::log( "\n~~~~ leet: 146 :end ~~~~\n" );
}
}//~
