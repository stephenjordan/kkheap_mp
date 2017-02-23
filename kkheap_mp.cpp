/*----------------------------------------------------------
  An implementation of the Karmarkar-Karp algorithm for the
  number partitioning problem. This uses the gnu
  multi-precision arithmetic library to handle big numbers
  and heaps from the C++ standard template library to
  improve efficiency. Written by Stephen Jordan in 2017.
  ----------------------------------------------------------*/

#include<gmpxx.h>   //for arbitrary precision arithmetic
#include<iostream>
#include<algorithm> //for heap operations
#include<vector>    //used by C++ standard heaps

using namespace std;

void printvec(vector<mpz_class> v) {
  int i;
  for (vector<mpz_class>::const_iterator i = v.begin(); i != v.end(); ++i) cout << *i << ' ';
  cout << endl;
}

int main(int argc, char *argv[]) {
  int i;                 //a counter variable
  mpz_class a, b;        //will store the biggest two numbers
  int N;                 //how many numbers there are
  int bits;              //how many bits each number has
  gmp_randstate_t state; //the internal state of the multiprecision rng
  mpz_t randval;         //straight from the rng
  mpz_t seed;            //the seed for the rng
  mpz_class classrand;   //converted to C++ style
  if(argc != 3) {
    cout << "Usage: kkheap_mp N BITS" << endl;
    return 0;
  }
  N = atoi(argv[1]);
  bits = atoi(argv[2]);
  //N = 10000;
  //bits = 60;
  cout << "N = " << N << endl;
  cout << "bits = " << bits << endl;
  mpz_init(randval);
  mpz_init_set_ui(seed, (unsigned long int)time(NULL));
  gmp_randinit_default(state);
  gmp_randseed(state, seed);
  // Initializing a vector
  vector<mpz_class> v1;
  //generate a random instance
  for(i = 0; i < N; i++) {
    mpz_urandomb(randval, state, bits);
    classrand =  mpz_class (randval);
    v1.push_back(classrand);
  }
  //cout << "RAND_MAX = " << RAND_MAX << endl; 
  //cout << "N = " << v1.size() << endl;
  //cout << "MAX = " << MAX << endl;
  // Converting vector into a heap
  // using make_heap()
  make_heap(v1.begin(), v1.end());
  //cout << "Instance: " << endl;
  //printvec(v1);

  for(i = 0; i < N-1; i++) {
    a = v1.front();
    pop_heap(v1.begin(), v1.end());
    v1.pop_back();
    b = v1.front();
    pop_heap(v1.begin(), v1.end());
    v1.pop_back();
    v1.push_back(abs(a-b));
    push_heap(v1.begin(), v1.end());
    //printvec(v1);
  }

  cout << "Result: " << endl;
  printvec(v1);
  mpz_clear(randval);
  mpz_clear(seed);
  return 0;
}


/*int main (void) {
  mpz_class a, b, c;
  a = 1234;
  b = "-5678";
  c = a+b;
  cout << "sum is " << c << "\n";
  cout << "absolute value is " << abs(c) << "\n";
  return 0;
}*/
