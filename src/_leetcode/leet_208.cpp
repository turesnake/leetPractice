/*
 * ====================== leet_208.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_208 {//~


// 更快的方法是 将 字典树中的 umap 换成 数组 

// 字典树  23%  100%
class Trie {

struct TrieNode{
    TrieNode(){ chars.resize( 26, nullptr ); }
    std::vector<TrieNode*> chars {};
    bool    isTail {false};
};

    TrieNode *trie {nullptr};

public:
    /** Initialize your data structure here. */
    Trie() {
        trie = new TrieNode();
    }
    
    // 参数皆为 非空小写str
    /** Inserts a word into the trie. */
    void insert( std::string word) {

        TrieNode *p = trie;
        size_t N = word.size();
        for( size_t i=0; i<N; i++ ){
            int idx = static_cast<int>(word.at(i)-'a');
            TrieNode *targetP = p->chars.at(idx);
            if( targetP ){// find
                p = targetP;
            }else{// not find
                p->chars.at(idx) = new TrieNode();
                p = p->chars.at(idx);
            }
            if( i==N-1 ){
                p->isTail = true;
            }
        }
    }
    
    // 参数皆为 非空小写str
    /** Returns if the word is in the trie. */
    bool search( std::string word) {
        
        TrieNode *p = trie;
        size_t N = word.size();
        for( size_t i=0; i<N; i++ ){
            int idx = static_cast<int>(word.at(i)-'a');
            TrieNode *targetP = p->chars.at(idx);
            if( targetP ){// find
                p = targetP;
            }else{// not find
                return false;
            }
            if( i==N-1 ){
                return p->isTail;
            }
        }
        return false;
    }
    
    // 参数皆为 非空小写str
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith( std::string prefix) {

        TrieNode *p = trie;
        size_t N = prefix.size();
        for( size_t i=0; i<N; i++ ){
            int idx = static_cast<int>(prefix.at(i)-'a');
            TrieNode *targetP = p->chars.at(idx);
            if( targetP ){// find
                p = targetP;
            }else{// not find
                return false;
            }
        }
        return true;
    }
};



//=========================================================//
void main_(){

    Trie tt {};

    tt.insert( "abcd" );
    cout<<tt.search( "abc" )<<endl;
    cout<<tt.startsWith( "abc" )<<endl;

    
    debug::log( "\n~~~~ leet: 208 :end ~~~~\n" );
}
}//~
