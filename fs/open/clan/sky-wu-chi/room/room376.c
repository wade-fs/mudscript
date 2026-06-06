inherit ROOM;
void create() {
	set( "short", "小朋友的房間" );
	set( "owner", "hello" );
	set( "object", ([
		"amount3"  : 2,
		"amount1"  : 34,
		"file2"    : "/obj/stone/powder",
		"file5"    : "/open/snow/obj/stone",
		"amount2"  : 254,
		"amount8"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/obj/stone/jiao",
		"amount7"  : 8,
		"file4"    : "/open/wu/obj/figring",
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount4"  : 1,
		"file1"    : "/obj/stone/suipian",
	]) );
	set( "item_desc", ([
		"馬桶" : @ITEM
裡面的大便還沒有沖,上面還有上千條的蛆在擩動,想吃啊!?
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 11746 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
由於是小朋友平日生活起居住的地方,所以讓人感覺起來什麼都相當
小,小桌子,小椅子,小床,小窗戶,小門,小歸小,卻也令人感覺相當整齊完
善,正所謂麻雀雖小,五臟俱全,反映在這也挺為貼切,平日小朋友都會在
這裡練練功夫,由於小朋友平時武藝進步並不如大哥哥們那麼的快,所以
如果您有空的話來這坐坐,給小朋友指導指導,他會很高興的.
LONG);
	setup();
	replace_program(ROOM);
}
