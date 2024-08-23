#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

class Solution{

    public:

    string fractionAddition(string expression){
        int finalNumerator = 0, finalDenominator = 1; // Start with 0 numerator and denominator as 1
        int n = expression.size(); // Get the size of the input string
        int i = 0;

        while (i < n) {
            int sign = 1; // Default sign is positive

            // Check if the current character is a sign
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') {
                    sign = -1; // If it's a '-', make the sign negative
                }
                i++; // Move to the next character
            }

            int numerator = 0;
            // Extract the numerator part of the fraction
            while (i < n && isdigit(expression[i])) {
                numerator = numerator * 10 + (expression[i] - '0'); // Build the numerator digit by digit
                i++;
            }
            numerator *= sign; // Apply the sign to the numerator

            i++; // Skip over the slash '/'

            int denominator = 0;
            // Extract the denominator part of the fraction
            while (i < n && isdigit(expression[i])) {
                denominator = denominator * 10 + (expression[i] - '0'); // Build the denominator digit by digit
                i++;
            }

            // Combine the current fraction with the running total
            finalNumerator = finalNumerator * denominator + numerator * finalDenominator;
            finalDenominator *= denominator;

            // Reduce the fraction to its simplest form
            int gcdValue = gcd(abs(finalNumerator), finalDenominator);
            finalNumerator /= gcdValue;
            finalDenominator /= gcdValue;
        }
        return to_string(finalNumerator) + '/' + to_string(finalDenominator); // Return the result as a string
    }

    private:

    // Function to find the greatest common divisor (GCD)
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a; // The GCD
    }

};

int main(){

    Solution s;

    cout << s.fractionAddition("-1/2+1/2") << endl; // Should print 0/1

    return 0;
}


// ************** CODED BY HASSAM FATHE @hassamcoddes *********************** //


// APPLICATIONS:

/*

This code demonstrates how to handle fractional addition and reduction in its simplest form. Here are some practical applications:

- **Mathematical Calculations**: Useful in software for performing arithmetic operations involving fractions.
- **Fraction Management**: Helpful in systems dealing with fractional data such as measurement systems or financial calculations.
- **Educational Tools**: Can be used in educational software to teach concepts related to fractions and their simplifications.
- **Recipe Management**: Applicable in applications that manage recipes where ingredients are given in fractional quantities.
- **Data Normalization**: Useful in scenarios where data needs to be normalized or simplified for consistent representation.

You can modify and integrate this code into various projects that involve fractional arithmetic operations.

*/
