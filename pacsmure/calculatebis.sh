for num in 0.173342 0.240012 0.306682 0.600030 0.733370 0.900045 0.926713 1.266730 1.506742 1.853426 2.526717 4.426812 4.613488 4.846833 
do
    rm out_${num}
    root -l -b -q "changeinput.C+(\"tetra\",\"SP1 -2 ${num}\",94)"
    mcnp i=tetra o=out_${num}&
    rm runtpe
    while [ $(jobs | wc -l) -ge 20 ] ; do sleep 1 ; done
done