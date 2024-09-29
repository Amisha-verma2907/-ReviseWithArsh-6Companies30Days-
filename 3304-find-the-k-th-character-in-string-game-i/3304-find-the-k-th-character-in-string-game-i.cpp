class Solution {
public:
    // Helper function to get the next character in the alphabet, with 'z' wrapping around to 'a'
    char getNextChar(char c) {
        return (c == 'z') ? 'a' : c + 1;
    }

    // Recursive function to find the k-th character in the string game
    char kthCharacter(int k) {
        string word = "a"; // Start with the initial word "a"
        return findKthCharacter(k, word);
    }

private:
    // Private recursive function to expand the word and find the k-th character
    char findKthCharacter(int k, string word) {
        // Base case: If k is within the length of the current word
        if (k <= word.length()) {
            return word[k - 1];
        }

        // Generate the next version of the word by transforming each character
        string nextWord = "";
        for (char c : word) {
            nextWord += getNextChar(c);
        }

        // Concatenate the original word with the newly generated word
        string newWord = word + nextWord;

        // Recur to find the k-th character in the expanded word
        return findKthCharacter(k, newWord);
    }
};
