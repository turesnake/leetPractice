/*
 * ====================== leet_648.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 648. 单词替换
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_648 {//~



// 字典树  66%,  66%
class S{

struct TrieNode{
    TrieNode(){ childs.resize( 26, nullptr ); }
    std::vector<TrieNode*> childs {};
    bool isTail {false};
};

    TrieNode *trie {nullptr};

    void insert_2_trie( const std::string &word ){
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
            if( i==N-1 ){// lst node
                p->isTail = true;
            }
        }
    }


    // reture word-root rightEndChar (include)
    size_t find_rootIdx( const std::string &word ){
        TrieNode *p = trie;
        size_t N = word.size();
        for( size_t i=0; i<N; i++ ){
            int idx = word.at(i)-'a';
            TrieNode *tgt = p->childs.at(idx);
            if(tgt){// find
                p = tgt;
            }else{// not find
                return N-1;// 不存在 root
            }
            if( p->isTail ){
                return i;
            }
        }
        return N-1;// 不存在 root
    }


public:
    // 1 <= dict.len <= 1000
    // 1 <= dict[i].len <= 100
    // 1 <= 句中词语数 <= 1000
    // 1 <= 句中词语长度 <= 1000
    std::string replaceWords( std::vector<std::string>& dict, std::string sentence ){


        trie = new TrieNode();
        for( const auto &s : dict ){
            insert_2_trie(s);
        }

        // 收集句中单词
        std::vector<std::string> words {};
        std::unordered_map<std::string,std::string> umap {};//<originWord,root>
        int Ns = static_cast<int>(sentence.size());
        int l = 0;
        int r = 0;
        while( l<Ns && r<Ns ){
            // find fst char
            for( ; l<Ns && sentence.at(l)==' '; l++ ){}
            r = l;
            for( ; r<Ns && sentence.at(r)!=' '; r++ ){}
            std::string newW ( sentence, l, r-l );
            //cout<<" newW:{"<< newW << "};" <<endl;
            words.push_back( newW );
            umap.emplace( newW, "" );
            l = r;// 单词后一格
        }

        // 为每个词，生成 最短词根
        for( auto &[word,root] : umap ){
            root.assign( word, 0, find_rootIdx(word)+1 );
            //cout<<"root:"<<root<<endl;
        }

        std::string out {};
        for( const auto &word : words ){
            out += umap.at(word);
            out += " ";
        }
        out.pop_back();
        return out;
    }
};



//=========================================================//
void main_(){

    std::vector<std::string> v {
        "cat","bat","rat"
    };
    std::string sss { "   the cattle was rattled by the battery" };

    cout<<"ret:"<<S{}.replaceWords( v, sss )<<endl;




    
    debug::log( "\n~~~~ leet: 648 :end ~~~~\n" );
}
}//~
