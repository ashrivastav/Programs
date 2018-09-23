#include<stdio.h>
#include<math.h>
#include<time.h>
void computePrime(int start, int end);
int main(){
 
     int count, i;
   int start[10],end[10];  
//      time_t t1,t2;
   
        scanf("%d",&i);
 count=i;
        
        for(i=0;i<count;i++)
            scanf("%d  %d",&start[i],&end[i]);
              
        i=0;
//  t1 = time(NULL);                        
        while(i<count)
  {       
                computePrime(start[i],end[i]);
          i++;
    } 
      return 0;
//     t2 = time(NULL);
 
//     printf("The time taken in seconds %d",t2-t1);
}
 
inline void computePrime(int start, int end){
    
        int  k,i,l, limit,j;
    register temp;
  double db1=0; 
  int a[100000];
          a[0]=3;
 
        limit = (int) sqrt(end);
        
        for(i=5,j=1;i<=limit;i+=2)
      {
               k = (int) sqrt(i);
              temp=3;
         while(temp <= k)
                {
                       if(i%temp==0)
                           break;
                  temp+=2;
                }
               if(temp >k)
                     a[j++]=i;
       }
 
//    for(i=0;i<j;i++)
//              printf("%d  ",a[i]);
    
//      printf("\n============\n");
     if(start<=2)
    {
               printf("%d\n",2);
               start=3;
        }
       if(start%2 ==0)
         start++;
 
       for(i=start;i<=end;i=i+2)
       {
            l=0;
            db1=sqrt(i);
            k= (int) db1;
           if(k==1)
                {
                  printf("%d\n",i);
               continue;
            }
               while( a[l] <= k && l < j)
              {
                       if(i%a[l]==0)
                           break;          
                        l++;
            }
               if(l >= j || a[l] > k)
          printf("%d\n",i);
       }
       printf("\n");
}

