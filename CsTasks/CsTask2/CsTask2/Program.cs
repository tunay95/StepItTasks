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


// With Primary Constructor

class Website(string siteName, string siteAddress, string siteDescription, string ipAddress)
{
    public string SiteName { get=>siteName; set=>siteName=value; }
    public string SiteAddress { get=> siteAddress; set=> siteAddress = value; }
    public string SiteDescription { get=> siteDescription; set=> siteDescription = value; }
    public string IpAddress { get=> ipAddress; set=> ipAddress = value; }

	public override string ToString()
	{
		return $"Site Name: {siteName}";
	}

	public void InputData()
    {

    }
}

