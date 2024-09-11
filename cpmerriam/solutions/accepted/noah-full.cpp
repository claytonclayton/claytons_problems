#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, m, k, q;
bool dictionaryWord[N];
int len[N], reqs[N];
vector <int> definitionLinks[N];

int dictId = 0;
map <string, int> dict;
map <int, string> reverseDict;
int add(string& word) {
    if (dict.count(word))
        return dict[word];
    reverseDict[dictId] = word;
    return dict[word] = dictId++;
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> len[i];

    dictId = 0;
    set <int> wordsInDict;
    set <pair <int, int> > edges;
    for (int i = 1; i <= n; i++) {
        string word; cin >> word;
        assert(word.back() == ':' && word.size() > 1 && "bad word");
        word.pop_back();
        int curWord = add(word);
        assert(wordsInDict.count(curWord) == false && "One word appear in the dictionary multiple times\n");
        dictionaryWord[curWord] = 1;
        set <int> curReqs;
        for (int j = 1; j < len[i]; j++) {
            string wordLink; cin >> wordLink;
            int link = add(wordLink);
            curReqs.insert(link);
            edges.insert({link, curWord});
        }
        reqs[curWord] = curReqs.size();
        for (auto& link : curReqs) 
            definitionLinks[link].push_back(curWord);

    }
    queue <int> bfs;
    for (int i = 0; i < dictId; i++) {
        if (reqs[i] == 0) bfs.push(i);
    }
    
    int ans = 0;
    while (!bfs.empty()) {
        int word = bfs.front(); bfs.pop();
        ans += dictionaryWord[word];
        for (auto& link : definitionLinks[word]) 
            if (--reqs[link] == 0) 
                bfs.push(link);
            
    }
    cout << ans << '\n';
}