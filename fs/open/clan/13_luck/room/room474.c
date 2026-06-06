inherit ROOM;
void create() {
	set( "short", "『廣場』" );
	set( "owner", "poll" );
	set( "object", ([
		"file6"    : "/open/killer/memory/static",
		"file7"    : "/obj/stone/powder",
		"file5"    : "/open/killer/memory/static",
		"file4"    : "/open/love/obj/cloth1",
		"amount1"  : 6,
		"file8"    : "/open/firedancer/npc/eq/r_boots",
		"file3"    : "/open/love/obj/legging",
		"amount4"  : 1,
		"amount10" : 1,
		"file1"    : "/obj/stone/suipian",
		"file10"   : "/open/magic-manor/obj/magic-sign",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount7"  : 62,
		"amount9"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_boots",
		"file2"    : "/open/ping/obj/cloud",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10124 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room466.c",
		"north"     : "/open/clan/13_luck/room/room473.c",
		"south"     : "/open/clan/13_luck/room/room462.c",
		"down"      : "/open/clan/13_luck/room/room105.c",
	]) );
	set( "long", @LONG

     這裡是洛陽城關帝廟前的廣場﹐地上整齊地鋪著大石板。廣場中央有
 一個木頭搭的架子﹐經過多年的風吹日曬雨淋﹐看來非常破舊。四周建築
 林立。往西你可以看到一條通往城外的大道﹐往東則是一間客棧，看來生
 意似乎很好，往東北則有一條小路往東南是新搬到洛陽的布袋戲班，裡面
 似乎很熱鬧。

LONG);
	setup();
	replace_program(ROOM);
}
