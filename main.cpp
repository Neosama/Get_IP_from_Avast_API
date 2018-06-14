
// Get IP info from AVAST API

#include <Windows.h>
#include <iostream>
#include <string>

// Rapidjson LIB
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "network.h"

using namespace rapidjson;
using namespace std;

int main()
{
	printf("GetIP from AVAST API\n\n");

	// API IP AVAST
	const char* url_avast = "ip-info.ff.avast.com";
	const char* useragent_avast = "Avast Emergency Update Agent";
	const char* path_url = "/v2/info";

	std::string output_json = http_request(url_avast, 80, useragent_avast, "GET", path_url, (char*)"", "");

	Document d;
	d.Parse(output_json.c_str());

	assert(d.IsObject());
	assert(d.HasMember("ip"));
	assert(d["ip"].IsString());
	printf("ip = %s\n", d["ip"].GetString());

	assert(d.HasMember("continent"));
	assert(d["continent"].IsString());
	printf("continent = %s\n", d["continent"].GetString());

	assert(d.HasMember("continentCode"));
	assert(d["continentCode"].IsString());
	printf("continentCode = %s\n", d["continentCode"].GetString());

	assert(d.HasMember("country"));
	assert(d["country"].IsString());
	printf("country = %s\n", d["country"].GetString());

	assert(d.HasMember("countryName"));
	assert(d["countryName"].IsString());
	printf("countryName = %s\n", d["countryName"].GetString());

	assert(d.HasMember("subdivisions"));
	assert(d["subdivisions"].IsArray());
	printf("subdivisions = %s %s\n", d["subdivisions"][0].GetString(), d["subdivisions"][1].GetString());

	assert(d.HasMember("city"));
	assert(d["city"].IsString());
	printf("city = %s\n", d["city"].GetString());

	assert(d.HasMember("timezone"));
	assert(d["timezone"].IsString());
	printf("timezone = %s\n", d["timezone"].GetString());

	assert(d.HasMember("latitude"));
	assert(d["latitude"].IsFloat());
	printf("latitude = %f\n", d["latitude"].GetFloat());

	assert(d.HasMember("longitude"));
	assert(d["longitude"].IsFloat());
	printf("longitude = %f\n", d["longitude"].GetFloat());

	assert(d.HasMember("isp"));
	assert(d["isp"].IsString());
	printf("isp = %s\n", d["isp"].GetString());

	assert(d.HasMember("asnNumber"));
	assert(d["asnNumber"].IsInt());
	printf("asnNumber = %i\n", d["asnNumber"].GetInt());

	assert(d.HasMember("asnOrganization"));
	assert(d["asnOrganization"].IsString());
	printf("asnOrganization = %s\n", d["asnOrganization"].GetString());

	assert(d.HasMember("organization"));
	assert(d["organization"].IsString());
	printf("organization = %s\n", d["organization"].GetString());

	assert(d.HasMember("postalCode"));
	assert(d["postalCode"].IsString());
	printf("postalCode = %s\n", d["postalCode"].GetString());

	getchar();
	return 0;
}