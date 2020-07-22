/*
 * ====================== leet_30.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 30. 串联所有单词的子串
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_30 {//~


// 这题有一个 被忽略的 条件：
// words 中单词 长度都 一样


//  字典树+回溯
//  实现正确，但在 172/173 中超时
class S{

class DTreeNode{
public:
    DTreeNode(){ childs.resize( 26, nullptr ); }
    std::vector<DTreeNode*> childs {};
    std::vector<int> tailIdxs {};// 单词可重复
};

    DTreeNode *dtree {nullptr};

    std::string *sp  {nullptr};
    std::vector<int> outs {};
    int Ns {};
    int Nw {};
    int NallWords {};// words 所有单词拼合长度

    std::unordered_set<int> useds {};// 已经使用的 单词idx


    void dtree_insert( const std::string &s, int idx ){
        int N = static_cast<int>(s.size());
        DTreeNode *p = dtree;
        for( int i=0; i<N; i++ ){
            char c = s[i];
            if( !p->childs[c-'a'] ){
                p->childs[c-'a'] = new DTreeNode();
            }
            p = p->childs[c-'a'];
            if( i==N-1 ){// lst char
                p->tailIdxs.push_back( idx );
            }
        }
    }

    // 一个回合，就是一个单词
    void rec( int sidx_ ){

        if( static_cast<int>(useds.size())==Nw ){
            outs.push_back( sidx_-NallWords );
            return;
        }
        if( sidx_ >= Ns ){
            return;
        }

        DTreeNode *p = dtree;

        for( int si=sidx_; si<Ns && p->childs[sp->at(si)-'a']; si++ ){
            p = p->childs[sp->at(si)-'a'];
            if( p->tailIdxs.empty() ){ continue; }

            for( int widx : p->tailIdxs ){
                if( useds.count(widx)==0 ){// 找到一个 可用的 单词
                    useds.insert( widx );// 登记
                    rec( si+1 );
                    useds.erase( widx );// 释放
                    break;// 重复单词，在一个位置只用一次
                }
            }
        }

    }

public:
    // s, words[i] 可为 空
    // words 中 单词可以是 重复的
    std::vector<int> findSubstring( std::string s, std::vector<std::string>& words ){

        Ns = static_cast<int>(s.size());
        Nw = static_cast<int>(words.size());
        //== 边界情况 ==//
        if( words.empty() ){ return {}; }
        if( words.size()==1 && words[0]=="" ){// words={""};
            if( s.empty() ){ return {0}; }
            for( int i=0; i<=Ns; i++ ){
                outs.push_back(i);
            }
            return outs;
        }
        if( s.empty() ){ return {}; }

        //== 准备数据 ==//
        sp = &s;

        //===  搭建 字典树  ===//
        dtree = new DTreeNode();

        for( int i=0; i<Nw; i++ ){
            if( words[i]=="" ){ return {}; }// words 包含 “” 及其它单词时，一定返回 空解
            dtree_insert( words[i], i );
            NallWords += static_cast<int>(words[i].size());
        }

        for( int i=0; i<=Ns-NallWords; i++ ){
            rec( i );
        }

        return outs;

    }
};



// 官方思路
// 核心思想就是 words 中单词等长，所以，可以用 hash 检测法 来快速检测

// 本质上还是 hash 思维

// 但是，存在一个 细微的 优化，
// 每次步进 wordLen 长度，只需要做 添头去尾 的操作就行。实际遍历 是 线性的


//   97%  100%
class S2{
public:
    // s, words[i] 可为 空
    // words 中 单词可以是 重复的
    std::vector<int> findSubstring( std::string s, std::vector<std::string>& words ){


        int Ns = static_cast<int>(s.size());
        int Nw = static_cast<int>(words.size());
        std::vector<int> outs {};
        //== 边界情况 ==//
        if( words.empty() ){ return {}; }
        if( words.size()==1 && words[0]=="" ){// words={""};
            if( s.empty() ){ return {0}; }
            for( int i=0; i<=Ns; i++ ){
                outs.push_back(i);
            }
            return outs;
        }
        if( s.empty() ){ return {}; }
        //====//
        int wordLen = static_cast<int>(words[0].size());
        int totalLen = wordLen * Nw;// 所有单词组合长度

        std::unordered_map<std::string,int> uwords {};//<str,num>
        for( const auto &word : words ){
            uwords[word]++;
        }

        std::unordered_map<std::string,int> twords {};//<str,num> 遍历时使用

        for( int off=0; off<wordLen; off++ ){// 小优化
            twords.clear();
            for( int i=off; i+totalLen-1<Ns; ){

                if( twords.empty() ){//== 第一回合 ==//

                    bool isLegal = true;     //区间是否为正确单词 
                    bool isNotTooMuch = true;//区间单词数量是否超了
                    int j=0;
                    for(; j<Nw; j++ ){
                        std::string chip ( s, i+j*wordLen, wordLen );
                        if( uwords.count(chip)==0 ){ 
                            isLegal=false; 
                            break; 
                        }
                        twords[chip]++;
                        if( isNotTooMuch && twords[chip]>uwords[chip] ){
                            isNotTooMuch=false;
                        }
                    }

                    if( !isLegal ){
                        // 从 j 后面一个区间 重新开始
                        twords.clear();
                        i = i+(j+1)*wordLen;
                        continue;
                    }

                    if( isNotTooMuch ){ outs.push_back(i); }
                    i += wordLen;
                    

                }else{//== 非第一回合 ==//
                    std::string lst ( s, i-wordLen, wordLen );// 将被减掉的区间
                    std::string neo ( s, i+(Nw-1)*wordLen, wordLen );// 将被加上的区间

                    twords.at(lst)--;
                    if( uwords.count(neo)==0 ){// 新区间单词非法
                        twords.clear();
                        i += totalLen;
                        continue;
                    }
                    twords[neo]++;

                    bool isNotTooMuch = true;//区间单词数量是否超了
                    for( auto &[chip,n] : twords ){
                        if( isNotTooMuch && n>uwords[chip] ){
                            isNotTooMuch = false;
                        }
                    }
                    if( isNotTooMuch ){ outs.push_back(i); }
                    i += wordLen;
                }
            }
        }

        return outs;
    }
};





//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 30 :end ~~~~\n" );
}
}//~
