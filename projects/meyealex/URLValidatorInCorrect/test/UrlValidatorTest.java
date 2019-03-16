

import junit.framework.TestCase;
import static org.junit.Assert.*;
import java.util.Random;
import org.junit.Test;
import java.lang.StringBuilder;
import java.nio.charset.StandardCharsets;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   //Manual Testing below

   public void testManualTest()
   {	   
      UrlValidtor urlVal = new URLValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      
      System.out.println("Manual Tests:");

      assertTrue(urlVal.isValid("http://www.google.com"));
      assertTrue(urlVal.isValid("httP://oregonstate.instructure.com"));
      assertTrue(urlVal.isValid("http://google.com"));
      assertTrue(urlVal.isValid("http://whois.nic.accenture/"));
      assertTrue(urlVal.isValid("http://www.google.com/t123"));

      assertFalse(urlVal.isValid("3ht://www,google.com"));
      assertFalse(urlVal.isValid("www.google.com"));
      assertFalse(urlVal.isValid("http://www.google.com/.."));
      assertFalse(urlVal.isValid("123ht://www.google.com"));
      assertFalse(urlVal.isValid("WWW.GOOGLE.COM"));
   
   
   }
   
   //Random Testing below

   @Test
	public void testIsValidRandom() {
		//String[] nullStr = {null,null};
		//RegexValidator regexGoogle = null; //RegexValidator will not work due to logic error preventing a deep dive into the code.
		//UrlValidator testGoogle = new UrlValidator(regexGoogle, UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.ALLOW_2_SLASHES);
		UrlValidator testGoogle = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.ALLOW_2_SLASHES);
		assertTrue("google", testGoogle.isValid("http://www.google.com"));
		System.out.println("Start-up test passed.");
		//Start Random Testing
		//Host name 1 to 63 characters should assert true
		String AlphaNumericSpString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" + "0123456789" + "abcdefghijklmnopqrstuvxyz" + "-_"; //excluded !@#$^&*()?/\\{}[],.<>:;%=+
		for(int j = 0; j < 100; j++) {
			Random r = new Random();
			int rand = r.nextInt(63 - 1 + 1) + 1; //Max tld is 63 characters
			// create StringBuffer size of AlphaNumericString 
			StringBuilder sbuff = new StringBuilder(rand + 12); 
			sbuff.append("http://www.");
			for (int i = 0; i < rand; i++) { 

				// generate a random number between 
				// 0 to AlphaNumericString variable length 
				int index = (int)(AlphaNumericSpString.length() * Math.random()); 

				// add Character one by one in end of sbuff 
				sbuff.append(AlphaNumericSpString.charAt(index)); 
			}
			sbuff.append(".com");
			System.out.println(rand);
			System.out.println(sbuff);
			UrlValidator testRand = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.ALLOW_2_SLASHES + UrlValidator.NO_FRAGMENTS);
			assertTrue("HOST IN RANGE 1 to 63", testRand.isValid(sbuff.toString()));
			sbuff.setLength(0);
		}
		System.out.println("Host name up to 63 characters passed.");
			//Host over 63 characters assert false
			for(int j = 0; j < 100; j++) {
				Random r = new Random();
				int rand = r.nextInt(128 - 64 + 1) + 64; //Max tld is 63 characters
				// create StringBuffer size of AlphaNumericString 
				StringBuilder sbuff = new StringBuilder(rand + 12); 
				sbuff.append("http://www.");
				for (int i = 0; i < rand; i++) { 

					// generate a random number between 
					// 0 to AlphaNumericString variable length 
					int index = (int)(AlphaNumericSpString.length() * Math.random()); 

					// add Character one by one in end of sbuff 
					sbuff.append(AlphaNumericSpString.charAt(index)); 
				}
				sbuff.append(".com");
				System.out.println(rand);
				System.out.println(sbuff);
				UrlValidator testRand = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.ALLOW_2_SLASHES + UrlValidator.NO_FRAGMENTS);
				//Assert false. To run all test switch to assertTrue as this is a bug
				assertFalse("HOST NAME OVER 63", testRand.isValid(sbuff.toString()));
				sbuff.setLength(0);
			}
			System.out.println("Host name over to 63 characters passed check.");
			//Check Domain Code is valid
			for(int j = 0; j < 50; j++) {
				Random r = new Random();
				int index = r.nextInt(247); 
				// create StringBuffer size of AlphaNumericString 
				StringBuilder sbuff = new StringBuilder(32); 
				sbuff.append("http://www.google."); 
				System.out.println(index);
				// add Character one by one in end of sbuff 
				sbuff.append(checkDomainCode[index]); 
				System.out.println(sbuff);
				UrlValidator testRand = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.ALLOW_2_SLASHES);
				assertTrue("Check TLD", testRand.isValid(sbuff.toString()));
				sbuff.setLength(0);
			}
			System.out.println("Domain Code Check Passed.");
			//Host name boundary test: 0 characters should assert false
			UrlValidator zero = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES + UrlValidator.ALLOW_2_SLASHES);
			//Assert false. To run all tests swtich to assertTrue as this is a bug.
			assertFalse("Check Zero Host", zero.isValid("http://www..jp"));
		}
	
	//TLD domain codes
	static final String[] checkDomainCode = new String[] {
			"com",
			"biz",
			"org",
			"net",
			"gov",
			"edu",
	        "ac",                 // Ascension Island
	        "ad",                 // Andorra
	        "ae",                 // United Arab Emirates
	        "af",                 // Afghanistan
	        "ag",                 // Antigua and Barbuda
	        "ai",                 // Anguilla
	        "al",                 // Albania
	        "am",                 // Armenia
	        "ao",                 // Angola
	        "aq",                 // Antarctica
	        "ar",                 // Argentina
	        "as",                 // American Samoa
	        "at",                 // Austria
	        "au",                 // Australia (includes Ashmore and Cartier Islands and Coral Sea Islands)
	        "aw",                 // Aruba
	        "ax",                 // Åland
	        "az",                 // Azerbaijan
	        "ba",                 // Bosnia and Herzegovina
	        "bb",                 // Barbados
	        "bd",                 // Bangladesh
	        "be",                 // Belgium
	        "bf",                 // Burkina Faso
	        "bg",                 // Bulgaria
	        "bh",                 // Bahrain
	        "bi",                 // Burundi
	        "bj",                 // Benin
	        "bm",                 // Bermuda
	        "bn",                 // Brunei Darussalam
	        "bo",                 // Bolivia
	        "br",                 // Brazil
	        "bs",                 // Bahamas
	        "bt",                 // Bhutan
	        "bv",                 // Bouvet Island
	        "bw",                 // Botswana
	        "by",                 // Belarus
	        "bz",                 // Belize
	        "ca",                 // Canada
	        "cc",                 // Cocos (Keeling) Islands
	        "cd",                 // Democratic Republic of the Congo (formerly Zaire)
	        "cf",                 // Central African Republic
	        "cg",                 // Republic of the Congo
	        "ch",                 // Switzerland
	        "ci",                 // Côte d'Ivoire
	        "ck",                 // Cook Islands
	        "cl",                 // Chile
	        "cm",                 // Cameroon
	        "cn",                 // China, mainland
	        "co",                 // Colombia
	        "cr",                 // Costa Rica
	        "cu",                 // Cuba
	        "cv",                 // Cape Verde
	        "cw",                 // Curaçao
	        "cx",                 // Christmas Island
	        "cy",                 // Cyprus
	        "cz",                 // Czech Republic
	        "de",                 // Germany
	        "dj",                 // Djibouti
	        "dk",                 // Denmark
	        "dm",                 // Dominica
	        "do",                 // Dominican Republic
	        "dz",                 // Algeria
	        "ec",                 // Ecuador
	        "ee",                 // Estonia
	        "eg",                 // Egypt
	        "er",                 // Eritrea
	        "es",                 // Spain
	        "et",                 // Ethiopia
	        "eu",                 // European Union
	        "fi",                 // Finland
	        "fj",                 // Fiji
	        "fk",                 // Falkland Islands
	        "fm",                 // Federated States of Micronesia
	        "fo",                 // Faroe Islands
	        "fr",                 // France
	        "ga",                 // Gabon
	        "gb",                 // Great Britain (United Kingdom)
	        "gd",                 // Grenada
	        "ge",                 // Georgia
	        "gf",                 // French Guiana
	        "gg",                 // Guernsey
	        "gh",                 // Ghana
	        "gi",                 // Gibraltar
	        "gl",                 // Greenland
	        "gm",                 // The Gambia
	        "gn",                 // Guinea
	        "gp",                 // Guadeloupe
	        "gq",                 // Equatorial Guinea
	        "gr",                 // Greece
	        "gs",                 // South Georgia and the South Sandwich Islands
	        "gt",                 // Guatemala
	        "gu",                 // Guam
	        "gw",                 // Guinea-Bissau
	        "gy",                 // Guyana
	        "hk",                 // Hong Kong
	        "hm",                 // Heard Island and McDonald Islands
	        "hn",                 // Honduras
	        "hr",                 // Croatia (Hrvatska)
	        "ht",                 // Haiti
	        "hu",                 // Hungary
	        "id",                 // Indonesia
	        "ie",                 // Ireland (Éire)
	        "il",                 // Israel
	        "im",                 // Isle of Man
	        "in",                 // India
	        "io",                 // British Indian Ocean Territory
	        "iq",                 // Iraq
	        "ir",                 // Iran
	        "is",                 // Iceland
	        "it",                 // Italy
	        "je",                 // Jersey
	        "jm",                 // Jamaica
	        "jo",                 // Jordan
	        "jp",                 // Japan
	        "ke",                 // Kenya
	        "kg",                 // Kyrgyzstan
	        "kh",                 // Cambodia (Khmer)
	        "ki",                 // Kiribati
	        "km",                 // Comoros
	        "kn",                 // Saint Kitts and Nevis
	        "kp",                 // North Korea
	        "kr",                 // South Korea
	        "kw",                 // Kuwait
	        "ky",                 // Cayman Islands
	        "kz",                 // Kazakhstan
	        "la",                 // Laos (currently being marketed as the official domain for Los Angeles)
	        "lb",                 // Lebanon
	        "lc",                 // Saint Lucia
	        "li",                 // Liechtenstein
	        "lk",                 // Sri Lanka
	        "lr",                 // Liberia
	        "ls",                 // Lesotho
	        "lt",                 // Lithuania
	        "lu",                 // Luxembourg
	        "lv",                 // Latvia
	        "ly",                 // Libya
	        "ma",                 // Morocco
	        "mc",                 // Monaco
	        "md",                 // Moldova
	        "me",                 // Montenegro
	        "mg",                 // Madagascar
	        "mh",                 // Marshall Islands
	        "mk",                 // Republic of Macedonia
	        "ml",                 // Mali
	        "mm",                 // Myanmar
	        "mn",                 // Mongolia
	        "mo",                 // Macau
	        "mp",                 // Northern Mariana Islands
	        "mq",                 // Martinique
	        "mr",                 // Mauritania
	        "ms",                 // Montserrat
	        "mt",                 // Malta
	        "mu",                 // Mauritius
	        "mv",                 // Maldives
	        "mw",                 // Malawi
	        "mx",                 // Mexico
	        "my",                 // Malaysia
	        "mz",                 // Mozambique
	        "na",                 // Namibia
	        "nc",                 // New Caledonia
	        "ne",                 // Niger
	        "nf",                 // Norfolk Island
	        "ng",                 // Nigeria
	        "ni",                 // Nicaragua
	        "nl",                 // Netherlands
	        "no",                 // Norway
	        "np",                 // Nepal
	        "nr",                 // Nauru
	        "nu",                 // Niue
	        "nz",                 // New Zealand
	        "om",                 // Oman
	        "pa",                 // Panama
	        "pe",                 // Peru
	        "pf",                 // French Polynesia With Clipperton Island
	        "pg",                 // Papua New Guinea
	        "ph",                 // Philippines
	        "pk",                 // Pakistan
	        "pl",                 // Poland
	        "pm",                 // Saint-Pierre and Miquelon
	        "pn",                 // Pitcairn Islands
	        "pr",                 // Puerto Rico
	        "ps",                 // Palestinian territories (PA-controlled West Bank and Gaza Strip)
	        "pt",                 // Portugal
	        "pw",                 // Palau
	        "py",                 // Paraguay
	        "qa",                 // Qatar
	        "re",                 // Réunion
	        "ro",                 // Romania
	        "rs",                 // Serbia
	        "ru",                 // Russia
	        "rw",                 // Rwanda
	        "sa",                 // Saudi Arabia
	        "sb",                 // Solomon Islands
	        "sc",                 // Seychelles
	        "sd",                 // Sudan
	        "se",                 // Sweden
	        "sg",                 // Singapore
	        "sh",                 // Saint Helena
	        "si",                 // Slovenia
	        "sj",                 // Svalbard and Jan Mayen Islands Not in use (Norwegian dependencies; see .no)
	        "sk",                 // Slovakia
	        "sl",                 // Sierra Leone
	        "sm",                 // San Marino
	        "sn",                 // Senegal
	        "so",                 // Somalia
	        "sr",                 // Suriname
	        "st",                 // São Tomé and Príncipe
	        "su",                 // Soviet Union (deprecated)
	        "sv",                 // El Salvador
	        "sx",                 // Sint Maarten
	        "sy",                 // Syria
	        "sz",                 // Swaziland
	        "tc",                 // Turks and Caicos Islands
	        "td",                 // Chad
	        "tf",                 // French Southern and Antarctic Lands
	        "tg",                 // Togo
	        "th",                 // Thailand
	        "tj",                 // Tajikistan
	        "tk",                 // Tokelau
	        "tl",                 // East Timor (deprecated old code)
	        "tm",                 // Turkmenistan
	        "tn",                 // Tunisia
	        "to",                 // Tonga
	        "tr",                 // Turkey
	        "tt",                 // Trinidad and Tobago
	        "tv",                 // Tuvalu
	        "tw",                 // Taiwan, Republic of China
	        "tz",                 // Tanzania
	        "ua",                 // Ukraine
	        "ug",                 // Uganda
	        "uk",                 // United Kingdom
	        "us",                 // United States of America
	        "uy",                 // Uruguay
	        "uz",                 // Uzbekistan
	        "va",                 // Vatican City State
	        "vc",                 // Saint Vincent and the Grenadines
	        "ve",                 // Venezuela
	        "vg",                 // British Virgin Islands
	        "vi",                 // U.S. Virgin Islands
	        "vn",                 // Vietnam
	        "vu",                 // Vanuatu
	        "wf",                 // Wallis and Futuna
	        "ws",                 // Samoa (formerly Western Samoa)
	   };
   

   //Unit Testing below
   
   public void testHttpSchemeWithValidUrl() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("http://wwww.google.com/test123"));
   }
   
   public void testHttpSchemeWithInvalidUrl() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("http://wwww.google.com/.."));
   }
   
   public void testFtpSchemeWithValidUrl() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("ftp://wwww.google.com/test123"));
   }
   
   public void testFtpSchemeWithInvalidUrl() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("ftp://wwww.google.com/.."));
   }
   
   public void testInvalidSchemeWithValidUrl() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("httfp://wwww.google.com/test123"));
   }
   public void testInvalidSchemeWithInvalidUrl() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("httfp://wwww.google.com/.."));
   }
   
   public void testValidUrlAuthWithValidUrl() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlVal.isValid("http://wwww.google.com/test123"));
   }
   
   public void testValidUrlAuthWithInvalidUrl() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("http://www.google.com/.."));
   }
   
   public void testInvalidUrlAuthWithValidUrl() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("http://1.2.3./test123"));
   }
   
   public void testInalidUrlAuthWithInvalidUrl() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlVal.isValid("http://1.2.3./.."));
   }
  
   


}
