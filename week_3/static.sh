: '
Create shell scripts for generating static and dynamic libraries. Utilize an example of your preference. Ensure that the program is not a simple calculator task and also from the provided tutorial material. Each program should incorporate a minimum of two functions based on the selected task.
'
echo "Files in the directory- "
ls
echo "Compiling and creating object files..."
gcc -c qsort.c -o qsort_obj.o
gcc -c bsearch.c -o bsearch_obj.o
gcc -c main.c -o main_obj.o
echo "creating a static_library archive"
ar rcs static.a bsearch_obj.o qsort_obj.o
echo "Files in the directory- "
ls
gcc -o main_res main_obj.o -L. static.a
./main_res

