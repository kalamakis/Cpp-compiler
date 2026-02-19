/* 1. Global Typedefs (όπως ορίζει η γραμματική σου) */
typedef int my_int;
typedef float my_float;

/* 2. Αλυσιδωτό Typedef (χρήση ενός ήδη υπάρχοντος typedef) */
typedef my_int number;

int main() {
    /* --- Δηλώσεις (πάντα στην αρχή του block) --- */
    
    number x;          /* Στην πραγματικότητα είναι int */
    my_float y;        /* Στην πραγματικότητα είναι float */
    
    number list L;     /* Συνδυασμός: typedef και list! (γίνεται int list) */
    number head_val;

    /* --- Εντολές --- */
    
    x = 42;
    
    /* Έλεγχος ότι το float δουλεύει κανονικά */
    y = 3.14;
    
    /* Δημιουργία λίστας και χρήση της list function */
    L = [10, 20, 30];
    head_val = CAR(L);

    /* --- Εκτυπώσεις --- */
    cout << "Number x should be 42: ";
    cout << x;
    
    cout << " | Float y should be 3.14: ";
    cout << y;

    cout << " | List Head should be 10: ";
    cout << head_val;

    return 0;
}