void Swap(int *a,int *b){
    int t=*a;*a=*b;*b=t;
}
void SelectSort(int A[],int N){
    int i,j,min;
    for(i=0;i<N-1;i++){
        min=i;
        for(j=i+1;j<N;j++)
            if(A[j]<A[min])
                min=j;
        Swap(&A[i],&A[min]);
}
