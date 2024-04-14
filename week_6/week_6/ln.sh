#! /bin/bash
#ln command
ls
echo
cat konoha.txt
echo 
ln -s konoha.txt ninja.txt
ls
echo "Rin Nohara was once a jinchuriki of 3-tails" >> konoha.txt
cat konoha.txt
echo
cat ninja.txt
ls -l
