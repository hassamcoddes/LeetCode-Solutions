#include<iostream>
#include<cmath>
using namespace std;

class Solution{
    public:

    int findComplement(int num){
        vector<int> binaryForm;  // To store the binary digits of the number
        int complement=0;  // This will hold the final complement value
        int remainder;
        
        // Convert the number to binary by repeatedly dividing by 2
        while(num!=0){
            remainder = num % 2;  // Get the last binary digit
            num = num / 2;  // Reduce the number for the next iteration
            binaryForm.push_back(remainder);  // Store the binary digit
        }

        // Flip the binary digits (1 -> 0 and 0 -> 1)
        for(int i = binaryForm.size()-1; i >= 0; --i){
            if(binaryForm[i] == 1){
                binaryForm[i] = 0;
            } else {
                binaryForm[i] = 1;
            }
        }

        // Convert the flipped binary digits back to a decimal number
        for(int i = binaryForm.size()-1; i >= 0; --i){
            complement += binaryForm[i] * pow(2, i);
        }
        return complement;
    }

};

int main(){
    Solution s;

    s.findComplement(5);  // Example call to test the function
    return 0;
}


// ************** CODED BY HASSAM FATHE @hassamcoddes *********************** //


///////////////// ************* APPLICATIONS *******************  ///////////////////////////

/*

1. **Data Encryption:** Binary complements are used in encryption algorithms to obfuscate data.
2. **Error Detection and Correction:** Useful in digital systems to detect and correct errors by flipping bits.
3. **Image Processing:** Bitwise operations like complementing are used for image manipulation.
4. **Bitwise Operations Practice:** Essential for understanding low-level programming and hardware interactions.
5. **Complement Calculation:** In computer science, it's used to find the 1's complement of binary numbers for various algorithms.

*/
