const arr = [1,2,3,4,5,6]
const newarr = arr.filter((num) => num > 2)
console.log(newarr)

const nums = arr.map((i) => i*10).map((i) => i+1).filter((i) => i>50) // we chain a lot
console.log(nums)

//reduce function :

// const arr1 = [1,2,3,4]
// const initalValue = 0
// const sum = arr1.reduce(
//     (accumulator, currentValue) => accumulator+currentValue, initialValue
// );

// reduce function has accumulator and currentValue
// accumulator is an empty variable, when you give an inital value it is sent inside the accumulator
// the sum of accumulator and currentValue is sent in the accumulator in the iterations

const total = arr.reduce(function(acc, currentValue){
    return acc+currentValue;
}, 0) // 0 is the initial value and currentValue will have the values of array in iteration