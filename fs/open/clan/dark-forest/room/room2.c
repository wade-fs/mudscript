inherit ROOM;
void create() {
	set( "short", "摩瑞亞礦坑" );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/obj/evil-kill-claw",
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount4"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"file10"   : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/obj/evil-kill-claw",
	]) );
	set( "build", 10068 );
	set( "exits", ([
		"up"        : "/open/clan/dark-forest/room/room19",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
