int main() {
    int i;

    // Σωστό loop
    for(i=0; i<10; i++) {
        if (i == 5) break;    // OK
        if (i == 2) continue; // OK
    }

    // ΛΑΘΟΣ: break έξω από loop
    // break;
}
