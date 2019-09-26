
#include<iostream.h>

class attendent
{

    public:
    int tim,flag,interviewer,room,num;
    void check_inter();
    void check_room();
    void reset_inter();
    void freeinter();

};
int z,m,n,r,tim=9,inter[100],rm[100];

int main()
{

    int i,j,free,tot=1;
    cout<<"\nNumber of attendants\n";
    cin>>n;
    cout<<"\nNumber of interviewers\n";
    cin>>m;
    cout<<"\nNumber of rooms\n";
    cin>>r;
    if(r>m)
    r=m;
    cout<<"\ncandidate\tinterviewer\troom\t        tim slot\n";
    attendent atten[100];
    for(i=0;i<n;i++)
    {
    atten[i].num=i;
    atten[i].flag=-1;
    }

    for(i=0;i<m;i++)
    inter[i]=-1;

    for(i=0;i<r;i++)
    rm[i]=-1;


    while((tot)&&(tim<18))
    {
            tot=0;
            for(i=0;i<n;i++)
             {
                if(atten[i].flag==-1)
                {
                atten[i].check_inter();
                if(atten[i].interviewer==-1)
                atten[i].flag=-1;
                else
                atten[i].flag=1;
                if(atten[i].flag==1)
                   {
                        atten[i].check_room();
                        if(atten[i].room!=-1)
                              atten[i].flag=1;
                        else
                         {
                              atten[i].reset_inter();
                              atten[i].flag=-1;
                         }
                        if(atten[i].flag==1)
                              atten[i].tim=tim;
            }
        }
}
                free=0;
                for(j=0;((j<r)&&(!free));j++)
                    if(rm[j]==-1)
                        free=1;

                    if(!free)
        {
                tim+=2;
                atten[i].freeinter();
        }
                if(tim==13)
                tim++;

                for(i=0;((i<n)&&(tot!=1));i++)
                if(atten[i].flag==-1)
                    tot=1;
    }
    for(i=0;i<n;i++)
    if(atten[i].tim>0)
    cout<<"\n"<<(atten[i].num)+1<<"\t\t"<<(atten[i].interviewer)+1<<"\t\t"<<(atten[i].room)+1<<"\t\t"<<atten[i].tim<<"  to "<<(atten[i].tim)+2;

    return 0;
}

void attendent::check_inter()
{
    int i=0;
    for(i=0;i<m;i++)
    if(inter[i]==-1)
    {
        inter[i]=0;
        this->interviewer=i;
        return;
    }
    this->interviewer=-1;

}

void attendent::check_room()
{
    int i;
    for(i=0;i<r;i++)
        if(rm[i]==-1)
        {
            rm[i]=0;
            this->room=i;
            return;
        }
        this->room=-1;
}

void attendent::freeinter()
{
    int i,f=0;
    for(i=0;i<m;i++)
    {
    if(inter[i]==-1)
    f++;
    }
     for(i=0;i<m;i++)
    if(inter[i]==0)
    if(f)
    f--;
    else
    inter[i]=-1;
    for(i=0;i<r;i++)
    if(rm[i]==0)
    rm[i]=-1;
}

void attendent::reset_inter()
{
    int i;
    for(i=m-1;i>-1;i--)
    if(inter[i]==0)
    {
    inter[i]=-1;
    return;
    }
}

