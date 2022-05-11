make all
echo "testing gtopoAssembleReduce"
./gtopoAssembleReduce   ./tmp.dem      43200   21600   216             0               0               ./GTOPO30/gt30w180n90_dem/gt30w180n90.dem       4800    6000    0               4800    ./GTOPO30/gt30w140n90_dem/gt30w140n90.dem       4800    6000    0               9600    ./GTOPO30/gt30w100n90_dem/gt30w100n90.dem       4800    6000    0               14400   ./GTOPO30/gt30w060n90_dem/gt30w060n90.dem       4800    6000    0               19200   ./GTOPO30/gt30w020n90_dem/gt30w020n90.dem       4800    6000    0               24000   ./GTOPO30/gt30e020n90_dem/gt30e020n90.dem       4800    6000    0               28800   ./GTOPO30/gt30e060n90_dem/gt30e060n90.dem       4800    6000    0               33600   ./GTOPO30/gt30e100n90_dem/gt30e100n90.dem       4800    6000    0               38400   ./GTOPO30/gt30e140n90_dem/gt30e140n90.dem       4800    6000    6000    0               ./GTOPO30/gt30w180n40_dem/gt30w180n40.dem       4800    6000    6000    4800    ./GTOPO30/gt30w140n40_dem/gt30w140n40.dem       4800    6000    6000    9600    ./GTOPO30/gt30w100n40_dem/gt30w100n40.dem       4800    6000    6000    14400   ./GTOPO30/gt30w060n40_dem/gt30w060n40.dem       4800    6000    6000    19200   ./GTOPO30/gt30w020n40_dem/gt30w020n40.dem       4800    6000    6000    24000   ./GTOPO30/gt30e020n40_dem/gt30e020n40.dem       4800    6000    6000    28800   ./GTOPO30/gt30e060n40_dem/gt30e060n40.dem       4800    6000    6000    33600   ./GTOPO30/gt30e100n40_dem/gt30e100n40.dem       4800    6000    6000    38400   ./GTOPO30/gt30e140n40_dem/gt30e140n40.dem       4800    6000    12000   0               ./GTOPO30/gt30w180s10_dem/gt30w180s10.dem       4800    6000    12000   4800    ./GTOPO30/gt30w140s10_dem/gt30w140s10.dem       4800    6000    12000   9600    ./GTOPO30/gt30w100s10_dem/gt30w100s10.dem       4800    6000    12000   14400   ./GTOPO30/gt30w060s10_dem/gt30w060s10.dem       4800    6000    12000   19200   ./GTOPO30/gt30w020s10_dem/gt30w020s10.dem       4800    6000    12000   24000   ./GTOPO30/gt30e020s10_dem/gt30e020s10.dem       4800    6000    12000   28800   ./GTOPO30/gt30e060s10_dem/gt30e060s10.dem       4800    6000    12000   33600   ./GTOPO30/gt30e100s10_dem/gt30e100s10.dem       4800    6000    12000   38400   ./GTOPO30/gt30e140s10_dem/gt30e140s10.dem       4800    6000    18000   0               ./GTOPO30/gt30w180s60_dem/gt30w180s60.dem       7200    3600    18000   7200    ./GTOPO30/gt30w120s60_dem/gt30w120s60.dem       7200    3600    18000   14400   ./GTOPO30/gt30w060s60_dem/gt30w060s60.dem       7200    3600    18000   21600   ./GTOPO30/gt30w000s60_dem/gt30w000s60.dem       7200    3600    18000   28800   ./GTOPO30/gt30e060s60_dem/gt30e060s60.dem       7200    3600    18000   36000   ./GTOPO30/gt30e120s60_dem/gt30e120s60.dem       7200    3600
diff tmp.dem test/dems/gtopo30full_reduced_216.dem
rm tmp.dem
echo "testing gtopoEcho"
./gtopoEcho ./test/dems/gtopo_reduced_0_0.dem 20 10 tmp.dem
diff tmp.dem test/dems/gtopo_reduced_0_0.dem
echo "testing gtopoComp"
./gtopoComp ./test/dems/gtopo_reduced_0_0.dem 20 10 tmp.dem
./gtopoComp ./test/dems/gtopo_reduced_0_0.dem 20 10 ./test/dems/gtopo_reduced_0_1.dem

rm tmp.dem
echo "testing gtopoTile"
./gtopoTile ./test/dems/gtopo30full_reduced_216.dem 200 100 10 "tmp_<row>_<column>.dem"
for i in {0..9}
do
	for j in {0..9}
	do
		diff ./test/dems/gtopo_reduced_$i\_$j.dem tmp_$i\_$j.dem
		rm tmp_$i\_$j.dem
	done
done
