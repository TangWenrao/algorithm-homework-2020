var cdns = [
    {
        x:9,
        y:37289
    },
    {
        x:11,
        y:42747
    },
    {
        x:13,
        y:59885
    },
    {
        x:15,
        y:66581
    },
    {
        x:17,
        y:70644
    }
];
var x = [10,12,14,16];//插值点
var y = [0,0,0,0];
var y_true = [40262,44765,63950,68595];
for(let i=0;i<x.length;i++){
    for(let j = 0;j < cdns.length;j++){
        var t = 1;
        for(let k =0;k < cdns.length;k++){
            if(k!=j){
                t *= (x[i] - cdns[k].x)/(cdns[j].x-cdns[k].x);
                // console.log("t",t);
            }
        }
        y[i] += t*cdns[j].y;
        // console.log("y[i]",y[i]);
    }
    console.log(x[i],y[i],y_true[i],y[i]-y_true[i]);
}