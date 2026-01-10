/* test_io.cpp */

int main() {
    int x;
    float y;
    int arr[5];

    // 1. Δοκιμή CIN
    // Ανάγνωση σε απλές μεταβλητές
    cin >> x >> y;

    // Ανάγνωση σε στοιχείο πίνακα (l-value)
    cin >> arr[0];

    // 2. Δοκιμή COUT
    // Εκτύπωση σταθερών (String, Int, Float)
    cout << "Results: " << 10 << 3.14;

    // Εκτύπωση μεταβλητών
    cout << x << y;

    // Εκτύπωση αποτελεσμάτων πράξεων (Expressions)
    cout << (x + 5) * 2;
    cout << arr[0];

    return 0;
}
