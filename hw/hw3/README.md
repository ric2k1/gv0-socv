# ----------------------------------
# To get HW#3 source code, you can : 
# ----------------------------------
(1) git clone https://github.com/ric2k1/gv0-socv; ./SETUP.sh; ./INSTALL.sh; (if first use gv0-socv engine) 
(2) cd gv0-socv/; git pull; make; (if has gv0-socv engine in your directory)

# ----------------------------------
# To try / play with BDD command in this homework, you can : 
# You can refer to "tutorial/GV_tutorial.pdf" for GV command
# Also, you can refer to "tests/dofile/" command to play with "gvbdd-ref" 
# ----------------------------------
cd hw3/ref; ./gvbdd-ref-{linux,mac}; 

# ----------------------------------
# In GV (this homework), the step you can try : 
# ----------------------------------
./gv 
yosysSetup> read design -v tests/a.v 
# "blast ntk": convert input design to AIG network, and store it into engine 
# Please do "blast ntk" before operating BDD command
yosysSetup> blast ntk 
# you can print network to realize the design, the ID or the variable name
yosysSetup> print aig -pi 
yosysSetup> print aig -po
yosysSetup> print aig -ri
yosysSetup> print aig -summary
# operate BDD command (setup mode)
# "breset": this command is optional, default create size=128 for _support, if your design is bigger than the scale, please reset more size (e.g. 500) for _support
yosysSetup> breset 500 8009 30011 
yosysSetup> bsetorder -f 
yosysSetup> bconstruct -all 
# After constructing BDD network, you can visualize node's BDD by its NetID
v3> breport 30 
# operate prove command (vrf mode) 
yosysSetup> set system vrf 
yosysSetup> pinit 

# ----------------------------------
# Or you can just execute dofile 
# ----------------------------------
./gv -f <filename>.dofile 

# ----------------------------------
# Even you can dump the terminal messages to output file for debugging 
# ----------------------------------
./gv -f <filename>.dofile > <filename>.txt

# ----------------------------------
# Note: you can try smaller cases under "tests/" folder first to test your program
# Since "vending.v" scale might cause BDD size exploded, you can try advanced technique to verify it (e.g. abstract design) 
# ----------------------------------
