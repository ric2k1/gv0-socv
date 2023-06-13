./aigtoaig ./tests/inputs/test1.aig ./tests/inputs/test1.aag
./aigtoaig ./tests/inputs/test2.aig ./tests/inputs/test2.aag
./gv -f ./tests/dofile/test.dofile
rm -rf ./tests/inputs/*.aig