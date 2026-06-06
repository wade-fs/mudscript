inherit ROOM;
void create() {
	set( "short", "廣場中央" );
	set( "owner", "mill" );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount9"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file3"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file7"    : "/open/ghost-hole/obj/ground-spirit",
		"file8"    : "/open/ghost-hole/obj/light-spirit",
		"amount2"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10128 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room499",
		"north"     : "/open/clan/13_luck/room/room497",
	]) );
	set( "long", @LONG

　　廣場中央反倒較為寧靜一點，沒有閒雜人等隨意走動。四周種植
著許多樹木，感覺十分清爽。但唯一美中不足的是，因這是通往殿內
的唯一通道，要進內都必需經由這過，因此常有來訪人士三三兩兩通
過，破壞了這片刻的安寧。
LONG);
	setup();
	replace_program(ROOM);
}
