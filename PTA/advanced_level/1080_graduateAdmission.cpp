#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Applicants {
    int id;  // id 0 ~ n-1
    int g_e;
    int g_i;
    int final;
    vector<int> prefs;  // index
};

struct School {
    int quota;
    vector<int> admit;  // index
};

int n, m, k;
School* schools[105];     // intdex starts from 0 to m-1
Applicants* apps[40050];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        School* school = new School;
        scanf("%d", &(school->quota));
        schools[i] = school;
    }
    for (int i = 0; i < n; i++) {
        Applicants* app = new Applicants;
        app->id = i;
        scanf("%d %d ", &(app->g_e), &(app->g_i));
        app->final = (app->g_e + app->g_i) / 2;
        int pref;
        for (int j = 0; j < k; j++) {
            scanf("%d", &pref);
            app->prefs.push_back(pref);
        }
        apps[i] = app;
    }

    sort(apps, apps+n, [](Applicants* a1, Applicants* a2) {
        if (a1->final > a2->final) return true;
        else if (a1->g_e > a2->g_e) return true;
        return false;
    });

    for (size_t i = 0; i < n; i++) {    // i - 排名
        // bool rejected = true;
        for (size_t j = 0; j < k; j++) {
            if (schools[apps[i]->prefs[j]]->quota > 0 ||
                    (i > 0 && *(schools[apps[i]->prefs[j]]->admit.end()-1) == apps[i-1]->id &&
                    apps[i-1]->final == apps[i]->final && apps[i-1]->g_e == apps[i]->g_e)) {
                schools[apps[i]->prefs[j]]->quota--;
                schools[apps[i]->prefs[j]]->admit.push_back(apps[i]->id);
                // rejected = false;
                break;
            }
        }
        // if (rejected) continue;
    }

    for (size_t i = 0; i < m; i++) {
        if (schools[i]->admit.empty()) {
            printf("\n");
            continue;
        }
        sort(schools[i]->admit.begin(), schools[i]->admit.end(), [](int a, int b) {return a < b;});
        printf("%d", schools[i]->admit[0]);
        for (size_t j = 1; j < schools[i]->admit.size(); j++) {
            printf(" %d", schools[i]->admit[j]);
        }
        if (i != m-1)   printf("\n");
    }

    return 0;
}