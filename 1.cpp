#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* FindMostFrequentWord(char* str) {
    int maxWordLength = 30;
    int wordFreq[maxWordLength + 1] = {0};  // Assuming max word length is 30
    
    int len = strlen(str);
    int i = 0;
    char word[maxWordLength + 1];
    int wordIndex = 0;
    int maxFreq = 0;
    
    while (i < len) {
        if (str[i] != ' ') {
            // Build the current word
            if (wordIndex < maxWordLength) {
                word[wordIndex++] = tolower(str[i]);
            }
        } else if (wordIndex > 0) {
            // Process the completed word
            word[wordIndex] = '\0';
            int wordLength = wordIndex;
            wordIndex = 0;
            
            // Increment the frequency count for the current word length
            wordFreq[wordLength]++;
            
            // Update the maximum frequency
            if (wordFreq[wordLength] > maxFreq) {
                maxFreq = wordFreq[wordLength];
            }
        }
        
        i++;
    }
    
    // Check the last word if it's not followed by a space
    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        int wordLength = wordIndex;
        
        wordFreq[wordLength]++;
        
        if (wordFreq[wordLength] > maxFreq) {
            maxFreq = wordFreq[wordLength];
        }
    }
    
    // Find the first occurrence of the word with the maximum frequency
    i = 0;
    wordIndex = 0;
    
    while (i < len) {
        if (str[i] != ' ') {
            word[wordIndex++] = str[i];
        } else if (wordIndex > 0) {
            word[wordIndex] = '\0';
            int wordLength = wordIndex;
            wordIndex = 0;
            
            if (wordLength <= maxWordLength && wordFreq[wordLength] == maxFreq) {
                return word;
            }
        }
        
        i++;
    }
    
    // Check the last word if it's not followed by a space
    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        int wordLength = wordIndex;
        
        if (wordLength <= maxWordLength && wordFreq[wordLength] == maxFreq) {
            return word;
        }
    }
    
    return NULL;  // Return NULL if no word is found (should not happen)
}

int main() {
    char str[] = "to jog is a good way to stay fit";
    char* mostFrequent = FindMostFrequentWord(str);
    printf("%s\n", mostFrequent);
    return 0;
}
