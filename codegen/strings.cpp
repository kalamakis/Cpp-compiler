// 1. Δοκιμή: Καθολικές Μεταβλητές (Globals)
int global_counter;
string global_prefix;

int main() {
    int a, b;
    string s1, s2, s3, s4;

    // --- Έλεγχος Globals ---
    global_counter = 100;
    global_prefix = "Hello ";
    cout << "Global counter is: " << global_counter << "\n";

    // --- 2. Έλεγχος Αυξομείωσης (++, --) ---
    a = 5;
    b = ++a; 
    cout << "Pre-inc (++a) : a=" << a << ", b=" << b << " (Expected: 6, 6)\n";

    a = 5;
    b = a++; 
    cout << "Post-inc (a++) : a=" << a << ", b=" << b << " (Expected: 6, 5)\n";

    a = 5;
    b = --a; 
    cout << "Pre-dec (--a) : a=" << a << ", b=" << b << " (Expected: 4, 4)\n";

    a = 5;
    b = a--; 
    cout << "Post-dec (a--) : a=" << a << ", b=" << b << " (Expected: 4, 5)\n";

    // --- 3. Έλεγχος Ένωσης Strings (Concat) ---
    s1 = "World";
    s2 = global_prefix + s1;
    cout << "Concat result  : " << s2 << "\n"; // Πρέπει να τυπώσει "Hello World"

    // --- 4. Έλεγχος Σύγκρισης Strings (Compare) ---
    s1 = "Apple";
    s2 = "Banana";
    s3 = "Apple";
    
    if (s1 == s3) {
        cout << "Success: Apple == Apple\n";
    } else {
        cout << "FAIL: String == operator\n";
    }

    if (s1 != s2) {
        cout << "Success: Apple != Banana\n";
    } else {
        cout << "FAIL: String != operator\n";
    }

    if (s1 < s2) {
        cout << "Success: Apple < Banana (A comes before B)\n";
    } else {
        cout << "FAIL: String < operator\n";
    }

    if (s2 > s1) {
        cout << "Success: Banana > Apple\n";
    } else {
        cout << "FAIL: String > operator\n";
    }

    return 0;
}
