# ICCAD 2023 Problem A
## Document
[ICCAD 2023 Problem A report](https://docs.google.com/document/d/1IwRJmWurMKUFpEzGPRlqsisgXPsYYjdKnI81r-mT59s/edit)

[CAD討論進度](https://docs.google.com/document/d/1_S91WvefRApemSWcJEM14oBDBZ7n9NKA2SnN2d04OFc/edit)

## Main Algorithm
* One matching 
if problem size is **too large** $\rightarrow$ ***it is not pratical to find all possible matching***
iteratively update current optimal matching until 3500 seconds and output current optimal matching
![](https://i.imgur.com/kkqAPN7.png)

* All matching
if problem size is **not too large** $\rightarrow$ find **all possible matching** at once and find optimal matching
![](https://i.imgur.com/vDqvAjW.png)

## Usage

### Compile
after build up gv environment then make

### Execution

#### Run all test file
./tests/sh/run_all.sh : run all test file in CAD_testdata and output result to corresponding directory

#### Run specific test file

./tests/sh/bmatch "input" "match" : run "input" file and output result to "match"

exemple : ./tests/sh/bmatch CAD_testdata/case01/input CAD_testdata/case01/match

# GV

## GV tool installation
```json=
git clone https://github.com/ric2k1/gv0-socv
cd gv0-socv/
# General Users
sudo ./SETUP.sh 
./INSTALL.sh
```

- **For using GV tool interface, type after installation:**
```json=
./gv
```

- **Please notice that, if the shell script has no permission, type:**
```json=
chmod +x <shell_script_filename>
```

## GV tool's third-party tools
- **parser** --> [yosys](https://github.com/YosysHQ/yosys), [berkeley-abc](https://github.com/berkeley-abc/abc)
- **file format converter** --> yosys
- **formal verification engine** --> berkeley-abc 
- **simulator** --> yosys

## GV tool's API
- Please check the document above to get detailed tutorials in "gv0-socv/doc/"
- Below are current supporting APIs, please type "help <command>" for detailed usage
    - **Common commands** 
    ```json=
    GV Help
    GV History 
    GV Usage
    GV Dofile
    GV Quit
    ```

    - **Verify commands**
    ```json=
    GV Formal Verify
    ```

    - **Simulate commands**
    ```json=
    GV Random Simulate
    GV SEt SAfe
    GV SHow
    ```

    - **Network commands** 
    ```json=
    GV BLAst Ntk
    GV File2 Aig
    GV File2 Blif
    GV PRInt Aig
    GV PRint Info
    GV REad Design
    GV SEt Engine
    GV WRite aig
    GV YosysCMD
    ```
    
    - **Abc commands** 
    ```json=
    GV ABCCMD
    GV ABCPrint
    GV ABCRead
    ```

    - **Mode commands** 
    ```json=
    GV RESET SYStem
    GV SEt System
    GV WIZard
    ```

    - **Bdd Commands** 
    ```json=
    GV BAND
    GV BCOFactor 
    GV BCOMpare 
    GV BConstruct 
    GV BDRAW 
    GV BEXist 
    GV BINV 
    GV BNAND 
    GV BNOR 
    GV BOR 
    GV BREPort 
    GV BRESET 
    GV BSETOrder 
    GV BSETVar 
    GV BSIMulate 
    GV BXNOR 
    GV BXOR 
    ```

    - **Prove Commands** 
    ```json=
    GV PCHECKProperty
    GV PIMAGe 
    GV PINITialstate 
    GV PTRansrelation 
    ```
   


