/*
 * ====================== leet_97.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 97. 交错字符串
 */
#include "innLeet.h"


namespace leet_97 {//~


// 直观思路中，可以用 回溯法求解，但是递归深度等于 s3.len
// 可能会引发爆栈 or 超时

// 二维dp， 类似走迷宫，取其地图思路
// 结合 bfs 来遍历

//   89%  100%
class S{

// 访问 s1,s2,s3 下标值要减1
struct Elem{
    int x {0};// [0,N1]
    int y {0};// [0,N2]
};

public:
    bool isInterleave( std::string s1, std::string s2, std::string s3 ){

        if( s1.empty() && s2.empty() ){ return s3.empty(); }
        if( s1.empty() ){ return s2==s3; }
        if( s2.empty() ){ return s1==s3; }
        if( s3.empty() ){ return false; }
        
        int N1 = static_cast<int>(s1.size());
        int N2 = static_cast<int>(s2.size());
        int N3 = static_cast<int>(s3.size());
        if( N1+N2 != N3 ){ return false; }

        std::vector<std::vector<char>> dp (N2+1, std::vector<char>(N1+1,0));
            // 0:未被遍历 1: 已被遍历
        std::deque<Elem> que {Elem{}};

        while( !que.empty() ){
            auto [x,y] = que.front();
            que.pop_front();
            if( dp[y][x]==1 ){ continue; }// 最关键的一步 
            //---//
            dp[y][x] = 1;
            //cout<<"  x:"<<x<<",y:"<<y<<endl;
            //---//
            if( x<N1 && dp[y][x+1]==0 && s1[x]==s3[x+y] ){
                que.push_back(Elem{ x+1, y });
            }
            if( y<N2 && dp[y+1][x]==0 && s2[y]==s3[x+y] ){
                que.push_back(Elem{ x, y+1 });
            }
        }
        return dp.at(N2).at(N1)==1;
        
    }
};





//=========================================================//
void main_(){

    std::string s1 = "cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc";
    std::string s2 = "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb";
    std::string s3 = "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb";

    auto ret = S{}.isInterleave( s1,s2,s3 );

    debug::log( "\nret:{}", ret );
    

    
    debug::log( "\n~~~~ leet: 97 :end ~~~~\n" );
}
}//~
