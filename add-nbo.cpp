#include <stdint.h> // for uint32_t
#include <stdio.h> // for printf
#include <netinet/in.h> // for ntohs ntols

int main (int argc, char* argv[])
{
    FILE* n1_file = fopen(argv[1],"rb");
    FILE* n2_file = fopen(argv[2],"rb");

    uint32_t N1 = 0;
    uint32_t N2 = 0;

    fread(&N1,4,1,n1_file);
    fread(&N2,4,1,n2_file);

    N1=ntohl(N1);
    N2=ntohl(N2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",N1,N1,N2,N2,N1+N2,N1+N2);

    fclose(n1_file);
    fclose(n2_file);

}
