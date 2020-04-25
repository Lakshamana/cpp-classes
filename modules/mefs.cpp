/* insert a dutch guy meme here */

int fat(int n) {
    return n == 0 ? 1 : n * fat(n - 1);
}

int sqr(int n) {
    return n * n;
}
