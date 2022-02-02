#include <iostream>
#include <utility>
#include <set>
#include <list>
 
using namespace std;
 
int main()
{
    list<pair<int, int>> graph;
    while (true)
    {
        int from, to;
        cin >> from;
        if (from == -1)
            break;
        cin >> to;
        graph.push_back({from, to});
    }
    cout << endl << endl;
 
    set<int> marked;
    vector<list<pair<int, int>>> component;
    auto dfs = [&](int v)
    {
        auto dfs_impl = [&](auto& impl, int v)
        {
            if (marked.count(v))
                return;
            marked.insert(v);
            for (auto [f, t] : graph)
                if (f == v)
                {
                    component.back().push_back({f, t});
                    impl(impl, t);
                }
        };
        dfs_impl(dfs_impl, v);
    };
 
    for (auto [f, t] : graph)
        if (!marked.count(f))
        {
            component.push_back({ });
            dfs(f);
        }
 
    for (unsigned i = 0; i < component.size(); ++i)
    {
        cout << i << " component:" << endl;
        for (auto [f, t] : component[i])
            cout << f << ' ' << t << endl;
        cout << endl << endl;
    }
 
    return 0;
}