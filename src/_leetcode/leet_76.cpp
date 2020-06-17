/*
 * ===================== leet_76.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 76. 最小覆盖子串
 */
#include "innLeet.h"


namespace leet_76 {//~


//    5%   6%
// 自己捣鼓的办法
// 用一个比较复杂的结构，来维护每个 关键字母的 下标
// 同时维护一个 区间边界

// 区间只在两种情况下被统计：
// -1- 所有目标字母，第一次被集齐时
// -2- 每一次，left 边界被推动时

class S{

struct E{
    size_t        num {1};//这个字母需要几个 
    std::set<int> sets{};
};

public:
    // t 中可能有多个重复字母
    // t 似乎一定存在字母
    std::string minWindow( std::string s, std::string t ){

        if(s.empty()){ return ""; }

        // 目标字母所在下标
        std::unordered_map<char,E> tIdxs {};
        for( char c : t ){
            auto [it,bl] = tIdxs.emplace( c, E{});
            if(!bl){ it->second.num++; }
        }

        std::set<int> range {};// 目前区间 各元素，按照 idx，从小到大排列

        int Ns = static_cast<int>(s.size());
        int Nt = static_cast<int>(t.size());
        int addNewTimes = 0; //添加新字母的个数

        int minl = 0;
        int minr = 0;
        int mmin = INT_MAX; // 最小区间记录

        for( int i=0; i<Ns; i++ ){
            char curC = s.at(i);
            auto fit = tIdxs.find(curC);
            if( fit==tIdxs.end() ){ continue; }// not find
            auto &elem = fit->second;

            // range insert
            range.insert( i );
            
            // 目标字母还未填满
            if( elem.sets.size() < elem.num ){
                elem.sets.insert(i);
                addNewTimes++;
                if( addNewTimes==Nt ){ // 所有目标字母，第一次被集齐时
                    minl = *range.begin();
                    minr = *range.rbegin();
                    mmin = minr - minl + 1;
                }
                continue;
            }

            // 如果已经填满,就要进行更换
            int beChangedIdx = *elem.sets.begin(); 
            bool isHead = (beChangedIdx == *range.begin());//更换的就是 区间头部字母

            range.erase( beChangedIdx );
            range.insert( i );
            elem.sets.erase( beChangedIdx );
            elem.sets.insert( i );

            if( isHead ){
                int newl = *range.begin();
                int newr = *range.rbegin();
                if( newr-newl+1 < mmin ){//找到更小的区间
                    mmin = newr-newl+1;
                    minl = newl;
                    minr = newr;
                }
            }
        }

        //cout<<"add:"<<addNewTimes<<endl;
        if( addNewTimes<Nt ){ return ""; }//没找全
        return std::string( s, minl, minr-minl+1 );

    }
};




// 官方解法中，这是一题 滑动窗口题
// 我感觉，我的方法，其实有点类似 滑动窗口，只是可能更麻烦些...





//=========================================================//
void main_(){

    auto ret = S{}.minWindow( "ADOBECODEBANC", "ABC" );

    cout<<"ret:"<<ret<<endl;
    


    debug::log( "\n~~~~ leet: 76 :end ~~~~\n" );
}
}//~
