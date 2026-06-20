// Last updated: 6/20/2026, 5:07:27 PM
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        queue<int> q;
        q.push(0);

        vector<bool> visited(n,false);
        visited[0]=true;

        int farthest = 0;

        while(!q.empty()) {

            int curr = q.front();
            q.pop();

            int start = max(curr + minJump, farthest + 1);
            int end = min(curr + maxJump, n - 1);

            for(int next = start; next <= end; next++) {

                if(s[next]=='0' && !visited[next]) {

                    if(next==n-1)
                        return true;

                    visited[next]=true;
                    q.push(next);
                }
            }

            farthest = end;
        }

        return n==1;
    }
};