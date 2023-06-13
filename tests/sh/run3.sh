./parser ./CAD_testdata/case03/circuit_1.v ./CAD_testdata/case03/1.v 1
./parser ./CAD_testdata/case03/circuit_2.v ./CAD_testdata/case03/2.v 2
./gv -f ./tests/dofile/run1.dofile
rm -rf ./CAD_testdata/case03/1.v
rm -rf ./CAD_testdata/case03/2.v
./aigtoaig CAD_testdata/case03/1.aig CAD_testdata/case03/1.aag
./aigtoaig CAD_testdata/case03/2.aig CAD_testdata/case03/2.aag
./aigtoaig ./CAD_testdata/case03/circuit_1.aig ./CAD_testdata/case03/circuit_1.aag 
./aigtoaig ./CAD_testdata/case03/circuit_2.aig ./CAD_testdata/case03/circuit_2.aag
./aig_map ./CAD_testdata/case03/1.aag ./CAD_testdata/case03/2.aag ./CAD_testdata/case03/name
rm -rf ./CAD_testdata/case03/*.aig
rm -rf ./CAD_testdata/case03/1.aag
rm -rf ./CAD_testdata/case03/2.aag
#./ ./CAD_testdata/case03/circuit_1.aag ./CAD_testdata/case03/circuit_2.aag ./CAD_testdata/case03/name
#rm -rf ./CAD_testdata/case03/*.aig ./CAD_testdata/case03/*.aag ./CAD_testdata/case03/name