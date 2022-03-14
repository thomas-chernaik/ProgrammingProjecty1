#lets make all our programs
make pgmEcho
make pgmComp
make pgma2b
make pgmb2a
#test for pgmEcho.
#first we will test it gives the correct output for an P2 pgm file.
echo "echoing testfile1 to testfileout1 and testfileout2"
./pgmEcho testfile1.pgm testfileout1.pgm
./pgmEcho testfile1.pgm testfileout2.pgm
diff testfileout2.pgm testfileout1.pgm
#then we test it for a P5 pgm file
echo "echoing testfile2 to testfilout3 and testfileout4"
./pgmEcho testfile2.pgm testfileout3.pgm
./pgmEcho testfile2.pgm testfileout4.pgm
diff testfileout3.pgm testfileout4.pgm
#these two files will be the same for pgmComp so it should output identical for both
echo "testing pgmComp with testfileout1-4"
./pgmComp testfileout1.pgm testfileout2.pgm
./pgmComp testfileout3.pgm testfileout4.pgm
rm testfileout*
#we will convert an ascii to a binary and then use our pgmComp to test it worked
echo "converting testfile1 to binary and using pgmComp to check it was successful"
./pgma2b testfile1.pgm testfile1b.pgm
./pgmComp testfile1.pgm testfile1b.pgm
#we do the same as pgma2b but in reverse for testing this.
echo "converting tsetfile2 to ascii and using pgmComp to check it was successful"
./pgmb2a testfile2.pgm testfile2a.pgm
./pgmComp testfile2.pgm testfile2a.pgm
rm testfile2a*
#now we test pgmReduce
echo "reducing testfile1 and comparing it to the expected output with pgmComp"
./pgmReduce testfile1.pgm 2 testfilereduceout.pgm
./pgmComp testfilereduce.pgm testfilereduceout.pgm
./pgmReduce testfile1b.pgm 2 testfilereduceoutb.pgm
./pgmComp testfilereduceb.pgm testfilereduceoutb.pgm
rm testfilereduceout*
#now we test pgmTile
echo "tiling testfile1 and comparing it to expected tiles"
./pgmTile testfile1.pgm 2 "testout_<row>_<col>.pgm"
./pgmComp testout_0_0.pgm test_0_0.pgm
./pgmComp testout_0_1.pgm test_0_1.pgm
./pgmComp testout_1_0.pgm test_1_0.pgm
./pgmComp testout_1_1.pgm test_1_1.pgm
rm testout_*
#now we testpgmAssemble
echo "assembling a tiled file and comparing it to the original file"
./pgmAssemble testAssemble.pgm 2 2 0 0 test_0_0.pgm 0 1 test_0_1.pgm 1 0 test_1_0.pgm 1 1 test_1_1.pgm
./pgmComp testAssemble.pgm testfile1.pgm
