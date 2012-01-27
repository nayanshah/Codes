#include "main.h"

#define LIMIT 8
#define ACCURACY 1e-4
#define INF 1e9
#define DL; cout << endl;
#define DB(X); cout << X << endl;

double domain[LIMIT+1][LIMIT+1];

double f(double x, double y) {
    return x+y;
}

struct point {
    int x;
    int y;
    double val;

    point(int x, int y) {
        this->x = x;
        this->y = y;
        if(x == 0 || y == 0 || x==LIMIT || y==LIMIT) {
            val = f(x, y);
            domain[x][y] = val;
        }
        else
            val = INF;
    }
    void print() {
        printf(" (%d, %d) ", x, y);
    }
};

point *mid(point *p, point *q) {
    int x = (p->x+q->x)/2;
    int y = (p->y+q->y)/2;
    point *m = new point(x, y);
    m->val = domain[p->x][p->y];
    return m;
}

point *five_point(point *p, point *q, point *r, point *s) {
    int x = (p->x+q->x+r->x+s->x)/4;
    int y = (p->y+q->y+r->y+s->y)/4;
    point *m = new point(x, y);
    m->val = (p->val+q->val+r->val+s->val)/4;
    domain[m->x][m->y] = m->val;
    return m;
}

void solve_grid( point *lu, point *ru, point *ld, point *rd) {
    // Terminatation
    if(abs(lu->x-ru->x) <= 1 || abs(lu->y - ld->y) <= 1 || abs(ld->x-rd->x) <= 1 || abs(ru->y - rd->y) <= 1)
        return;
    point *lm = mid(lu, ld);
    point *rm = mid(ru, rd);
    point *um = mid(lu, ru);
    point *dm = mid(ld, rd);

    point *m = five_point(lu, ru, ld, rd);

    point *ldc = five_point(lm, m, ld, dm);
    point *rdc = five_point(m, rm, dm, rd);
    point *luc = five_point(lu, um, lm, m);
    point *ruc = five_point(um, ru, m, rm);

    point *ndm = five_point(ldc, m, dm, rdc); // l u  d r
    point *nrm = five_point(m, ruc, rdc, rm);
    point *nlm = five_point(lm, luc, ldc, m);
    point *num = five_point(luc, um, m, ruc);

    solve_grid(lm, m, ld, dm);
    solve_grid(m, rm, dm, rd);
    solve_grid(lu, um, lm, m);
    solve_grid(um, ru, m, rm);
    solve_grid(luc, ruc, ldc, rdc);

}

void solve() {
    point *lu = new point(0,LIMIT);
    point *ru = new point(LIMIT,LIMIT);
    point *ld = new point(0,0);
    point *rd = new point(LIMIT,0);
    cout << "-- Original --" << endl;
    for(int i=0; i<=LIMIT; i++) {
        for(int j=0; j<=LIMIT; j++) {
            cout << domain[i][j] << " ";
        }
        DL;
    }
    solve_grid(lu, ru, ld, rd);
    DL;cout << "-- Solved --" << endl;
    for(int i=0; i<=LIMIT; i++) {
        for(int j=0; j<=LIMIT; j++) {
            printf("%5.1f ", domain[i][j]);
        }
        DL;
    }
}
