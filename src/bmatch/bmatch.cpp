/****************************************************************************
  FileName     [ satMgr.cpp ]
  PackageName  [ sat ]
  Synopsis     [ Define sat prove package interface ]
  Author       [ ]
  Copyright    [ Copyleft(c) 2010 LaDs(III), GIEE, NTU, Taiwan ]
 ****************************************************************************/

#include "gvMsg.h"
#include "gvSatMgr.h"
#include "reader.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void
SATMgr::booleanMatching() {
    cout << "enter booleanMatching!" << endl;
    SatProofRes  pRes;
    GVSatSolver* gvSatSolver = new GVSatSolver(gvNtkMgr);
    pRes.setSatSolver(gvSatSolver);

    // bulid matrix

    // while (1) {

    // solve mapping matrix
    // if UNSAT -> return no match
    // if SAT -> keep going

    // (matching SAT)
    // build miter (建亨)

    // (miter UNSAT)
    // record score & exclude current matching (wish)

    // }
}