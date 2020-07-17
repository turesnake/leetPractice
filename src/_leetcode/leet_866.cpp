/*
 * ====================== leet_866.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 866. 回文素数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_866 {//~



//   未完 ...





class S{


    // 最朴素的 素数检测法， n>2
    bool check_prime( int n ){
        if( (n&1)==0 ){ return false; }
        int logn = static_cast<int>(sqrt(static_cast<double>(n))) + 1;
        for( int i=3; i<=logn; i+=2 ){
            if( n%i==0 ){ return false; }
        }
        return true;
    }


    std::vector<int> v {};// 回文检查用

    // 检查 回文
    bool check_rec( int n ){
        v.clear();
        for( int i=n; i>0; i/=10 ){
            v.push_back( i%10 );
        }
        int N = static_cast<int>(v.size());
        int l=0; 
        int r=N-1;
        while( l<r ){
            if( v[l]!=v[r] ){ return false; }
        }
        return true;
    }


public:
    // 1 <= N <= 10^8
    // 答案肯定存在，且小于 2 * 10^8
    int primePalindrome( int N ){

        if( N==1 ){ return 2; }// 1
        if( N<11 ){// [2,0]
            for( int i=N; ;i++ ){
                if( check_prime(i) ){ return i; }
            }
        }
        if( N<101 ){ return 101; }



        //   以后 做 ....



        return 0;

    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 866 :end ~~~~\n" );
}
}//~
