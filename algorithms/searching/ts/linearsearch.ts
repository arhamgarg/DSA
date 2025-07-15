/**
 * @file linearsearch.ts
 * @description Provides User linear search
 * @author JestiferHarold
 * @created 2025-07-15
 * 
 * This File Includes:
 * - linear search
 */

/**
 * Searches the target element in a linear format
 * @param array integer array which is to be searched
 * @param n number of elements in the integer array
 * @param target the target that is to be found in the integer array
 * @returns the index of the target in the array if present, else -1
 */
function linearSearch(array: number[], n: number, target: number): number {
    for (let i: number = 0; i < n; i ++) {
        if (array[i] == target) {
            return i;
        }
    }
    
    return -1;
}

export {
    linearSearch
}