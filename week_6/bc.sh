# bc command
# Setting scale for decimal precision
echo "Using scale to set decimal precision:"
result=$(echo "scale=2; 5/2" | bc)
echo "5 divided by 2 is: $result"
# Using -l option for math library functions
echo "Using the -l option for math library functions:"
result_sin=$(echo "s(0)" | bc -l)
echo "Sine of 0 is: $result_sin"
# Using -q option for quiet output
echo "Using the -q option for quiet output:"
result_sqrt=$(echo "sqrt(16)" | bc -q)
echo "Square root of 16 is: $result_sqrt"
# Using -i option for specifying input base
echo "Using the -i option for specifying input base:"
result_hex=$(echo "ibase=16; F+1" | bc)
echo "Hexadecimal F + 1 is: $result_hex"
