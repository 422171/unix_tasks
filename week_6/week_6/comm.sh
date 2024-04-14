# comm command
echo "konoha.txt:-"
cat konoha.txt
echo "shinobi.txt"
cat shinobi.txt
echo "1.comparing the two files using comm:-"
comm konoha.txt shinobi.txt
echo "suppressing 1st column:-"
comm -1 konoha.txt shinobi.txt
echo "suppressing 2nd column:-"
comm -2 konoha.txt shinobi.txt
echo "suppressing 3rd column:-"
comm -3 konoha.txt shinobi.txt
echo "suppressing 1,3 columns:-"
comm -13 konoha.txt shinobi.txt
echo "Using '!' as delimiter:-"
comm --output-delimiter=! konoha.txt shinobi.txt