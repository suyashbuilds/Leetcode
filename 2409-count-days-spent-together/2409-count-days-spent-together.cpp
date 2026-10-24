class Solution {
public:
    int finddayofyear(string date, vector<int> &cumMonthdays){

        int month = stoi(date.substr(0,2));
        int days = stoi(date.substr(3));

        return cumMonthdays[month-1] + days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        vector<int> monthdays = {31,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> cumMonthdays(13,0);
        cumMonthdays[1] = 31;
        for(int i=2; i<=12; i++){
            cumMonthdays[i] = cumMonthdays[i-1] + monthdays[i-1];
        }

        int arriveAliceday = finddayofyear(arriveAlice, cumMonthdays);
        int leaveAliceday = finddayofyear(leaveAlice,cumMonthdays);
        int arriveBobday = finddayofyear(arriveBob,cumMonthdays);
        int leaveBobday = finddayofyear(leaveBob,cumMonthdays);

        int overlapdays = min(leaveAliceday, leaveBobday) - max(arriveAliceday, arriveBobday) + 1;

        return overlapdays < 0 ? 0 : overlapdays;
    }
};