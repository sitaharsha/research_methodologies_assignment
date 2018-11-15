#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
    ZZ m,p,q,n,pin,car,c,r,m1,m2,md,ch,c1,c2;
    long int b;
//-------------------------------------Key Generation-------------
    cout << "Number of bits of plain text to be encrpted : " ;
    cin>>b;
    cout<<endl;
    GenPrime(p,b/2+4);
    do {
        GenPrime(q,b/2+4);
    }while(q==p);
    n=p*q;
    pin=(p-1)*(q-1);
    car=pin/GCD(p-1,q-1); 
    cout<<"Public key is         :"<<"("<<n<<","<<n+1<<")"<<endl;
    cout<<"Private key is        :"<<"("<<p<<","<<q<<")"<<endl;
//-------------------------------------Encryption-----------------
    cout<<"Enter plain text      :"<<endl;
    cin>>m;
    do {
        ch=GCD((r=RandomBnd(n)),n);
    }while(ch!=1);
    PowerMod(c1,(n+1),m,n*n);
    PowerMod(c2,r,n,n*n);
    MulMod(c,c1,c2,n*n);
    cout<<"Cipher text is        :"<<c<<endl;
//------------------------------------Decryption-----------------
    PowerMod(m1,c,car,n*n);
    PowerMod(m2,n+1,car,n*n);
    InvMod(m2,((m2-1)/n),n);
    MulMod(md,((m1-1)/n),m2,n);
    cout<<"Plain text is         :"<<md<<endl;

    return 0;
}
