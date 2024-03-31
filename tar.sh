#tar command
echo "0. contents of the file file1.txt"
cat file1.txt
echo -e "\n"

echo "0. contents of the file file2.txt"
cat file2.txt
echo -e "\n"
:'
'-c': Creates a new archive.
'-v': Displays verbose output, showing the progress of the archiving process.
'-f': Specifies the filename of the archive
'
#uncompressed tar Archive
echo "1. creating Archive of all .txt files in the current directory..."
tar cvf file.tar *.txt
#'-x': Extracts files from an archive.
echo "2. Extracting files from the Archive..."
tar xvf file.tar

:'
'-z': Uses gzip compression.
'-j': Uses bzip2 compression.
'-J': Uses xz compression.
'
# creating a compressed tar archive file
#using -z
echo '3.creating gzip compressed tar file...'
tar cvzf file.tar.gz file1.txt
#Extracting a gzip tar Archive
echo '4. Extracting files from the Archive...'
tar xvzf file.tar.gz

#Creating compressed tar archive file
#using -j 
#"compression size < the size of the gzip"
#"compression and extraction time > the time of the gzip"
echo '5.creating jzip compressed tar file...'
tar cvfj file.tar.tbz file1.txt


echo 'creating three archives...'
tar cf one.tar file1.txt file2.txt
tar cf two.tar fur.txt pre.txt
tar czf three.tar.gz pre.txt file2.txt
#'-t': lists the files and directories of a tar file without extracting them
echo '6.displaying the contents of archives created-'
tar tf one.tar
echo '----------'
tar tf two.tar
echo '----------'
tar tf three.tar.gz

#update existing tar file
echo '7.updating tar file one.tar...'
tar rvf one.tar fur.txt
echo 'displaying contents of one.tar-'
tar tf one.tar

#To Untar multiple .tar, .tar.gz, .tar.tbz files:
echo '8.untar one.tar files fur.txt and file1.txt at a time...'
tar xvf file1.tar.gz one.tar two.tar

#pattern searching
echo '9.searching for fur.txt in two.tar'
tar tvf two.tar | grep "fur.txt" 

#searching for a file
echo '10.searching for pre.txt in three.tar.gz'
tar tzvf three.tar.gz pre.txt

#wildcards
echo 'updating two.tar...'
tar rvf two.tar team7.webp
echo '11.search for an image in .webp format'
tar tvf two.tar --wildcards '*.webp'
echo 'search for all files in .txt format'
tar tvf two.tar --wildcards '*.txt'


