package main

func linearSearch(arr []int , target int) int{
	for i:=0;i<len(arr);i++{
		if(arr[i] == target){
			return i;
		}
	}
	return -1;
}
