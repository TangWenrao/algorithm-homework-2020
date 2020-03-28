var cdns = [
    {
        x: 9,
        y: 37289
    },
    {
        x: 11,
        y: 42747
    },
    {
        x: 13,
        y: 59885
    },
    {
        x: 15,
        y: 66581
    },
    {
        x: 17,
        y: 70644
    }
];
var n = cdns.length;
var x = [10, 12, 14, 16];//插值点
var y = [0, 0, 0, 0]
var f = new Array();
for (let a = 0; a < n; a++) {
    f[a] = new Array();
    f[a][0] = cdns[a].y;
    for (let b = 1; b < n; b++) {
        f[a][b] = 0;
    }
}
var y_true = [40262, 44765, 63950, 68595];
for (let i = 0; i < x.length; i++) {
    for (let j = 1; j < n; j++) {
        for (let k = j; k < n; k++) {
            f[k][j] = (f[k][j - 1] - f[k - 1][j - 1]) / (cdns[k].x - cdns[k - j].x);
            // console.log("f",f[k][j]);

        }
    }
    y[i] = f[n - 1][n - 1];
    for (j = n - 2; j >= 0; j--) {
        y[i] = f[j][j] + (x[i] - cdns[j].x) * y[i];
    }
    console.log(x[i], y[i], y_true[i], y[i] - y_true[i]);
}