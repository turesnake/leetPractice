/*
 * ====================== leet_638.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 638. 大礼包
 */
#include "innLeet.h"


namespace leet_638 {//~

// 背包dp
// 在原始思路中，这是一个 六维dp，不过鉴于 最多6种物品，每个最多买6个
// 本题购买的的变数种类 就是 6^6 = 46656 种
// 以此为基础，来构建一个 一维dp
// ----
// -1- 对所有 礼包做一次整理和排序
// 剔除掉 无法购买的礼包
// 计算出每个礼包的 优惠力度（原价到 礼包价的 off）
// 根据 off 高低排序，off 高的排前面（优惠力度大的）

// 然后，dp计算的就是 优惠差值最大的一种选择（这样问题就单一了）

// dp[i][j][k] = max( a[a1][b1][c1]+dp[i-a1][j-b1][k-c1], ... );

// 上述描述其实有个问题
// 目标 dp[2][3][2], 如果按照进位思想来实现，那么势必会实现 dp[1][6][6]
// 而这是不需要的

// 实际上我们要准备的 dp状态值，只需要从 dp[0][0][0] -> dp[2][3][2]
// 一共 3*4*3=36 种
//



//    5%     12% 
class S{

    std::vector<int> dp {};
    // 记录 每个状态的 最大优化值
    // 最多 7*6=117649 个元素。 并不会被填满，而是非常稀疏，只用到有限的 几个位置

    void dp_resize(){// N 维
        int num=1;
        for( int i=0; i<6; i++ ){ num *= 7; }
        dp.resize( num, 0 );
    }

    int &dp_at( int i1=0, int i2=0, int i3=0, int i4=0, int i5=0, int i6=0 ){
        int idx = 7776*i1 + 1296*i2 + 216*i3 + 36*i4 + 6*i5 + i6;
        return dp.at( idx );
    }

public:
    // 最多6种物品， 100种大礼包。
    // 每种物品，你最多只需要购买6个。
    // 你不可以购买超出待购清单的物品，即使更便宜。
    int shoppingOffers( std::vector<int> price, 
                        std::vector<std::vector<int>> special, 
                        std::vector<int> needs) {

        int Np = static_cast<int>(price.size());// 物品种类
        int Ns = static_cast<int>(special.size());// 礼包数量
        if(Np==0){ return 0; }

        dp_resize();

        std::vector<int> offs ( Ns, 0 );// 每个礼包 优惠差值
        for( int j=0; j<Ns; j++ ){
            int sum = 0;
            for( int i=0; i<Np; i++ ){
                sum += price[i] * special[j][i];
            }
            offs.at(j) = sum - special[j].back();
        }

        //cout<<"-1-"<<endl;

        int Na = Np>0 ? needs[0] : 0;
        int Nb = Np>1 ? needs[1] : 0;
        int Nc = Np>2 ? needs[2] : 0;
        int Nd = Np>3 ? needs[3] : 0;
        int Ne = Np>4 ? needs[4] : 0;
        int Nf = Np>5 ? needs[5] : 0;

        for( int a=0; a<=Na; a++ ){
        for( int b=0; b<=Nb; b++ ){
        for( int c=0; c<=Nc; c++ ){
        for( int d=0; d<=Nd; d++ ){
        for( int e=0; e<=Ne; e++ ){
        for( int f=0; f<=Nf; f++ ){

            //cout<<"-2-"<<endl;

            int mmax = 0;
            for( int j=0; j<Ns; j++ ){// 尝试购买每一种能买的礼包
                auto &spec = special.at(j);
                //---
                int ia = Np>0 ? spec[0] : 0;
                int ib = Np>1 ? spec[1] : 0;
                int ic = Np>2 ? spec[2] : 0;
                int id = Np>3 ? spec[3] : 0;
                int ie = Np>4 ? spec[4] : 0;
                int iff = Np>5 ? spec[5] : 0;
                if( ia>a || ib>b || ic>c || id>d || ie>e || iff>f ){ continue; }// 此包没法买
                int ans = offs[j] + dp_at( a-ia,b-ib,c-ic,d-id,e-ie,f-iff );
                mmax = std::max( mmax, ans );
            }
            dp_at(a,b,c,d,e,f) = mmax;
            //cout<<"-3-"<<endl;
        }}}}}}
        //cout<<"-4-"<<endl;

        int ia = Np>0 ? needs[0] : 0;
        int ib = Np>1 ? needs[1] : 0;
        int ic = Np>2 ? needs[2] : 0;
        int id = Np>3 ? needs[3] : 0;
        int ie = Np>4 ? needs[4] : 0;
        int iff = Np>5 ? needs[5] : 0;

        int dpv = dp_at( ia,ib,ic,id,ie,iff );

        //cout<<"-5-"<<endl;

        int originSum = 0;
        for( int i=0; i<Np; i++ ){
            originSum += needs[i] * price[i];
        }
        return originSum - dpv;


    }
};


// 参考答案用了 dfs   80%  87%
class S2{

    std::vector<std::vector<int>*> specs {};
    std::vector<int> *pricep {};

    int Np {};
    int outMin {};

    // 值传递 need 包
    // sum 累加的 优惠值
    void work( std::vector<int> tneeds, int sum ){

        bool isFind = false;
        for( auto *cp : specs ){
            std::vector<int>& specs = *cp;

            // 检测是否可用
            bool isLegal = true;
            for( int i=0; i<Np; i++ ){
                if( specs[i] > tneeds[i] ){  
                    isLegal = false;
                    break;
                }
            }
            if(!isLegal){ continue; }// 无法使用本礼包
            isFind = true;

            // 正式使用
            std::vector<int> pneeds ( tneeds.begin(), tneeds.end() );
            bool isAllZero = true;
            for( int i=0; i<Np; i++ ){
                pneeds[i] -= specs[i];
                if( pneeds[i]!=0 ){ isAllZero=false; }
            }
            
            if( isAllZero ){// need 耗光，开始清算
                outMin = std::min( outMin, sum+specs.back() );
            }else{
                work( std::move(pneeds), sum+specs.back() );
            }
        }
        if( isFind ){ return; }

        // 当发现没有 礼包 适用时，说明要做最终清算了
        for( int i=0; i<Np; i++ ){
            sum += pricep->at(i) * tneeds[i];
        }
        outMin = std::min( outMin, sum );
    }


public:
    // 最多6种物品， 100种大礼包。
    // 每种物品，你最多只需要购买6个。
    // 你不可以购买超出待购清单的物品，即使更便宜。
    int shoppingOffers( std::vector<int> price, 
                        std::vector<std::vector<int>> special, 
                        std::vector<int> needs ){
        

        Np = static_cast<int>(price.size());// 物品种类
        int Ns = static_cast<int>(special.size());// 礼包数量
        if(Np==0){ return 0; }

        for( auto &c : special ){
            bool isLegal = true;
            for( int i=0; i<Np; i++ ){
                if( c[i] > needs[i] ){ 
                    isLegal = false;
                    break;
                }
         
            }
            if( !isLegal ){ continue; }
            specs.push_back( &c );
        }
        pricep = &price;

        for( int i=0; i<Np; i++ ){
            outMin += price[i] * needs[i];
        }

        work( needs, 0 );
        return outMin;


    }


};




//=========================================================//
void main_(){

    std::vector<int> price { 9,9 };

    std::vector<std::vector<int>> special { 
        {1,1,1}
    };

    std::vector<int> needs { 2,2 };


    //-----//


    auto ret1 = S{}.shoppingOffers( price, special, needs );
    cout<<"ret1:"<<ret1<<endl;

    auto ret2 = S2{}.shoppingOffers( price, special, needs );
    cout<<"ret2:"<<ret2<<endl;

    
    debug::log( "\n~~~~ leet: 638 :end ~~~~\n" );
}
}//~
