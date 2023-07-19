echo
echo "COMPILING..."
echo "----------------------------------------------------------------------"
echo
make re
echo
echo
echo "TESTING BASIC ADDITION..."
echo "----------------------------------------------------------------------"
echo
echo "\"1 1 +\" should print \"2\"..."
./bin/RPN "1 1 +"
echo
echo "\"2 3 +\" should print \"5\"..."
./bin/RPN "2 3 +"
echo
echo "\"2 3 4 +\" should print \"Error\"..."
./bin/RPN "2 3 4 +"
echo
echo "\"2 3 + 4\" should print \"Error\"..."
./bin/RPN "2 3 + 4"
echo

echo "TESTING BASIC SUBSTRACTION..."
echo "----------------------------------------------------------------------"
echo
echo "\"1 1 -\" should print \"0\"..."
./bin/RPN "1 1 -"
echo
echo "\"2 3 -\" should print \"-1\"..."
./bin/RPN "2 3 -"
echo
echo "\"2 3 4 -\" should print \"Error\"..."
./bin/RPN "2 3 4 -"
echo
echo "\"2 3 - 4\" should print \"Error\"..."
./bin/RPN "2 3 - 4"
echo

echo "TESTING BASIC MULTIPLICATION..."
echo "----------------------------------------------------------------------"
echo
echo "\"1 1 *\" should print \"1\"..."
./bin/RPN "1 1 *"
echo
echo "\"2 3 *\" should print \"6\"..."
./bin/RPN "2 3 *"
echo
echo "\"2 3 4 *\" should print \"Error\"..."
./bin/RPN "2 3 4 *"
echo
echo "\"2 3 * 4\" should print \"Error\"..."
./bin/RPN "2 3 * 4"
echo


echo "TESTING BASIC DIVISION..."
echo "----------------------------------------------------------------------"
echo
echo "\"1 1 /\" should print \"1\"..."
./bin/RPN "1 1 /"
echo
echo "\"7 3 /\" should print \"2\"..."
./bin/RPN "7 3 /"
echo
echo "\"2 3 4 /\" should print \"Error\"..."
./bin/RPN "2 3 4 /"
echo
echo "\"2 3 / 4\" should print \"Error\"..."
./bin/RPN "2 3 / 4"
echo

echo "TESTING EVALUATION CHECKS..."
echo "----------------------------------------------------------------------"
echo
echo "\"8 9 * 9 - 9 - 9 - 4 - 1 +\" should print \"42\"..."
./bin/RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo
echo "\"9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -\" should print \"42\"..."
./bin/RPN "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
echo
echo "\"1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /\" should print \"15\"..."
./bin/RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
