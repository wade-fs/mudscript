inherit ROOM;
void create() {
	set( "short", "棄刀塚" );
	set( "owner", "del" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/water-ball",
		"amount9"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/obj/golden-ball",
		"file6"    : "/open/magic-manor/obj/wood-ball",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/obj/fire-ball",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/obj/golden-ball",
		"file3"    : "/open/magic-manor/obj/golden-ball",
		"amount5"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/magic-manor/obj/water-ball",
		"amount1"  : 1,
	]) );
	set( "build", 10332 );
	set( "item_desc", ([
		"girl" : @ITEM
半透明帶著微紅的臉兒，過肩的烏髮，略噘的小桃唇，他是
棄刀塚的藥僮。不知在多小的時候被雨兒從山林裡帶回來，
當時身上僅掛著一個刻有『月』字的玉佩，直到黑夜奔雷ζ
到十三吉祥作客，見其活潑可愛，將她收為義女。
ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room201.c",
		"up"        : "/open/clan/ou-cloud-club/room/room133",
		"west"      : "/open/clan/ou-cloud-club/room/room147.c",
	]) );
	set( "long", @LONG
穿越幾乎腐朽的木門之後，你來到一塊滿佈黃沙的空地
，中央是一個半人高的土堆，土堆前有塊石碑，但字跡早已
模糊，北邊是一個老舊的小涼亭，上面是兩個蒲團跟一張石
桌，你走近一看，桌上還放著一個只下了半局的棋盤跟一壺
濃郁的香茶。幾步之外有一位小女孩(girl)正對著你微笑。
ˉ
LONG);
	setup();
	replace_program(ROOM);
}
