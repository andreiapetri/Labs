int sum(int *start, int *end){
    int total = 0;
    while (start < end){
        total += *start++; // Combined increment and dereference
    }
    return total;
}
