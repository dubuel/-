#include <stdio.h>
#include <stdlib.h>

int mapA[8][8];
int mapB[8][8];

struct data
{
    int i;
    int j;
    int data;
};
struct data D[64];
int N,M;

void DFS(int data, int direction);
void Howtomove(int data, int direction);
void CCTV1(int data,int direction);
void CCTV2(int data,int direction);
void CCTV3(int data,int direction);
void CCTV4(int data,int direction);
void CCTV5(int data,int direction);

int main()
{
    int k = 0;
    scanf("%d %d", &N,&M);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &mapA[i][j]);
            mapB[i][j] = mapA[i][j];
            if(mapA[i][j] != 0)
            {
                D[k].i = i;
                D[k].j = j;
                D[k++].data = mapA[i][j];
            }
        }
    }
    Howtomove(0,3);

    printf("%d %d\n", N,M);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            printf("%d ", mapB[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < k; i++)
    {
        printf("%d %d %d\n", D[i].i,D[i].j,D[i].data);
    }

    return 0;

}

void Howtomove(int data, int direction)     // data is CCTV count
{
    switch(D[data].data)
    {
    case 1: CCTV1(data,direction); break;
    case 2: CCTV2(data,direction); break;
    case 3: CCTV3(data,direction); break;
    case 4: CCTV4(data,direction); break;
    case 5: CCTV5(data,direction); break;
    }
}

void CCTV1(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++;mapB[i][j] == 0 && j < M;j++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
    else if(direction == 1)
    {
        for(j--;mapB[i][j] == 0 && j >= 0;j--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
    else if(direction == 2)
    {
        for(i++;mapB[i][j] == 0 && i < N ;i++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
    else if(direction == 3)
    {
        for(i--; mapB[i][j] == 0 && i >= 0 ;i--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
}
void CCTV2(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++;mapB[i][j] == 0 && j < M;j++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(j = D[data].j -1;mapB[i][j] == 0 && j >= 0;j--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
    else if(direction == 1)
    {
        for(i++;mapB[i][j] != 6 && i < N ;i++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i = D[data].i -1; mapB[i][j] != 6 && i >= 0 ;i--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }

}
void CCTV3(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++;mapB[i][j] == 0 && j < M;j++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i++, j = D[data].j;mapB[i][j] == 0 && i < N ;i++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
    else if(direction == 1)
    {
        for(j++;mapB[i][j] == 0 && j < M;j++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i--, j = D[data].j; mapB[i][j] == 0 && i >= 0 ;i--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
    else if(direction == 2)
    {
        for(j--;mapB[i][j] == 0 && j >= 0;j--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i++, j = D[data].j;mapB[i][j] == 0 && i < N ;i++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
    else if(direction == 3)
    {
        for(j--;mapB[i][j] == 0 && j >= 0;j--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i--, j = D[data].j; mapB[i][j] == 0 && i >= 0 ;i--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }

}
void CCTV4(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++;mapB[i][j] == 0 && j < M;j++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i++, j = D[data].j;mapB[i][j] == 0 && i < N ;i++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i = D[data].i -1, j = D[data].j; mapA[i][j] == 0 && i >= 0 ;i--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
    else if(direction == 1)
    {
        for(j++;mapB[i][j] == 0 && j < M;j++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i--, j = D[data].j; mapA[i][j] == 0 && i >= 0 ;i--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(j = D[data].j -1, i = D[data].i;mapB[i][j] == 0 && j >= 0;j--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
    else if(direction == 2)
    {
        for(j--;mapB[i][j] == 0 && j >= 0;j--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i++, j = D[data].j;mapB[i][j] == 0 && i < N ;i++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(j = D[data].j +1, i = D[data].i;mapB[i][j] == 0 && j < M;j++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
    else if(direction == 3)
    {
        for(j--;mapB[i][j] == 0 && j >= 0;j--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i--, j = D[data].j; mapB[i][j] == 0 && i >= 0 ;i--)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
        for(i= D[data].i+1, j = D[data].j;mapB[i][j] == 0 && i < N ;i++)       //avoid the wall and out of the map
        {
            mapB[i][j] = 7;
        }
    }
}
void CCTV5(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    for(j--;mapB[i][j] == 0 && j >= 0;j--)       //avoid the wall and out of the map
    {
        mapB[i][j] = 7;
    }
    for(i--, j = D[data].j; mapB[i][j] == 0 && i >= 0 ;i--)       //avoid the wall and out of the map
    {
        mapB[i][j] = 7;
    }
    for(i= D[data].i+1, j = D[data].j;mapB[i][j] == 0 && i < N ;i++)       //avoid the wall and out of the map
    {
        mapB[i][j] = 7;
    }
    for(j = D[data].j +1, i = D[data].i;mapB[i][j] == 0 && j < M;j++)       //avoid the wall and out of the map
    {
        mapB[i][j] = 7;
    }
}

