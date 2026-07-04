// --- Test 1: Arrays and Functions ---

// Καθολικός δισδιάστατος πίνακας
int matrix[2][3];

// Συνάρτηση που δέχεται πίνακα, μια παράμετρο κατ' αξία και δύο κατ' αναφορά
int  process_data(int data[5], int multiplier, int &sum, float &avg) {
    int i;
    sum = 0;
   
    for (i = 0; i < 5; i++) {
        // Τροποποίηση του πίνακα (περνάει by reference έμμεσα)
        data[i] = data[i] * multiplier;
        sum = sum + data[i];
    }
    // Υπολογισμός μέσου όρου (έλεγχος μετατροπής int σε float)
    avg = sum / 5.0;
    return 0;
}

int main() {
    int local_arr[5];
    int i, j, total;
    float average;

    // 1. Αρχικοποίηση τοπικού μονοδιάστατου πίνακα
    for (i = 0; i < 5; i++) {
        local_arr[i] = i + 1; // [1, 2, 3, 4, 5]
    }

    // 2. Αρχικοποίηση καθολικού δισδιάστατου πίνακα
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            matrix[i][j] = i + j;
        }
    }

    total = 0;
    average = 0.0;
   
    // 3. Κλήση συνάρτησης
    process_data(local_arr, 2, total, average);

    // 4. Εκτυπώσεις
    cout << "--- Test 1 Results ---\n";
    cout << "Total sum (Expected 30): " << total << "\n";
    cout << "Average (Expected 6.0): " << average << "\n";
    cout << "Modified local_arr[0] (Expected 2): " << local_arr[0] << "\n";
    cout << "Matrix[1][2] (Expected 3): " << matrix[1][2] << "\n";

    return 0;
}