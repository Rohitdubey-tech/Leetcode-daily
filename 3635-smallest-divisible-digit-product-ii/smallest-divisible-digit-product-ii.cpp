class Solution {
    int f2[10] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
    int f3[10] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
    int f5[10] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    int f7[10] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};

    int min_len(int c2, int c3, int c5, int c7){
        int l = c7 + c5 + c3/2 + c2/3;
        int r3 = c3%2, r2 = c2%3;
        if(r3 && r2 == 2) return l + 2;
        return l + (r3 || r2 ? 1 : 0);
    }

    string fill(int len, int c2, int c3, int c5, int c7){
        string res = "";
        for(int i=0;i<len;i++){
            for(int d=1;d<=9;d++){
                int n2 = max(0, c2 - f2[d]), n3 = max(0, c3 - f3[d]);
                int n5 = max(0, c5 - f5[d]), n7 = max(0, c7 - f7[d]);
                if(min_len(n2,n3,n5,n7) <= len - 1 - i){
                    res += (char)('0' + d);
                    c2 = n2; c3 = n3; c5 = n5; c7 = n7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        while(t%2==0){
            c2++;
            t/=2;
        }
        while(t%3==0){
            c3++;
            t/=3;
        }
        while(t%5==0){
            c5++;
            t/=5;
        }
        while(t%7==0){
            c7++;
            t/=7;
        }
        if(t > 1) return "-1";

        int n = num.size();
        vector<int> p2(n+1,0), p3(n+1,0), p5(n+1,0), p7(n+1,0);
        int first_zero = n;

        for(int i=0;i<n;i++){
            int d = num[i] - '0';
            if(d==0){
                first_zero = i;
                break;
            }
            p2[i+1] = p2[i] + f2[d];
            p3[i+1] = p3[i] + f3[d];
            p5[i+1] = p5[i] + f5[d];
            p7[i+1] = p7[i] + f7[d];
        }

        if(first_zero == n && p2[n]>=c2 && p3[n]>=c3 && p5[n]>=c5 && p7[n]>=c7){
            return num;
        }

        for(int i=n-1;i>=0;i--){
            if(i > first_zero) continue;
            for(int d=num[i] - '0'+1;d<=9;d++){
                int r2 = max(0, c2-p2[i]-f2[d]);
                int r3 = max(0, c3-p3[i]-f3[d]);
                int r5 = max(0, c5-p5[i]-f5[d]);
                int r7 = max(0, c7-p7[i]-f7[d]);

                int avail = n - 1 - i;
                if(min_len(r2,r3,r5,r7) <= avail){
                    return num.substr(0,i) + (char)('0' + d) + fill(avail,r2,r3,r5,r7);
                }
            }
        }
        int target_len = max(n+1,min_len(c2,c3,c5,c7));
        return fill(target_len, c2, c3, c5, c7);
    }
};