// 1) getArrayBounds adlı bir funksiya yaradın. Bu funksiya massiv qəbul etməli və 
// 3 elementli yeni massiv qaytarmalıdır: [massivin uzunluğu, ilk element, son element].

// function getArrayBounds(arr){
//     if(typeof(arr)!="array") return null
//     return [arr.length, arr[0], arr[arr.length-1]]
// }

// let i = "salam"
// console.log(getArrayBounds([1,2,3]));




// 2) getSum adlı bir funksiya yaradın. Bu funksiya ədədlər massivini qəbul etməli və 
// bütün elementlərin cəmini qaytarmalıdır.

// function getSum(arr) {
//     let sum = 0

//     if (typeof (arr) != "object") return null
//     arr.forEach(element => {
//         if (typeof (element) != "number") return null
//         else sum += element
//     });

//     return sum
// }

// console.log(`Sum: ${getSum([1, 2, 3, 4, 5])}`);




// 3) getSpecialNumbers adlı funksiya yaradın. Bu funksiya m və n ədədləri arasındakı (daxil olmaqla)
//  3-ə tam bölünən ədədləri massiv şəklində qaytarmalıdır

// function getSpecialNumbers(start, end) {
//     let arr = []
//     if (start % 3 !== 0) start += 3 - start % 3

//     for (let i = start; i <= end; i += 3) {
//         arr.push(i)
//     }

//     return arr
// }

// console.log(getSpecialNumbers(21, 27));




// 4) swap adlı funksiya yaradın. Bu funksiya massiv qəbul etməli, 
// ilk elementi sonuncuya keçirməli və yeni massiv qaytarmalıdır.

// function swap(arr){
//     let first = arr[0]
//     const [arr[0], ...arr[arr.length-1]] = first
//     arr.push(temp)
// }




// 5.1) Massivdəki bütün sadə ədədləri tapın ( isPrime funksiyasını yaradın və massivi süzün ).

// let arr = [13,17,31,37,61,5,113,112]

// function isPrime(arr) {
//     const primeNumbers = arr.filter(number => {
//         let alert = 0
//         for (let i = 2; i < number; i++) {
//             if(number%i==0) alert+=1
//         }

//         if(alert>0) return false
//         return true
//     })

//     return primeNumbers
// }

// const primeNums = isPrime(arr)
// console.log(primeNums);


// 5.2) İkiölçülü massivi transpozisiya edin.

// const matrix = [
//   [1, 2],
//   [3, 4],
//   [5, 6]
// ];
// // => [[1, 3, 5], [2, 4, 6]]

// function transpose(matrix) {
//   let arr = []
//   let tempArr = []

//   for (let j = 0; j < matrix[j].length; j++) {
//     for (let i = 0; i < matrix.length; i++) {
//       tempArr.push(matrix[i][j])
//     }
//     arr.push(tempArr)
//     tempArr=[]
//   }

//   return arr
// }

// console.log(transpose(matrix));


// 5.3) Unikal dəyərlər Massivdən təkrarları çıxarın. (İpucu: new Set() və ya filter + indexOf)

// const arr = [1,2,2,3,4,5,5]

// const result = arr.filter()

// function duplicatedNums(element){
//   if(element.indexOf(element)) return element
// }




// 6) getSpecialNumbers adlı funksiya yaradın. Bu funksiya ədədlər massivini qəbul etməli və
// yalnız 3-ə tam bölünən elementlərdən ibarət yeni massiv qaytarmalıdır.

// let arr = [1, 5,2, 3, 25, 24, 27]

// function getSpecialNumbers(arr) {
//   let newArr=[]
//   for(let i = 0; i<arr.length;i++)
//     if (arr[i] % 3 === 0) newArr.push(arr[i]);

//   return newArr
// }

// console.log(getSpecialNumbers(arr))




// 7) sortDesc adlı funksiya yaradın. Bu funksiya verilmiş ədədlər massivini azalan sıra ilə sıralamalıdır.

function
