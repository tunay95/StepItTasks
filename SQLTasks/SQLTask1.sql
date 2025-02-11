 -- [1] Bütün kitabların mövzularını göstərmək, lakin mövzu adları təkrarlanmasın.

 SELECT DISTINCT [Topic]
 FROM Books_En 


 -- [2] Kitabın kodunu, adını və 1 səhifəsinin qiymətini göstərmək.
 
 SELECT [Code], [Name], Price/Pages AS OnePagePrice
 FROM Books_En
 WHERE Pages <> 0


 -- [3] Peter" nəşriyyatından başqa istənilən nəşriyyat tərəfindən buraxılmış və qiyməti 20 rubl(dan) aşağı olan bütün kitabları göstərmək.

 SELECT *
 FROM Books_En
 WHERE Publisher NOT IN ('Peter') AND [Price] < 20
 ORDER BY [Price]


 -- [4] Peter" nəşriyyatından başqa istənilən nəşriyyat tərəfindən buraxılmış və qiyməti 20 ilə 40 rubl arasında olan bütün kitabları göstərmək.

 SELECT *
 FROM Books_En
 WHERE Publisher NOT IN ('Peter') AND [Price] BETWEEN 20 AND 40
 ORDER BY [Price]


 -- [5] Peter" nəşriyyatından başqa istənilən nəşriyyat tərəfindən buraxılmış və ya qiyməti 20 ilə 40 rubl arasında, ya da 10 rubldan az olan bütün kitabları göstərmək.

 SELECT *
 FROM Books_En
 WHERE Publisher NOT IN ('Peter') OR ([Price] BETWEEN 20 AND 40) OR [Price] < 10
 ORDER BY [Price]


 -- [6] Bir səhifəsinin qiyməti 10 qəpikdən az olan bütün kitabları göstərmək.

 SELECT [Name], [Code], [Price], [Pages], [Topic], [Publisher], [Category], [Price]/[Pages] AS OnePagePrice
 FROM Books_En
 WHERE [Price]/[Pages] < 0.1 AND Pages <> 0
 ORDER BY [OnePagePrice]


 -- [7] Ya dərslik, ya da "C&C++" mövzusunda olan və "Peter" və ya "DiaSoft" nəşriyyatı tərəfindən buraxılmış bütün kitabları göstərmək.
 
  SELECT [Name], [Code], [Price], [Pages], [Topic], [Publisher], [Category]
  FROM Books_En
  WHERE [Category] IN ('Tutorials','C&C++') AND [Publisher] IN ('Peter','DiaSoft')
  ORDER BY [Category]


 -- [8] Adında "Windows" sözü olan bütün kitabları göstərmək.

 SELECT * 
 FROM Books_En
 WHERE [Name] LIKE N'%Windows%'


 -- [9] Adında "Windows" sözü olan, lakin "Microsoft" sözü olmayan bütün kitabları göstərmək.

 SELECT * 
 FROM Books_En
 WHERE [Name] LIKE N'%Windows%' AND [Name] NOT LIKE N'%Microsoft%'


 -- [10] Adında ən azı bir rəqəm olan bütün kitabları göstərmək.

 SELECT * 
 FROM Books_En
 WHERE [Name] LIKE N'%[0-9]%'


 -- [11] Adında ən azı üç rəqəm olan bütün kitabları göstərmək.

 SELECT * 
 FROM Books_En
 WHERE [Name] LIKE N'%[0-9]%[0-9]%[0-9]%'

