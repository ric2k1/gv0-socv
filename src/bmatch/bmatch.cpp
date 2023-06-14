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

// calculate score based on the mapping results
static int getScore(GVSatSolver* matrixSolver, const vector<vector<Var>>& outputMatrix) {
    // TODO: How about undefined output ?? Is it possible that there is undefined variable in the output matrix ?
    int score = 0;
    for (int row = 0; row < outputMatrix.size() / 2; ++row) {
        bool foundOne = false;
        for (int col = 0; col < outputMatrix[row].size(); ++col) {
            if (matrixSolver->getVarValue(outputMatrix[2 * row][col]) == 1) {
                score ++;
                foundOne = true;
            }
            if (matrixSolver->getVarValue(outputMatrix[2 * row + 1][col]) == 1) {
                score ++;
                foundOne = true;
            }
        }
        if (foundOne) score += 1;
    }
    return score;
}

void
SATMgr::booleanMatching(int nPI1, int nPI2, int nPO1, int nPO2) {
    cout << "enter booleanMatching!" << endl;
    // SatProofRes  pRes;
    GVSatSolver* matrixSolver = new GVSatSolver(gvNtkMgr);
    GVSatSolver* miterSolver = new GVSatSolver(gvNtkMgr);
    // pRes.setSatSolver(matrixSolver);
    /*
    for (int i = 0; i < gvNtkMgr->getOutputSize(); ++i) {
        miterSolver->addBoundedVerifyData(gvNtkMgr->getOutput(i), 0);
    }
    miterSolver->add_XNOR_gate(gvNtkMgr->getInput(0), gvNtkMgr->getInput(nPI1));
    assert(0);
    */
    //cout<<"be "<<gvNtkMgr->getNetSize()<<endl;
    //gvNtkMgr->createNet();
    //cout<<"af "<<gvNtkMgr->getNetSize()<<endl;

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
    //cout<<"PI1 "<<nPI1<<" PI2 "<<nPI2<<" PO1 "<<nPO1<<" PO2 "<<nPO2<<endl;

    // bulid matrix
    // build each output Data
    cout << "init current clause: " << matrixSolver->getNumClauses() << endl;
    // (1) input permutation matirx
    vector<vector<Var>> inputMatrix(nPI1 * 2 + 2,vector<Var>(nPI2));    // have little change
    for (int col = 0; col < nPI2; ++col) {
        for (int row = 0; row < nPI1 * 2 + 2; ++row) {
            Var newVar            = matrixSolver->newVar();
            inputMatrix[row][col] = newVar;
        }
    }
    // add input constraint
    vector<bool> inputCol_b(2 * nPI2, false);
    vector<Var> inputCol_v(2 * nPI2);
    for (unsigned v = 0; v < nPI1; ++v) { //notice 0, 1 row not >= 1
        for (unsigned col = 0; col < nPI2; ++col) {
            inputCol_v[2 * col] = inputMatrix[2 * v][col];
            inputCol_v[2 * col + 1] = inputMatrix[2 * v + 1][col];
        }
        matrixSolver->addCNF(inputCol_v, inputCol_b);
    }

    vector<Var> inputRow1_v(nPI1 * 2 + 2);
    vector<bool> inputRow1_b(nPI1 * 2 + 2, false);
    for (unsigned col = 0; col < nPI2; ++col) {
        for (unsigned row = 0; row < nPI1 * 2 + 2; ++row) {
            inputRow1_v[row] = inputMatrix[row][col];
        }
        matrixSolver->addCNF(inputRow1_v, inputRow1_b);
    }

    for (unsigned col = 0; col < nPI2; ++col) {
        for (unsigned row1 = 0; row1 < nPI1 * 2 + 2; ++row1) {
            for (unsigned row2 = row1 + 1; row2 < nPI1 * 2 + 2; ++row2) {
                matrixSolver->addCNF(inputMatrix[row1][col], true, inputMatrix[row2][col], true);
            }
        }
    }
    // (2) output permutation matirx
    vector<vector<Var>> outputMatrix(nPO1 * 2,vector<Var>(nPO2));
    for (int col = 0; col < nPO2; ++col) {
        for (int row = 0; row < nPO1 * 2; ++row) {
            Var newVar            = matrixSolver->newVar();
            outputMatrix[row][col] = newVar;
        }
    }
    // add output constraint
    for (unsigned col = 0; col < nPO2; ++col) {
        for (unsigned row1 = 0; row1 < nPO1 * 2; ++row1) {
            for (unsigned row2 = row1 + 1; row2 < nPO1 * 2; ++row2) {
                matrixSolver->addCNF(outputMatrix[row1][col], true, outputMatrix[row2][col], true);
            }
        }
    }

    cout << "builded matrix, current clause: " << matrixSolver->getNumClauses()
         << endl;
    // build miter
    cout << "init current clause: " << miterSolver->getNumClauses() << endl;
    for (int i = 0; i < gvNtkMgr->getOutputSize(); ++i) {
        miterSolver->addBoundedVerifyData(gvNtkMgr->getOutput(i), 0);
    }

    // weird example
    // miterSolver->assumeProperty(gvNtkMgr->getInput(0), false, 0);
    // miterSolver->assumeProperty(gvNtkMgr->getInput(1), false, 0);
    // miterSolver->assumeProperty(gvNtkMgr->getInput(2), false, 0);
    // miterSolver->assumeProperty(gvNtkMgr->getInput(3), false, 0);
    // miterSolver->assumeProperty(gvNtkMgr->getOutput(0), false, 0);

    // if (miterSolver->assump_solve()) {
    //     cout << "output" << endl;
    //         for (int i = 0; i < gvNtkMgr->getOutputSize(); ++i) {
    //             cout << i << ":" << miterSolver->getDataValue(gvNtkMgr->getOutput(i), 0) << endl;
    //     }
    //     cout << "input" << endl;
    //         for (int i = 0; i < gvNtkMgr->getInputSize(); ++i) {
    //             cout << i << ":" << miterSolver->getDataValue(gvNtkMgr->getInput(i), 0) << endl;
    //     } 
    // }

    unsigned num_ntk = gvNtkMgr->getNetSize();
    cout << "init ntk num: " << num_ntk << endl;
    cout << "builded ckt, current clause: " << miterSolver->getNumClauses()
         << endl;
    cout << nPI1 << " " << nPI2 << " " << nPO1 << " " << nPO2 << endl;
    vector<vector<GVNetId>> i_Matching(nPI1 * 2,vector<GVNetId>(nPI2));
    // input should be same
    for (int v2 = 0; v2 < nPI2; ++v2) {
        for (int v1 = 0; v1 < nPI1; ++v1) {
            cout << v1 << " " << v2 << endl;
            i_Matching[v1 * 2][v2] = miterSolver->add_XNOR_gate(gvNtkMgr->getInput(v1), gvNtkMgr->getInput(nPI1 + v2));
            i_Matching[v1 * 2 + 1][v2] = miterSolver->add_XNOR_gate(~gvNtkMgr->getInput(v1), gvNtkMgr->getInput(nPI1 + v2));
        }
    }
    cout << "----" << endl;
    vector<vector<GVNetId>> o_Matching(nPO1 * 2,vector<GVNetId>(nPO2));
    // output should not be different(because !P, so use XOR)
    for (int v2 = 0; v2 < nPO2; ++v2) {
        for (int v1 = 0; v1 < nPO1; ++v1) {
            cout << v1 << " " << v2 << endl;
            o_Matching[v1 * 2][v2] = miterSolver->add_XOR_gate(gvNtkMgr->getOutput(v1), gvNtkMgr->getOutput(nPO1 + v2));
            o_Matching[v1 * 2 + 1][v2] = miterSolver->add_XOR_gate(~gvNtkMgr->getOutput(v1), gvNtkMgr->getOutput(nPO1 + v2));
        }
    }
    cout << "now ntk num: " << gvNtkMgr->getNetSize() << endl;
    cout << "builded mitter, current clause: " << miterSolver->getNumClauses()
         << endl;
    // unsigned mustOut = 0;
    vector<vector<bool>> inputAns(nPI1 * 2 + 2,vector<bool>(nPI2));
    vector<vector<bool>> outputAns(nPO1 * 2,vector<bool>(nPO2));
    int score = -1;
    bool foundOneAns = false; // must find at least one solution
    while (1) {
        // #ifdef DEBUG
        // ++mustOut;
        // if (mustOut > 1000) break;
        // #endif
    // solve mapping matrix
    // if UNSAT -> return no match
    // if SAT -> keep going
        // if (matrixSolver->assump_solve()) {
        GVNetId S;
        bool is_S;
        if (matrixSolver->solve()) {
            // assert(!(matrixSolver->getVarValue(inputMatrix[0][0]) == 1 && matrixSolver->getVarValue(inputMatrix[0][1]) == 1));
            // assert(!(matrixSolver->getVarValue(inputMatrix[1][0]) == 1 && matrixSolver->getVarValue(inputMatrix[0][0]) == 1));
            // cout << "matrixSolver SAT" << endl;
            // cout << "input" << endl;
            // for (int col = 0; col < nPI2; ++col) {
            //     for (int row = 0; row < nPI1 * 2 + 2; ++row) {
            //         cout << matrixSolver->getVarValue(inputMatrix[row][col]) << " ";
            //     }
            //     cout << endl;
            // }
            // cout << "output" << endl;
            // for (int col = 0; col < nPO2; ++col) {
            //     for (int row = 0; row < nPO1 * 2; ++row) {
            //         cout << matrixSolver->getVarValue(outputMatrix[row][col]) << " ";
            //     }
            //     cout << endl;
            // }
            
            miterSolver->assumeRelease();
            // input should be same
            for (int v2 = 0; v2 < nPI2; ++v2) {
                for (int v1 = 0; v1 < 2 * nPI1; ++v1) {
                    if (matrixSolver->getVarValue(inputMatrix[v1][v2]) == 1)
                        miterSolver->assumeProperty(i_Matching[v1][v2], false, 0);
                }
                if (matrixSolver->getVarValue(inputMatrix[nPI1 * 2][v2]) == 1)
                    miterSolver->assumeProperty(gvNtkMgr->getInput(v2), false, 0);
                if (matrixSolver->getVarValue(inputMatrix[nPI1 * 2 + 1][v2]) == 1)
                    miterSolver->assumeProperty(~gvNtkMgr->getInput(v2), false, 0);
            }
            // output should not be different
            // GVNetId S;
            is_S = false;
            for (int v2 = 0; v2 < nPO2; ++v2) {
                for (int v1 = 0; v1 < nPO1 * 2; ++v1) {
                    if (matrixSolver->getVarValue(outputMatrix[v1][v2]) == 1) {
                        // cout << "output "<< v1 << " " << v2 << " should always same" << endl;
                        if (!is_S) {S = o_Matching[v1][v2]; is_S = true;}
                        else S = miterSolver->add_OR_gate(o_Matching[v1][v2], S);
                    }
                }
            }
            if (is_S) miterSolver->assumeProperty(S, false, 0);
        } else {
            // matrixSlover UNSAT -> no remaining matching
            cout << "No remaining matching" << endl;
            break;
        }

        if (miterSolver->assump_solve()) { 
            // miterSolver SAT -> exclude this wrong mapping from mappingSolver
            // cout << "miterSlover SAT" << endl;
            if (is_S) {
                // cout << "matrixSolver" << endl;
                // cout << "input" << endl;
                // for (int col = 0; col < nPI2; ++col) {
                //     for (int row = 0; row < nPI1 * 2; ++row) {
                //         if (matrixSolver->getVarValue(inputMatrix[row][col]) == 1) {
                //             cout << "input "<< row << " " << col << " is same ? ";
                //             cout << miterSolver->getDataValue(i_Matching[row][col], 0) << endl;
                //         }
                //     }
                // }
                if (matrixSolver->getVarValue(inputMatrix[0][0]) == 1 && matrixSolver->getVarValue(inputMatrix[2][1]) == 1) {
                    if (true) {
                    // if (matrixSolver->getVarValue(outputMatrix[0][0]) == 1 && matrixSolver->getVarValue(outputMatrix[2][1]) == 1) {
                        cout << "output" << endl;
                        for (int i = 0; i < gvNtkMgr->getOutputSize(); ++i) {
                            cout << i << ":" << miterSolver->getDataValue(gvNtkMgr->getOutput(i), 0) << endl;
                        }
                        cout << "input" << endl;
                        for (int i = 0; i < gvNtkMgr->getInputSize(); ++i) {
                            cout << i << ":" << miterSolver->getDataValue(gvNtkMgr->getInput(i), 0) << endl;
                        }
                        for (int col = 0; col < nPI2; ++col) {
                            for (int row = 0; row < nPI1 * 2; ++row) {
                                if (matrixSolver->getVarValue(inputMatrix[row][col]) == 1) {
                                    cout << "input "<< row << " " << col << " is same ? ";
                                    cout << miterSolver->getDataValue(i_Matching[row][col], 0) << endl;
                                }
                            }
                        }
                        for (int col = 0; col < nPO2; ++col) {
                            for (int row = 0; row < nPO1 * 2; ++row) {
                                // cout << matrixSolver->getVarValue(outputMatrix[row][col]) << " ";
                                if (matrixSolver->getVarValue(outputMatrix[row][col]) == 1) {
                                    cout << "output "<< row << " " << col << " is not same ? ";
                                    cout << miterSolver->getDataValue(o_Matching[row][col], 0) << endl;
                                }
                            }
                            // cout << endl;
                        }
                        cout << "is there output not match : " << miterSolver->getDataValue(S, 0) << endl;
                    }
                }
                // cout << miterSolver->getDataValue(S, 0) << endl;
            }
            // cout << miterSolver->getDataValue(S, 0) << endl;
        } 
        else {
            // miterSolver UNSAT -> find a matching mapping
            cout << "miterSlover UNSAT -> find a matching mapping" << endl;
            foundOneAns = true;
            int newScore = getScore(matrixSolver, outputMatrix);
            if (newScore > score) {
                cout << "Update mapping with score: " << newScore << ", mapping as follows:" << endl;
                cout << "input" << endl;
                for (int col = 0; col < nPI2; ++col) {
                    for (int row = 0; row < nPI1 * 2 + 2; ++row) {
                        inputAns[row][col] = matrixSolver->getVarValue(inputMatrix[row][col]);
                        cout << inputAns[row][col] << " ";
                    }
                    cout << endl;
                }
                cout << "output" << endl;
                for (int col = 0; col < nPO2; ++col) {
                    for (int row = 0; row < nPO1 * 2; ++row) {
                        outputAns[row][col] = matrixSolver->getVarValue(outputMatrix[row][col]);
                        cout << outputAns[row][col] << " ";
                    }
                    cout << endl;
                }
                score = newScore; //modify
            }
            // block the found mapping
            // modify : take out the loop
        }
        int nofMatrixVar = nPI2 * (nPI1 * 2 + 2) + nPO2 * (nPO1 * 2);
        vector<Var> vs(nofMatrixVar);
        vector<bool> bs(nofMatrixVar); // bs[index] is true -> ~vs[index] in clause
        int index = 0;
        for (int col = 0; col < nPI2; ++col) {
            for (int row = 0; row < nPI1 * 2 + 2; ++row) {
                vs[index] = inputMatrix[row][col];
                bs[index] = (matrixSolver->getVarValue(inputMatrix[row][col]) == 1);
                index ++;
            }
        }
        for (int col = 0; col < nPO2; ++col) {
            for (int row = 0; row < nPO1 * 2; ++row) {
                vs[index] = outputMatrix[row][col];
                bs[index] = (matrixSolver->getVarValue(outputMatrix[row][col]) == 1);
                index ++;
            }
        }
        matrixSolver->addCNF(vs, bs);
    }
    assert(foundOneAns);
    // output optimal solution
    cout << "Optimal score: " << score << ", mapping as follows:" << endl;
    cout << "input" << endl;
    for (int col = 0; col < nPI2; ++col) {
        for (int row = 0; row < nPI1 * 2 + 2; ++row) {
            inputAns[row][col] = matrixSolver->getVarValue(inputMatrix[row][col]);
            cout << inputAns[row][col] << " ";
        }
        cout << endl;
    }
    cout << "output" << endl;
    for (int col = 0; col < nPO2; ++col) {
        for (int row = 0; row < nPO1 * 2; ++row) {
            outputAns[row][col] = matrixSolver->getVarValue(outputMatrix[row][col]);
            cout << outputAns[row][col] << " ";
        }
        cout << endl;
    }
}


// /****************************************************************************
//   FileName     [ bmatch.cpp ]
//   PackageName  [ bmatch ]
//   Synopsis     [ Define sat prove package interface ]
//   Author       [ ]
//   Copyright    [ Copyleft(c) 2010 LaDs(III), GIEE, NTU, Taiwan ]
//  ****************************************************************************/

// #include "gvMsg.h"
// #include "gvSatMgr.h"
// #include "reader.h"
// #include <cassert>
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// // #define isGVNetInverted(netId) (netId.cp)

// void
// SATMgr::booleanMatching(int nPI1, int nPI2, int nPO1, int nPO2) {
//     cout << "enter booleanMatching!" << endl;
//     SatProofRes  pRes;
//     GVSatSolver* gvSatSolver = new GVSatSolver(gvNtkMgr);
//     pRes.setSatSolver(gvSatSolver);

//     // assume input number= nPI1, nPI2
//     // assume onput number= nPO1, nPO2
//     //int nPI1 = 2;
//     //int nPI2 = 2;
//     //int nPO1 = 2;
//     //int nPO2 = 2;

//     /*
//     for (int i = 0; i < gvNtkMgr->getInputSize(); ++i) {
//         cout<<"input:"<<i<<" "<<gvNtkMgr->getNetNameFromId(gvNtkMgr->getInput(i).id)<<endl;
//     }
//     for (int i = 0; i < gvNtkMgr->getOutputSize(); ++i) {
//         cout<<"output:"<<i<<" "<<gvNtkMgr->getNetNameFromId(gvNtkMgr->getOutput(i).id)<<endl;
//     }*/

//     // bulid matrix
//     // build each output Data
//     cout << "init current clause: " << gvSatSolver->getNumClauses() << endl;
//     for (int i = 0; i < gvNtkMgr->getOutputSize(); ++i) {
//         gvSatSolver->addBoundedVerifyData(gvNtkMgr->getOutput(i), 0);
//     }
//     cout << "builded circuit relation, current clause: "
//          << gvSatSolver->getNumClauses() << endl;

//     // (1) input permutation matirx
//     vector<vector<Var>> inputMatrix(nPI2, vector<int>(nPI1 * 2 + 2));
//     for (int row = 0; row < nPI2; ++row) {
//         for (int col = 0; col < nPI1 * 2 + 2; ++col) {
//             Var newVar            = gvSatSolver->newVar();
//             inputMatrix[row][col] = newVar;
//         }
//     }
//     for (int i = 0; i < nPI2; ++i) {
//         for (int j = 0; j < nPI1; ++j) {
//             // ### for aij -> XOR: xj == yi
//             Var XOR_a;
//             gvSatSolver->addXorCNF(XOR_a, gvNtkMgr->getInput(j), false,
//                                    gvNtkMgr->getInput(i + nPI1), false);
//             gvSatSolver->addCNF(XOR_a, true, inputMatrix[i][j * 2], true);
//             // ### for bij -> XOR': xj' == yi
//             Var XOR_b;
//             gvSatSolver->addXorCNF(XOR_b, gvNtkMgr->getInput(j), true,
//                                    gvNtkMgr->getInput(i + nPI1), false);
//             gvSatSolver->addCNF(XOR_b, true, inputMatrix[i][j * 2 + 1], true);
//         }
//     }
//     // ### for zi/Oi -> yi = constant 0 / 1
//     for (int row = 0; row < nPI2; ++row) {
//         // constant 0
//         gvSatSolver->addCNF(gvNtkMgr->getInput(row + nPI1), true,
//                             inputMatrix[row][nPI1 * 2], true);
//         // constant 1
//         gvSatSolver->addCNF(gvNtkMgr->getInput(row + nPI1), false,
//                             inputMatrix[row][nPI1 * 2 + 1], true);
//     }
//     cout << "building input matrix -- aij bij end, current clause: "
//          << gvSatSolver->getNumClauses() << endl;


//     // constraints for input permutation matirx
//     //   (a) each input y map to x or 0/1
//     //       <=1: each two var AND can not be 1 (only a var can be 1)
//     for (int row = 0; row < inputMatrix.size(); ++row) {
//         for (int col = 0; col < inputMatrix[0].size() - 1; ++col)
//             for (int other = col + 1; other < inputMatrix[0].size(); ++other) {

//                 Var newV = gvSatSolver->newVar();
//                 gvSatSolver->addAigCNF(newV, inputMatrix[row][col], false,
//                                        inputMatrix[row][other], false);
//                 gvSatSolver->assertProperty(newV, false);
//             }
//     }

//     bool result;
//     result = gvSatSolver->solve();
//     if (result) {
//         for (int row = 0; row < nPI2; ++row) {
//             for (int col = 0; col < nPI1 * 2 + 2; ++col) {
//                 cout << gvSatSolver->getDataValue(inputMatrix[row][col]) << " ";
//             }
//             cout << endl;
//         }
//     } else {
//         cout << "UNSAT" << endl;
//     }

//     //      !=0: the whole row can not be 0
//     for (int row = 0; row < inputMatrix.size(); ++row) {
//         Var temp = gvSatSolver->newVar();
//         gvSatSolver->addAigCNF(temp, inputMatrix[row][0], true,
//                                inputMatrix[row][1], true);
//         for (int col = 2; col <= inputMatrix[0].size(); ++col) {
//             for (int j = 2; j < nPI2; ++j) {
//                 Var newV = gvSatSolver->newVar();
//                 gvSatSolver->addAigCNF(newV, inputMatrix[row][col], true, temp,
//                                        false);
//                 temp = newV;
//             }
//             gvSatSolver->assertProperty(temp, false);
//         }
//     }

//     cout << "constraints (a) finished, current clause: "
//          << gvSatSolver->getNumClauses() << endl;

//     //   (b) many input y to one x -> can't be no mapping(?)
//     // y -> x
//     for (int j = 0; j < nPI1; ++j) {
//         vector<Var>  vas;
//         vector<bool> fas(nPI2 * 2, false);
//         for (int i = 0; i < nPI2; ++i) {
//             vas.push_back(inputMatrix[i][j * 2]);
//             vas.push_back(inputMatrix[i][j * 2 + 1]);
//         }
//         gvSatSolver->addCNF(vas, fas);
//     }
//     // y-> 0/1
//     vector<Var>  vas;
//     vector<bool> fas(nPI2, false);
//     // constant 0
//     for (int i = 0; i < nPI2; ++i) {
//         vas.push_back(inputMatrix[i][nPI1 * 2]);
//     }
//     gvSatSolver->addCNF(vas, fas);
//     vas.clear();
//     for (int i = 0; i < nPI2; ++i) {
//         vas.push_back(inputMatrix[i][nPI1 * 2]);
//     }
//     gvSatSolver->addCNF(vas, fas);
//     cout << "constraints (b) finished, current clause: "
//          << gvSatSolver->getNumClauses() << endl;

//     // (2) output permutation matirx
//     vector<vector<Var>> outputMatrix(nPO2, vector<int>(nPO1 * 2 + 2));
//     for (int row = 0; row < nPO2; ++row) {
//         for (int col = 0; col < nPO1 * 2 + 2; ++col) {
//             Var newVar             = gvSatSolver->newVar();
//             outputMatrix[row][col] = newVar;
//         }
//     }

//     for (int i = 0; i < nPO2; ++i) {
//         for (int j = 0; j < nPO1; ++j) {
//             // ### for cij -> XOR: fj == f*i
//             Var XOR_c;
//             gvSatSolver->addXorCNF(XOR_c, gvNtkMgr->getOutput(j), false,
//                                    gvNtkMgr->getOutput(i + nPO1), false);
//             gvSatSolver->addCNF(XOR_c, true, outputMatrix[i][j * 2], true);
//             // ### for bij -> XOR': fj' == f*i
//             Var XOR_d;
//             gvSatSolver->addXorCNF(XOR_d, gvNtkMgr->getOutput(j), true,
//                                    gvNtkMgr->getOutput(i + nPO1), false);
//             gvSatSolver->addCNF(XOR_d, true, outputMatrix[i][j * 2 + 1], true);
//         }
//     }
//     cout << "building output matrix -- cij dij end, current clause: "
//          << gvSatSolver->getNumClauses() << endl;

//     // constraints for output permutation matirx
//     //  many output f* map one output f sum<=1
//     for (int row = 0; row < outputMatrix.size(); ++row) {
//         // the same row -> one seat & the same column -> one man
//         for (int col = 0; col < outputMatrix[0].size() - 1; ++col)
//             for (int other = col + 1; other < outputMatrix[0].size(); ++other) {
//                 Var newV = gvSatSolver->newVar();
//                 gvSatSolver->addAigCNF(newV, outputMatrix[row][col], false,
//                                        outputMatrix[row][other], false);
//                 gvSatSolver->assertProperty(newV, false);
//             }
//     }

//     cout << "constraints  finished, current clause: "
//          << gvSatSolver->getNumClauses() << endl;

//     // while (1) {

//     // solve mapping matrix
//     // if UNSAT -> return no match
//     // if SAT -> keep going

//     // (matching SAT)
//     // build miter (建亨)

//     // (miter UNSAT)
//     // record score & exclude current matching (wish)
//     // }
// }
