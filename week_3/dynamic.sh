#dynamic
echo "Files in the directory- "
ls
echo "creating shared library object..." 
gcc *.o -shared -o dynamic.so
echo "Files in the directory- "
ls
echo "linking main_obj.o and dynamic.so..."
gcc -o main_res main_obj.o -L. dynamic.so
echo "trying to run the program..."
./main_res
sudo cp dynamic.so /usr/lib
echo "Program output: "
./main_res
sudo rm /usr/lib/dynamic.so 
export LD_LIBRARY_PATH=:/home/student/Desktop/422171/unix/t
echo "Program output: "
./main_res
echo "Files in the directory- "
ls
ldd main_res

