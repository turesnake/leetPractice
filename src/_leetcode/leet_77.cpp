/*
 * ====================== leet_77.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 77. 组合
 */
#include "innLeet.h"


namespace leet_77 {//~


// dp版 对内存很不友好，需要执行很多次 vector 复制
// 改用 dfs+回溯


// 递归版   97%   32%
class S{

    std::vector<std::vector<int>> outs {};
    std::vector<int> vec {};
    int nn {};
    int kk {};
    
    // i:     本回合要处理的元素
    // leftK: 还需要填入的 元素
    void work( int i, int leftK ){
        if( leftK == 0 ){
            outs.push_back( vec );// copy
            return;
        }
        int leftN = nn-i+1;
        if( leftN < leftK ){// 本分支无效
            return;
        }else if( leftN == leftK ){// 尾部全填满
            for( int j=i; j<=nn; j++ ){ vec.push_back(j); }
            outs.push_back( vec );// copy
            for( int j=i; j<=nn; j++ ){ vec.pop_back(); }
            return;
        }
        //-- 加 i --//
        vec.push_back(i);
        work( i+1, leftK-1 );
        vec.pop_back();
        //-- 不加 i --//
        work( i+1, leftK );
    }


public:
    std::vector<std::vector<int>> combine( int n, int k ){
        nn = n;
        kk = k;
        work( 1, k );
        return outs;
    }
};



//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 77 :end ~~~~\n" );
}
}//~
