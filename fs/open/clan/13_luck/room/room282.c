inherit ROOM;
void create() {
	set( "short", "照名設備室" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/killer/obj/bellstar",
		"file8"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount3"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/capital/obj/gold_pill",
		"file9"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount2"  : 62967,
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount7"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file1"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file3"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/obj/fire-color-ribbon",
	]) );
	set( "light_up", 1 );
	set( "build", 15939 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room277",
	]) );
	set( "long", @LONG

    照明設備是在幻想中必備的器具，如李元濟身上的狼眼鑽戒，穿過
那七星之塔，魔森林，和可怕的網中人，才能到達的魔界商店，所販賣
的魔界戒子都有此功能，而戒子帶在身上就可以了，不需要裝備靠著他
的發亮，就可以看到房間的任何地方了。

LONG);
	setup();
	replace_program(ROOM);
}
