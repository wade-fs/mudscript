inherit ROOM;
void create() {
	set( "short", "鴻門前道" );
	set( "object", ([
		"amount2"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/gsword/obj/yuskirt",
		"amount5"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/port/obj/wolf_ring",
		"file2"    : "/open/gsword/obj/dragon-sword",
		"amount6"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/scholar/obj/icefan",
		"file5"    : "/open/gsword/obj/yubracelet",
		"amount3"  : 1,
		"file4"    : "/open/ping/obj/cloud",
		"file6"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "build", 12192 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room528",
		"east"      : "/open/clan/13_luck/room/room342",
	]) );
	set( "long", @LONG
前方不遠處座落一座如宮殿般的樓院，單是莊前那道朱紅色大門，
亦足有兩丈之高，在門的旁立了二隻一丈高的石獅子，眼神透漏出不可
一世的神情，仿佛在告訴你他是多麼的偉大；圍著慕府的外牆，亦達半
里之闊，外牆更雕琢得美輪美奐，氣派不凡；這座樓院想必便是天下人
為之驚氈的『易水樓』了。

LONG);
	setup();
	replace_program(ROOM);
}
