class Sorting:
    @staticmethod
    def merge_sort(arr):
        n = len(arr)

        if n == 1:
            return arr

        m = len(arr) // 2
        L = arr[:m]
        R = arr[m:]

        L = Sorting.merge_sort(L)
        R = Sorting.merge_sort(R)
        l, r = 0, 0
        L_len = len(L)
        R_len = len(R)

        sorted_arr = [0] * n
        i = 0

        while l < L_len and r < R_len:
            if L[l] < R[r]:
                sorted_arr[i] = L[l]
                l += 1
            else:
                sorted_arr[i] = R[r]
                r += 1

            i += 1

        while l < L_len:
            sorted_arr[i] = L[l]
            l += 1
            i += 1

        while r < R_len:
            sorted_arr[i] = R[r]
            r += 1
            i += 1

        return sorted_arr
