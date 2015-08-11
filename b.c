#define __STDC_FORMAT_MACROS
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <list>
#include <deque>
#include <unistd.h>

//http://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
#include <iostream>
#include <iomanip>
using namespace std;
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}



static inline void loadBar(unsigned int x, unsigned int n, unsigned int w = 50)
{
/*    if ( (x != n) && (x % (n/100+1) != 0) ) return;
 
    float ratio  =  x/(float)n;
    int   c      =  ratio * w;
 
    std::cout << setw(3) << (int)(ratio*100) << "% [";
    for (int x=0; x<c; x++) cout << "=";
    for (int x=c; x<w; x++) cout << " ";
    std::cout << "]\r" << flush;*/

float progress = (float)x /n;
    int barWidth = 70;

    std::cerr << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cerr << "=";
        else if (i == pos) 
        {std::cerr << ">";
        //char ggg[3];fread(ggg, 1,1, stdin);
        }
        else std::cerr << " ";
    }
    std::cerr << "] " << int(progress * 100.0) << " %\r";
    std::cerr.flush();

}

void print_progress(double act,double max,double limit)
{
 Color::Modifier red(Color::FG_RED);
  Color::Modifier green(Color::FG_GREEN);
    Color::Modifier def(Color::FG_DEFAULT);
    //cout << "This ->" << red << "word" << def << "<- is red." << endl;
if (act>limit)
std::cerr<<red;
else
std::cerr<<green;

//std::cout<<"csovi";
loadBar((int)(act*500), (int)(max*500));
std::cerr<<def;
std::cerr.flush();
}





using namespace std;



int main()
{
int modi=-1,offset=-1;

#define READNUM 500
const int bytesize = 2*READNUM; //read in 32 bits

char buffer[bytesize];
int16_t c = 0;
uint32_t sum=0;
deque<int16_t> elems;
//int samplerate=32000;
int samplerate=44100;
//double seconds=0.1;
double seconds=42;
int len=(int)(samplerate*seconds);
int insound=len;
int v=len*100;
int i=0;
double sum2=0;
// fgets(buffer, 1, stdin);
int first_run=1;
int end=0;
while( true){
//fgets(buffer, bytesize, stdin);
fread(buffer, 2,READNUM, stdin);
//fwrite (buffer , 2,READNUM, stdout);

if (feof(stdin) ) 
{
end=1;
}

  for (int j=0;j<READNUM;j++)
  {
  if (offset!=-1)
  {
  if (i%modi==offset)
  {
  system("numlockx toggle");
  }
    //fprintf(stderr,"beat,%5d\n",i);
  }
  i++;
  //memcpy( &c, buffer, bytesize);
  #define INT16_MIN 0
  int16_t ff=0;
  if (elems.size()>len)
  {
  ff=elems.front();
  elems.pop_front();
  {
  char * b=(char*)&ff;
  printf("%c%c",b[0],b[1]);
  }
  
  }
  sum=std::max((uint32_t)0,sum<abs(ff)?0:sum-abs(ff));
  //char temp=buffer[j*2];
  //buffer[j*2]=buffer[j*2+1];
  //buffer[j*2+1]=temp;
  c=*((int16_t*)(&buffer[j*2]));
  elems.push_back(c);
  sum+=abs(c);
  //fprintf(stderr,"test sound %d\n",sum);
//  return 0;
//  fprintf(stderr,"t1sound %" PRIu32 " % " PRId16 " %d\n",sum,c,elems.size());
  //int to_remove=8050;
//    sum=std::max((uint32_t)0,sum<to_remove?0:((uint32_t)sum-to_remove));
  //    fprintf(stderr,"t2sound %" PRIu32 " % " PRId16 " %d\n",sum,c,elems.size());
//usleep(100);
//if (sum>7000000) return 0;
//if (i%5000==0 )

if (i%(len/2)==0 && elems.size()>=len  && modi==-1)
{
double sum2=0;
sum=0;
int16_t e2[len];
int k=0;
for (deque<int16_t>::iterator o=elems.begin();o!=elems.end();++o)
{
//double q=*o;
//e2[k]=sqrt(q*q);
e2[k]=*o;
k++;
}

for (int ww=0;ww<len-1;ww++)
{
e2[ww]=abs(e2[ww]-e2[ww+1]);

}

int n=5;
double summax=0;
int sumi=0;
for (int i=60;i<160;i+=1)
{
int16_t e3[len];

double sumnow=0;
//summax=0;
int distance=samplerate*60/(i);

for (int t=0;t<len;t++)
{
int a=0;
double d=0;
for (a=0;a<n;a++)
{
int pos=t-a*distance;
if (pos<0) break;
d+=e2[pos];
}
d=d/(a);
//sumnow+=d*d;
e3[t]=d;
}
for (int t=0;t<len-1;t++)
{
sumnow+=pow(abs(e3[t]-e3[t+1]),2);
//sumnow+=pow(e3[t],2);
}


if (sumnow>summax)
{
summax=sumnow;
sumi=i;
//fprintf(stderr,"sumi uj max:%d %f\n",sumi,summax);
}

}
modi=samplerate*60/sumi;
double maxsum=0;
for (int z=0;z<modi;z++)
{
double sumnow=0;
for (int l=0;l<len;l+=modi)
{
sumnow+=e2[l];
}
if (sumnow>maxsum)
{
maxsum=sumnow;
offset=(i+z)%modi;
}

}
fprintf(stderr,"sumi:%d %f %d %d\n",sumi,summax,modi,offset);

  }
 }
}
fclose(stdin);


}
