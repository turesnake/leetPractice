/*
 * ====================== leet_m08_07.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 08.07. 无重复字符串的排列组合
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m08_07 {//~


// 朴素法, 本质上是 dfs  49%，100%
class S{

    struct Elem{
        char c      {};
        bool isUsed {false};
    };

    std::vector<Elem> data {};
    std::vector<std::string> outStrs {};// 全部字符串
    std::string word {};// 当前操作字符串
    int N {};

    // deep, [0,N-1]
    void work( int deep ){
        for( int i=0; i<N; i++ ){
            auto &elem = data.at(i);
            if( elem.isUsed ){ continue; }// 跳过已经被占位的
            elem.isUsed = true;// 每层，每次确认一位
            word.push_back(elem.c);
            if( deep == N-1 ){// 最后一层
                outStrs.push_back( word );
            }else{
                work( deep+1 );
            }
            word.pop_back();
            elem.isUsed = false;// 使用完毕后要释放
        }
    }
public:
    // 1 <= S.size() <= 9
    std::vector<std::string> permutation( std::string S ){
        for( char c : S ){
            data.push_back(Elem{c,false});
        }
        N = static_cast<int>(S.size());
        work( 0 );
        return outStrs;
    }
};


// 交换法 
// 暂未成功通过 bfs 来实现...





//=========================================================//
void main_(){


    auto ret = S{}.permutation( "abc" );

    for( auto &s : ret ){ cout << s <<endl; }


    debug::log( "\n~~~~ leet: m08_07 :end ~~~~\n" );
}
}//~
