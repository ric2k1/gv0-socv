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
    // set initial state to all zero
    GVNtkMgr mgr; // The ntk mgr. You can get the ntk info from the manager.
}

void
BddMgrV::buildPTransRelation() {
    // TODO : remember to set _tr, _tri
    GVNtkMgr mgr; // The ntk mgr. You can get the ntk info from the manager.

}

void
BddMgrV::buildPImage(int level) {
    // TODO : remember to add _reachStates and set _isFixed
    // note:: _reachStates record the set of reachable states
    GVNtkMgr mgr; // The ntk mgr. You can get the ntk info from the manager.
    
}

void
BddMgrV::runPCheckProperty(const string& name, BddNodeV monitor) {
    // TODO : prove the correctness of AG(~monitor)
    GVNtkMgr mgr; // The ntk mgr. You can get the ntk info from the manager.
}
