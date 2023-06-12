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
SATMgr::booleanMatching(int nPI1, int nPI2, int nPO1, int nPO2) {
    cout << "enter booleanMatching!" << endl;
    SatProofRes  pRes;
    GVSatSolver* gvSatSolver = new GVSatSolver(gvNtkMgr);
    pRes.setSatSolver(gvSatSolver);

    //cout<<"be "<<gvNtkMgr->getNetSize()<<endl;
    //gvNtkMgr->createNet();
    //cout<<"af "<<gvNtkMgr->getNetSize()<<endl;
    
    // assume input number= nPI1, nPI2
    // assume onput number= nPO1, nPO2

    //revise port name
    string name;
    for (int i = 0; i < gvNtkMgr->getInputSize(); ++i) {
        name = gvNtkMgr->getNetNameFromId(gvNtkMgr->getInput(i).id).substr(1);
        gvNtkMgr->setNetNameFromId(gvNtkMgr->getInput(i).id, name);
        //cout<<"input:"<<i<<" "<<gvNtkMgr->getNetNameFromId(gvNtkMgr->getInput(i).id)<<endl;
    }
    for (int i = 0; i < gvNtkMgr->getOutputSize(); ++i) {
        name = gvNtkMgr->getNetNameFromId(gvNtkMgr->getOutput(i).id).substr(1);
        gvNtkMgr->setNetNameFromId(gvNtkMgr->getOutput(i).id, name);
        //cout<<"output:"<<i<<" "<<gvNtkMgr->getNetNameFromId(gvNtkMgr->getOutput(i).id)<<endl;
    }

    //calculate PI PO
    int circuit_number;
    for (int i = 0; i < gvNtkMgr->getInputSize(); ++i) {
        circuit_number = gvNtkMgr->getNetNameFromId(gvNtkMgr->getInput(i).id)[0] - '0';
        switch (circuit_number)
        {
        case 1:
            nPI1++;
            break;
        
        case 2:
            nPI2++;
            break;
        
        default:
            cerr<<"circuit number \""<<circuit_number<<"\" error"<<endl;
            break;
        }
    }
    for (int i = 0; i < gvNtkMgr->getOutputSize(); ++i) {
        circuit_number = gvNtkMgr->getNetNameFromId(gvNtkMgr->getOutput(i).id)[0] - '0';
        switch (circuit_number)
        {
        case 1:
            nPO1++;
            break;
        
        case 2:
            nPO2++;
            break;
        
        default:
            cerr<<"circuit number \""<<circuit_number<<"\" error"<<endl;
            break;
        }
    }
    cout<<"PI1 "<<nPI1<<" PI2 "<<nPI2<<" PO1 "<<nPO1<<" PO2 "<<nPO2<<endl;

    // bulid matrix
    // build each output Data
    cout << "init current clause: " << gvSatSolver->getNumClauses() << endl;
    for (int i = 0; i < gvNtkMgr->getOutputSize(); ++i) {
        gvSatSolver->addBoundedVerifyData(gvNtkMgr->getOutput(i), 0);
    }
    cout << "builded circuit relation, current clause: "
         << gvSatSolver->getNumClauses() << endl;

    // (1) input permutation matirx
    vector<vector<Var>> inputMatrix(nPI2, vector<int>(nPI1 * 2 + 2));
    for (int row = 0; row < nPI2; ++row) {
        for (int col = 0; col < nPI1 * 2 + 2; ++col) {
            Var newVar            = gvSatSolver->newVar();
            inputMatrix[row][col] = newVar;
        }
    }
    for (int i = 0; i < nPI2; ++i) {
        for (int j = 0; j < nPI1; ++j) {
            // ### for aij -> XOR: xj == yi
            Var XOR_a;
            gvSatSolver->addXorCNF(XOR_a, gvNtkMgr->getInput(j), false,
                                   gvNtkMgr->getInput(i + nPI1), false);
            gvSatSolver->addCNF(XOR_a, true, inputMatrix[i][j * 2], true);
            // ### for bij -> XOR': xj' == yi
            Var XOR_b;
            gvSatSolver->addXorCNF(XOR_b, gvNtkMgr->getInput(j), true,
                                   gvNtkMgr->getInput(i + nPI1), false);
            gvSatSolver->addCNF(XOR_b, true, inputMatrix[i][j * 2 + 1], true);
        }
    }
    // ### for zi/Oi -> yi = constant 0 / 1
    for (int row = 0; row < nPI2; ++row) {
        // constant 0
        gvSatSolver->addCNF(gvNtkMgr->getInput(row + nPI1), true,
                            inputMatrix[row][nPI1 * 2], true);
        // constant 1
        gvSatSolver->addCNF(gvNtkMgr->getInput(row + nPI1), false,
                            inputMatrix[row][nPI1 * 2 + 1], true);
    }
    cout << "building input matrix -- aij bij end, current clause: "
         << gvSatSolver->getNumClauses() << endl;


    // constraints for input permutation matirx
    //   (a) each input y map to x or 0/1
    //       <=1: each two var AND can not be 1 (only a var can be 1)
    for (int row = 0; row < inputMatrix.size(); ++row) {
        for (int col = 0; col < inputMatrix[0].size() - 1; ++col)
            for (int other = col + 1; other < inputMatrix[0].size(); ++other) {

                Var newV = gvSatSolver->newVar();
                gvSatSolver->addAigCNF(newV, inputMatrix[row][col], false,
                                       inputMatrix[row][other], false);
                gvSatSolver->assertProperty(newV, false);
            }
    }

    bool result;
    result = gvSatSolver->solve();
    if (result) {
        for (int row = 0; row < nPI2; ++row) {
            for (int col = 0; col < nPI1 * 2 + 2; ++col) {
                cout << gvSatSolver->getDataValue(inputMatrix[row][col]) << " ";
            }
            cout << endl;
        }
    } else {
        cout << "UNSAT" << endl;
    }

    //      !=0: the whole row can not be 0
    for (int row = 0; row < inputMatrix.size(); ++row) {
        Var temp = gvSatSolver->newVar();
        gvSatSolver->addAigCNF(temp, inputMatrix[row][0], true,
                               inputMatrix[row][1], true);
        for (int col = 2; col <= inputMatrix[0].size(); ++col) {
            for (int j = 2; j < nPI2; ++j) {
                Var newV = gvSatSolver->newVar();
                gvSatSolver->addAigCNF(newV, inputMatrix[row][col], true, temp,
                                       false);
                temp = newV;
            }
            gvSatSolver->assertProperty(temp, false);
        }
    }

    cout << "constraints (a) finished, current clause: "
         << gvSatSolver->getNumClauses() << endl;

    //   (b) many input y to one x -> can't be no mapping(?)
    // y -> x
    for (int j = 0; j < nPI1; ++j) {
        vector<Var>  vas;
        vector<bool> fas(nPI2 * 2, false);
        for (int i = 0; i < nPI2; ++i) {
            vas.push_back(inputMatrix[i][j * 2]);
            vas.push_back(inputMatrix[i][j * 2 + 1]);
        }
        gvSatSolver->addCNF(vas, fas);
    }
    // y-> 0/1
    vector<Var>  vas;
    vector<bool> fas(nPI2, false);
    // constant 0
    for (int i = 0; i < nPI2; ++i) {
        vas.push_back(inputMatrix[i][nPI1 * 2]);
    }
    gvSatSolver->addCNF(vas, fas);
    vas.clear();
    for (int i = 0; i < nPI2; ++i) {
        vas.push_back(inputMatrix[i][nPI1 * 2]);
    }
    gvSatSolver->addCNF(vas, fas);
    cout << "constraints (b) finished, current clause: "
         << gvSatSolver->getNumClauses() << endl;

    // (2) output permutation matirx
    vector<vector<Var>> outputMatrix(nPO2, vector<int>(nPO1 * 2 + 2));
    for (int row = 0; row < nPO2; ++row) {
        for (int col = 0; col < nPO1 * 2 + 2; ++col) {
            Var newVar             = gvSatSolver->newVar();
            outputMatrix[row][col] = newVar;
        }
    }

    for (int i = 0; i < nPO2; ++i) {
        for (int j = 0; j < nPO1; ++j) {
            // ### for cij -> XOR: fj == f*i
            Var XOR_c;
            gvSatSolver->addXorCNF(XOR_c, gvNtkMgr->getOutput(j), false,
                                   gvNtkMgr->getOutput(i + nPO1), false);
            gvSatSolver->addCNF(XOR_c, true, outputMatrix[i][j * 2], true);
            // ### for bij -> XOR': fj' == f*i
            Var XOR_d;
            gvSatSolver->addXorCNF(XOR_d, gvNtkMgr->getOutput(j), true,
                                   gvNtkMgr->getOutput(i + nPO1), false);
            gvSatSolver->addCNF(XOR_d, true, outputMatrix[i][j * 2 + 1], true);
        }
    }
    cout << "building output matrix -- cij dij end, current clause: "
         << gvSatSolver->getNumClauses() << endl;

    // constraints for output permutation matirx
    //  many output f* map one output f sum<=1
    for (int row = 0; row < outputMatrix.size(); ++row) {
        // the same row -> one seat & the same column -> one man
        for (int col = 0; col < outputMatrix[0].size() - 1; ++col)
            for (int other = col + 1; other < outputMatrix[0].size(); ++other) {
                Var newV = gvSatSolver->newVar();
                gvSatSolver->addAigCNF(newV, outputMatrix[row][col], false,
                                       outputMatrix[row][other], false);
                gvSatSolver->assertProperty(newV, false);
            }
    }

    cout << "constraints  finished, current clause: "
         << gvSatSolver->getNumClauses() << endl;

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
