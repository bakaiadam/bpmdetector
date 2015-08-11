#g++ -g b.c -o b &&  mpg123 -s http://192.168.1.$i:8080/|./b | lame -r -s 44.1 -m m - -b 192 $filename
#g++ -g b.c -o b &&  mpg123 -s "http://kubox.dreamhosters.com/mp3s/Chromeo%20-%20Fancy%20Footwork%20%5B2007%5D/04%20-%20Bonafied%20Lovin'%20(Tough%20Guys).mp3"|./b | mplayer -

stdbuf -i0 -o0 -e0 command
g++ -g b.c -o b &&  mpg123 -s "http://kubox.dreamhosters.com/mp3s/Chromeo%20-%20Fancy%20Footwork%20%5B2007%5D/04%20-%20Bonafied%20Lovin'%20(Tough%20Guys).mp3" | ./b 2>aaa|  aplay -f cd -

