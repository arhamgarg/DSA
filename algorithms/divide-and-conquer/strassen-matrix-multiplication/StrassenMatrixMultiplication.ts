class StrassenMatrixMultiplication {
	private add(A: number[][], B: number[][]): number[][] {
		const n: number = A.length;
		const C: number[][] = Array.from({ length: n }, () => new Array(n).fill(0));

		for (let i = 0; i < n; i++) {
			for (let j = 0; j < n; j++) {
				C[i][j] = A[i][j] + B[i][j];
			}
		}

		return C;
	}

	private subtract(A: number[][], B: number[][]): number[][] {
		const n: number = A.length;
		const C: number[][] = Array.from({ length: n }, () => new Array(n).fill(0));

		for (let i = 0; i < n; i++) {
			for (let j = 0; j < n; j++) {
				C[i][j] = A[i][j] - B[i][j];
			}
		}
        
		return C;
	}

	public strassen(A: number[][], B: number[][]): number[][] {
		const n: number = A.length;

		if (n === 1) {
			return [[A[0][0] * B[0][0]]];
		}

		const k: number = n / 2;

		const A11: number[][] = Array.from({ length: k }, () => new Array(k));
		const A12: number[][] = Array.from({ length: k }, () => new Array(k));
		const A21: number[][] = Array.from({ length: k }, () => new Array(k));
		const A22: number[][] = Array.from({ length: k }, () => new Array(k));

		const B11: number[][] = Array.from({ length: k }, () => new Array(k));
		const B12: number[][] = Array.from({ length: k }, () => new Array(k));
		const B21: number[][] = Array.from({ length: k }, () => new Array(k));
		const B22: number[][] = Array.from({ length: k }, () => new Array(k));

		for (let i = 0; i < k; i++) {
			for (let j = 0; j < k; j++) {
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + k];
				A21[i][j] = A[i + k][j];
				A22[i][j] = A[i + k][j + k];

				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + k];
				B21[i][j] = B[i + k][j];
				B22[i][j] = B[i + k][j + k];
			}
		}

		const P1: number[][] = this.strassen(A11, this.subtract(B12, B22));
		const P2: number[][] = this.strassen(this.add(A11, A12), B22);
		const P3: number[][] = this.strassen(this.add(A21, A22), B11);
		const P4: number[][] = this.strassen(A22, this.subtract(B21, B11));
		const P5: number[][] = this.strassen(
			this.add(A11, A22),
			this.add(B11, B22),
		);
		const P6: number[][] = this.strassen(
			this.subtract(A12, A22),
			this.add(B21, B22),
		);
		const P7: number[][] = this.strassen(
			this.subtract(A11, A21),
			this.add(B11, B12),
		);

		const C11: number[][] = this.add(this.subtract(this.add(P5, P4), P2), P6);
		const C12: number[][] = this.add(P1, P2);
		const C21: number[][] = this.add(P3, P4);
		const C22: number[][] = this.subtract(
			this.subtract(this.add(P1, P5), P3),
			P7,
		);

		const C: number[][] = Array.from({ length: n }, () => new Array(n));

		for (let i = 0; i < k; i++) {
			for (let j = 0; j < k; j++) {
				C[i][j] = C11[i][j];
				C[i][j + k] = C12[i][j];
				C[i + k][j] = C21[i][j];
				C[i + k][j + k] = C22[i][j];
			}
		}

		return C;
	}
}

export { StrassenMatrixMultiplication };
