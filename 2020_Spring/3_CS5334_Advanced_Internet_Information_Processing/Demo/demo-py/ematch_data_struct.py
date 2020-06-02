
usNeighborRegions = {
   "atlantic coast": {"atlantic coast":0, "east": 10, "northeast": 5, "north east": 5, "south": 50,"southeast":5, "south east": 5},
   "east":           {"east": 0, "atlantic coast":0,"new england":0,"north":50,"northeast": 0,\
				"north east":0, "south": 50, "southeast":0, "south east": 0},
   "great lakes":    {"great lakes":0,"middle east":20,"north":0},
   "middle":         {"middle":0,"middle east": 20, "middle west": 20},
   "middle east":    {"middle east":0,"middle": 20},
   "middle west":    {"middle west":0,"mountain": 20, "north":20, "northwest":20, "west":20},
   "mountain":       {"mountain":0, "middle west":10,"north":20, "northwest":20, "north west":20},
   "new england":    {"new england":0,"atlantic coast":30, "east": 50, "north east": 10, "northeast":10},
   "north":          {"north":0,"atlantic coast":50,"east":50,"great lakes":0,"middle":30,"middle east":30, \
			"middle west":30,"mountain":10,"new england":0,"northeast":0,"northwest":0,"north west":0, \
			"north east":0,"pacific coast":50, "pacific": 50, "west": 50},
   "northeast":      {"northeast":0, "north east":0,"atlantic coast":50,"east":40,"new england":0,"north":50},
   "north east":     {"north east":0, "northeast":0,"atlantic coast":50,"east":40,"new england":0,"north":50},
   "northwest":      {"northwest":0, "north west":0,"middle west":20,"mountain":20,"north":50,"pacific":50,"pacific coast":50,"west":50},
   "north west":      {"north west":0, "northwest":0,"middle west":20,"mountain":20,"north":50,"pacific":50,"pacific coast":50,"west":50},
   "pacific":        {"pacific":0,"north":50,"northwest":10,"pacific coast":0,"pacific west":0,"west":5},
   "pacific coast":  {"pacific coast":0,"north":50,"northwest":10,"pacific":0,"pacific west":0,"west":5},
   "pacific west":   {"pacific west":0,"pacific coast":0,"north":50,"northwest":20,"pacific":0,"west":5},
   "south":          {"south":0,"atlantic coast":50,"east":50,"middle":30,"middle east":30, \
			"southeast":0,"south east":0, "southwest":0, "south west":0, "west": 50},
   "southeast":      {"southeast":0, "south east":0,"atlantic coast":30,"east":10,"south":50},
   "south east":     {"southeast":0, "south east":0,"atlantic coast":30,"east":10,"south":50},
   "southwest":      {"southwest":0,"south west":0,"middle":30,"south":50},
   "south west":     {"southwest":0,"south west":0,"middle":30,"south":50},
   "west":           {"west":0, "north": 50, "northwest":0, "pacific":0,"pacific coast":0, "south": 50}
}

usRegionsNoOverlappingList = {
	"atlantic coast": {"southwest":0, "south west":0}
}
usStatesInRegions = {
   "atlantic coast": ["florida","georgia","maryland","new jersey","north carolina", "south carolina", "virginia"],
   "east":            ["connecticut","florida","georgia","maine","maryland","massachusetts","new hampshire","new jersey","new york","north carolina","pennsylvania","rhode island","south carolina","vermont", "virginia","west virginia"],
   "great lakes":     ["illinois","indiana","michigan","new york","ohio","wisconsin"],
   "middle":          ["iowa","kansas","missouri","nebraska","oklahoma","south datoka"],
   "middle east":     ["illinois","indiana","kentucky","Missouri","tennessee"],
   "middle west":     ["colorado","idaho","neveda","utah","wyoming"],
   "mountain":        ["colorado","idaho","montana","neveda","utah","wyoming"],
   "new england":     ["connecticut","maine","massachusetts","new hampshire","rhode island","vermont"],
   "north":           ["connecticut","idaho","indiana","illinois","iowa","maine","massachusetts","michigan","minnesota","montana","new hampshire","new jersey","new york","north dakota","ohio","oregon","pennsylvania","rhode island","south dakota","utah","vermont","washington","wyoming"],
   "northeast":       ["connecticut","maine","maryland","massachusetts","new hampshire","new jersey","new york","pennsylvania","rhode island","vermont"],
   "north east":       ["connecticut","maine","maryland","massachusetts","new hampshire","new jersey","new york","pennsylvania","rhode island","vermont"],
   "northwest":       ["idaho","oregon","washington"],
   "north west":       ["idaho","oregon","washington"],
   "pacific":         ["california","hawaii","oregon","washington"],
   "pacific coast":   ["california","oregon","washington"],
   "pacific west":   ["california","oregon","washington"],
   "south":           ["alabama","arizona","arkansas","florida","georgia","louisiana","mississippi","new mexico","oklahoma","south carolina","tennessee","texas"],
   "southeast":       ["alabama","florida","georgia","mississippi","south carolina"],
   "south east":       ["alabama","florida","georgia","mississippi","south carolina"],
   "southwest":       ["arizona","arkansas","new mexico","oklahoma","texas"],
   "south west":       ["arizona","arkansas","new mexico","oklahoma","texas"],
   "west":            ["california","arizona","idaho","nevada","oregon","utah","washington"]

}

usCitiesInStates = {

   "alabama":      ["mobile"],
   "alaska":       ["anchorage"],
   "arizona":      ["phoenix", "tempe", "tucson"],
   "arkansas":     ["little rock"],
   "california":   ["cupertino", "fremont", "haywood", "los angeles", "milpitas", \
	   "mountain view", "oakland", "palo alto", "sacramento", \
	   "san diego", "san francisco", "san jose", "santa clara", \
	   "sunnyvale"],
   "colorado":     ["colorado springs", "denver"],
   "connecticut":  ["hartford"],
   "delaware":     ["wilmington"],
   "florida":      ["miami", "orlando", "tampa bay"],
   "georgia":      ["atlanta"],
   "hawaii":       ["honolulu"],
   "idaho":        ["boise"],
   "illinois":     ["chicago"],
   "indiana":      ["indianapolis"],
   "iowa":         ["des moines"],
   "kansas":       ["wichita"],
   "Kentucky":     ["lexington", "louisville"],
   "louisiana":    ["new orleans"],
   "maine":        ["augusta"],
   "maryland":     ["baltimore"],
   "massachusetts":["boston"],
   "michigan":     ["detroit"], 
   "minnesota":    ["minneapolis"],
   "mississippi":  ["jackson"],
   "missouri":     ["kansas city", "st louis"],
   "montana":      ["great falls"],
   "nebraska":     ["lincoln", "omaha"],
   "nevada":       ["las vegas", "reno"],
   "new hampshire":["concord"],
   "new jersey":   ["newark", "morristown"],                   
   "new mexico":   ["albuquerque", "santa fe"],
   "new york":     ["albany", "buffalo", "new york","new york city", "syracuse"], 
   "north carolina":["charlotte", "raleigh"],
   "north dakota": ["brismrck"],
   "ohio":         ["cincinnati", "cleveland", "columbus", "dayton", "toledo"],
   "oklahoma":     ["oklahoma city", "tulsa"],
   "oregon":       ["portland", "hillsboro"],
   "pennsylvania": ["allentown", "harrisburg", "pittsburgh", "philadelphia"],
   "rhode island": ["providence"],
   "south carolina":["charleston", "columbia sc"],
   "south dakota": ["rapid city", "sioux falls"],
   "tennessee":    ["memphis", "nashville"], 
   "texas":        ["austin", "dallas", "fort worth", "houston", "san antonio"],
   "utah":         ["salt lake city"],
   "vermont":      ["burlington"],
   "virginia":     ["alexandria", "arlington", "richmond"],
   "washington":   ["seattle"],
   "west virginia":["charleston","morgan town"],
   "wisconsin":    ["green bay", "milwaukee"],
   "wyoming":      ["cheyenne","jackson holes"]

}
#print (neighborRegions,"\n")

usNeighborCities = {
   "albuquerque":          {"albuquerque":0,"el paso":20, "phoenix": 30, "sante fe": 5, "tucson": 25},
   "alexandria":           {"alexandria": 0, "washington":5, "baltimore":15, "richmond":20,"philedalphia":25},
   "alington":             {"alington":0,"alexandria": 5, "washington":5, "baltimore":15, "richmond":15,"philedalphia":25},
   "allentown":            {"allentown":0,"harrisburg":15,"philadelphia":10,"newark":15, "wilmington":20,"baltimore":25},
   "anchorage":            {"anchorage":0},
   "atlanta":              {"atlanta":0,"mobile":25,"columbia sc":30},
   "augusta":              {"augusta":0,"concord":20},
   "austin":               {"austin":0,"dallas":10,"el paso": 30, "san antonio":5,"houston":15},
   "baltimore":            {"baltimore":0, "alexandria":15, "harrisburg":15, "allentown":15, "washington": 10, "philadelphia":20, "wilmington": 20},
   "boise":                {"boise":0, "portland":30, "salt lake city": 30},
   "boston":               {"boston":0, "concord":10, "hartford":10, "providence":15},
   "broomfield":           {"broomfield":0},
   "buffalo":              {"buffalo":0, "syracuse":20, "pittsburgh":20},
   "burlington":           {"burlington":0},
   "charleston sc":        {"charleston sc":0, "columbia sc":20},
   "charleston wv":        {"charleston wv":0, "lexington":20, "columbus": 30},
   "charlotte":            {"charlotte": 0, "raleigh": 20, "columbia sc": 25},
   "chicago":              {"chicago": 0, "milwaukee": 15, "indianapolis": 20},
   "cincinnati":           {"cincinnati": 0, "dayton": 5, "columbus": 15, "lexington":10, \
				"indianapolis": 10, "louisville": 10},
   "cleveland":            {"cleveland": 0, "buffalo": 20, "columbus": 10, "pittsburgh": 15,"toledo": 5},
   "colorado springs":     {"colorado springs": 0, "denver": 5, "Albuqueque": 20},
   "columbia sc":          {"columbia sc": 0, "charleston sc": 15, "charlotte": 15},
   "columbus":             {"columbus": 0, "dayton": 5, "cincinnati": 10, "cleveland":25, \
				"indianapolis": 25, "toledo": 30},
   "concord":              {"concord": 0, "boston": 20, "hartford": 30, "providence": 30,"augusta": 30},
   "cupertino":            {"cupertino": 0, "fremont": 3, "san jose": 2, "sunnyvale": 1, \
                                "mountain view": 2, "santa clara": 1, "palo alto": 2, \
                                "milpitas": 2, "haywood": 4, "oakland": 8, \
                                "san francisco": 8, "sacramento": 15},
   "dallas":               {"dallas": 0, "austin": 10, "fort worth": 5, "houston": 15, "oklahoma city": 10, "san antonio": 20},
   "dayton":               {"dayton": 0, "cincinnati": 10, "columbus": 20, "indianapolis": 30,"toledo": 30},
   "denver":               {"denver": 0, "colorado springs": 20},
   "des moines":           {"des moines": 0, "kansas city": 30},
   "detroit":              {"detroit": 0, "toledo": 20},
   "el paso":              {"el paso": 0, "albuquerque": 30, "san antonio":60},
   "fort worth":           {"fort worth": 0, "austin":10, "dallas": 5, "houston": 15, "oklahoma city": 10},
   "fremont":              {"fremont": 0, "cupertino": 3, "san jose": 3, "sunnyvale": 3, \
                		"mountain view": 3, "santa clara": 3, "palo alto": 3, \
                		"milpitas": 3, "haywood": 2, "oakland": 6, \
                		"san francisco": 6, "sacramento": 14},
   "green bay":            {"green bay": 0, "milwaukee": 20, "chicago": 30},
   "harrisburg":           {"harrisburg": 0, "allentown": 20, "baltimore": 20, "washington": 30,\
				"philadelphia": 30, "pittsburgh": 35, "wilmington": 30},
   "hartford":             {"hartford": 0, "providence": 10, "boston": 20, "concord": 30},
   "haywood":              {"haywood": 0, "cupertino": 4, "san jose": 4, "sunnyvale": 4},
   "hillsboro":            {"hillsboro": 0, "portland": 5, "seattle": 35},
   "honolulu":             {"honolulu":0},
   "houston":              {"houston": 0, "austin": 10, "dallas": 15, "fort worth": 15, \
				"shreveport": 15, "san antonio": 10},
   "indianapolis":         {"indianapolis": 0,"louisville": 30, "cincinnati": 30, \
				"lexington": 35, "dayton": 30},
   "kansas city":          {"kansas city": 0, "st louis": 30, "wichita": 30, "omaha": 45,"lincoln": 45},
   "las vegas":            {"las vegas": 0, "los angeles": 30,"reno": 20},
   "lexington":            {"lexington": 0, "louisville": 10, "cincinnati": 20, \
				"nashville": 25, "memphis": 30, "charleston wv": 30},
   "lincoln":              {"lincoln": 0, "omaha": 10, "des moines": 40, "kansas city": 40},
   "little rock":          {"little rock": 0, "dallas": 20, "memphis": 30, "shreveport": 30},
   "los angeles":          {"los angeles": 0, "san diego": 20},
   "louisville":           {"louisville": 0, "lexington": 10, "cincinnati": 30, "indianapolis": 40},
   "memphis":              {"memphis": 0, "nashville": 30, "little rock": 30},
   "miami":                {"miami": 0, "orlando": 30, "tampa bay": 30},
   "milpitas":             {"milpitas": 0, "cupertino": 3, "san jose": 1, "sunnyvale": 2, \
				"mountain view": 3, "santa clara": 2, "palo alto": 3, "haywood": 4, \
				"fremont": 3, "oakland": 5, "san francisco": 7, "sacramento": 15},
   "milwaukee":            {"milwaukee": 0,"green bay": 30, "chicago": 30},
   "minneapolis":          {"minneapolis": 0},
   "mobile":               {"mobile": 0, "new orleans": 30},
   "morristown":           {"morristown": 0, "new york city": 10, "newark": 10, \
					"philadelphia": 30, "allentown": 30, "wilmington": 30},
   "mountain view":        {"mountain view": 0, "cupertino": 2, "san jose": 2, "sunnyvale": 1, \
				"milpitas": 2, "santa clara": 1, "palo alto": 1, "haywood": 5, \
				"fremont": 4, "oakland": 6, "san francisco": 7, "sacramento": 15},
   "nashville":            {"nashville": 0, "memphis": 30, "louisville": 40},
   "new orleans":          {"new orleans": 0, "mobile": 30, "houston": 40},
   "new york":             {"new york":0, "new york city": 0, "newark": 10, "morristown": 10, \
				"philadelphia": 30, "allentown": 30, "wilmington": 30},
   "newark":               {"newark": 0, "new york":10, "new york city": 10, "morristown": 10, \
				"philadelphia": 25, "allentown": 25, "wilmington": 25},
   "oakland":              {"oakland": 0, "cupertino": 8, "san jose": 8, "sunnyvale": 8, \
				"milpitas": 8, "santa clara": 8, "palo alto": 6, \
				"haywood": 4, "fremont": 5, "mountain view": 6, \
				"san francisco": 3, "sacramento": 10, "reno": 32},
   "oklahoma city":        {"oklahoma city": 0,"dallas": 20, "fort worth": 20, "tulsa": 30,"wichita": 40},
   "omaha":                {"omaha": 0, "lincoln": 10, "des moines": 30, "kansas city": 40},
   "orlando":              {"orlando": 0, "miami": 30, "tampa bay": 20},
   "palo alto":            {"palo alto": 0, "cupertino": 2, "san jose": 2, "sunnyvale": 1,  \
				"milpitas": 2, "santa clara": 1, "mountain view": 1, \
				"haywood": 4, "fremont": 2, "oakland": 6, \
				"san francisco": 6, "sacramento": 15},
   "philadelphia":         {"philadelphia": 0, "allentown": 10, "baltimore": 30,"wilmington": 10, \
				"morristown": 30, "newark":20, "new york city": 35,"harrisburg": 40},
   "phoenix":              {"phoenix": 0, "tempe": 0, "tucson": 10},
   "pittsburgh":           {"pittsburgh": 0, "cleveland": 30, "harrisburg": 40},
   "portland":             {"portland": 0, "hillsboro": 5, "seattle": 35},
   "providence":           {"providence": 0, "hartford": 5, "boston": 20, "concord": 30},
   "raleigh":              {"raleigh": 0, "charlotte": 25, "columbia sc": 25},
   "reno":                 {"reno": 0, "sacramento": 25, "las vegas": 30, "san francisco": 35, \
				"oakland": 32, "san jose": 38},
   "richmond":             {"richmond": 0, "alexandria": 20, "washington dc": 25, "raleigh": 30},
   "sacramento":           {"sacramento": 0, "reno": 35, "oakland": 10, "san jose": 15, \
				"san francisco": 13, "santa clara": 15, "palo alto": 15, "milpitas": 15,\
				"cupertino": 15, "sunnyvale": 15, "haywood": 13, "fremont": 14, \
				"mountain view": 15},
   "salt lake city":       {"salt lake city": 0, "reno": 40},
   "san antonio":          {"san antonio": 0, "austin": 5, "dallas": 20, "el paso": 30, "houston": 10},
   "san diego":            {"san diego": 0, "los angeles": 25},
   "saint louis":          {"saint louis": 0, "kansas city": 35},
   "san francisco":        {"san francisco": 0, "cupertino": 8, "san jose": 8, "sunnyvale": 8, \
				"milpitas": 8, "santa clara": 8, "palo alto": 6, "haywood": 4,
				"fremont": 5, "mountain view": 6,"oakland": 3,"sacramento": 13, "reno": 35},
   "san jose":             {"san jose": 0, "cupertino": 1,"mountain view": 2,"sunnyvale": 1,"milpitas": 1, \
				"santa clara": 1, "palo alto": 1, "haywood": 4, "fremont": 3,"oakland": 6, \
                		"san francisco": 7, "sacramento": 15, "reno": 38},
   "santa fe":             {"sante fe":0,"albuquerque":5,"el paso":20, "phoenix": 30, "tucson": 25},
   "santa clara":          {"santa clara": 0, "cupertino": 1, "mountain view": 1, "sunnyvale": 1, \
				"milpitas": 1, "san jose": 1, "palo alto": 2, "haywood": 4, "fremont": 3, \
				"oakland": 6, "san francisco": 7, "sacramento": 15},
   "st louis":             {"st louis": 0, "kansas city": 35},
   "seattle":              {"seattle": 0, "hillsboro": 35, "portland": 35},
   "shreveport":           {"shreveport": 0, "dallas": 40, "little rock": 40},
   "sunnyvale":            {"sunnyvale":0, "mountain view":1, "cupertino": 2, "san joso": 2,"milpitas": 2, \
				"santa clara": 1, "palo alto": 1, "haywood": 5, "fremont": 4,"oakland": 6, \
				"san francisco": 7, "sacramento": 15},
   "syracuse":             {"syracuse": 0, "albany": 20, "buffalo": 40},
   "tampa bay":            {"tampa bay": 0, "orlando": 20, "miami": 30},
   "tempe":                {"tempe": 0, "phoenix": 0, "tucson": 10},
   "toledo":               {"toledo": 0, "detroit": 30, "columbus": 30, "cleveland": 35, "dayton": 35},
   "tucson":               {"tucson": 0, "tempe": 0, "phoenix": 0},
   "tulsa":                {"tulsa":  0, "oklahoma city": 30, "kansas city": 20,"wichita": 40},
   "washington dc":        {"washington dc": 0, "alexandria": 5, "baltimore": 10, "harrisburg": 30, \
				"philadelphia":30, "wilmington": 30, "allentown":40,"washington": 0},
   "washington":           {"washington": 0, "alexandria": 5, "baltimore": 10, "harrisburg": 30, \
				"philadelphia":30, "wilmington": 30, "allentown": 40,"washington dc": 0},
   "wichita":              {"wichita": 0, "kansas city": 40, "oklahoma city": 40, "tulsa": 40},
   "wilmington":           {"wilmington":0,"allentown":30,"baltimore": 30, "harrisburg":40, "newark": 30, \
				"new york": 35, "philadelphia": 10}
}


usNeighborStates = {
   "alabama":    {"alabama":0, "florida":50, "georgia":40, "mississippi":30,"tennessee":40},
   "alaska":     {"alaska": 0},
   "arizona":    {"arizona": 0,"california":25,"colorado":30,"nevada":30,"new mexico":15,"utah":40},
   "arkansas":   {"arkansas": 0, "louisiana": 40, "mississippi": 40, "missouri": 30, "oklahoma": 40, \
                	"tennessee": 40, "texas": 40},
   "california": {"california": 0, "arizona": 30, "nevada": 30, "oregon": 40},
   "colorado":   {"colorado": 0, "arizona": 40, "kansas": 30, "nebraska": 30, "new mexico": 40, \
                	"oklahoma": 40, "utah": 30, "wyoming": 40},
   "connecticut":{"connecticut": 0, "massachusetts": 30, "new york": 40, "rhode island": 20},
   "delaware":   {"delaware": 0, "maryland": 30, "new jersey": 30, "pennsylvania": 40},
   "florida":    {"florida": 0, "alabama": 40, "georgia": 30},
   "georgia":    {"georgia": 0, "alabama": 30, "florida": 30, "north carolina": 40},
   "hawaii":     {"hawaii": 0},
   "idaho":      {"idaho": 0, "montana": 40, "nevada": 30, "oregon": 30, "utah": 30, "washington state": 40,\
			"wyoming": 40},
   "illinois":   {"illinois": 0, "indiana": 30, "iowa": 40, "missouri": 30, "kentucky": 40, "wisconsin": 40},
   "indiana":    {"indiana": 0, "illinois": 30, "kentucky": 40, "michigan": 35, "ohio": 30},
   "iowa":       {"iowa": 0, "illinois": 30, "minnesota": 40, "missouri": 30, "nebraska": 40, \
                	"south dakota": 40, "wisconsin": 40},
   "kansas":     {"kansas": 0, "colorado": 30, "missouri": 30, "nebraska": 30, "oklahoma": 30},
   "kentucky":   {"kentucky": 0, "illinois": 35, "indiana": 30, "missouri": 40, "ohio": 40, \
                	"tennessee": 20, "virginia": 50, "west virginia": 45},
   "louisiana":  {"louisiana": 0, "arkansas": 30, "mississippi": 30, "texas": 40},
   "maine":      {"maine": 0, "new hampshire": 30, "vermont": 40},
   "maryland":   {"maryland": 0, "delaware": 20, "virginia": 30, "pennsylvania": 35, "virginia": 30,\
                	"west virginia": 40},
   "massachusetts":{"massachusetts": 0, "connecticut": 20, "new hampshire": 25, "new york": 35,\
                	"rhode island": 20, "vermont": 25},
   "michigan":   {"michigan": 0, "indiana": 30, "ohio": 30},
   "minnesota":  {"minnesota": 0, "iowa": 30, "north dakota": 40, "south dakota": 40, "wisconsin": 30},
   "mississippi":{"mississippi": 0, "alabama": 30, "arkansas": 30, "louisiana": 30, "tennessee": 40},
   "missouri":   {"missouri": 0, "arkansas": 30, "kansas": 30, "illinois": 30, "iowa": 30, \
   			"nebraska": 40, "oklahoma": 40, "kentucky": 40, "tennessee": 45},
   "montana":    {"montana": 0, "idaho": 30, "north dakota": 40, "south dakota": 40, "wyoming": 30},
   "nebraska":   {"nebraska": 0, "colorado": 30, "kansas": 30, "iowa": 30, "missouri": 30, \
   			"south dakota": 35, "wyoming": 40},
   "nevada":     {"nevada": 0, "california": 30, "utah": 30, "arizona": 30, "idaho": 40, "oregon": 40},
   "new hampshire":{"new hampshire": 0, "maine": 30, "vermont": 20, "massachusetts": 20, \
                	"connecticut": 30, "rhode island": 30},
   "new jersey": {"new jersey": 0, "delaware": 20, "pennsylvania": 30, "new york": 30, "maryland": 30},
   "new mexico": {"new mexico": 0, "arizona": 30, "colorado": 30, "utah": 40, "texas": 40},
   "new york":   {"new york": 0, "new jersey": 30, "pennsylvania": 30, "massachusetts": 30, \
                	"connecticut": 30, "vermont": 30},
   "north carolina":{"north carolina": 0, "georgia": 20, "south carolina": 30, "virginia": 30, "tennessee": 35},
   "north dakota": {"north dakota": 0, "south dakota": 30, "montana": 40, "minnesota": 40},
   "ohio":       {"ohio": 0, "indiana": 30, "michigan": 30, "kentucky": 40, "pennsylvania": 35, "west virginia": 40},
   "oklahoma":   {"oklahoma": 0, "arkansas": 30, "kansas": 20, "missouri": 40, "texas": 30, "colorado": 50},
   "oregon":     {"oregon": 0, "idaho": 40, "california": 40, "nevada": 40, "washington state": 40},
   "pennsylvania":{"pennsylvania": 0, "delaware": 30, "maryland": 20, "new jersey": 30, \
                	"new york": 30,  "ohio": 30, "west virginia": 30},
   "rhode island":{"rhode island": 0, "massachusetts": 20, "connecticut": 10},
   "south carolina":{"south carolina": 0, "north carolina": 30, "georgia": 30},
   "south dakota":{"south dakota": 0, "north dakota": 30, "iowa": 40, "montana": 40, "nebraska":40, \
                	"wisconsin": 40, "wyoming": 40},
   "tennessee":   {"tennessee": 0, "arkansas": 30, "mississippi": 30, "alabama": 30, "georgia": 35, \
                	"north carolina": 40, "virginia": 45, "kentucky": 20, "missouri": 40},
   "texas":       {"texas": 0, "new mexico": 40, "oklahoma": 30, "louisiana": 30, "arkansas": 40},
   "utah":        {"utah": 0, "arizona": 40, "colorado": 30, "nevada": 30, "idaho": 40, "wyoming": 40,\
                	"new mexico": 45},
   "vermont":     {"vermont": 0, "new york": 30, "new hampshire": 20, "massachusetts": 20},
   "virginia":    {"virginia": 0, "maryland": 20, "west virginia": 30, "north carolina": 30,\
                	"tennessee": 40, "kentucky": 40},
   "washington":  {"washington": 0, "oregon": 30, "idaho": 40},
   "west virginia": {" west virginia": 0, "virginia": 30, "ohio": 30, "pennsylvania": 30, "kentucky": 40},
   "wisconsin":   {"wisconsin": 0, "minnesota": 30, "iowa": 30, "illinois": 30},
   "wyoming":     {"wyoming": 0, "utah": 30, "colorado": 30, "idaho": 30, "nebraska": 30, "montana": 30, \
                	"south dakota": 40}
}

usStatesPrimaryRegion = {
   "alabama":        ["southeast", "east"],
   "alaska":         ["northwest"],
   "arizona":        ["southwest","south west"],
   "arkansas":       ["southwest", "south west","south"],
   "california":     ["pacific coast","pacific west", "pacific", "west"],
   "colorado":       ["mountain"],
   "connecticut":    ["northeast", "north east", "new england", "atlantic coast", "east"],
   "delaware":       ["atlantic coast", "east"],
   "florida":        ["southeast", "south east", "east"],
   "georgia":        ["southeast", "south east", "atlantic coast", "east"],
   "hawaii":         ["pacific"],
   "idaho":          ["mountain", "north"],
   "illinois":       ["north", "great lakes"],
   "indiana":        ["north"],
   "iowa":           ["middle", "north"],
   "kansas":         ["middle"],
   "kentucky":       ["east", "middle east"],
   "louisiana":      ["south"],
   "maine":          ["north east", "northeast", "new england", "east"],
   "maryland":       ["atlantic coast", "east"],
   "massachusetts":  ["north east", "northeast", "new england", "east"],
   "michigan":       ["north", "great lakes"],
   "minnesota":      ["north", "great lakes"],
   "mississippi":    ["southeast", "south east", "south"],
   "missouri":       ["middle"],
   "montana":        ["mountain", "north"],
   "nebraska":       ["middle"],
   "nevada":         ["mountain", "west"],
   "new hampshire":  ["north east", "northeast", "new england"],
   "new jersey":     ["atlantic coast", "east"],
   "new mexico":     ["southwest", "south west", "south"],
   "new york":       ["north east", "northeast", "new england","east"],
   "north carolina": ["atlantic coast", "east"],
   "north dakota":   ["north"],
   "ohio":           ["north", "great lakes"],
   "oklahoma":       ["southwest", "south west", "south"],
   "oregon":         ["pacific coast","pacific west", "pacific", "west"],
   "pennsylvania":   ["north east", "northeast", "east"],
   "rhode island":   ["north east", "northeast", "new england", "east"],
   "south carolina": ["southeast", "south east", "atlantic coast"],
   "south dakota":   ["north"],
   "tennessee":      ["south"],
   "texas":          ["southwest", "south west","south"],
   "utah":           ["mountain", "west"],
   "vermont":        ["north east", "northeast", "new england", "east"],
   "virginia":       ["atlantic coast", "east"],
   "washington":     ["pacific coast","pacific west", "pacific", "west"],
   "west virginia":  ["east"],
   "wisconsin":      ["north", "great lakes"],
   "wyoming":        ["mountain", "west"]
}

#for key, value in usNeighborStates.items() :
#     print ("key=", key, ", value=", value, "\n")
#     for k, v in value.items() :
#         print ("k=", k, ", v=", v, "\n")

#s/\([A-Z]\),/\1":/g
#for key,value in usStatesInRegions.items() :
#for key, value in usCitiesInStates.items() :
#     print ("key=", key, ", value=", value, "\n")
     #for k, v in value.items() :
      #   print ("k=", k, ", v=", v, "\n")
#for key, value in usNeighborCities.items() :
#     print ("key=", key, ", value=", value, "\n")
#     for k, v in value.items() :
#         print ("k=", k, ", v=", v, "\n")

#for key, value in usStatesPrimaryRegion.items() :
#	print ("State:", key,"<br>\n")
#	for region in value :
#		print ("Region =", region)
#	print ("<br>\n")

page_size = 15

search_region_but_only_has_state_name_deduction =  10
search_region_but_only_has_city_name_deduction =   15

search_state_but_only_has_region_name_deduction = 35
search_state_but_only_has_city_name_deduction = 30

search_city_but_only_has_region_name_deduction = 45
search_city_but_only_has_state_name_deduction =  40
