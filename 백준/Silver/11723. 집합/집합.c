#include<stdio.h>
#include<string.h>
int set[21] = {0,};

int main(){
    int m,x;
    char str[7];
    scanf("%d",&m);
    while(m--){
        scanf("%s",str);
        if(strcmp(str,"add")==0){
            scanf("%d",&x);
            set[x]=1;
        }
        else if(strcmp(str,"remove")==0){
            scanf("%d",&x);
            set[x]=0;
        }
        else if(strcmp(str,"check")==0){
            scanf("%d",&x);
            printf("%d\n",set[x]);
        }
        else if(strcmp(str,"toggle")==0){
            scanf("%d",&x);
            set[x]=set[x] ? 0 : 1;
        }
        else if(strcmp(str,"all")==0){
            for(int i=1;i<21;i++)
                set[i]=1;
        }
        else{
            for(int i=1;i<21;i++)
                set[i]=0;
        }
    }
}