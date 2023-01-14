// DFS
class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &group, int curr, int &minChar)
    {
        visited[curr] = 1;
        group.push_back(curr);
        minChar = min(curr, minChar);
        for (int i = 0; i < 26; i++)
        {
            if (adj[curr][i] && !visited[i])
                dfs(adj, visited, group, i, minChar);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.length();
        vector<vector<int>> adj(26, vector<int>(26));
        for (int i = 0; i < n; i++)
        {
            adj[s1[i] - 'a'][s2[i] - 'a'] = 1;
            adj[s2[i] - 'a'][s1[i] - 'a'] = 1;
        }
        vector<int> charMap(26);
        for (int i = 0; i < 26; i++)
            charMap[i] = i;
        vector<int> visited(26);

        for (int i = 0; i < 26; i++)
        {
            if (!visited[i])
            {
                vector<int> group;
                int minChar = 100;
                dfs(adj, visited, group, i, minChar);

                for (int x : group)
                    charMap[x] = minChar;
            }
        }

        string ans = "";
        for (char x : baseStr)
        {
            ans += (char)(charMap[x - 'a'] + 'a');
        }
        return ans;
    }
};

//Dual Mapping
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        map<char, int>m;
        int counter = 1;
        for(int i = 0; i < n; i++){
            if(m.find(s1[i]) == m.end() && m.find(s2[i]) == m.end()){
                m[s1[i]] = counter;
                m[s2[i]] = counter;
                counter++;
            }
            else if(m.find(s1[i]) == m.end()) m[s1[i]] = m[s2[i]];
            else if(m.find(s2[i]) == m.end()) m[s2[i]] = m[s1[i]];
            else{
                int x = m[s2[i]];
                vector<char>cleanup;
                for(auto &p : m) if(p.second == x) cleanup.push_back(p.first);
                for(char y: cleanup) m[y] = m[s1[i]];
            }
        }

        map<int, vector<char>>m2;
        for(auto &p: m){
            if(m2.find(p.second) == m2.end()) m2[p.second] = {};
            m2[p.second].push_back(p.first);
        }

        string ans = "";
        for(char x: baseStr){
            if(m.find(x) == m.end()) ans += x;
            else ans += (m2[m[x]][0]);
        }
        return ans;
    }
};