/*
 * ====================== leet_204.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 204. 计数质数
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_204 {//~


// 最直观的办法，但是性能不高 18.16%，84.62%
class S{
    std::vector<int> primes {};
    bool isPrime( int n ){
        for( int i : primes ){
            if( i*i>n ){ break; }
            if( n%i==0 ){ return false; }
        }
        return true;
    }
public:
    // 小于 n 的 质数个数
    int countPrimes(int n) {
        if( n<=2 ){ return 0; }
        if( n==3 ){ return 1; }
        primes.push_back(2);
        for( int i=3; i<n; i++ ){
            if( isPrime(i) ){
                primes.push_back( i );
            }
        }
            cout << "primes: " << endl;
            for( int i : primes ){ cout << i << ", "; }
            cout << endl;
        return static_cast<int>(primes.size());
    }
};


// 方法2
// 事建立一个数组，然后将不是 素数的标记出来
// 待实现 ...





//=========================================================//
void main_(){

  
    cout << S{}.countPrimes( 4 ) << endl;
  

    debug::log( "\n~~~~ leet: 204 :end ~~~~\n" );
}
}//~
