#include <bitset>
#define MAX_NUMBER 50001
typedef vector<int> vi; 
typedef vector<vi> vvi; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n)
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 

class Solution {
public:
    bitset<MAX_NUMBER> createBitSetInterval(int start, int end){
        if (end<=start) return bitset<MAX_NUMBER>();
        bitset<MAX_NUMBER> bits;
        FOR(i, start, end) bits[i] = true;
        return bits;
    }
    bool doesOverlap( bitset<MAX_NUMBER> interval1,  bitset<MAX_NUMBER> interval2){
        return (interval1 & interval2) != bitset<MAX_NUMBER>(0);
    }

    /**
     * @param intervals: the intervals
     * @param rooms: the sum of rooms
     * @param ask: the ask
     * @return: true or false of each meeting
     */
    vector<bool> meetingRoomIII(vector<vector<int>> &intervals, int rooms, vector<vector<int>> &ask) {
        vector<bitset<MAX_NUMBER>> roomSchedule(rooms);
        TRAV(interval, intervals){
            auto curInterval = createBitSetInterval(interval[0], interval[1]);
            REP(i, rooms){
                if(!doesOverlap(curInterval, roomSchedule[i])){
                    roomSchedule[i] |= curInterval;
                    cout << "schedule: ("<< interval[0] << "," << interval[1] << ")" << " in room" << i << endl;
                    break;
                }
            }
        }
        std::vector<bool> output(ask.size());
        int i=0;
        TRAV(interval, ask){
            auto curInterval = createBitSetInterval(interval[0], interval[1]);
            TRAV(room, roomSchedule){
                if(!doesOverlap(room, curInterval)) {
                    output[i] = true;
                    break;
                }
            }
            i++;
        }
        return output;
    }
};