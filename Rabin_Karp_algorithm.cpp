//Find the index at which we got that pattern is match with txt string .
#include <iostream>
#include <string>
using namespace std;

const int d = 256; // Number of characters in the alphabet(base of hash func.)

void search(const string& pat, const string& txt, int q) {
    int M = pat.length();
    int N = txt.length();
    int p = 0; // Hash value for the pattern
    int t = 0; // Hash value for the text
    int h = 1;

    // Calculate h = d^(M-1) % q
    for (int i = 0; i < M - 1; ++i)
        h = (h * d) % q;        //calculates the new hash value by multiplying the current hash value ;consider intermediate hash val 

    // Calculate hash value for pattern and first window of text
    for (int i = 0; i < M; ++i) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over the text
    for (int i = 0; i <= N - M; ++i) {
        // Check if hash values match
        if (p == t) {
            // Check individual characters
            int j;
            for (j = 0; j < M; ++j) {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        // Update hash value for next window
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            // Convert negative hash value to positive
            if (t < 0)
                t += q;
        }
    }
}

int main() {
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    int q = 101; // A prime number,it can be any large prime no.
    search(pat, txt, q);
    return 0;
}
