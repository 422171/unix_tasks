#sed : stream editor
#Can do insertion, deletion, search and replace(substitution).
#supports regular expression and thus can perform complex pattern matching.
echo "Contents of file employee.txt"
cat employee.txt
echo -e '\n'

echo "1.0 replace em with E"
sed 's/em/E/' employee.txt
echo "1.10 replace 0 with 1"
sed 's/0/1/' employee.txt
echo "1.11 replace 0 with 1 as many times as possible in a line"
sed 's/0/1/g' employee.txt
echo "1.2 replace 0 with 1 except in the 5th line"
sed '5!s/0/1/' employee.txt
echo "1.3 replace 0 with 1 in 1st line to 3rd line"
sed '1,3 s/0/1/' employee.txt
echo "1.4 print only replaced lines"
sed -n '1,3 s/0/1/p' employee.txt
echo "1.5 print replaced lines twice(both before and after replacement)"
sed '1,3 s/0/1/p' employee.txt
echo -e '\n'

echo "2.0 delete a particular (2nd) line"
sed '2d' employee.txt
echo "2.1 delete last line"
sed '$d' employee.txt
echo "2.2 delete 1st line to 4th line"
sed '1,4d' employee.txt
echo "2.3 delete 4th line to end of file"
sed '4,$d' employee.txt
echo -e "2.4 delete the line that contains \"22\""
sed '/22/d' employee.txt
echo "2.5 delete a specific pattern (2000)"
sed '/2000/d' employee.txt
echo -e '\n'

echo "3.0 insert a blank line after each line"
sed G employee.txt
echo "3.1 insert a blank line after each line containing \"5\""
sed '/5/G' employee.txt
echo "3.2 insert 3 blank spaces before each line"
sed 's/^/   /' employee.txt
echo -e '\n'

echo "NOTE: Original contents unchanged"
cat employee.txt
