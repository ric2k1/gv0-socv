/****************************************************************************
  FileName     [ satCmd.cpp ]
  PackageName  [ sat ]
  Synopsis     [ Define basic sat prove package commands ]
  Author       [ ]
  Copyright    [ Copyleft(c) 2010 LaDs(III), GIEE, NTU, Taiwan ]
 ****************************************************************************/

#include "bmatchCmd.h"
#include "gvMsg.h"
#include "gvSatMgr.h"
#include "util.h"
#include <cstring>
#include <iomanip>
using namespace std;

static SATMgr* satMgr = new SATMgr();

bool
GVinitBMatchCmd() {
    return (gvCmdMgr->regCmd("SATVerify BMatch", 4, 2, new SATVerifyBMatchCmd));
}

//----------------------------------------------------------------------
//    SATVerify BMatch
//----------------------------------------------------------------------
GVCmdExecStatus
SATVerifyBMatchCmd::exec(const string& option) {
    vector<string> options;
    GVCmdExec::lexOptions(option, options);
    if (options.size() == 0){
        satMgr->booleanMatching(0 ,0, 0, 0);
    }
    else if (options.size() == 4){
        satMgr->booleanMatching(stoi(options[0]), stoi(options[1]), stoi(options[2]), stoi(options[3]));
    }
    else{
        return GVCmdExec::errorOption(GV_CMD_OPT_ILLEGAL,
        "<(int nPI1), (int nPI2), (int nPO1), (int nPO2)>");
    }
    //if (n == 0)
        //return GVCmdExec::errorOption(GV_CMD_OPT_MISSING, options[1]);
    return GV_CMD_EXEC_DONE;
}

void
SATVerifyBMatchCmd::usage(const bool& verbose) const {
    gvMsg(GV_MSG_IFO)
        << "Usage: SATVerify BMatch"
        << endl;
}

void
SATVerifyBMatchCmd::help() const {
    cout << setw(20) << left << "SATVerify BMatch:"
         << "boolean matching" << endl;
}
