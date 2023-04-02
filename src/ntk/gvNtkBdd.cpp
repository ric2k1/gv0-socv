/****************************************************************************
  FileName     [ v3NtkBdd.cpp ]
  PackageName  [ v3/src/ntk ]
  Synopsis     [ V3 Network to BDDs. ]
  Author       [ Cheng-Yin Wu ]
  Copyright    [ Copyright(c) 2012-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#ifndef V3_NTK_C
#define V3_NTK_C

#include "bddMgrV.h"  // MODIFICATION FOR SoCV BDD
#include "bddNodeV.h" // MODIFICATION FOR SoCV BDD
#include "gvMsg.h"
#include "gvNtk.h"
#include "stack"
#include "util.h"

extern BddMgrV* bddMgrV; // MODIFICATION FOR SoCV BDD

const bool
GVNtkMgr::setBddOrder(const bool& file) {
    unsigned supportSize = getInputSize() + getInoutSize() + 2 * getFFSize();
    unsigned bddspsize   = bddMgrV->getNumSupports();
    if (supportSize >= bddMgrV->getNumSupports()) {
        gvMsg(GV_MSG_ERR) << "BDD Support Size is Smaller Than Current Design Required !!" << endl;
        return false;
    }
    // build support
    unsigned supportId = 1;
    // build PI (primary input)
    for (unsigned i = 0, n = getInputSize(); i < n; ++i) {
        GVNetId nId     = (file) ? getInput(i) : getInput(n - i - 1);
        string  netName = getNetNameFromId(nId.id);
        bddMgrV->addBddNodeV(nId.id, bddMgrV->getSupport(supportId)());
        bddMgrV->addBddNodeV(netName, bddMgrV->getSupport(supportId)());
        ++supportId;
    }
    // build InOut (Not use)
    for (unsigned i = 0, n = getInoutSize(); i < n; ++i) {
        const GVNetId& nId     = (file) ? getInout(i) : getInout(n - i - 1);
        string         netName = getNetNameFromId(nId.id);
        bddMgrV->addBddNodeV(nId.id, bddMgrV->getSupport(supportId)());
        bddMgrV->addBddNodeV(netName, bddMgrV->getSupport(supportId)());
        ++supportId;
    }
    // build FF_CS (X: current state)
    for (unsigned i = 0, n = getFFSize(); i < n; ++i) {
        const GVNetId& nId     = (file) ? getFF(i) : getFF(n - i - 1);
        string         netName = getNetNameFromId(nId.id);
        bddMgrV->addBddNodeV(nId.id, bddMgrV->getSupport(supportId)());
        bddMgrV->addBddNodeV(netName, bddMgrV->getSupport(supportId)());
        ++supportId;
    }
    // build FF_NS (Y: next state)
    // here we only create "CS_name + _ns" for y_i
    for (unsigned i = 0, n = getFFSize(); i < n; ++i) {
        const GVNetId& nId     = (file) ? getFF(i) : getFF(n - i - 1);
        GVNetId        ri      = getInputNetId(nId, 0); // get RI
        string         netName = getNetNameFromId(ri.id);
        bddMgrV->addBddNodeV(netName, bddMgrV->getSupport(supportId)());
        ++supportId;
    }
    // Constants (const0 node, id=0)
    for (uint32_t i = 0; i < getConstSize(); ++i) {
        assert(getGateType(getConst(i)) == GV_NTK_OBJ_CONST0);
        bddMgrV->addBddNodeV(getConst(i).id, BddNodeV::_zero());
        ++supportId;
    }
    // FF that stores const0 (take as const0 node)
    for (uint32_t i = 0; i < getFFConst0Size(); ++i) {
        assert(getGateType(getFFConst0(i)) == GV_NTK_OBJ_FF_NS);
        bddMgrV->addBddNodeV(getFFConst0(i).id, BddNodeV::_zero());
        bddMgrV->addBddNodeV(getRoIdFromRiId(getFFConst0(i).id), BddNodeV::_zero());
        ++supportId;
    }

    return true;
}

void
GVNtkMgr::buildNtkBdd() {
    // TODO: build BDD for ntk here
    // Perform DFS traversal from DFF inputs, inout, and output gates.
    // Collect ordered nets to a GVNetVec
    // Construct BDDs in the DFS order
}

void
GVNtkMgr::buildBdd(const GVNetId& netId) {
    vector<GVNetId> orderedNets;

    orderedNets.clear();
    orderedNets.reserve(getNetSize());

    // set flag for DFS
    newMiscData();
    dfsOrder(netId, orderedNets);
    assert(orderedNets.size() <= getNetSize());

    // TODO: build BDD for the specified net here
}

// Put fanins of a net (id) into a vector (nets) in topological order
void
GVNtkMgr::dfsOrder(const GVNetId& id, vector<GVNetId>& nets) {
    if (isLatestMiscData(id)) return;

    setLatestMiscData(id);
    //  traverse fanin logics
    const GV_Ntk_Type_t type = getGateType(id);
    if ((type == GV_NTK_OBJ_FF_NS) || (type == GV_NTK_OBJ_PO)) {
        dfsOrder(getInputNetId(id, 0), nets);
    } else if (type == GV_NTK_OBJ_AIG) {
        dfsOrder(getInputNetId(id, 0), nets);
        dfsOrder(getInputNetId(id, 1), nets);
    }
    nets.push_back(id); // Record Order
}

#endif
