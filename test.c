int main ( ) {
    int y =3;
	int *x = &y;
    int z;
    
    z = y + *x;
    printf(z + z);
}
