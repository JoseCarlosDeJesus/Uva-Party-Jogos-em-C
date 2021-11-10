//Rat in a Maze Game implemented in C

#include<conio.h>
#include<stdio.h>
#define SIZE 15
#include<stdlib.h>
void main()
{
int maze[SIZE][SIZE],mark[SIZE][SIZE],stack[SIZE][3];
static int
move[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};

int i,j,m,n,top,mov,g,h;
system("cls");
printf("enter size");
scanf("%d%d",&m,&n);
for(i=1;i<=m;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&maze[i][j]);
}
}
for(i=0;i<=n+1;i++)
maze[0][i]=1;
for(i=0;i<=n+1;i++)
maze[m+1][i]=1;
for(i=0;i<=m+1;i++)
maze[i][0]=1;
for(i=0;i<=m+1;i++)
maze[i][n+1]=1;
for(i=1;i<=m;i++)
{
for(j=1;j<=n;j++)
{
mark[i][j]=0;
}
}
mark[1][1]=1;
stack[0][0]=1;
stack[0][1]=1;
stack[0][2]=2;
top=1;
while(top!=0)
{
i=stack[0][0];
j=stack[0][1];
mov=stack[0][2];
top=top-1;
while(mov<=7)
{
g=i+move[mov][0];
h=j+move[mov][1];

if(mark[g][h]==0&&maze[g][h]==0)
{
mark[g][h]=1;
top++;
stack[top][0]=i;
stack[top][1]=j;
mov=-1;
i=g;j=h;
}
mov=mov+1;
if(g==m&&h==n)
{
printf("path made by the rat is");

for(i=1;i<=top;i++)
printf("%d %d",stack[i][0],stack[i][1]);
printf("%d %d",m,n);

getch();
exit(0);
}
}
}
}
