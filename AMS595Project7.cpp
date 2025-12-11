#include <iostream>
#include <vector>
using namespace std;

/* 1. Conditional Statements */
void conditional_statement(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    //example of following in ccp lecture 2
    switch (n) {
        case -1: 
            cout << "negative one\n";
            break;
        case 0: 
            cout << "zero\n";
            break;
        case 1:
            cout << "positive one\n";
            break;
        default:
            cout << "other value\n";
            break;
    }
}


/* 2. Printing a Vector */
void print_vector(std::vector<int> v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

/* 3. While Loops */
void fibonacci_generator(){
    long long a = 1, b = 2;
    //use of long long because of its LARGE range

    while (a <= 4000000){
        cout << a << " ";
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << "\n";
}

/* 4. Functions */
/*-----4.1 If Prime-----*/
bool isprime(int n) {

    if (n <= 1) return false;
    //any number <=1 is NOT prime

    //Now, we will loop through all numbers 2 up to sqrt(n)
    for (int i = 2; i * i <= n; i++) {

        if (n % i == 0) return false;
        //if n is even, it's not prime
    }
    return true;
}

void test_isprime() {
    std::cout << "isprime(2) = " << isprime(2) << "\n";
    std::cout << "isprime(10) = " << isprime(10) << "\n";
    std::cout << "isprime(17) = " << isprime(17) << "\n";
}


/*-----4.2 Factorize-----*/
vector<int> factorize(int n) {

    //We create an empty vector ans to store the factors
    vector<int> ans;

    //Now, we loop through every value 1 to n
    for (int i = 1; i <= n; i++) {

        if (n % i == 0)
            ans.push_back(i);
            /*if i is a factor, push_back adds a copy 
            of i to the end of our list ans*/
    }
    return ans;
}

void test_factorize() {
    print_vector(factorize(2));
    print_vector(factorize(72));
    print_vector(factorize(196));
}

/*-----4.3 Prime Factorization-----*/
vector<int> prime_factorize(int n) {
    vector<int> ans;

    /*Starting with i=2, we will continue to divide n by i
    until it's completely broken down.
    Then, we move on to i=3.*/
    int i = 2;
    while (n > 1) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
        i++;
    }
    return ans;
}

void test_prime_factorize() {
    print_vector(prime_factorize(2));
    print_vector(prime_factorize(72));
    print_vector(prime_factorize(196));
}

/* 5. Recursive Functions and Loops */
void pascal(int n) {
    if (n <= 0) return;

    vector<int> row;
    //row will store a single row of Pascal's Triangle at a time

    //We iterate from 1 to n
    for (int i = 1; i <= n; i++) {

        /*The following code will change the size 
        of row to i for each iteration.*/
        row.resize(i);

        row[0] = 1;
        //We explicitly set the first value in every row to =1

        row[i - 1] = 1;
        //i-1 is the index of the last position in the row

        /*Starting at the second-to-last index and moving backward
        while stopping right before index 0*/
        for (int j = i - 2; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }

        //We print each value of our row
        for (int v : row) {
            cout << v << " ";
        }  
        cout << "\n";
    }
}

/* Main */
int main() {

    // 1. 
    conditional_statement();

    // 2.
    print_vector({1,3,5,7,9});

    // 3.
    fibonacci_generator();

    // 4.
    test_isprime();
    test_factorize();
    test_prime_factorize();

    // 5.
    pascal(5);

    return 0;
}