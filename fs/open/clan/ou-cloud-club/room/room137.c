inherit ROOM;
void create() {
	set( "short", "$HIW$波-無塵室(1)$NOR$" );
	set( "owner", "perth" );
	set( "object", ([
		"file1"    : "/open/ping/questsfan/obj/diamond_skirt",
		"amount8"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"amount4"  : 1,
		"file10"   : "/open/ghost-hole/obj/light-spirit",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount5"  : 1190,
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"file6"    : "/open/killer/obj/s_pill",
		"amount7"  : 1,
		"file3"    : "/open/killer/headkill/obj/i_dag",
		"amount3"  : 1,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/ping/questsfan/obj/diamond_boots",
		"file4"    : "/open/killer/obj/dagger",
		"file8"    : "/open/killer/headkill/obj/world_dag",
		"amount6"  : 546,
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 11029 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room387.c",
		"west"      : "/open/clan/ou-cloud-club/room/room325.c",
		"north"     : "/open/clan/ou-cloud-club/room/room174.c",
		"south"     : "/open/clan/ou-cloud-club/room/room479.c",
	]) );
	set( "long", @LONG

「傲雲殺手」，斗大的招牌懸在門口，令你感覺到一股壓力一
進入房間，一股刺鼻的藥味，嗆得你一陣頭暈目眩，令人做噁，卻
看到一個白影迅速地在各藥水、火爐間移動，拿著你看不大懂的器
具，在數片薄薄白白的玻璃上切切割割，大概是波又突發奇想，準
備研發什麼新暗器了，令你迫不及待地想與他的新武器較量一番

LONG);
	setup();
	replace_program(ROOM);
}
