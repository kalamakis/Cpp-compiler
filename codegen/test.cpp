/* test_enum_errors.cpp */

enum Status {
    IDLE,
    RUNNING,
    FINISHED
};

enum Color {
    RED,
    GREEN,
    BLUE
};

int main() {
    Status s;
    Color c;
    int x;

    /* --- 1. Λάθη Ανάθεσης (Assignment) --- */

    // Λάθος: Ανάθεση int σε Enum (Strict typing)
    // Ο κώδικας στο sem_check_assignment απαγορεύει (Enum = Non-Enum)
    // s = 1;

    // Λάθος: Ανάθεση διαφορετικού Enum
    // Status = Color απαγορεύεται
    // s = RED;

    // Λάθος: Ανάθεση Enum σε int
    // (Βάσει της sem_check_assignment που είδαμε, αυτό χτυπάει γιατί right->kind == TYPE_ENUM)
    // x = IDLE;


    /* --- 2. Λάθη Σύγκρισης (Equality/Relational) --- */

    // Λάθος: Σύγκριση δύο ΔΙΑΦΟΡΕΤΙΚΩΝ Enums
    // Επιτρέπουμε Enum == Int, αλλά όχι Status == Color
    // if (IDLE == RED) {
    //     x = 0;
    // }

    // if (RUNNING > BLUE) {
    //     x = 0;
    // }


    /* --- 3. Λάθη Τροποποίησης (L-Values) --- */

    // Λάθος: Προσπάθεια αλλαγής τιμής μιας σταθεράς Enum
    // IDLE = 5;

    // Λάθος: Προσπάθεια ανάθεσης στο όνομα του Τύπου
    // Status = 1;
    // Color = 2;


    /* --- 4. Λάθη Πράξεων (Arithmetic) --- */

    // Λάθος: Πρόσθεση Enum (δεν θεωρείται "numeric" στο is_numeric)
    // Η sem_binary_arith ζητάει is_numeric (int/float)
    // x = IDLE + 1;

    return 0;
}
