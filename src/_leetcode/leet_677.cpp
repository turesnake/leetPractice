/*
 * ====================== leet_677.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 677. 键值映射
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_677 {//~


// 字典树  41%  100%
class MapSum {


struct TrieNode{
    TrieNode(){childs.resize( 26, nullptr ); }
    std::vector<TrieNode*> childs {};
    int  sum    {0}; // 自己已经所有 子树 值的总和
    int  val    {0};// 自身值
    bool isTail {false}; // == true 说明 已经被设置过了 
};

    TrieNode *trie {nullptr};

public:
    /** Initialize your data structure here. */
    MapSum() {
        trie = new TrieNode();
    }
    
    void insert( std::string key, int val) {

        std::vector<TrieNode*> road { trie };
        int off {};
        TrieNode *p = trie;
        size_t N = key.size();
        for( size_t i=0; i<N; i++ ){
            size_t idx = static_cast<size_t>(key.at(i)-'a');
            TrieNode *target = p->childs.at(idx);
            if(target){// find
                p = target;
            }else{// not find
                p->childs.at(idx) = new TrieNode();
                p = p->childs.at(idx);
            }
            road.push_back(p);
            if( i==N-1 ){// lst node
                if(p->isTail){
                    off = val - p->val;
                    p->val = val;
                }else{
                    p->isTail = true;
                    off = val;
                    p->val = val;
                }
            }
        }
        //--//
        for( TrieNode *tp : road ){
            tp->sum += off;
        }
    }
    
    int sum( std::string prefix) {

        TrieNode *p = trie;
        size_t N = prefix.size();
        for( size_t i=0; i<N; i++ ){
            size_t idx = static_cast<size_t>(prefix.at(i)-'a');
            TrieNode *target = p->childs.at(idx);
            if(target){// find
                p = target;
            }else{// not find
                return 0;
            }
        }
        return p->sum;
    }
};


//=========================================================//
void main_(){

    MapSum ms {};

    ms.insert( "abs", 1 );
    ms.insert( "abc", 2 );
    ms.insert( "abkkk", 3 );
    cout<< ms.sum( "abc" )<<endl;






    
    debug::log( "\n~~~~ leet: 677 :end ~~~~\n" );
}
}//~
