inherit ROOM;
void create() {
	set( "short", "齊天道" );
	set( "object", ([
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/gsword/obj1/karmor",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"file10"   : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"file8"    : "/daemon/class/blademan/obj/mhands",
		"amount10" : 1,
		"file5"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"file2"    : "/open/scholar/obj/icefan",
		"amount6"  : 1,
		"file9"    : "/open/wu/npc/obj/armband",
		"file1"    : "/daemon/class/bonze/puty_pullium",
		"amount3"  : 1,
	]) );
	set( "owner", "mad" );
	set( "build", 18595 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room25",
		"south"     : "/open/clan/13_luck/room/room23",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    走著走著你發現天藍的空不見了，變成了人為的燈火時，你猜想著
是不是要到了，看看四周警備更森嚴，不準敵人伺機而入，再走一會看
到深藍殿堂想必那就是霸者傳人之殿一『齊天殿』，你將可目睹傳人之
真面目了。

LONG);
	setup();
	replace_program(ROOM);
}
