int main() {
    /* 1. Δηλώσεις (Πάντα στην αρχή) */
    int list L;
    int x;
    int list tail;

    /* 2. Δημιουργία Λίστας [10, 20] -> CONS */
    L = [10, 20];

    /* 3. Δοκιμή CAR */
    x = CAR(L);
    cout << x;      /* Πρέπει να τυπώσει 10 */

    /* 4. Δοκιμή CDR */
    tail = CDR(L);
    x = CAR(tail);
    cout << x;      /* Πρέπει να τυπώσει 20 */

    return 0;
}