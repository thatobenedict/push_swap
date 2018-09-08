IN5=$(ruby -e "puts (0..4).to_a.shuffle.join(' ')")
IN100=$(ruby -e "puts (0..99).to_a.shuffle.join(' ')")
IN500=$(ruby -e "puts (0..499).to_a.shuffle.join(' ')")
BIN=../push_swap
echo Identity
$BIN 42
$BIN 0 1 2 3
$BIN 0 1 2 3 4 5 6 7 8 9
echo Simple version 2 1 0
$BIN 2 1 0 | wc -l
echo Another simple version 1 5 2 4 3
$BIN 1 5 2 4 3 | wc -l
echo Sort 5 random
echo $IN5
$BIN $IN5 | wc -l
echo Sort 100 random 
$BIN $IN100 | wc -l
echo Sort 500 random
$BIN $IN500 | wc -l
#$BIN $IN500 | ../checker $IN500
