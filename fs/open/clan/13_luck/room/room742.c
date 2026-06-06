inherit ROOM;
void create() {
	set( "short", "血狼族" );
	set( "object", ([
		"amount4"  : 215,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount1"  : 209,
		"amount8"  : 259,
		"file5"    : "/open/fire-hole/obj/y-pill",
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 114,
		"amount3"  : 300,
		"amount5"  : 29,
		"file3"    : "/open/ping/obj/poison_pill",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/open/mon/obj/mon-pill",
		"amount10" : 1,
		"amount9"  : 1,
		"file9"    : "/open/mon/obj/thousand-nectar",
	]) );
	set( "build", 10453 );
	set( "owner", "markw" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room727",
	]) );
	set( "long", @LONG
傳說在雲南一帶有個極為神秘恐怖的禁地─血狼窟，連當地居民都不太敢接近，
在這塊地的附近長滿了一種植物，會令人產生幻覺，人人稱它做 攝魄草 吃下去後會
進入昏迷狀態，隔了三個時辰後才會慢慢甦醒，這便是血狼族族人用來餵食祭品的密
藥。血狼族供奉血狼神，相信血狼神能賜給他們強大的力量，所以每個月都會抓一個
漢人來獻給血狼神。未經煉製的 攝魄草 會散發出令人昏迷的氣味，而將該草提煉成
 迷魂散 的工作則由祭司來執行，因他們長期置身於充滿此草的屋中，多半都會發瘋
，族人便將其獻祭給血狼神。至於由誰送去血狼窟呢？當然是百毒不侵的血狼族族長
他對此草具有免疫力，所以每月的祭品都是由族長送去。而族長是如何產生的呢？每
年的六月會舉行一個比武大會，只要是年滿二十的族人方可參加，第一名的人就要接
受祭司所設計的考驗，也就是對藥的免疫性，若挑戰失敗則加入祭司的行列，負責採
草與製藥的工作；若是闖關成功便暫時接下族長繼承人的位子，也是隔年大賽的第一
種子，直到現任族長大限已到，便將畢生功力傳給繼承人。而這位新的血狼霸主則必
須闖進血狼窟，抓一隻血狼出來，將其血抽出與所有族人分享，其頭骨連同皮毛做成
族長的戰衣。血狼兇猛異常，其獠牙又尖又長，最可怕的是牠那雙血紅的雙眼，會讓
人產生無比的恐懼，嚇到全身僵硬，而族長所練的 血狼八殺 正是為對付血狼所創。

LONG);
	setup();
	replace_program(ROOM);
}
