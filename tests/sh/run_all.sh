for ((i = 1 ; i < 11 ; i++)); do
    if [[ ${#i} -eq 1 ]]; then
        num=0"$i"
    else
        num="$i"
    fi
    ./tests/sh/bmatch ./CAD_testdata/case"$num"/input ./CAD_testdata/case"$num"/match
done