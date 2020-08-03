/*
 * ====================== leet_959.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 959. 由斜杠划分区域
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_959 {//~


// 将格子的 每个顶点，看作是对象
// 每个格子的 左上角，为基础点
// 斜线，就是 两个顶点 间的连线
// ---
// 使用 并查集，将每个连通分量 收集为一个集合
// 统计每个 连通分量内，边缘顶点的个数 k
// 每个连通分量，都能将总体 空间 增加 k-1 个 碎片

//  分别统计每个 连通分量的： 边界顶点数， 内部环数


// 此外，还存在多种方法，比如，把一个格子，分解成 3*3 的更小的格子
// 然后把斜线，分解成 对角线上的 三个格子
// 全部标记好后，就可以做 空白格子的 孤岛检测了

// 未尝试 ...




//    10%   5%
class S{

class UnionFindSet{
    std::vector<int> st {};
    int N {};
public:
    explicit UnionFindSet( int N_ ):N(N_){
        st.resize(N,0);
        for( int i=0; i<N; i++ ){
            st[i]=i;
        }
    }
    int find( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find(st[a]);
        return st[a];
    }
    void merge( int a, int b ){
        int ra = find(a);
        int rb = find(b);
        if( ra==rb ){ return; }
        st[rb] = ra;
    }
};

struct Cnt{// 连通分量数据
    int edgeNum {};// 边个数
    std::unordered_set<int> vtKeys {};
    std::unordered_set<int> borderVtKeys {};
};

public:
    // 1 <= grid.length == grid[0].length <= 30
    // grid[i][j] 是 '/'、'\'、或 ' '
    int regionsBySlashes( std::vector<std::string>& grid ){


        int Ng = static_cast<int>(grid.size());// 格子数量，顶点数量要 +1
        if( Ng==1 ){ return grid[0][0]==' ' ? 1 : 2; }
        int N = Ng+1;    // 顶点边长
        int Ntotal = N*N;// 顶点总数

        //--- init ufs ---//
        UnionFindSet ufs {Ntotal};
        std::unordered_set<int> borderKeys {};// 边界顶点，存储的是 key= h * N + w;
        std::vector<std::vector<int>> edges {};// 有效边信息，顶点存储为 key 格式

        int lkey {};
        int rkey {};
        for( int h=0; h<Ng; h++ ){
            for( int w=0; w<Ng; w++ ){
                if( grid[h][w]==' ' ){ continue; }
                if( grid[h][w]=='/' ){
                    rkey = h*N + (w+1);// 右上
                    lkey = (h+1)*N + w;// 左下
                    if( h==0 || w+1==Ng ){ borderKeys.insert( rkey ); }
                    if( h+1==Ng || w==0 ){ borderKeys.insert( lkey ); }
                }else{// '\\'
                    lkey = h*N + w;        // 左上
                    rkey = (h+1)*N + (w+1);// 右下
                    if( h==0 || w==0 ){       borderKeys.insert( lkey ); }
                    if( h+1==Ng || w+1==Ng ){ borderKeys.insert( rkey ); }
                }
                ufs.merge( lkey, rkey );
                edges.push_back( {lkey,rkey} );
            }
        }

        std::unordered_map<int,Cnt> cnts {};

        //-- 二次遍历 --//
        for( auto &te : edges ){
            int a = te[0];
            int b = te[1];
            auto &cnt = cnts[ ufs.find(a) ];

            cnt.edgeNum++;
            cnt.vtKeys.insert( a );
            cnt.vtKeys.insert( b );
            if( borderKeys.count(a)>0 ){ cnt.borderVtKeys.insert( a );}
            if( borderKeys.count(b)>0 ){ cnt.borderVtKeys.insert( b );}
        }

        int borderNum = 0;// 每个连通分量内，k 个 边界顶点，会增加 k-1 个碎片
        int loopNum = 0;// 全局环数

        for( auto &[k,cnt] : cnts ){
            int bN = static_cast<int>(cnt.borderVtKeys.size());
            borderNum += bN==0 ? 0 : bN-1;
            int vtN = static_cast<int>(cnt.vtKeys.size());
            loopNum += (vtN>cnt.edgeNum+1) ? 0 : (cnt.edgeNum+1)-vtN;
        }
        return 1 + borderNum + loopNum;


    }
};



//=========================================================//
void main_(){

    std::vector<std::string> mat {
        "/\\/\\",
        "\\///",
        " \\//",
        "////"
    };

    auto ret = S{}.regionsBySlashes( mat );
    cout<<"ret:"<<ret<<endl;


 
    

    debug::log( "\n~~~~ leet: 959 :end ~~~~\n" );
}
}//~
