/*
 * ====================== leet_1255.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1255. 得分最高的单词集合
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1255 {//~

// -1- 收集 能被拼出来的单词， 字母/个数
// dfs + 回溯



//   86%   100%
class S{

struct Elem{
    Elem( std::unordered_map<char,int> &&umap_, int value_ ):
        umap(umap_),value(value_){}
    std::unordered_map<char,int> umap;
    int                          value;// 单词价值
};


    std::vector<char> letterNums    {};//目标字符 存在个数
    std::vector<Elem> legalWords {};// 能被拼出来的单词
    int Nlw {};
    int outSum {0};

    // idx 访问 legalWords
    void work( int idx, int sum ){

        if( idx >= Nlw ){
            outSum = std::max( outSum, sum );
            return;
        }

        // 检查 可否累加 本回合的单词
        bool isCan = true;
        for( auto [c,n] : legalWords[idx].umap ){
            if( letterNums[c-'a'] < n ){
                isCan=false;
                break;
            }
        }
        // 本单词加不下了，跳过本回合单词
        if( !isCan ){
            work( idx+1, sum );// 易错点，本回合无法累加，不意味着线路的终止！！！
            return;
        }

        // -1- 采用 本回合单词
        for( auto [c,n] : legalWords[idx].umap ){
            letterNums[c-'a'] -= n;
        }
        work( idx+1, sum+legalWords[idx].value );
        for( auto [c,n] : legalWords[idx].umap ){
            letterNums[c-'a'] += n;
        }
        // -2- 跳过 本回合单词
        work( idx+1, sum );
    }


public:
    // 1 <= words.length <= 14
    // 1 <= words[i].length <= 15
    // 1 <= letters.length <= 100
    // letters[i].length == 1
    // score.length == 26
    // 0 <= score[i] <= 10
    // words[i] 和 letters[i] 只包含小写的英文字母
    int maxScoreWords( std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {

        // 统计 可用字符 个数
        letterNums.resize( 26, 0 );
        for( char c : letters ){
            letterNums[c-'a']++;
        }

        // 收集所有 可以被 拼写的单词
        for( const auto &word : words ){
            std::unordered_map<char,int> umap {};
            for( char c : word ){
                umap[c]++;
            }
            bool isLegal = true;
            for( const auto [c,n] : umap ){
                if( letterNums[c-'a'] < n ){
                    isLegal=false;
                    break;
                }
            }
            if( isLegal ){
                int value = 0;
                for( const auto [c,n] : umap ){
                    value += score[c-'a'] * n;
                }
                if( value>0 ){// 没价值的单词直接忽略
                    legalWords.emplace_back( std::move(umap), value );
                }
            }
        }
        Nlw = static_cast<int>(legalWords.size());
        work(0,0);
        return outSum;

    }
};



//=========================================================//
void main_(){

    std::vector<std::string> words { "da","ac","aba","abcc","cadc" };
    std::vector<char> letters { 'a','a','a','a','b','c','c','c','d','d','d' };
    std::vector<int> score { 3,7,9,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    auto ret = S{}.maxScoreWords( words, letters, score );
    cout<<"ret:"<<ret<<endl;




    debug::log( "\n~~~~ leet: 1255 :end ~~~~\n" );
}
}//~
