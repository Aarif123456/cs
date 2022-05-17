// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    char curBuffer[4];
    int curBufferIndex = 4, curBufferSize = 4;

    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    int read(char* const buf, int n) {
        if(!n || !curBufferSize) return 0;
        auto cur = buf;
        while((cur-buf)<n){
            /* If we reach end of buffer try to read again */
            if(curBufferIndex >= curBufferSize){
                curBufferSize = read4(curBuffer);
                curBufferIndex = 0;
            }
            if(!curBufferSize) break;
            *cur = *(curBuffer + curBufferIndex);
            cur++; curBufferIndex++;
        }
        *cur = '\0';
        return strlen(buf);
    }
};