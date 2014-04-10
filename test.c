int main ( ) {
    int x = 1;
    int y = 2;
	int *z = &y;
    /*
    int z;
    z = y + *x;
    printf(z + z);
    */
    
    *z = x;
}
