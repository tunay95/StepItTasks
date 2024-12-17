
#region Task

/*
"Veb-sayt" class-ı yaradın. Class-ın field-lərində aşağıdakı məlumatları saxlamaq lazımdır:

Saytın adı
Saytın ünvanı
Saytın təsviri
Saytın IP ünvanı

Class-ın metodlarını reallaşdırın:

Məlumatların daxil edilməsi üçün metod
Məlumatların ekrana çıxarılması üçün metod
Class-ın field-lərinin dəyərlərini almaq üçün üçün metodlar (hər bir field üçün ayrıca metod)

Bu tapşırığı iki variantda etmək lazımdır: Primary constructor ilə və Primary constructor-suz
*/

#endregion


//Website website = new("Globus", "www.globus.az", "Cografiya sevenlerin sayti", "192.168.1.1");
//Console.WriteLine(website);

//Website2 website2 = new("Globus", "www.globus.az", "Cografiya sevenlerin sayti", "192.168.1.1");
//Console.WriteLine(website2);



// With Primary Constructor

class Website(string siteName, string siteAddress, string siteDescription, string ipAddress)
{
	public string SiteName { get; set; } = siteName;
	public string SiteAddress { get; set; } = siteAddress;
	public string SiteDescription { get; set; } = siteDescription;
	public string IpAddress { get; set; } = ipAddress;

	public override string ToString()
	{
		return $@"Site Name: {SiteName}
Site Address: {SiteAddress}
Site Description: {SiteDescription}
Ip Address: {IpAddress}";
	}

}


// Without Primary Constructor

class Website2
{
	private string siteName;
	private string siteAddress;
	private string siteDescription;
	private string ipAddress;

	public Website2(string siteName, string siteAddress, string siteDescription, string ipAddress)
	{
		this.siteName = siteName;
		this.siteAddress = siteAddress;
		this.siteDescription = siteDescription;
		this.ipAddress = ipAddress;
	}

	public string GetSiteName() => siteName;
	public string GetSiteAddress() => siteAddress;
	public string GetSiteDescription() => siteDescription;
	public string GetIpAddress() => ipAddress;

	public override string ToString()
	{
		return $@"Site Name: {siteName}
Site Address: {siteAddress}
Site Description: {siteDescription}
Ip Address: {ipAddress}";
	}

}