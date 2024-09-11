const myArr = [0,1,2,3,4] // elements can be of different types and are resizable

// shallow copies : a copy of an element share the same reference
// deep copies : they dont ....

const arr = new Array(1,2,3,4);
// .push(element) adds number to the array at the end
// .pop() removes last element in the array
// .shift() removes first
// .unshift(element) adds element at first
// .includes(element) checks if the number is present in array (true/false)
// .indexOf(element) gives the index of element, if doesnt exist then -1
// .join() adds all the elements of array in a string along with commas
// .slice(start, end) here the end is not included, slips the array but doesnt change the original array
// .splice(start, end) end is included and splits the array with the original array not containing values in the range
// and returns removed range