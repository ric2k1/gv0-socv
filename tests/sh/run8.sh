./parser ./CAD_testdata/case08/circuit_1.v ./CAD_testdata/case08/1.v 1
./parser ./CAD_testdata/case08/circuit_2.v ./CAD_testdata/case08/2.v 2
./gv -f ./tests/dofile/run1.dofile
rm -rf ./CAD_testdata/case08/1.v
rm -rf ./CAD_testdata/case08/2.v
./aigtoaig CAD_testdata/case08/1.aig CAD_testdata/case08/1.aag
./aigtoaig CAD_testdata/case08/2.aig CAD_testdata/case08/2.aag
./aigtoaig ./CAD_testdata/case08/circuit_1.aig ./CAD_testdata/case08/circuit_1.aag 
./aigtoaig ./CAD_testdata/case08/circuit_2.aig ./CAD_testdata/case08/circuit_2.aag
./aig_map ./CAD_testdata/case08/1.aag ./CAD_testdata/case08/2.aag ./CAD_testdata/case08/name
rm -rf ./CAD_testdata/case08/*.aig
rm -rf ./CAD_testdata/case08/1.aag
rm -rf ./CAD_testdata/case08/2.aag
#./ ./CAD_testdata/case08/circuit_1.aag ./CAD_testdata/case08/circuit_2.aag ./CAD_testdata/case08/name
#rm -rf ./CAD_testdata/case08/*.aig ./CAD_testdata/case08/*.aag ./CAD_testdata/case08/name