// 1) 1-dən n-ə qədər ədədlərin cəmini hesablayın.

// let sum = 0
// let borderNum;

// do{
//     borderNum = parseInt(prompt("Enter Border Number: "))           // normalda const verecekdim sadece daxil edilen ededin 100-200 arasinda olmadigi halda yeniden daxil edilmesi ucun mecbur let ile yazdim.
// }
// while(borderNum>200 || borderNum<100)

// const n = borderNum

// for(let i=1; i<=n; i++){
//     sum+=i
// }

// console.log(`Sum: ${sum}`)




// 2) m-dən n-ə qədər bütün tək ədədlərin hasilini hesablayın.

// let result = 1
// let start;
// let end;

// do{
//     start = parseInt(prompt("Enter Start Number: "))   
//     end = parseInt(prompt("Enter End Number: "))   
// }
// while(start>0 && end>start)

// const m = start
// const n = end

// for(let i = m; i <= n; i+=2 ){
//     if(i%2==0) i++
//     result *= i
// }
    
// console.log(`Result: ${result}`);




// 3) Vurma cədvəli.

// for(let i = 1; i <= 5; i++){

//     console.log(`=>${i}<=`);
//     for(let j = 1; j <= 9; j++){
//         console.log(`${i} x ${j} = ${i*j}`);
//     }
//     console.log("\n");
// }