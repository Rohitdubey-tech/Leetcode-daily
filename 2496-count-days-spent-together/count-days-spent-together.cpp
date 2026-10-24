int days[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Solution {
public:
    using int2=pair<int, int>;
    inline int2 mmdd(string& s){
        const int m=(s[0]-'0')*10+s[1]-'0', d=(s[3]-'0')*10+s[4]-'0';
        return {m, d};
    }
    inline int cntDays(int2& mmdd){
        return days[mmdd.first-1]+mmdd.second;
    }
    int countDaysTogether(string& arriveAlice, string& leaveAlice, string& arriveBob, string& leaveBob) {
        if (days[12]<365) partial_sum(days, days+13, days);

        int2 ss=max(mmdd(arriveAlice), mmdd(arriveBob)), 
             tt=min(mmdd(leaveAlice), mmdd(leaveBob));
        if (ss>tt) return 0;
        return cntDays(tt)-cntDays(ss)+1;
    }
};