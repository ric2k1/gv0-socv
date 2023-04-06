## To get HW#3 source code, you can : 
- if first install
```json=
git clone https://github.com/ric2k1/gv0-socv
./SETUP.sh
./INSTALL.sh
```
- if has installed before
```json=
cd gv0-socv/
git pull
make
```

## To try / play with BDD command in this homework, you can : 
- You can refer to "tutorial/GV_tutorial.pdf" for GV command
- Also, you can refer to "tests/dofile/" command to play with "gvbdd-ref" 
```json=
cd hw3/ref
./gvbdd-ref-{linux,mac}
```

## In GV (this homework), the step you can try : 
- **"blast ntk"**: convert input design to AIG network, and store it into engine 
    - please do "blast ntk" before operating BDD command
- **"print aig"**: you can print network to realize the design, the ID or the variable name
- **"breset"**: this command is optional, default create size=128 for _support, if your design is bigger than the scale, please reset more size (e.g. 500) for _support
- **"breport"**: After constructing BDD network, you can visualize node's BDD by its NetID
```json=
./gv 
yosysSetup> read design -v tests/a.v 
yosysSetup> blast ntk 
yosysSetup> print aig -pi 
yosysSetup> print aig -po
yosysSetup> print aig -ri
yosysSetup> print aig -summary
yosysSetup> breset 500 8009 30011 
yosysSetup> bsetorder -f 
yosysSetup> bconstruct -all 
yosysSetup> breport 50 
yosysSetup> set system vrf 
vrf> pinit 
```

## Or you can just execute dofile 
```json=
./gv -f <filename>.dofile 
```

## Even you can dump the terminal messages to output file for debugging 
```json=
./gv -f <filename>.dofile > <filename>.txt
```

## Note: you can try smaller cases under "tests/" folder first to test your program
- Since "vending.v" scale might cause BDD size exploded, you can try advanced technique to verify it (e.g. abstract design) 
