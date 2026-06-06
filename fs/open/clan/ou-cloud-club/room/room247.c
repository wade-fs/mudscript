inherit ROOM;
void create() {
	set( "short", "歸元村" );
	set( "object", ([
		"amount3"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount2"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount5"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount8"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount10" : 1,
		"amount4"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "owner", "circle" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room446",
	]) );
	set( "build", 10063 );
	set( "light_up", 1 );
	set( "long", @LONG
這是鯨魚的棲息地，隨處都可以看到很多鯨魚的
存在在這可以看到很多鯨魚在此游來游去，有數不清
的魚在這生活著當然還有一隻最大的鯨魚王也是這的
主人在此生活著，希望每一個人都能來這逛逛街，並
且保護我們這些稀有動物。

LONG);
	setup();
	replace_program(ROOM);
}
