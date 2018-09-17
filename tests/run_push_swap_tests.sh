IN5=$(ruby -e "puts (0..4).to_a.shuffle.join(' ')")
IN12=$(ruby -e "puts (0..7).to_a.shuffle.join(' ')")
BIN=../push_swap
#echo Identity
#$BIN 42
#$BIN 0 1 2 3
#$BIN 0 1 2 3 4 5 6 7 8 9
#echo Simple version 2 1 0
#$BIN 2 1 0 | wc -l
#echo Another simple version 1 5 2 4 3
#$BIN 1 5 2 4 3 | wc -l
#echo Sort 5 random
#echo $IN5
#$BIN $IN5 | wc -l
#echo Sort 12 random
#echo $IN12 > out12
#cat out12
#$BIN $IN12 > outmoves
#$BIN $IN12 | wc -l
#$BIN $IN12 | ../checker $IN12
#echo Sort 100 random 
touch result100.log
touch result500.log
while true; do
	IN100=$(ruby -e "puts (0..99).to_a.shuffle.join(' ')")
	IN500=$(ruby -e "puts (0..499).to_a.shuffle.join(' ')")
	$BIN $IN100 > out100
   	cat out100 | wc -l >> result100.log
	cat out100 | ../checker $IN100 >> result100.log
	$BIN $IN500 > out500
	cat out500 | wc -l >> result500.log
	cat out500 | ../checker $IN500 >> result500.log
done
#echo Sort 500 random

