class Searching {
    static int LinearSearch(List<int> array, int target) {
        int n = array.length;

        for (int i = 0; i < n; i ++) {
            if (array[i] == target) {
                return i;
            }
        }        

        return -1;
    }
}