class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<char> e1={s1[0],s1[2]};
        vector<char> e2={s2[0],s2[2]};

        vector<char> o1={s1[1],s1[3]};
        vector<char> o2={s2[1],s2[3]};

        sort(e1.begin(),e1.end());
        sort(e2.begin(),e2.end());
        sort(o1.begin(),o1.end());
        sort(o2.begin(),o2.end());

        return e1==e2 && o1==o2;
    }
};