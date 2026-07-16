for num in $(seq 0.006667 0.006667 6.667)
do  
    root -l -b -q "changeinput.C+(\"tetra\",\"SP1 -2 ${num}\",94)"
    mcnp i=tetra o=out_${num}&
    rm runtpe
    while [ $(jobs | wc -l) -ge 20 ] ; do sleep 1 ; done
done

for num in $(seq 0.006667 0.006667 6.667)
do
    root -l -b -q "readandwrite.C+(\"out_${num}\",\"data.dat\",\"multiplier bin:\")"
done