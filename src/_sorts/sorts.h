/*
 * ========================= sorts.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_SORTS_H
#define TPR_SORTS_H

#include "pch.h"



namespace sorts_bubble_Sort { void main_(); }
namespace sorts_heapsort { void main_(); }
namespace sorts_insertion_sort { void main_(); }
namespace sorts_mergesort { void main_(); }
namespace sorts_quicksort { void main_(); }
namespace sorts_selection_sort { void main_(); }


inline void sorts_mian(){
    debug::log("\n\n============= Sorts_Test: Begin ================>>\n");

    sorts_mergesort::main_();

    debug::log("\n============= Sorts_Test: End ==================<<\n\n");
}

#endif
