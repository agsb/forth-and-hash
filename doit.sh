
gcc djb2.c
./a.out < annexh.list > annexh.hash
sort < annexh.hash > annexh.sort
uniq -w 10 -D < annexh.sort > annexh.uniq

