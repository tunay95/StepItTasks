
#region Task

/*
1. Article (Məhsul) strukturu təsvir edin, hansı ki, aşağıdakı sahələri ehtiva edir:
- Məhsulun kodu (product code)
- Məhsulun adı (product name)
- Qiymət (price)

2. Client (Müştəri) strukturu təsvir edin, hansı ki, aşağıdakı sahələri ehtiva edir:
- Müştəri kodu (client code)
- Tam adı (full name)
- Ünvan (address)
- Telefon (telephone)
- Müştərinin sifarişlərinin sayı (number of orders by the client)
- Sifarişlərin ümumi məbləği (total amount of orders)

3. RequestItem (Sifariş Elementi) strukturu təsvir edin, hansı ki, aşağıdakı sahələri ehtiva
edir:
- Məhsul (commodity)
- Məhsul vahidlərinin sayı (number of commodity units)

4. Request (Sifariş) strukturu təsvir edin, hansı ki, aşağıdakı sahələri ehtiva edir:
- Sifariş kodu (order code)
- Müştəri (client)
- Sifariş tarixi (order date)
- Sifariş edilmiş məhsulların siyahısı (a list of ordered products)
- Sifarişin qiyməti (order price) — (Bu sahəni hesablanmış xassə (calculated property) ilə
həyata keçirin)

5. ArticleType (Məhsul Tipi) adlandırılmış tipini (enumeration) təsvir edin, hansı ki,
məhsulun növlərini müəyyən edir və 1-ci tapşırıqda qeyd olunan Article strukturuna uyğun
sahəni əlavə edin.

6. ClientType (Müştəri Tipi) adlandırılmış tipini (enumeration) təsvir edin, hansı ki,
müştərinin əhəmiyyətini (məsələn, adi müştəri, VIP müştəri) müəyyən edir və 2-ci
tapşırıqda qeyd olunan Client strukturuna uyğun sahəni əlavə edin.

7. PayType (Ödəniş Növü) adlandırılmış tipini (enumeration) təsvir edin, hansı ki,
müştərinin sifariş üçün ödəniş formasını müəyyən edir və 4-cü tapşırıqda qeyd olunan
Request strukturuna uyğun sahəni əlavə edin.
 */

#endregion


Article article1 = new()
{
	productCode = 1002,
	productName = "Apple",
	price = 12.2m,
	articleType = ArticleType.Food
};

Article article2 = new()
{
	productCode = 1003,
	productName = "Bed",
	price = 5400.0m,
	articleType = ArticleType.Furniture
};


Client client = new()
{
	clientCode = "CL1",
	clientFullname = "Tunay Huseynli",
	clientAddress = "Babek Highway 95",
	clientTelephone = "0502820377",
	clientOrderCount = 4,
	clientTotalAmountOrders = 10350
};

RequestItem requestItem = new()
{
	article = article1,
	commodityCount = 3
};

Request request = new()
{
	client = client,
	orderCode = "OC11",
	dateTime = DateTime.Now,
	orderedCommodities = new() { article1, article2 },
	payType=PayType.Card
};

Console.WriteLine(article1);
Console.WriteLine('\n');
Console.WriteLine(article2);
Console.WriteLine('\n');
Console.WriteLine(client);
Console.WriteLine('\n');
Console.WriteLine(requestItem);
Console.WriteLine('\n');
Console.WriteLine(request);


enum ArticleType
{
	Electronics,
	Furniture,
	Clothes,
	Food,
	Book
}

enum ClientType
{
	Ordinary,
	Vip
}

enum PayType
{
	Card,
	Cash
}


struct Article
{
	public int productCode;
	public string productName;
	public decimal price;
	public ArticleType articleType;
	public override string ToString()
	{
		return $@"Article:

Product Code: {productCode}
Product Name: {productName}
Product Price: {price}
Product Category: {articleType}";
	}
}

struct Client
{
	public string clientCode;
	public string clientFullname;
	public string clientAddress;
	public string clientTelephone;
	public int clientOrderCount;
	public decimal clientTotalAmountOrders;
	public ClientType clientType;
	public override string ToString()
	{
		return $@"Client:

Client Code: {clientCode}
Client Fullname: {clientFullname}
Client Address: {clientAddress}
Client Telephone: {clientTelephone}
Client Order Count: {clientOrderCount}
Total Amount Orders: {clientTotalAmountOrders}
Client Type: {clientType}";
	}
}

struct RequestItem
{
	public Article article;
	public int commodityCount;
	public override string ToString()
	{
		return $@"RequestItem:

{article}
----------
Commodity Count: {commodityCount}";
	}
}

struct Request
{
	public Client client;
	public string orderCode;
	public DateTime dateTime;
	public List<Article> orderedCommodities;
	public PayType payType;
	public decimal OrderPrice
	{
		get
		{
			return client.clientOrderCount * client.clientTotalAmountOrders;
		}
	}

	public void ShowOrderedCommodities()
	{
		for (int i = 0; i < orderedCommodities.Count; i++)
		{
			Console.WriteLine(orderedCommodities[i]);
		}
	}

	public override string ToString()
	{
		return $@"Request:

{client}
----------
Order Code: {orderCode}
Date-Time: {dateTime}
Payment Type: {payType}
Order Price: {OrderPrice}";
	}
}


