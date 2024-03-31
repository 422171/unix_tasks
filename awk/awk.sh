#awk command
echo "0. contents of the file employee.txt"
cat employee.txt
echo -e "\n"

echo "1. 1st and 3rd columns of employee.txt"
awk '{ print $1, $3 }' employee.txt
echo -e "\n"

#sum of all the values at 3rd column/field (salary) of the file 
echo -e "2. total salary"
awk '{ sum += $3 } END { print sum }' employee.txt
echo -e "\n"

#NR gives the count of lines (no. of records) 
echo "3. average salary"
awk '{ sum += $3 } END { print sum / NR }' employee.txt
echo -e "\n"

echo "4.0 substring of length 3 starting from the 2nd character of 1st field"
#NOTE: if length of substring exceeds field's length, only fields characters are printed
awk '{ print substr($1, 2, 3) }' employee.txt
#if length parameter is not provided, end of the field will be the end of substring
echo "4.10 substring starting from the 3rd character of 1st field"
awk '{print substr($1,3)   }' employee.txt
echo "4.11 substring starting from the 2nd character of 3rd field"
awk '{print substr($3,2) }' employee.txt
echo -e "\n"

echo "5. Last field of the file"
awk '{ print $NF }' employee.txt
echo -e "\n"

#if else 
echo "6. classification of employees into seniors and juniors"
awk '{ if ($3 > 15000) { print "senior" } else { print "junior" } }' employee.txt
echo -e "\n"

#function
echo "7. squares of values of 3rd and 4th fields"
awk 'function square(x) { return x*x } { print square($3),"\t", square($4) }' employee.txt
echo -e "\n"

