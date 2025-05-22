// 1) İki ədədi toplayan funksiya yaradın.

// function sum(a,b){
//     return a + b
// }

// let a = parseInt(prompt("Enter First Argument: ")) 
// let b = parseInt(prompt("Enter Second Argument: ")) 

// console.log("Sum: ", sum(a,b))




// 2) Konsola salamlaşma çıxaran bir funksiya yaradın.

// function sayHi(name){
//     console.log("Hi, ", name);
// }

// let name = prompt("Enter Your Name: ")

// sayHi(name)




// 3) Bir ədədin cüt və ya tək olduğunu müəyyən edən funksiya yaradın.

// function getEvenOdd(number){
//     if(number === 0) console.log("Zero's Neither Even, Nor Odd.");
//     else if(number%2==1) console.log("Odd");
//     else console.log("Even");
// }

// let number = parseInt(prompt("Enter Number: "))

// getEvenOdd(number)




// 4) Bir ədədin kvadratını qaytaran funksiya yaradın.

// square = (number) => console.log("Square: ", number ** 2);
 
// let number = parseInt(prompt("Enter Number: ")) 

// square(number)




// 5) İki ədəd qəbul edən bir funksiya yaz. Əgər hər ikisi ədəddirsə, cəmini qaytarsın.
//  Əks halda, "Yanlış dəyərlər daxil edilib" mesajı qaytarsın. 

// isNumber = (num1, num2) => {
//     if(typeof(num1) == "number" && typeof(num2) == "number")  console.log(`Sum: ${num1} + ${num2} = ${num1 + num2}`);
//     else console.log("Invalid Values Entered.");
// }

// isNumber(1,2)
// isNumber(1,"2")
// isNumber("1",2)kişi tunay
// isNumber("1","2")




// 6) İstifadəçinin adını parametr kimi qəbul edən bir funksiya yaz.
//  Əgər ad varsa, "Salam [ad]" mesajı çıxarsın, əks halda "İstifadəçi tapılmadı" yazsın.

// sayWelcome = (name) => {
//    if(name && typeof(name) == "String") console.log("Welcome, ", name);
//    else console.log("User not found.");
// }

// let name = prompt("Enter Your Name: ")

// sayWelcome(name)




// 7) Verilmiş yaşa görə istifadəçinin yetkin (18 və yuxarı) olub-olmadığını müəyyən edən funksiya yaz.
//  Nəticəni true və ya false olaraq qaytar.

// isAdult = (age) => age >= 18

// let age = parseInt(prompt("Enter Your Age: "))

// console.log("You're adult: ", isAdult(age));




// 8) Ad, soyad və yaş qəbul edən funksiya yaz. Əgər bütün məlumatlar daxil edilibsə, tam cümlə qaytarsın.
//  Əgər yaş yoxdursa, onu qeyd etmədən yalnız ad və soyadı göstərsin. Əgər heç biri yoxdursa, "Məlumat yoxdur" mesajı ver.

// userInfo = (name, surname, age) => {
//     if(name && surname) { 
//         console.log(`My name's ${name} ${surname} `);
//         if(age) console.log(`and I'm ${age} years old.`);
//     }

//     else console.log("No Information");
// }

// let name = prompt("Enter Your Name: ")
// let surname = prompt("Enter Your Surname: ")
// let age = parseInt(prompt("Enter your Age: "))

// userInfo(name, surname, age)




// 9) Ədədi qəbul edən və onun müsbət, mənfi və ya sıfır olduğunu təyin edən funksiya yaz.
//  Müvafiq mesaj qaytarsın: “Müsbət ədəd”, “Mənfi ədəd” və ya “Sıfır”.

// isPositiveNegativeZero = (number) => {
//     if(number > 0) console.log("Positive Number.");
//     else if(number < 0) console.log("Negative Number.");
//     else console.log("Zero.");
// }

// let number = parseInt(prompt("Enter Number: "))

// isPositiveNegativeZero(number)




// 10) Adı qəbul edən və onun uzunluğunu yoxlayan funksiya yaz.
//  Əgər ad 5 simvoldan uzundursa, “Uzun ad”, əks halda “Qısa ad” mesajı qaytarsın.

// checkName = (name) => {
//     console.log("The Length of The Name: ",name.length);
    
//     if(name.length > 5)  console.log("Long Name");
//     else  console.log("Short Name");
// }

// let name = prompt("Enter Name: ")

// checkName(name)

