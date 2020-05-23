/*
 * ======================== leetCode.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.01.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_LEET_CODE_H
#define TPR_LEET_CODE_H

#include "pch.h"


/* 惯用技巧：
 * INT_MIN, INT_MAX  <limits.h>
 * -----
 * int 转 string: std::to_string()
 * -----
 * 容器可以直接用 一对迭代器来初始化
 * -----
 * 消除成对的元素方法[1]
 *     if( set.erase(i)==0 ){ set.insert( i ); }
 * 消除成对的元素方法[2]
 *     异或运算 a^b^b = a
 *     可以将一整组数据都 异或起来，最后成对的元素都会被自动 对消掉
 *    
 */


namespace leet_1 { void main_(); }

namespace leet_3 { void main_(); }

namespace leet_6 { void main_(); }
namespace leet_7 { void main_(); }
namespace leet_8 { void main_(); }
namespace leet_9 { void main_(); }// 回文数，待新方案：8.02%, 5.95% 

namespace leet_11 { void main_(); }

namespace leet_13 { void main_(); }
namespace leet_14 { void main_(); }
namespace leet_15 { void main_(); }
namespace leet_16 { void main_(); }
namespace leet_17 { void main_(); }


namespace leet_20 { void main_(); }
namespace leet_21 { void main_(); }
namespace leet_22 { void main_(); }// 回溯
namespace leet_23 { void main_(); }

namespace leet_26 { void main_(); }
namespace leet_27 { void main_(); }

namespace leet_39 { void main_(); }
namespace leet_42 { void main_(); }
namespace leet_46 { void main_(); }

namespace leet_53 { void main_(); }//=*--动态规划--*=
namespace leet_54 { void main_(); }
namespace leet_56 { void main_(); }
namespace leet_58 { void main_(); }//...无脑...

namespace leet_62 { void main_(); }//=*--动态规划--*= 基础
namespace leet_63 { void main_(); }//=*--动态规划--*=
namespace leet_64 { void main_(); }//=*--动态规划--*=

namespace leet_67 { void main_(); }

namespace leet_70 { void main_(); }//=*--动态规划--*=
namespace leet_72 { void main_(); }
namespace leet_73 { void main_(); }

namespace leet_78 { void main_(); }
namespace leet_88 { void main_(); }

namespace leet_95 { void main_(); }//=*--动态规划--*=
namespace leet_96 { void main_(); }//=*--动态规划--*=

namespace leet_101 { void main_(); }
namespace leet_102 { void main_(); }
namespace leet_104 { void main_(); }
namespace leet_110 { void main_(); }
namespace leet_111 { void main_(); }

namespace leet_120 { void main_(); }//=*--动态规划--*=
namespace leet_121 { void main_(); }

namespace leet_130 { void main_(); }// 广度优先
namespace leet_136 { void main_(); }// 异或消除成对元素
namespace leet_138 { void main_(); }

namespace leet_141 { void main_(); }

namespace leet_155 { void main_(); }

namespace leet_167 { void main_(); }
namespace leet_169 { void main_(); }// Boyer-Moore Algorithm 多数投票算法

namespace leet_198 { void main_(); }//=*--动态规划--*=
namespace leet_200 { void main_(); }
namespace leet_202 { void main_(); }
namespace leet_203 { void main_(); }

namespace leet_206 { void main_(); }

namespace leet_209 { void main_(); }

namespace leet_215 { void main_(); }

namespace leet_225 { void main_(); }//...无脑...
namespace leet_226 { void main_(); }

namespace leet_256 { void main_(); }//=*--动态规划--*=
namespace leet_257 { void main_(); }
namespace leet_258 { void main_(); }

namespace leet_263 { void main_(); }
namespace leet_264 { void main_(); }

namespace leet_283 { void main_(); }

namespace leet_287 { void main_(); }

namespace leet_295 { void main_(); }// 最大堆+最小堆 求中位数

namespace leet_300 { void main_(); }// **难**
namespace leet_303 { void main_(); }// 树状数组
namespace leet_307 { void main_(); }// 树状数组
namespace leet_314 { void main_(); }

namespace leet_338 { void main_(); }// 临时方案，等待更正式的方案

namespace leet_344 { void main_(); }//...无脑...
namespace leet_346 { void main_(); }
namespace leet_347 { void main_(); }
namespace leet_349 { void main_(); }

namespace leet_357 { void main_(); }

namespace leet_374 { void main_(); }// 奇怪，与本机运行不一致...
namespace leet_375 { void main_(); }//=*--动态规划--*= **难**

namespace leet_401 { void main_(); }
namespace leet_402 { void main_(); }
namespace leet_409 { void main_(); }

namespace leet_415 { void main_(); }

namespace leet_451 { void main_(); }
namespace leet_452 { void main_(); }
namespace leet_455 { void main_(); }

namespace leet_464 { void main_(); }

namespace leet_486 { void main_(); }//=*--动态规划--*= 100%  100%

namespace leet_504 { void main_(); }
namespace leet_509 { void main_(); }

namespace leet_543 { void main_(); }

namespace leet_617 { void main_(); }

namespace leet_696 { void main_(); }
namespace leet_698 { void main_(); }

namespace leet_712 { void main_(); }//=*--动态规划--*= 5.28%  55.56%

namespace leet_763 { void main_(); }

namespace leet_784 { void main_(); }

namespace leet_821 { void main_(); }
namespace leet_876 { void main_(); }

namespace leet_912 { void main_(); }// sorts

namespace leet_931 { void main_(); }//=*--动态规划--*=

namespace leet_945 { void main_(); }

namespace leet_997 { void main_(); }// 5.12%, 16.67%

namespace leet_1025 { void main_(); }//=*--动态规划--*=
namespace leet_1047 { void main_(); }
namespace leet_1071 { void main_(); }

namespace leet_1143 { void main_(); }//=*--动态规划--*= 8.93%, 100%

namespace leet_1160 { void main_(); }// 5.15% 20%

namespace leet_1277 { void main_(); }//=*--动态规划--*= 5.07%， 50%

namespace leet_1314 { void main_(); }//=*--动态规划--*=


namespace leet_LCP_01 { void main_(); }//...无脑...


namespace leet_m03 { void main_(); }
namespace leet_m09 { void main_(); }// 用两栈实现队列，...无脑...
namespace leet_m24 { void main_(); }
namespace leet_m25 { void main_(); }
namespace leet_m40 { void main_(); }
namespace leet_m42 { void main_(); }//=*--动态规划--*=
namespace leet_m47 { void main_(); }//=*--动态规划--*=
namespace leet_m57 { void main_(); }
namespace leet_m57_2 { void main_(); }
namespace leet_m58_1 { void main_(); }//...无脑...
namespace leet_m58_2 { void main_(); }//...无脑...
namespace leet_m62 { void main_(); }

namespace leet_m01_01 { void main_(); }
namespace leet_m01_06 { void main_(); }

namespace leet_m16_17 { void main_(); }//=*--动态规划--*= 34.46%，100%

namespace leet_m17_16 { void main_(); }//=*--动态规划--*=

// oths:
namespace leet_knapsack_problems { void main_(); }// 背包问题练习


inline void leetCode_mian(){
    debug::log("\n\n============= Leet Code: Begin ================>>\n");

    leet_1143::main_();

    debug::log("\n============= Leet Code: End ==================<<\n\n");
}


#endif 

