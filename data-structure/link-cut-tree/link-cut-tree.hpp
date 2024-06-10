#pragma once
#include "data-structure/link-cut-tree/reversible-splay-tree.hpp"
#include "data-structure/link-cut-tree/link-cut-tree-base.hpp"

/**
 * Author: Teetat T.
 * Date: 2024-05-19
 * Description: Link Cut Tree.
 */

template<class Monoid>
struct LinkCutTree:LinkCutTreeBase<ReversibleSplayTree<Monoid>>{};

