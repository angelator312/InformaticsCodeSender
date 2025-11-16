// https://arena.olimpiici.com/#/catalog/789/problem/102067
#include<iostream>
#ifdef Deval
#define fprintf(args...) ;
#endif
#define endl "\n"
#define int long long
using namespace std;

const int MAX_Y=501;
const int MAX_X=501;

int memorization[MAX_X][MAX_Y];
int maxPleasure[MAX_X][MAX_Y];
int matrix[MAX_X][MAX_Y];
int maxY,maxX;

inline int GetMaxPleasure(const int& x,const int& y)
{
    return (x<maxX||y<maxY)?maxPleasure[x][y]:0;
}
inline int max(const int& a,const int& b)
{
    return a>b?a:b;
}
void Read()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>maxY>>maxX;
    for(int y=0; y<maxY; ++y)
        for(int x=0; x<maxX; ++x)
            cin>>matrix[x][y];

}

signed main()
{
    Read();
    int sum=0;

    for(int y=maxY; y>=0; --y)
    {
        for(int x=maxX; x>=0; --x)
        {
            maxPleasure[x][y]=max(GetMaxPleasure(x+1,y),GetMaxPleasure(x,y+1));
            memorization[x][y]=maxPleasure[x][y]+matrix[x][y];
            maxPleasure[x][y]=max(maxPleasure[x][y],memorization[x][y]);
            sum+=memorization[x][y];
        }
    }
    /*
        for(int y=0; y<maxY; ++y)
        {
            for(int x=0; x<maxX; ++x)
            {
                fprintf(stderr,"%d ",memorization[x][y]);
            }
            fprintf(stderr,"\n");
        }
        for(int y=0; y<maxY; ++y)
        {
            for(int x=0; x<maxX; ++x)
            {
                fprintf(stderr,"%d ",maxPleasure[x][y]);
            }
            fprintf(stderr,"\n");
        }
        //cerr<<endl;
      */  cout<<sum<<endl;
    return 0;
}
