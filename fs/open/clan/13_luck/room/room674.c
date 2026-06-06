inherit ROOM;
void create() {
	set( "short", "丹藥房" );
	set( "owner", "sevenll" );
	set( "object", ([
		"file7"    : "/open/fire-hole/obj/w-pill",
		"amount9"  : 152,
		"amount5"  : 171,
		"file10"   : "/open/ping/obj/poison_pill",
		"amount10" : 29,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"file9"    : "/open/mon/obj/mon-pill",
		"amount8"  : 60,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file4"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 230,
		"amount7"  : 34,
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount4"  : 245,
		"amount3"  : 13,
		"amount1"  : 27,
		"file8"    : "/open/fire-hole/obj/y-pill",
		"amount2"  : 142,
		"file1"    : "/open/fire-hole/obj/k-pill",
	]) );
	set( "build", 11279 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room675",
	]) );
	set( "long", @LONG
    你好奇的把門推開,聞道陣陣的香味,眼前是一個很大的丹
爐子,但是下面卻沒有火,你偷偷的把他打開來,一道彩色的光,
忽然從爐子中衝出,你看到裡面有十種珍奇丹藥,忍不住想偷吃
,門外傳來一陣腳步聲,你只好趕快離開
LONG);
	setup();
	replace_program(ROOM);
}
