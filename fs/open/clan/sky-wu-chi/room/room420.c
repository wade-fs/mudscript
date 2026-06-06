inherit ROOM;
void create() {
	set( "short", "Yuki房間的壁櫥" );
	set( "object", ([
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 128,
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/mon-pill",
	]) );
	set( "owner", "yuki" );
	set( "light_up", 1 );
	set( "build", 10012 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room421",
		"east"      : "/open/clan/sky-wu-chi/room/room410.c",
	]) );
	set( "long", @LONG
這個是Yuki房間的壁櫥，比想像中來的巨大甚至寬廣大可以躺下
五六個人都沒問題，不經讓人感到懷疑這個壁櫥是不是有著不可告人
的用途才需要做的如此龐大，這挑起你的好奇心讓你一滴不漏的搜查
這個地方，卻意外的什麼都沒有找到，卻聽到一陣一陣的奸笑聲彷
彿在嘲笑你的愚笨
LONG);
	setup();
	replace_program(ROOM);
}
