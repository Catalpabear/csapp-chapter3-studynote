void decode1(long*xp,long*yp,long*zp){
    long temp1=*xp;
    long temp2=*yp;
    long temp3=*zp;
    *yp=temp1;
    *zp=temp2;
    *xp=temp3;
}