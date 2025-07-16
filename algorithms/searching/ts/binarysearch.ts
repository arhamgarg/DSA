/**
 * @file binarysearch.ts
 * @description Provides User binary search
 * @author JestiferHarold
 * @created 2025-07-15
 * 
 * This File Includes:
 * - binary search
 */

/**
 * function to search a target in the array by dividing the array in half every iteration. Binary Search
 * @param array the integer array 
 * @param target the target to be found
 * @returns index of the target in the array if found, else -1
 */
function binarySearch(array: number[], target: number): number {
    let low: number = 0;
    let high: number = array.length - 1;
    let mid: number;

    while (high >= low) {
        mid = low + Math.floor((high - low) / 2);

        if (array[mid] == target)
            return mid;
    
        if (array[mid] > target)
            high = mid - 1;

        else 
            low = mid + 1;
    }

    return -1;
}

export {
    binarySearch    
}