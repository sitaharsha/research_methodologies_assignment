#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
    ZZ m,p,q,n,pin,car,c,r,r1,m1,m2,md,ch,c1,c2,tn;
    long int b;
//-------------------------------------Key Generation-------------
    cout << "Number of bits of plain text to be encrpted : " ;
    cin>>b;
    cout<<endl;
    GenPrime(p,b/4+4);
    do {
        GenPrime(q,b/4+4);
    }while(q==p);
    n=p*q;
    pin=(p-1)*(q-1);
    car=pin/GCD(p-1,q-1); 
    cout<<"Public key is         :"<<"("<<n<<","<<n+1<<")"<<endl;
    cout<<"Private key is        :"<<"("<<p<<","<<q<<")"<<endl;
//-------------------------------------Encryption-----------------
    cout<<"Enter plain text      :"<<endl;
    cin>>m;
    r1=m%n;
    r=(m-r1)/n;
    PowerMod(c1,(n+1),r1,n*n);
    PowerMod(c2,r,n,n*n);
    MulMod(c,c1,c2,n*n);
    cout<<"Cipher text is        :"<<c<<endl;
//------------------------------------Decryption-----------------
    PowerMod(m1,c,car,n*n);
    PowerMod(m2,n+1,car,n*n);
    InvMod(m2,((m2-1)/n),n);
    MulMod(md,((m1-1)/n),m2,n);
    cout<<"Plain text part 1  is         :"<<md<<endl;
    InvMod(c1,(c1%n),n);
    MulMod(c1,c,c1,n);
    InvMod(tn,n%car,car);
    PowerMod(c1,c1,tn,n);
    cout<<"Plain text part 2  is         :"<<c1<<endl;
    cout<<"Plain text is                 :"<<md+n*c1<<endl;
    return 0;
}
