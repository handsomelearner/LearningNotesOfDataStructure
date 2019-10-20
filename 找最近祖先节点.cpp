BinTree FindClosestAncestor(BinTree BT,BinTree T1,BinTree T2){
    if(BT==NULL||BT==T1||BT==T2) return BT;
    BinTree Left=FindClosestAncestor(BT->Left,T1,T2);
    BinTree Right=FindClosestAncestor(BT->Right, T1, T2);
    if(Left!=NULL&&Right!=NULL) return BT;
    if(Left!=NULL) return Left;
    if(Right!=NULL) return Right;
    return NULL;
}
