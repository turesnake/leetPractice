/*
 * ====================== leet_1065.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1065. 字符串的索引对
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1065 {//~



// 字典树  52%  50%
class S{

struct TrieNode{
    TrieNode(){ childs.resize(26,nullptr); }
    std::vector<TrieNode*> childs {};
    bool isTail {false};
};

    TrieNode    *trie {nullptr};
    std::string *textp {nullptr};
    std::vector<std::vector<int>> outs {};


    void insert( const std::string &word ){
        TrieNode *p = trie;
        size_t N = word.size();
        for( size_t i=0; i<N; i++ ){
            int idx = word.at(i)-'a';
            TrieNode *tgt = p->childs.at(idx);
            if(tgt){// find
                p = tgt;
            }else{// not find
                p->childs.at(idx) = new TrieNode();
                p = p->childs.at(idx);
            }
            if( i==N-1 ){
                p->isTail=true;
            }
        }
    }


    void search(){
        int Nt = static_cast<int>(textp->size());
        for( int l=0; l<Nt; l++ ){//
            TrieNode *p = trie;
            for( int r=l; r<Nt; r++ ){
                int idx = textp->at(r)-'a';
                TrieNode *tgt = p->childs.at(idx);
                if(tgt){// find
                    p = tgt;
                }else{// not find
                    break;
                }
                if(p->isTail){
                    outs.push_back( {l,r} );
                }
            }
        }
    }

public:
    // words 中单词无重复
    // 1 <= text.len <= 100
    // 1 <= words.len <= 20
    // 1 <= words[i].len <= 50
    std::vector<std::vector<int>> indexPairs( std::string text, std::vector<std::string>& words ){

        trie = new TrieNode();
        for( const auto &word : words ){
            insert( word );
        }
        textp = &text;
        search();
        return outs;
    }
};


//=========================================================//
void main_(){
    
    debug::log( "\n~~~~ leet: 1065 :end ~~~~\n" );
}
}//~
