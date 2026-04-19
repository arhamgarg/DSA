// given 2 matrices A and B: return A + B
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

// given 2 matrices A and B: return A - B
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

// given 2 matrices A and B: return A X B (Strassen)
fn strassen(a: &Vec<Vec<i32>>, b: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let n = a.len();

    // base case: single element multiplication
    if n == 1 {
        return vec![vec![a[0][0] * b[0][0]]];
    }

    let k = n / 2;

    // divide matrices into 4 parts each
    let mut a11 = vec![vec![0; k]; k];
    let mut a12 = vec![vec![0; k]; k];
    let mut a21 = vec![vec![0; k]; k];
    let mut a22 = vec![vec![0; k]; k];

    let mut b11 = vec![vec![0; k]; k];
    let mut b12 = vec![vec![0; k]; k];
    let mut b21 = vec![vec![0; k]; k];
    let mut b22 = vec![vec![0; k]; k];

    // fill sub matrices
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

    // compute the 7 products (core idea of Strassen)
    let p1 = strassen(&a11, &subtract(&b12, &b22));
    let p2 = strassen(&add(&a11, &a12), &b22);
    let p3 = strassen(&add(&a21, &a22), &b11);
    let p4 = strassen(&a22, &subtract(&b21, &b11));
    let p5 = strassen(&add(&a11, &a22), &add(&b11, &b22));
    let p6 = strassen(&subtract(&a12, &a22), &add(&b21, &b22));
    let p7 = strassen(&subtract(&a11, &a21), &add(&b11, &b12));

    // merge partial results into final quadrants
    let c11 = add(&subtract(&add(&p5, &p4), &p2), &p6);
    let c12 = add(&p1, &p2);
    let c21 = add(&p3, &p4);
    let c22 = subtract(&subtract(&add(&p1, &p5), &p3), &p7);

    let mut c = vec![vec![0; n]; n];

    // place each quadrant into result matrix
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

fn main() {
    // sample 4 x 4 matrix input
    let a = vec![
        vec![1, 2, 3, 4],
        vec![5, 6, 7, 8],
        vec![9, 10, 11, 12],
        vec![13, 14, 15, 16],
    ];

    let b = vec![
        vec![17, 18, 19, 20],
        vec![21, 22, 23, 24],
        vec![25, 26, 27, 28],
        vec![29, 30, 31, 32],
    ];

    // perform strassen multiplication
    let result = strassen(&a, &b);

    println!("Resulting Matrix:");

    // print matrix row by row
    for row in result {
        println!("{:?}", row);
    }
}
