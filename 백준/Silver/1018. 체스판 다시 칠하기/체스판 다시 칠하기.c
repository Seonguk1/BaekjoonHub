#include <stdio.h>

int main(){
    int n, m, min=100;
    char arr[51][51];
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%s", arr[i]);
    }
    
    for(int i=0;i<=n-8;i++){
        for(int j=0;j<=m-8;j++){
            int count1=0,count2=0;
            for(int k=i;k<i+8;k++){
                for(int l=j;l<j+8;l++){
                    if((k+l)%2==0){
                        if(arr[k][l]=='B') count1++;
                        if(arr[k][l]=='W') count2++;
                            
                    }
                    else{
                        if(arr[k][l]=='W') count1++;
                        if(arr[k][l]=='B') count2++;
                    }        
                }
            }
            int current_min_changes = (count1 < count2) ? count1 : count2;
            if(current_min_changes < min) {
                min = current_min_changes;
            }
        }
    }
    
    printf("%d", min);
}