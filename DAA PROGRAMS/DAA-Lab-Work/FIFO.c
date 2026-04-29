#include<stdio.h>

int mian(){

    int i, j, n, no, k;
    int a[50], frame[10];
    int count = 0;
    int avail;

    printf("Enter No. of pages: ");
    scanf("%d",&n);
    printf("Enter Pages Number: ");
    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &no);
    for(i=0; i<no; i++){
        frame[i] = -1;
    j = 0;
    }
    printf("\t Ref string \t Pageframe");
    for(i=1; i<=n; i++){
        printf("%d \t \t", a[i]);
        avail = 0;

        for(k=0; k<no; k++){
            if(frame[k] == a[i]){
                avail = 1;
            }
            if (avail == 0)
            {
                frame[j] = a[i];
                j = (j+1) % no;
                count ++;
                
                for(k=0; k < no; k++){
                    printf("%d\t", frame[k]);
                }

                printf("\n");
            }
        }
            printf("Page Fault is %d", count);
    }
    return 0;

}