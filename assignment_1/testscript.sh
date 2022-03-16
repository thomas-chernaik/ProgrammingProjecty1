#lets make all our programs
make all
#test for pgmEcho.
#first we will test it gives the correct output for an P2 pgm file.
echo "echoing testfile1 to testfileout1 and testfileout2"
./pgmEcho images/testfile1.pgm images/testfileout1.pgm
./pgmEcho images/testfile1.pgm images/testfileout2.pgm
diff images/testfileout2.pgm images/testfileout1.pgm
#then we test it for a P5 pgm file
echo "echoing testfile2 to testfilout3 and testfileout4"
./pgmEcho images/testfile2.pgm images/testfileout3.pgm
./pgmEcho images/testfile2.pgm images/testfileout4.pgm
diff images/testfileout3.pgm images/testfileout4.pgm
#these two files will be the same for pgmComp so it should output identical for both
echo "testing pgmComp with testfileout1-4"
./pgmComp images/testfileout1.pgm images/testfileout2.pgm
./pgmComp images/testfileout3.pgm images/testfileout4.pgm
rm images/testfileout*
#we will convert an ascii to a binary and then use our pgmComp to test it worked
echo "converting testfile1 to binary and using pgmComp to check it was successful"
./pgma2b images/testfile1.pgm images/testfile1b.pgm
./pgmComp images/testfile1.pgm images/testfile1b.pgm
#we do the same as pgma2b but in reverse for testing this.
echo "converting tsetfile2 to ascii and using pgmComp to check it was successful"
./pgmb2a images/testfile2.pgm images/testfile2a.pgm
./pgmComp images/testfile2.pgm images/testfile2a.pgm
rm images/testfile2a*
#now we test pgmReduce
echo "reducing testfile1 and comparing it to the expected output with pgmComp"
./pgmReduce images/testfile1.pgm 2 images/testfilereduceout.pgm
./pgmComp images/testfilereduce.pgm images/testfilereduceout.pgm
./pgmReduce images/testfile1b.pgm 2 images/testfilereduceoutb.pgm
./pgmComp images/testfilereduceb.pgm images/testfilereduceoutb.pgm
rm images/testfilereduceout*
#now we test pgmTile
echo "tiling testfile1 and comparing it to expected tiles"
./pgmTile images/testfile1.pgm 2 "images/testout_<row>_<col>.pgm"
./pgmComp images/testout_0_0.pgm images/test_0_0.pgm
./pgmComp images/testout_0_1.pgm images/test_0_1.pgm
./pgmComp images/testout_1_0.pgm images/test_1_0.pgm
./pgmComp images/testout_1_1.pgm images/test_1_1.pgm
rm images/testout_*
#now we testpgmAssemble
echo "assembling a tiled file and comparing it to the original file"
./pgmAssemble images/testAssemble.pgm 2 2 0 0 images/test_0_0.pgm 0 1 images/test_0_1.pgm 1 0 images/test_1_0.pgm 1 1 images/test_1_1.pgm
./pgmComp images/testAssemble.pgm images/testfile1.pgm
