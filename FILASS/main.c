
#include "filas.h"


int main(){



cqueue *cq=cqcreate ( 2);
cqenqueue (cq, 3);
cqenqueue (cq, 2);
printf("%d",cq->elm[0]);
cqPune(cq, 1);
printf("%d",cq->elm[0]);
printf("%d",cq->elm[1]);
cqPromove(cq, 1);

}

