/****************************************************************************
  FileName     [ proveBdd.cpp ]
  PackageName  [ prove ]
  Synopsis     [ For BDD-based verification ]
  Author       [ ]
  Copyright    [ Copyleft(c) 2010-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#include "bddMgrV.h"
#include "gvMsg.h"
#include "gvNtk.h"
#include "util.h"
#include <iomanip>
#include <iostream>
#include <vector>

void
BddMgrV::buildPInitialState() {
    // TODO : remember to set _initState
    // Hint : use "gvNtkMgr" to get the network info from the manager 
    // set initial state to all zero
}

void
BddMgrV::buildPTransRelation() {
    // TODO : remember to set _tr, _tri
    // Hint : use "gvNtkMgr" to get the network info from the manager
}

void
BddMgrV::buildPImage(int level) {
    // TODO : remember to add _reachStates and set _isFixed
    // Hint : use "gvNtkMgr" to get the network info from the manager
    // note:: _reachStates record the set of reachable states
}

void
BddMgrV::runPCheckProperty(const string& name, BddNodeV monitor) {
    // TODO : prove the correctness of AG(~monitor)
    // Hint : use "gvNtkMgr" to get the network info from the manager
}
