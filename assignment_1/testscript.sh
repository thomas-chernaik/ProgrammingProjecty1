#lets make all our programs
make pgmEcho
make pgmComp
make pgma2b
make pgmb2a
#test for pgmEcho.
#first we will test it gives the correct output for an P2 pgm file.
./pgmEcho testfile1.pgm testfileout1.pgm
diff testfile1.pgm testfileout1.pgm
#then we test it for a P5 pgm file
./pgmEcho testfile2.pgm testfileout2.pgm
diff testfile2.pgm testfileout2.pgm
#these two files will be the same for pgmComp so it should output identical for both
./pgmComp testfile1.pgm testfileout1.pgm
./pgmComp testfile2.pgm testfileout2.pgm
#we will convert an ascii to a binary and then use our pgmComp to test it worked
./pgma2b testfile1.pgm testfile1b.pgm
./pgmComp testfile1.pgm testfile1b.pgm
#we do the same as pgma2b but in reverse for testing this.
./pgmb2a testfile2.pgm testfile2a.pgm
./pgmComp testfile2.pgm testfile2a.pgm
