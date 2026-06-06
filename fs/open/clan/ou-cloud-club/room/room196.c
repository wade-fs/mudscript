inherit ROOM;
void create() {
	set( "short", "$HIR$真情$HIC$一$HIY$世$NOR$" );
	set( "owner", "flyindance" );
	set( "object", ([
		"amount10" : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"file2"    : "/open/capital/obj/gold_pill",
		"amount9"  : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/killer/obj/k_ring",
		"amount1"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/ping/obj/ring-2",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/poison/obj/pearl",
		"amount4"  : 1,
		"file3"    : "/open/port/obj/wolf_ring",
		"amount3"  : 1,
		"file1"    : "/open/capital/guard/gring",
		"file4"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 10513 );
	set( "light_up", 1 );
	set( "exits", ([
		"ghost"     : "/open/clan/ou-cloud-club/room/room332",
		"enter"     : "/open/clan/ou-cloud-club/room/room228",
		"west"      : "/open/clan/ou-cloud-club/room/room130.c",
	]) );
	set( "long", @LONG
劍君十二恨的老大〔無情〕的住所，傳聞此人
是幫主在求武時的大哥，武學似乎還在幫主劍君之
上，但卻隱居於此，而此房裝飾更為簡樸，只有一
張床可以用來睡覺跟幾隻拿來練武用的木人佇立著
而已．牆角道是擺著不少武具．

LONG);
	setup();
	replace_program(ROOM);
}
