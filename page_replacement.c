#include <stdio.h>
#include <stdlib.h>

char str[11][5]={"NONE","aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "iii", "jjj"};

//int cur=0;

int insert(int* arr, int* cnt, int* oldd, int size){
	int i, j, l, ent, temp, check, high;
	int k=i+1;
	
	//printf("현재 10번 중 %d번째\n",cur);
	printf("Enter page no between 1to10: ");
	scanf("%d",&ent);
	printf("\n");
	
	
	for(i=0;i<size;i++){
		if(arr[i]==0){
			check=0;		//공백이 있음
			break;
		}
		else if(arr[i]==ent){
			check=1;		//페이지가 있음
			break;
		}
		else{
			check=2;		//다 다름
		}
	}
	
	//printf("모드: %d\n\n",check);
	
	if(check==0&&ent<=10&&ent>=1){		//메모리 공백이 있는 경우
		for(l=0;l<size&&arr[l]!=0;l++){
			++oldd[l];
		}
		
		for(i=0;i<size;i++){
			if(arr[i]==0){		//새 것인 경우
				arr[i]=ent;
				cnt[i]++;		//새것이 아니면 있는지 비교 후 있으면 카운트 업, 없으면 카운트 낮은 것 대체
				oldd[i]++;
				break;
			}
			
			else if(arr[i]==ent){
				arr[i]=ent;
				cnt[i]++;
				oldd[i]=1;
				break;
			}
		}
	}
	
	
	if(check==1&&ent<=10&&ent>=1){		//페이지 성공
		for(l=0;l<size&&arr[l]!=0;l++){
			++oldd[l];
		}
		
		for(i=0;i<size;i++){
			if(arr[i]==ent){
				cnt[i]++;
				oldd[i]=1;
				break;
			}
		}
	}
	
	
	if(check==2&&ent<=10&&ent>=1){		//페이지 실패
		for(l=0;l<size&&arr[l]!=0;l++){
			++oldd[l];
		}
		high=0;
		for(i=0;i<size;i++){
			if(high<oldd[i]){
				high=oldd[i];
				temp=i;
			}
		}
		arr[temp]=ent;
		cnt[temp]=1;
		oldd[temp]=1;
	}
	//cur++;
}

int show(int* arr, int* cnt, int* oldd,int size){
	int i, j, k, temp, temp2, temp3;
	
	for(j=0;j<size-1;j++)
    {
        for(k=0;k<size-1-j;k++)
        {
            if(oldd[k] < oldd[k+1]) //연달아있는 두수중 앞에 있는수가 크다면
            {
                temp = oldd[k];   
                oldd[k]=oldd[k+1];
                oldd[k+1] = temp;
				
				temp2 = arr[k];   
                arr[k]=arr[k+1];
                arr[k+1] = temp2;

				temp3 = cnt[k];   
                cnt[k]=cnt[k+1];
                cnt[k+1] = temp3;
            }
        }
     }

	printf("Contain		Pageno		Pagecount\n");
	for(i=0;i<size;i++){
		printf("%s		%d		%d\n",str[arr[i]], arr[i], cnt[i]);
	}
}

int main(){

	int choice=0;
	int size, i;	//table size
	int* table;
	int* page_count;
	int* old;

	printf("Enter Your Table Size: ");
	scanf("%d",&size);

	table= (int*)malloc(size*sizeof(int));
	page_count= (int*)malloc(size*sizeof(int));
	old= (int*)malloc(size*sizeof(int));
	
	for(i=0;i<size;i++){
		table[i]=0;		//table 초기화
		page_count[i]=0;
		old[i]=0;
	}


	while(1){
		printf("1. Insert\n2. Show\n3. Exit\nEnter Your Choice: ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice){
		case 1: 
		insert(table, page_count, old, size);
		continue;

		case 2:
		show(table, page_count, old, size);
		continue;

		case 3:	
		printf("3\n");
		break;

		default:
		printf("Insert 1 to 3\n");
		continue;
		}
	break;
	}
	return 0;
}
