/*
 * ====================== leet_269.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 269. 火星词典
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_269 {//~


// 图：拓扑排序


// 单词头字母，也构成一个 新单词
// 单字母单词无意义，被剔除
// 单词内重复字母无意义，被精简


// 这题在描述上存在一个 巨大的 问题：
// 只有单词间 才有顺序
// 单词内部的字符之间，是无序的



// 还存在一个 细节：
// 参数 {"abc","ab"} 最终将输出 "", 因为 这个字典序本身 就是错的



//  bfs   90%   100%
class S{
public:
    // 全为 小写字母
    // 若参数 顺序不合法，返回 ""
    // 若存在多种排列可能，返回任意一个
    // 参数内 单词非空
    std::string alienOrder( std::vector<std::string>& words ){


        if( words.empty() ){ return ""; }

        //== 统计所有出现的 字符 ==//
        std::vector<int> chars (26,0); // 记录所有 单词 
        for( const auto &word : words ){
            for( char c : word ){ chars[c-'a']++; }
        }
        //=========//
        std::unordered_map<char,int> indegrees {};
        std::unordered_map<char,std::unordered_set<char>> nexts {};
        std::deque<char> que {};
        std::string outStr {};
        int count = 0; // 出现 字母数
        //---//
        for( int i=0; i<26; i++ ){
            if( chars[i]>0 ){ 
                indegrees['a'+i] = 0;// create
                count++; 
            }
        }
        //== 收集 字符间关系 ==//
        int N = static_cast<int>(words.size());
        for( int l=0; l<N-1; l++ ){
            const auto &s1 = words[l]; 
            const auto &s2 = words[l+1];
            int Nmin = static_cast<int>( std::min(s1.size(),s2.size()) );

            int i=0;
            for(; i<Nmin && s1[i]==s2[i]; i++ ){}
            if( i==Nmin ){// 重合区间内，字符都相同
                if( s1.size()>s2.size() ){ return ""; }// 绝对错误的 字典序
                continue;
            }
            // 现在，i 指向第一个 相异的 字符
            char lc = s1[i];
            char rc = s2[i];
            if( nexts.count(lc)==0 || nexts[lc].count(rc)==0 ){
                nexts[lc].insert(rc);// 只加载一次
                indegrees[rc]++;
            }
        }
        //for( auto [c,n] : indegrees ){ cout<<" "<<c<<":"<<n<<",";}cout<<endl;
        for( auto [c,n] : indegrees ){
            if( n==0 ){
                que.push_back(c);
                outStr.push_back(c);
                count--;
            }
        }
        while( !que.empty() ){
            char tgtC = que.front();
            que.pop_front();
            for( char b : nexts[tgtC] ){
                indegrees[b]--;
                if( indegrees[b]==0 ){
                    que.push_back(b);
                    outStr.push_back(b);
                    count--;
                }
            }
        }
        return count==0 ? outStr : "";


        
    }
};


//=========================================================//
void main_(){

    std::vector<std::string> v {
        "wrt",
        "wrf",
        "er",
        "ett",
        "rftt"
    };

    auto ret = S{}.alienOrder(v);

    cout<<"ret:"<<ret<<endl;

    
    debug::log( "\n~~~~ leet: 269 :end ~~~~\n" );
}
}//~
