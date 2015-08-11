set title "Sample data plot"
 set style data histograms
#plot 'aaa' with points
plot '< tail -n 288 aaa' with lines
pause 0.1
replot
reread

pause -1 "Hit any key to continue"
