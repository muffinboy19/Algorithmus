#include <iostream>

int find_c(int a, int b) {
    int c = b;

    // If c is already equal to a, modify c to be different
    if (c == a) {
        // Find a bit that is not set in a and set it in c
        int bit_position = 0;
        while ((a & (1 << bit_position)) != 0) {
            bit_position++;
            if (bit_position >= sizeof(int) * 8) {
                return -1;
            }
        }
        c |= (1 << bit_position); // Set the found bit in c
    }

    // Ensure c is not equal to a
    if (c == a) {
        return -1;
    }

    // Verify that a & c == b and c is greater than both a and b
    if ((a & c) != b || c <= a || c <= b) {
        // Try to find a c that satisfies the condition
        for (c = b + 1; c < (1 << (sizeof(int) * 8)); c++) {
            if ((a & c) == b && c != a && c > a && c > b) {
                return c;
            }
        }
        return -1;
    }

    return c;
}

int main() {
    int a = 5; // Example values
    int b = 4;
    int result = find_c(a, b);
    if (result != -1) {
        std::cout << "The value of c is: " << result << std::endl;
    } else {
        std::cout << "No valid value of c found." << std::endl;
    }
    return 0;
}
