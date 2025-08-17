class Searching:
    @staticmethod
    def binary_search(self, arr, target):
        N = len(arr)
        L = 0
        R = N - 1

        while L <= R:
            M = L + ((R - L) // 2)

            if arr[M] == target:
                return True
            elif target < arr[M]:
                R = M - 1
            else:
                L = M + 1

        return False
