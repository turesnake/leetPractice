/*
 * ====================== leet_720.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 720. 词典中最长的单词
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_720 {//~




// 字典树 36%，  33%
class S{

    struct TireNode{
        TireNode()=default;
        std::unordered_map<char,TireNode*> umap {};
        int  wordIdx  {-1}; // 如果自己是 word尾字符，记录自己word 在 vector 中下标 
    };


    std::vector<std::string> *wordsp {};
    TireNode *trie {};
    int     targetWordIdx {-1};
    size_t  maxLen {0};


    void insert( const std::string &word, int wordIdx ){
        TireNode *p = trie;
        int N = static_cast<int>(word.size());
        for( int i=0; i<N; i++ ){
            char c = word.at(i);
            auto fit = p->umap.find(c);
            if( fit!=p->umap.end() ){//find
                p = fit->second;
            }else{// not find
                auto [it,bl] = p->umap.emplace(c, new TireNode() );
                p = it->second;
            }
            if( i==N-1 ){ p->wordIdx = wordIdx; }
        }
    }

    // dfs 回溯
    void search_trie( TireNode *p ){

        if( p->wordIdx>=0 && p->wordIdx!=INT_MAX ){
            // 捕获一个单词，做 比较
            size_t wordLen = wordsp->at(p->wordIdx).size();
            if( wordLen > maxLen ){
                maxLen = wordLen;
                targetWordIdx = p->wordIdx;
            }else if( wordLen == maxLen ){// 需要比较 字典序
                const auto &w1 = wordsp->at(p->wordIdx);
                const auto &w2 = wordsp->at(targetWordIdx);
                if( w1.compare(w2)<0 ){
                    targetWordIdx = p->wordIdx;
                }
            }
        }else if( p->wordIdx<0 ){// 后面不再连续 
            return;
        }
        if( p->umap.empty() ){// leaf
            return;
        }
        for( auto [c,tp] : p->umap ){
            search_trie( tp );
        }
    }


public:
    // 1<= len <= 1000
    // 1<= [i].len <= 30
    std::string longestWord( std::vector<std::string>& words ){

        trie = new TireNode();
        trie->wordIdx = INT_MAX;
        wordsp = &words;
        int Nv = static_cast<int>(words.size());
        for( int i=0; i<Nv; i++ ){
            insert( words.at(i), i );
        }
        search_trie( trie );
        return (targetWordIdx<0) ? "" : words.at(targetWordIdx);
    }
};





//=========================================================//
void main_(){

    //std::vector<std::string> v { "w","wo","wor","worl", "world" };
    std::vector<std::string> v { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    //std::vector<std::string> v { "a", "ap", "app", "appl", "apple" };
    //std::vector<std::string> v { "1","12","123" };
    //std::vector<std::string> v { "123","1","12" };


    cout << "ret:"<<S{}.longestWord(v) << endl;




    
    debug::log( "\n~~~~ leet: 720 :end ~~~~\n" );
}
}//~
