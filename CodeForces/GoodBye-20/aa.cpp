// https://codeforces.com/blog/entry/68953
// vector space if of size (D * 2);
// works for ints <= 1e9;
const int D = 30;

// vector is an integer in [0, 1 << D);
// f(vector) = lowest set bit in vector; // f value;
// basis[i] == 0 if no vector exist whose f value is i;
// else f(basis[i]) = i; 
// and no other basis[j] will have f value i; (j != i);
// It only means that any vector in the arr can be represented as a linear combination of vactors in vector space;
vi basis(D); 

int sz = 0; // initial size of basis;

// return true if newVector becomes a part of basis othewise false;
bool insertVector(int newVector){
    for(int i = 0; i < D; ++i){
        // if no set bit at position i;
        if((newVector >> i & 1) == 0) continue;

        // now there is a set bit on position i;

        if(basis[i] == 0){
            // no vector in basis exist whose f value is i;
            // so newVector is an independent vector from all the vectors present in the basis;
            // so newVector will be also add in the basis;

            sz++;
            basis[i] = newVector;

            return true;
        }

        // subtracting basis[i] from newVector in vector space;
        newVector ^= basis[i];
    }

    return false;
}



// to copy
const int D = 30;
vi basis(D); 
int sz = 0; 

bool insertVector(int newVector){
    for(int i = 0; i < D; ++i){
        if((newVector >> i & 1) == 0) continue;

        if(basis[i] == 0){
            sz++;
            basis[i] = newVector;
            return true;
        }
        
        newVector ^= basis[i];
    }
    return false;
}