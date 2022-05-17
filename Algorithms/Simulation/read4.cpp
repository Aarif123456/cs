/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char buf4[4] = {0,0,0,0};
    int bufPointer = 4, bufSize = 4;

    int read(char *buf, int n) {
        int charRead = 0;
        while(charRead < n and bufSize){
            while(charRead < n and bufPointer < bufSize){
                *buf = buf4[bufPointer];
                buf++;
                charRead++;
                bufPointer++;
            }
            if(bufSize == bufPointer){
                bufSize = read4(buf4);
                bufPointer = 0;
            }
        }
        return charRead;
    }
};