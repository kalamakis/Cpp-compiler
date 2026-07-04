// --- Test 2: Types, Enums, Chars and Logic ---

enum color { RED = 1, GREEN, BLUE };

// Συνάρτηση με μεικτούς τύπους
float compute(int a, float b) {
    float res;
    // Το a (int) πρέπει να γίνει ng cast σε float αυτόματα πριν τον πολλαπλασιασμό
    res = a * b + 2.5;
    return res;
}

int main() {
    int i, j;
    float f, c_res;
    char c1, c2;
    color my_col1, my_col2;

    cout << "--- Test 2 Results ---\n";

    // 1. Μετατροπές (Casting)
    i = 10;
    f = 3.14;
   
    f = f + i;      // Το i γίνεται float -> 13.14
    j = f;          // Το f γίνεται int (αποκοπή) -> 13

    cout << "Float after addition (Expected 13.14): " << f << "\n";
    cout << "Int after truncation (Expected 13): " << j << "\n";

    c_res = compute(5, 1.2); // 5 * 1.2 + 2.5 = 8.5
    cout << "Compute result (Expected 8.5): " << c_res << "\n";

    // 2. Chars και Enums (Μόνο σχεσιακοί τελεστές επιτρέπονται)
    c1 = 'A';
    c2 = 'Z';
    my_col1 = color.RED;     // Χρήση ονόματος τύπου για τις σταθερές
    my_col2 = color.GREEN;

    if (c1 < c2) {
        cout << "Success: 'A' is less than 'Z'\n";
    }

    if (my_col1 != my_col2) {
        cout << "Success: RED is not GREEN\n";
    }

    // 3. Λογικές πράξεις (Short-circuiting)
    if (j > 10 && f > 5.0) {
        cout << "Success: Logical AND passed\n";
    }

    if (i == 0 || j == 13) {
        cout << "Success: Logical OR passed (j is 13)\n";
    }

    // 4. Λογική Άρνηση (NOT)
    if (!(i == 0)) {
        cout << "Success: Logical NOT passed\n";
    }

    return 0;
}