/*
 * ====================== leet_974.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 974. 和可被 K 整除的子数组
 */
#include "innLeet.h"


namespace leet_974 {//~


// 超时 本质上还是 暴力法
class S1{    
    std::vector<std::vector<int>> dp {};//[0]行不存在

    int &dp_at( int idx, int len ){
        return dp.at(len-1).at(idx);
    }

    void dp_resize( int N ){
        dp.resize( N );
        for( int n=1; n<=N; n++ ){// each len
            dp.at(n-1).resize( N-n+1, 0 );
        }
    }

public:
    int subarraysDivByK( std::vector<int>& A, int K ){

        int Na = static_cast<int>(A.size());
        dp_resize(Na);
        int times {0};

        // 手动实现[1]行
        for( int i=0; i<Na; i++ ){
            int mod = A.at(i)%K;
            if( mod==0 ){ times++; }
            dp_at(i,1) = mod;
        }

        // 自从实现后面各行
        for( int n=2; n<=Na; n++ ){//each len
            for( int i=0; i<Na-n+1; i++ ){//each elem
                int mod = (dp_at(i,n-1)+A.at(i+n-1)) % K;
                dp_at(i,n) = mod;
                if( mod==0 ){ times++; }
            }
        }

            cout << "dp:"<< endl;
            for( auto &c : dp ){
                for( auto e : c ){ cout << e << ", "; }
                cout << endl;
            }cout << "====="<< endl;

        return times;
    }
};



// 尝试用 前缀和 来解
class S2{
public:

class  FTree{
    std::vector<int> data {};//[0]空置
    int lowBit( int v ){return v&(-v);}
public:
    FTree()=default;
    void init( int N ){
        data.resize( N+1, 0 );//[0]空置
    }
    void add( int idx, int addV ){
        int i = idx+1;
        while( i < static_cast<int>(data.size()) ){
            data.at(i) += addV;
            i += lowBit(i);
            
        }
    }
    int sum( int idx ){
        int i = idx+1;
        int sum = 0;
        while( i>0 ){
            sum += data.at(i);
            i -= lowBit(i);
        }
        return sum;
    }
};

    FTree ftree {};


public:
    int subarraysDivByK( std::vector<int>& A, int K ){

        int Na = static_cast<int>(A.size());
        ftree.init(Na);
        for( int i=0; i<Na; i++ ){
            ftree.add( i, A.at(i) );
        }
        int times {0};
        for( int l=0; l<Na; l++ ){
            for( int r=l; r<Na; r++ ){
                int sum = ftree.sum(r) - ftree.sum(l-1);
                if( sum%K==0 ){ times++; }
            }
        }
        return times;
    }
};


// 官方方案
// 前缀和 + 模 
//
class S3{
public:
    int subarraysDivByK( std::vector<int>& A, int K ){

        int Na = static_cast<int>(A.size());
        std::unordered_map<int,int> mmap {}; //<mod,times>
        mmap.emplace( 0,1 );// 必须事先写入的
        int mod {0};
        int times {0};

        for( int i : A ){
            mod = (mod+i) % K;
            if( mod<0 ){ mod += K; }
            if( mmap.find(mod)!=mmap.end() ){//existed
                times += mmap.at(mod);
                mmap.at(mod)++;
            }else{
                mmap.emplace( mod,1 );
            }
        }
        return times;
    }
};






//=========================================================//
void main_(){

    std::vector<int> a { 4,5,0,-2,-3,1 };
    cout << S3{}.subarraysDivByK(a,5) <<endl;


    /*
    S2::FTree kt {};
    kt.init( 10 );
    for( int i=0; i<10; i++ ){
        kt.add( i,1 );
    }
    cout << kt.sum(9) << endl;
    */

    

    debug::log( "\n~~~~ leet: 974 :end ~~~~\n" );
}
}//~
