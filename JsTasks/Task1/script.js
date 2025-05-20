// Task 1
console.log("Task 1")


console.log("undefined + '5': ", undefined + '5');  // undefined5
console.log("null + 5: ", null + 5);    //5
console.log("true + 1: ", true + 1);    //2
console.log("false + 'false': ", false + 'false');  //falsefalse
console.log("10 - '2': ", 10 - '2');    //8
console.log("'5' * '2': ", '5' * '2');  //10
console.log("'10' / 2: ", '10' / 2);    //5
console.log("5 + 3 + '1': ", 5 + 3 + '1');  //81
console.log("'1' + 5 + 3: ", '1' + 5 + 3);  //153
console.log("10 % 3: ", 10 % 3);    //1
console.log("2 ** 3: ", 2 ** 3);    //8
console.log("5 == '5': ", 5 == '5');    //true
console.log("5 === '5': ", 5 === '5');  //false
console.log("null == undefined: ", null == undefined);  //true
console.log("undefined === null: ", undefined === null);    //false
console.log("typeof NaN: ", typeof NaN);    //number
console.log("!0: "+ !0);    //true
console.log("!!'text': "+ !!'text');    //true



//Task 2
console.log("\nTask 2")

console.log("17 to string is " + String(17));
console.log("-17.17 to string is "+ String(-17.17));
console.log("false to string is "+ String(false));
console.log("null to string is "+ String(null));                //Hamisi oldugu kimi qalir
console.log("undefined to string is "+ String(undefined));
console.log("0 to string is "+ String(0));

/* === */

console.log("\n'17' to number is " + Number('17'));              //17
console.log("true to number is " + Number('true'));              //Nan
console.log("false to number is " + Number('false'));            //Nan
console.log("null to number is " + Number('null'));              //Nan
console.log("undefined to number is " + Number('undefined'));    //Nan
console.log("'   20   ' to number is " + Number('   20   '));    //20
console.log("'      ' to number is " + Number('      '));        //0
console.log("'   30d   ' to number is " + Number('   30d   '));  //Nan

/* == */
console.log("\nnull to boolean is " + Boolean('null'));          //true
console.log("undefined to boolean is " + Boolean('undefined'));  //true
console.log("0 to boolean is " + Boolean('0'));                  //true
console.log("-0 to boolean is " + Boolean('-0'));                //true 
console.log("NaN to boolean is " + Boolean("NaN"));              //true 
console.log("'' to boolean is " + Boolean(''));                  //false
console.log("' ' to boolean is " + Boolean(' '));                //true
console.log("17 to boolean is " + Boolean('17'));                //true
console.log("'Hello' to boolean is " + Boolean('Hello'));        //true



//Task 3
console.log("\nTask 3")

/* ədədlərin müqayisəsi */

const a = 17;
const b = 5;
console.log("'a' > 'b': ", 'a' > 'b');      //true
console.log("'a' <= 'b': ", 'a' <= 'b');    //false
console.log("'a' == 'b': ", 'a' == 'b');    //false
console.log("'a' != 'b': ", 'a' != 'b');    //false

/* sətirlərin müqayisəsi */

console.log("\n'a' < 'b': ", 'a' < 'b');    //true
console.log("'ab' > 'a': ",'ab' > 'a');     //true

/* sərt (strict) müqayisə */

console.log("\n17 === 1: ", 17 === 1);                      //false
console.log("17 === 17: ", 17 === 17);17 === 17             //true
console.log("17 === '17': ", 17 === '17');                  //false
console.log("17 === true: ", 17 === true);17 === true;      //false
console.log("'0' === '': ", '0' === '');                    //false
console.log("true === false: ", true === false);            //false
console.log("true === true: ", true === true);              //true
console.log("null === undefined: ", null === undefined);    //false
console.log("false === 0: ", false === 0);                  //false

/* qeyri-sərt (non-strict) müqayisə */

console.log("\n17 == '17': ", 17 == '17');                  //true
console.log("'0' == '': ", '0' == '');                      //false
console.log("0 == '': ", 0 == '');                          //true
console.log("null == undefined: ", null == undefined);      //true
console.log("false == 0: ", false == 0);                    //true

/* diqqətli olun: null və undefined ilə işləyərkən */

console.log("\nundefined == null: ", undefined == null);    //true
console.log("undefined == 0: ", undefined == 0);            //false
console.log("null == 0: ", null == 0);                      //false
console.log("undefined < 0: ", undefined < 0);              //false
console.log("undefined > 0: ", undefined > 0);              //false


//Task 4
console.log("\nTask 4")

/* || (VƏ YA) operatoru */
console.log("\nfalse || true: ", false || true); // true
console.log("false || true || false: ", false || true || false); // true
console.log("false || false || false: ", false || false || false); // false

/* && (VƏ) operatoru */
console.log("\nfalse && true: ", false && true); // false
console.log("false && true && false: ", false && true && false); // false
console.log("true && true && true: ", true && true && true); // true

/* Məntiqi operatorlar istənilən tipdə verilənlərə tətbiq oluna bilər */

/* || birinci doğru (true) dəyəri tapır */
console.log("\n'text' || false: ", 'text' || false); // 'text'
console.log("true || 'text': ", true || 'text'); // true
console.log("undefined || null || 0 || '' || null: ", undefined || null || 0 || '' || null); // null

const customAmount = null;
const defaultAmount = 17;
const amount = customAmount || defaultAmount;
console.log("\namount: ", amount); // 17

/* && birinci yalan (false) dəyəri tapır */
console.log("\n'text' && false: ", 'text' && false); // false
console.log("true && 'text': ", true && 'text'); // 'text'
console.log("undefined && null && 0 && '' && null: ", undefined && null && 0 && '' && null); // undefined

/* İnkar operatoru (!) */
console.log("\n!true: ", !true); // false
console.log("!false: ", !false); // true
console.log("!'text': ", !'text'); // false
console.log("!!'text': ", !!'text'); // true



//Task 5
console.log("\nTask 5")

let age=18

if (true) console.log('\nI\'m in');

if (false) {
    console.log('I\'m not in');
}

if ('text') {
    console.log('Yes');
}

if (null) {
    console.log('Yes');
} else {
    console.log('Else');
}

if (age < 16) {
    console.log('Too young');
} else if (age >= 16 && age < 18) {
    console.log('Almost ready');
} else if (age >= 18 && age < 65) {
    console.log('Ready');
} else {
    console.log('Else');
}


// Ternar operatoru ? : ( const result = şərt ? dəyər1 : dəyər2; )

const amount2 = 17;

const result = amount2 > 17 ? 'full' : console.log('empty');
