echo "\033[0;93m"
echo TESTING EXAMPLES..
echo
echo "----------------------------------------------------------"
echo "./bin/PmergeMe 3 5 9 7 4 \033[0;39m"
./bin/PmergeMe 3 5 9 7 4
echo

echo "\033[0;93m----------------------------------------------------------"
echo "./bin/PmergeMe \"-1\" \"2\" \033[0;39m"
./bin/PmergeMe "-1" "2"
echo

echo "\033[0;93m----------------------------------------------------------"
echo "./bin/PmergeMe \`jot -r 6 1 100000 | tr '\ n\' ' '\` \033[0;39m"
./bin/PmergeMe `jot -r 6 1 100000 | tr '\n' ' '`
echo

echo "\033[0;93m----------------------------------------------------------"
echo "./bin/PmergeMe \`jot -r 3000 1 100000 | tr '\ n\' ' '\` \033[0;39m"
./bin/PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
echo