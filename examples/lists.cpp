int main() {
    /* 1. Όλες οι Δηλώσεις στην αρχή του block */
    int list L;
    int list tail;
    int list rest;
    
    int val1;
    int val2;
    int val3;

    /* 2. Κατασκευή Λίστας [10, 20, 30] */
    /* Αυτό θα παράγει εντολές IR_CONS στο backend */
    L = [10, 20, 30]; 

    /* 3. Έλεγχος CAR (Πρώτο στοιχείο) */
    val1 = CAR(L);
    cout << "CAR (10): ";
    cout << val1;

    /* 4. Έλεγχος CADR (Δεύτερο στοιχείο) */
    /* Ο κώδικας παραγωγής θα το σπάσει σε CAR(CDR(L)) */
    val2 = CADR(L);
    cout << " | CADR (20): ";
    cout << val2;

    /* 5. Έλεγχος συνδυασμού CDR και μετά CAR */
    tail = CDR(L);
    val2 = CAR(tail);
    cout << " | CAR(CDR) (20): ";
    cout << val2;

    /* 6. Έλεγχος CDDR και μετά CAR (Τρίτο στοιχείο) */
    rest = CDDR(L);
    val3 = CAR(rest);
    cout << " | CAR(CDDR) (30): ";
    cout << val3;

    return 0;
}