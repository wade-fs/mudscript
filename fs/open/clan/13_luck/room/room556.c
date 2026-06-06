inherit ROOM;
void create() {
	set( "short", "你會選擇什麼呢?(4)" );
	set( "owner", "dfyw" );
	set( "object", ([
		"file6"    : "/obj/gift/xiandan",
		"amount2"  : 1,
		"amount3"  : 1,
		"file8"    : "/obj/gift/xiandan",
		"amount8"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"file1"    : "/obj/gift/xiandan",
		"file10"   : "/obj/gift/xiandan",
		"amount10" : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room560",
	]) );
	set( "long", @LONG
遺憾與後悔，橫豎都得接受一個。
一是遺憾，一是後悔，無論如何，都得選一，
這就是知悉未來的不可不為。同樣的邏輯也可應用在愛情裡。
不愛他，會遺憾，遺憾自己沒能成就一段時情；
愛了他，會後悔，因為個性不合，因為了無結局，
後悔自己衝動跳入，引火自焚，然後灼燒成傷，傷人傷己。
我總想，追求事業與投入愛情，
本應是美好的嚮往，怎會落入似是兩敗俱傷的局面？
竟是去也不成，回也不成，兩頭都是缺憾。
究竟是哪裡出了錯？
是貪心嗎？還是狠心？
LONG);
	setup();
	replace_program(ROOM);
}
