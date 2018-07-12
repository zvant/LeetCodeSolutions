/**
 * https://leetcode.com/problems/rectangle-area/description/
 * 2015/07
 * 20 ms
 */

#define SWAP(X, Y) {(tmp) = (X); (X) = (Y); (Y) = (tmp);}

int overlapArea(int A, int B, int C, int D, int E, int F, int G, int H);

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int tmp;
    if(A > C)
        SWAP(A, C);
    if(B > D)
        SWAP(B, D);
    if(E > G)
        SWAP(E, G);
    if(F > H)
        SWAP(F, H);
    
    int area1 = (A - C) * (B - D);
    int area2 = (E - G) * (F - H);
    
    return area1 + area2 - overlapArea(A, B, C, D, E, F, G, H);
}

int overlapArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    if(A == C || B == D || E == G || F == H)
        return 0;
    
    if(C <= E || B >= H || D <= F || G <= A)
        return 0;
    
    int x, y;
    if(A < E && C < G)
        x = C - E;
    else
        if(A > E && C > G)
            x = G - A;
        else
            x = (C - A) > (G - E) ? (G - E) : (C - A);
    
    if(D < H && B < F)
        y = D - F;
        else
            if(D > H && B > F)
                y = H - B;
            else
                y = (D - B) > (H - F) ? (H - F) : (D - B);
    
    return x * y;
}
