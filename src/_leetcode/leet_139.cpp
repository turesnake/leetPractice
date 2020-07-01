/*
 * ====================== leet_139.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 139. 单词拆分
 */
#include "innLeet.h"


namespace leet_139 {//~



// 字典树 + 回溯 + 倒序的 状态记忆


//  74%   48%
class S{

struct TrieNode{
    TrieNode(){ chars.resize( 26, nullptr ); }
    std::vector<TrieNode*> chars {};
    bool isTail {false};
};

    TrieNode *trie {nullptr};

    void insert( const std::string &word ){
        TrieNode *p = trie;
        size_t N = word.size();
        for( size_t i=0; i<N; i++ ){
            char idx = word[i]-'a';
            if( !p->chars[idx] ){
               p->chars[idx] = new TrieNode();
            }
            p = p->chars[idx];
            if( i==N-1 ){// lst char
                p->isTail = true;
            }
        }
    }

public:
    // 拆分时可以重复使用字典中的单词
    // 你可以假设字典中没有重复的单词
    // s 和 所有 word 都非空
    bool wordBreak( std::string s, std::vector<std::string>& wordDict ){

        trie = new TrieNode();
        for( const auto &word : wordDict ){
            insert( word );
        }

        int Ns = static_cast<int>(s.size());
        std::vector<char> dp (Ns, 0);// 0:不成立   1:成立

        for( int i=Ns-1; i>=0; i-- ){

            TrieNode *p = trie;
            int r=i;
            bool isFindLegal = false;
            for(; r<Ns && p && p->chars[s[r]-'a']; r++ ){
                p = p->chars[s[r]-'a'];
                if( p->isTail  ){
                    if( r==Ns-1 || dp[r+1]==1 ){
                        isFindLegal = true;
                        break;
                    } 
                }
            }
            dp[i] = isFindLegal ? 1 : 0;
        }
        return dp[0]==1;


    }
};






//=========================================================//
void main_(){

    std::string s = "abbc";
    std::vector<std::string> words { "ab", "bc" };

    auto ret = S{}.wordBreak( s, words );

    debug::log( "ret:{}", ret );






    
    debug::log( "\n~~~~ leet: 139 :end ~~~~\n" );
}
}//~
