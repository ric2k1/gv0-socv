/****************************************************************************
  FileName     [ bmatch.cpp ]
  PackageName  [ bmatch ]
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

// #define isGVNetInverted(netId) (netId.cp)

void
SATMgr::booleanMatching() {
    cout << "enter booleanMatching!" << endl;
    SatProofRes  pRes;
    GVSatSolver* gvSatSolver = new GVSatSolver(gvNtkMgr);
    pRes.setSatSolver(gvSatSolver);

    // assume input number= nPI1, nPI2
    // assume onput number= nPO1, nPO2
    int nPI1 = 2;
    int nPI2 = 2;
    int nPO1 = 2;
    int nPO2 = 2;

    // bulid matrix
    // build each output Data
    cout << "init current clause: " << gvSatSolver->getNumClauses() << endl;
    for (int i = 0; i < gvNtkMgr->getOutputSize(); ++i) {
        gvSatSolver->addBoundedVerifyData(gvNtkMgr->getOutput(i), 0);
    }
    cout << "builded circut relation, current clause: "
         << gvSatSolver->getNumClauses() << endl;

    // (1) input permutation matirx
    vector<vector<Var>> inputMatrix(nPI1 * 2 + 2,vector<int>(nPI2));
    for (int col = 0; col < nPI2; ++col) {
        for (int row = 0; row < nPI1 * 2 + 2; ++row) {
            Var newVar            = gvSatSolver->newVar();
            inputMatrix[row][col] = newVar;
        }
    }
    // ### for aij
    for (int i = 0; i < nPI2; ++i) {
        for (int j = 0; j < nPI1; ++j) {
            // XOR xj == yi
            Var XOR;
            gvSatSolver->addXorCNF(XOR, gvNtkMgr->getInput(j), false,
                                   gvNtkMgr->getInput(i + nPI1), false);
            gvSatSolver->addCNF(XOR, true, inputMatrix[j * 2][i], true);
        }
    }
     cout << "building matrix -- aij end, current clause: " << gvSatSolver->getNumClauses()
         << endl;
   
    // ### for bij
    for (int i = 0; i < nPI2; ++i) {
        for (int j = 0; j < nPI1; ++j) {
            // XOR xj == yi
            Var XOR;
            gvSatSolver->addXorCNF(XOR, gvNtkMgr->getInput(j), true,
                                   gvNtkMgr->getInput(i + nPI1), false);
            gvSatSolver->addCNF(XOR, true, inputMatrix[j * 2 + 1][i],
                                true);
        }
    }
    cout << "building matrix -- bij end, current clause: " << gvSatSolver->getNumClauses()
         << endl;
    // ### for yi = constant 0 / 1
    for (int col = 0; col < nPI2; ++col) {
        // constant 0
        gvSatSolver->addCNF(gvNtkMgr->getInput(col + nPI1), true,
                            inputMatrix[col][nPI1 * 2], true);

        // constant 1
        gvSatSolver->addCNF(gvNtkMgr->getInput(col + nPI1), false,
                            inputMatrix[col][nPI1 * 2], true);
    }
    cout << "builded matrix, current clause: " << gvSatSolver->getNumClauses()
         << endl;

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
