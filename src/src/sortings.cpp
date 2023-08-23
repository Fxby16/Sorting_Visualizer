#include <global.h>
#include <utilities.h>

void BubbleSort(){
int DIM=v.size();
    for(int i=0;i<DIM;i++)
        for(int j=0;j<DIM-i-1;j++){
            if(v[j]>v[j+1]){
                std::swap(v[j],v[j+1]);
                visualize(j,j+1,DIM-i);
            }
            SDL_Delay(1);
        }
}

//-------------------------------------------------------------------------------

void SelectionSort(){
int DIM=v.size();
    for(int i=0;i<DIM-1;i++){
        int min_idx=i;
        for(int j=i+1;j<DIM;j++){
            if(v[j]<v[min_idx]){
                min_idx=j;
                visualize(-1,min_idx,i);
                SDL_Delay(20);
            }
        }
        
        if(min_idx>i)
            std::swap(v[i],v[min_idx]);
    }
}

//-------------------------------------------------------------------------------

void InsertionSort(){
int DIM=v.size();
    for(int i=1;i<DIM;i++){
        int temp=v[i];
        int j=i-1;

        while(j>=0 && v[j]>temp){
            v[j+1]=v[j];
            visualize(j,j+1,i);
            SDL_Delay(5);
            --j;
        }
        v[j+1]=temp;
        visualize(-1,j+1,i);
        SDL_Delay(5);
    }
}

//-------------------------------------------------------------------------------

void Merge(int left,int mid,int right){
std::vector<int>temp(v.size());
int i=left,j=mid,k=left;
	while((i<=mid-1)&&(j<=right)){
		if(v[i]<=v[j]){
			temp[k]=v[i];
            visualize(i,j);
            k++;
            i++;
		}
		else{
			temp[k]=v[j];
            visualize(i,j);
            k++;
            j++;
		}
    }
    while(i<=mid-1){
        temp[k]=v[i];
        visualize(i);
        k++;
        i++;
    }
 
    while(j<=right){
        temp[k]=v[j];
        visualize(j);
        k++;
        j++;
    }
 
    for (i=left;i<=right;i++){
        v[i]=temp[i];
        visualize(i);
        SDL_Delay(10);
    }
}
void MergeSort(int left,int right){
	int mid;
	if (right>left){
		mid=(right+left)/2;
		MergeSort(left,mid);
		MergeSort(mid+1,right);
		Merge(left,mid+1,right);
	}
}

//-------------------------------------------------------------------------------

int partition(int low,int high){
    int pivot=v[high];
    int i=(low-1);
    for(int j=low;j<high;j++){
        if(v[j]<pivot){
            i++;
            std::swap(v[i],v[j]);
            visualize(i,j,high);
        }
        SDL_Delay(4);
    }
    std::swap(v[i+1],v[high]);
    visualize(-1,i+1,high);
    return (i+1);
}

void QuickSort(int low,int high){
    while(low<high){
        int pi=partition(low,high);
        if(pi-low<high-pi){  
            QuickSort(low,pi-1);
            low=pi+1;
        }
        else{
            QuickSort(pi+1,high);
            high=pi-1;
        }
    }
}

//-------------------------------------------------------------------------------


void heapify(int N,int i){
    int largest = i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<N && v[l]>v[largest])
        largest=l;

    if(r<N && v[r]>v[largest])
        largest=r;

    if(largest!=i){
        std::swap(v[i],v[largest]);
        visualize(i,largest);
        SDL_Delay(3);
        heapify(N,largest);
    }
}

void HeapSort(int N){

    for(int i=N/2-1;i>=0;i--)
        heapify(N,i);

    for(int i=N-1;i>0;i--){
        std::swap(v[0],v[i]);
        visualize(0,i);
        SDL_Delay(3);
        heapify(i,0);
    }
}

//-------------------------------------------------------------------------------

void ShellSort(int N){
    for(int gap=N/2;gap>0;gap/=2){
        for(int i=gap;i<N;i+=1){
            int temp=v[i];
            int j;            
            for(j=i;j>=gap && v[j-gap]>temp;j-=gap){
                v[j]=v[j-gap];
                visualize(j,j-gap,i);
                SDL_Delay(2);
            }
            v[j]=temp;
            visualize(j,-1,i);
            SDL_Delay(2);
        }
    }
}

//-------------------------------------------------------------------------------

void Bingo(int &N,int &bingo,int &nextBingo){
    for (int i=1;i<N;bingo=std::min(bingo,v[i]),nextBingo=std::max(nextBingo,v[i]),i++){
        visualize(-1,i,-1);
        SDL_Delay(10);
    }
}

void BingoSort(int N){
    int bingo=v[0];
    int nextBingo=v[0];
    Bingo(N,bingo,nextBingo);
    int largestEle=nextBingo;
    int nextElePos=0;
    while(bingo<nextBingo){
        int startPos=nextElePos;
        for(int i=startPos;i<N;i++){
            if(v[i]==bingo){
                std::swap(v[i],v[nextElePos]);
                visualize(-1,nextElePos,i);
                SDL_Delay(50);
                nextElePos=nextElePos+1;
            }
            else if(v[i]<nextBingo){
                nextBingo=v[i];
            }
        }
        bingo=nextBingo;
        nextBingo=largestEle;
    }
}

//-------------------------------------------------------------------------------

int getNextGap(int gap){
    gap=(gap*10)/13;
    if (gap<1)
        return 1;
    return gap;
}

void CombSort(int N){
    int gap=N;
    bool swapped=true;
    while(gap!=1 || swapped==true){
        gap=getNextGap(gap);
        swapped=false;

        for(int i=0;i<N-gap;i++){
            if(v[i]>v[i+gap]){
                std::swap(v[i],v[i+gap]);
                swapped=true;
            }
            visualize(i,-1,i+gap);
            SDL_Delay(3);
        }
    }
}

//-------------------------------------------------------------------------------

void CocktailSort(int N){
    bool swapped=true;
    int start=0;
    int end=N-1;
 
    while(swapped){
        swapped=false;
        for(int i=start;i<end;++i){
            if(v[i]>v[i+1]){
                std::swap(v[i],v[i+1]);
                visualize(-1,i+1,i);
                SDL_Delay(1);
                swapped=true;
            }
        }
        if(!swapped)
            break;
        swapped=false;
        --end;
        for(int i=end-1;i>=start;--i){
            if(v[i]>v[i+1]){
                std::swap(v[i],v[i+1]);
                visualize(-1,i+1,i);
                SDL_Delay(1);
                swapped=true;
            }
        }
        ++start;
    }
}