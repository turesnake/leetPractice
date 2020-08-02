/*
 * ====================== leet_339.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 399. 除法求值
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_339 {//~


// 在此题中，可能存在环，但是环 不会影响计算结果
// 用 uset<string> 记录所有 顶点，未知顶点一律导致结果为 -1.0
// --- 
// -1- 将两元素之间的关系，一正一反，都记录下来，这样不管从哪个元素，都能找到目标
// -2- 存在一种特殊情况：两元素 都存在，但两者之间没有任何关系，此时应该返回 -1.0


// 朴素法 dfs   45%   40%
class S{

    std::unordered_map<std::string,std::unordered_map<std::string,double>> adjs {};
    std::unordered_set<std::string> elems {};
    int N {};
    int Nq {};

    std::unordered_set<std::string> used {};// for work, 
    std::vector<double> ans {};


    bool rec( const std::string &a, const std::string &tgt, double sum, int idx ){
        if( adjs[a].count(tgt)>0 ){// find
            ans[idx] = sum * adjs[a][tgt];
            return true;
        }
        for( auto &[str,val] : adjs[a] ){
            if( used.count(str)>0 ){ continue; }
            used.insert(str);// 登记
            bool bl = rec( str, tgt, sum*val, idx );
            if(bl){ return true; }
            used.erase(str);// 释放
        }
        return false;
    }
public:
    // 结果均为 正值
    // 输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果
    std::vector<double> calcEquation(
            std::vector<std::vector<std::string>>& equations, 
            std::vector<double>& values, 
            std::vector<std::vector<std::string>>& queries ){


        N = static_cast<int>(equations.size());
        Nq = static_cast<int>(queries.size());

        for( int i=0; i<N; i++ ){
            auto &a = equations[i][0];
            auto &b = equations[i][1];
            elems.insert( a );// maybe
            elems.insert( b );// maybe
            adjs[a].emplace( b, values[i] );// maybe
            adjs[b].emplace( a, 1.0/values[i] );// maybe
        }

        ans.resize( Nq, -99.9 );

        for( int i=0; i<Nq; i++ ){
            auto &src = queries[i][0];
            auto &dst = queries[i][1];

            if( elems.count(src)==0 || elems.count(dst)==0 ){
                ans[i] = -1.0;
                continue;
            }
            used.clear();
            bool bl = rec( src, dst, 1.0, i );
            if(!bl){ ans[i] = -1.0; }// 两元素虽然存在，但两者间并无关系，
        }
        return ans;

    }
};


// 带权并查集   速度惊人

//    100%   81%
class S2{

class UnionFindSet{ // 带权并查集
struct E{
    int    dst {0};
    double w   {1.0};
};
    std::vector<E> st {};
    int N {};
    E find( int a, double w ){
        if( st[a].dst==a ){ return E{a,w}; }
        st[a] = find( st[a].dst, st[a].w );
        return E{ st[a].dst, st[a].w*w };
    }
public:
    explicit UnionFindSet(int N_):N(N_){
        st.resize( N, E{} );
        for( int i=0; i<N; i++ ){
            st[i] = E{ i, 1.0 };
        }
    }
    // 此处的 w，是 a->b 的权重
    void merge( int a, int b, double w ){
        E ea = find( a, 1.0 );
        E eb = find( b, 1.0 );
        if( ea.dst==eb.dst ){ return; }
        st[eb.dst] = E{ ea.dst, ea.w*w/eb.w };// rb 成为 ra 的儿子
    }
    bool isSameRoot( int a, int b ){
        return find(a,1.0).dst==find(b,1.0).dst;
    }
    int rootSize(){
        int sum = 0;
        for( int i=0; i<N; i++ ){
            if( find(i,1.0).dst==i ){ sum++; }
        }
        return sum;
    }
    // 计算 a 指向 b 的权重值
    double calc_weight( int a, int b ){
        if( !isSameRoot(a,b) ){ return -1.0; }
        return st[b].w / st[a].w;
    }
};


public:
    // 结果均为 正值
    // 输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果
    std::vector<double> calcEquation(
            std::vector<std::vector<std::string>>& equations, 
            std::vector<double>& values, 
            std::vector<std::vector<std::string>>& queries ){


        int N = static_cast<int>(equations.size());
        int Nq = static_cast<int>(queries.size());

        //--- 将 所有 str 元素，分别用 vec/umap 存储，实现 str-idx 间正反查 ---//
        std::unordered_set<std::string> uset {};
        for( auto &tv : equations ){
            uset.insert( tv[0] );
            uset.insert( tv[1] );
        }
        int Ne = static_cast<int>(uset.size());
        std::vector<std::string> elems (uset.begin(), uset.end());
        std::unordered_map<std::string,int> eidxs {};
        for( int i=0; i<Ne; i++ ){
            eidxs.emplace( elems[i], i );
        }

        //--- 用 带权并查集，来存储 关系 ---//
        UnionFindSet ufs {Ne};
        for( int i=0; i<N; i++ ){
            auto &a = equations[i][0];
            auto &b = equations[i][1];
            ufs.merge( eidxs[a], eidxs[b], values[i] );
        }

        //--- 正式计算 结果 ---//
        std::vector<double> ans (Nq, -99.9);
        for( int i=0; i<Nq; i++ ){
            auto &src = queries[i][0];
            auto &dst = queries[i][1];

            if( uset.count(src)==0 || uset.count(dst)==0 ){
                ans[i] = -1.0;
            }else{
                ans[i] = ufs.calc_weight( eidxs[src], eidxs[dst] );
            }
        }
        return ans;

    }

};


//=========================================================//
void main_(){

    std::vector<std::vector<std::string>> equations {
        {"a","b"},
        {"e","f"},
        {"b","e"}
    };
    std::vector<double> values {
        3.4, 1.4, 2.3
    };
    std::vector<std::vector<std::string>> queries {
        {"b","a"},
        {"a","f"},
        {"f","f"},
        {"e","e"},
        {"c","c"},
        {"a","c"},
        {"f","e"}
    };

    auto ret = S2{}.calcEquation( equations, values, queries );

    cout<<"ret: "<<endl;
    for( auto i : ret ){
        cout<<i<<", ";
    }cout<<endl;

    
    

    debug::log( "\n~~~~ leet: 339 :end ~~~~\n" );
}
}//~
