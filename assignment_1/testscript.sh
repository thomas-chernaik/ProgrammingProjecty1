#test for pgmEcho.
#first we will test it gives the correct output for an P2 pgm file.
./pgmEcho testfile1.pgm testfileout1.pgm
diff testfile1.pgm testfileout1.pgm
./pgmEcho testfile2.pgm testfileout2.pgm
diff testfile2.pgm testfileout2.pgm
