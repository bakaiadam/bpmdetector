#g++ -g b.c -o b &&  mpg123 -s http://192.168.1.$i:8080/|./b | lame -r -s 44.1 -m m - -b 192 $filename
#g++ -g b.c -o b &&  mpg123 -s "http://kubox.dreamhosters.com/mp3s/Chromeo%20-%20Fancy%20Footwork%20%5B2007%5D/04%20-%20Bonafied%20Lovin'%20(Tough%20Guys).mp3"|./b | mplayer -

stdbuf -i0 -o0 -e0 command
#g++ -g b.c -o b &&  mpg123 -s "http://kubox.dreamhosters.com/mp3s/Chromeo%20-%20Fancy%20Footwork%20%5B2007%5D/04%20-%20Bonafied%20Lovin'%20(Tough%20Guys).mp3" | ./b 2>aaa|  aplay -f cd -


#g++ -g b.c -o b &&  mpg123 -s "http://kubox.dreamhosters.com/mp3s/Chromeo%20-%20Fancy%20Footwork%20%5B2007%5D/04%20-%20Bonafied%20Lovin'%20(Tough%20Guys).mp3" | ./b |  aplay -f cd -

#g++ -g b.c -o b &&  mpg123 -s "http://kubox.dreamhosters.com/mp3s/Chromeo%20-%20Fancy%20Footwork%20%5B2007%5D/04%20-%20Bonafied%20Lovin'%20(Tough%20Guys).mp3" | ./b | buffer| aplay -f cd -

#g++ -g b.c -o b &&  mpg123 -s "http://kubox.dreamhosters.com/mp3s/BuckyDoneGun.mp3" | ./b
#g++ -g b.c -o b &&  mpg123 -s "http://kubox.dreamhosters.com/mp3s/BuckyDoneGun.mp3" | ./b >/dev/null

#g++ -g b.c -o b &&  mpg123 -s "http://f10.su/m/_NEW/_MUSIC/Minimal%20Techno%20and%20Tech%20House%20(2011)/%D0%9D%D0%BE%D0%B2%D0%B0%D1%8F%20%D0%BF%D0%B0%D0%BF%D0%BA%D0%B0/Naum_Kaaz%20-%20Synesthesia.mp3" | ./b >/dev/null
#ezét jól kitalálja


#g++ -g b.c -o b &&  mpg123 -s "http://kubox.dreamhosters.com/mp3s/Chromeo%20-%20Fancy%20Footwork%20%5B2007%5D/04%20-%20Bonafied%20Lovin'%20(Tough%20Guys).mp3"  | ./b >/dev/null


#g++ -g b.c -o b &&  mpg123 -s "http://f10.su/m/_NEW/_MUSIC/Minimal%20Techno%20and%20Tech%20House%20(2011)/%D0%9D%D0%BE%D0%B2%D0%B0%D1%8F%20%D0%BF%D0%B0%D0%BF%D0%BA%D0%B0/Naum_Kaaz%20-%20Synesthesia.mp3" | stdbuf -i0 -o0 -e0 ./b | stdbuf -i0 -o0 -e0  aplay -f cd

#g++ -g -I/usr/include/alsa b.c -o b -lasound &&  mpg123 -s "http://f10.su/m/_NEW/_MUSIC/Minimal%20Techno%20and%20Tech%20House%20(2011)/%D0%9D%D0%BE%D0%B2%D0%B0%D1%8F%20%D0%BF%D0%B0%D0%BF%D0%BA%D0%B0/Naum_Kaaz%20-%20Synesthesia.mp3" | ./b   #| stdbuf -i0 -o0 -e0  aplay -f cd

g++ -g -I/usr/include/alsa b.c -o b -lasound &&  mpg123 -s "http://kubox.dreamhosters.com/mp3s/Chromeo%20-%20Fancy%20Footwork%20%5B2007%5D/11%20-%20100%25.mp3" | ./b   #| stdbuf -i0 -o0 -e0  aplay -f cd
