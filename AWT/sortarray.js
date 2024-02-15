let numbers = [4, 2, 5, 1, 3];

numbers.sort((a, b) => a - b);

console.log("Sorted array in ascending order:", numbers);


numbers.sort((a, b) => b - a);


console.log("Sorted array in descending order:", numbers);