void InsertSort(int A[],int Mid,int i){
    int a=A[i];
    int j;
    for(j=i-Mid;j>=0&&a<A[j];j-=Mid){
        A[j+Mid]=A[j];
    }
    A[j+Mid]=a;
}
void ShellSort(int A[],int N){
    for(int Mid=N/2;Mid>0;Mid/=2){
        for(int i=Mid;i<N;i++){
            InsertSort(A,Mid,i);
        }
    }
}
