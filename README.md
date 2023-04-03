# gv0
Verification research for general RTL/system-level designs (take 0.0)

# GV tool installation
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

# GV tool's third-party tools
- **parser** --> [yosys](https://github.com/YosysHQ/yosys), [berkeley-abc](https://github.com/berkeley-abc/abc)
- **file format converter** --> yosys
- **formal verification engine** --> berkeley-abc 
- **simulator** --> yosys

# GV tool's API 
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

# GV tool's set-system-mode flow
- Please check the document above to get detailed tutorials in gv0-socv/doc/
