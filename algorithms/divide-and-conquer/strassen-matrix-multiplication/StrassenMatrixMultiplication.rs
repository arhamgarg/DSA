fn add(a: &Vec<Vec<i32>>, b: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let n = a.len();
    let mut result = vec![vec![0; n]; n];

    for i in 0..n {
        for j in 0..n {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    result
}

fn subtract(a: &Vec<Vec<i32>>, b: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let n = a.len();
    let mut result = vec![vec![0; n]; n];

    for i in 0..n {
        for j in 0..n {
            result[i][j] = a[i][j] - b[i][j];
        }
    }

    result
}

fn strassen(a: &Vec<Vec<i32>>, b: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let n = a.len();

    if n == 1 {
        return vec![vec![a[0][0] * b[0][0]]];
    }

    let k = n / 2;

    let mut a11 = vec![vec![0; k]; k];
    let mut a12 = vec![vec![0; k]; k];
    let mut a21 = vec![vec![0; k]; k];
    let mut a22 = vec![vec![0; k]; k];

    let mut b11 = vec![vec![0; k]; k];
    let mut b12 = vec![vec![0; k]; k];
    let mut b21 = vec![vec![0; k]; k];
    let mut b22 = vec![vec![0; k]; k];

    for i in 0..k {
        for j in 0..k {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + k];
            a21[i][j] = a[i + k][j];
            a22[i][j] = a[i + k][j + k];

            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + k];
            b21[i][j] = b[i + k][j];
            b22[i][j] = b[i + k][j + k];
        }
    }

    let p1 = strassen(&a11, &subtract(&b12, &b22));
    let p2 = strassen(&add(&a11, &a12), &b22);
    let p3 = strassen(&add(&a21, &a22), &b11);
    let p4 = strassen(&a22, &subtract(&b21, &b11));
    let p5 = strassen(&add(&a11, &a22), &add(&b11, &b22));
    let p6 = strassen(&subtract(&a12, &a22), &add(&b21, &b22));
    let p7 = strassen(&subtract(&a11, &a21), &add(&b11, &b12));

    let c11 = add(&subtract(&add(&p5, &p4), &p2), &p6);
    let c12 = add(&p1, &p2);
    let c21 = add(&p3, &p4);
    let c22 = subtract(&subtract(&add(&p1, &p5), &p3), &p7);

    let mut c = vec![vec![0; n]; n];

    for i in 0..k {
        for j in 0..k {
            c[i][j] = c11[i][j];
            c[i][j + k] = c12[i][j];
            c[i + k][j] = c21[i][j];
            c[i + k][j + k] = c22[i][j];
        }
    }

    c
}
