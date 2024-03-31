#cpio command
ls -l
echo -e "\n"
#1
ls | cpio -ov > ~/compress.cpio
echo -e "\n"
#2
ls | cpio -iv < ~/compress.cpio
echo -e "\n"
#3
ls | cpio -ov -H tar > ~/new.tar
echo -e "\n"
ls -l
echo -e "\n"
tar tf new.tar
echo -e "\n"
#4.1
cpio -iv -F ~/new.tar
echo -e "\n"
#5
find . -iname "*.txt" | cpio -ov > ~/compress.cpio
echo -e "\n"
ls -l
echo -e "\n"
#6.1
find . -iname "*.txt" | cpio -ov -H tar > ~/new2.tar
echo -e "\n"
#6.2
find . -iname "*.txt" | cpio -ov -H tar > ~/new3.tar
echo -e "\n"
#4.2
cpio -it -F ~/new.tar
