/*
 * ====================== leet_676.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 676. 实现一个魔法字典
 */
#include "innLeet.h"


namespace leet_676 {//~


// 字典树  75%   100%
class MagicDictionary {


struct TrieNode{
    TrieNode(){ childs.resize(26,nullptr); }
    std::vector<TrieNode*> childs {};
    bool    isTail {false};
};

    TrieNode *trie {nullptr};
    std::string *targetWord {nullptr};
    int Ntw {};


    // tp not null
    // bl: 是否已经修改字母了
    // ret: 是否找到 合适的 word
    bool work( TrieNode *tp, int idx, bool isChanged ){

        char curC = targetWord->at(idx);
        int cIdx = curC-'a';
        TrieNode *tgtChild = tp->childs.at(cIdx);

        if( idx==Ntw-1 ){// lst char
            if(isChanged){// 修改已经被使用
                // 只有当 目标字母存在，且是单词尾字母，才成立
                return (tgtChild && tgtChild->isTail);
            }else{// 需要在本次使用修改

                for( int i=0; i<26; i++ ){// each c
                    TrieNode *tmpChild = tp->childs.at(i);
                    if( i==cIdx || (!tmpChild) ){ continue; }
                    if( tmpChild->isTail ){ return true; }// 找到合适的word
                }
                return false;
            }

        }else{// not lst char
            if(isChanged){// 修改已经被使用
                if(!tgtChild){ return false; }
                return work( tgtChild, idx+1, isChanged );
            }else{// 修改没有被使用
                // 本回合不使用修改
                if(tgtChild){
                    bool ret = work( tgtChild, idx+1, false );
                    if(ret){ return true; }// 找到即返回
                }
                // 本回合使用修改
                for( int i=0; i<26; i++ ){// each c
                    TrieNode *tmpChild = tp->childs.at(i);
                    if( i==cIdx || (!tmpChild) ){ continue; }
                    bool ret = work( tmpChild, idx+1, true );
                    if(ret){ return true; }// 找到即返回
                }
                return false;
            }
        }
    }



public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        trie = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict( std::vector<std::string> dict) {

        for( const auto &word : dict ){
            TrieNode *p = trie;
            size_t Nw = word.size();
            for( size_t i=0; i<Nw; i++ ){
                int idx = word.at(i)-'a';
                TrieNode *tgt = p->childs.at(idx);
                if( tgt ){// find
                    p = tgt;
                }else{// nullptr
                    p->childs.at(idx) = new TrieNode();
                    p = p->childs.at(idx);
                }
                if( i==Nw-1 ){// lst
                    p->isTail = true;
                }
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search( std::string word) {
        if(word.empty()){ return false; }
        targetWord = &word;
        Ntw = static_cast<int>(word.size());
        return work( trie, 0, false );
    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 676 :end ~~~~\n" );
}
}//~
