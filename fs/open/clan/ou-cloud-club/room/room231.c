inherit ROOM;
void create() {
	set( "short", "$HIY$聚寶盆$NOR$" );
	set( "object", ([
		"amount2"  : 269,
		"amount6"  : 5950,
		"amount10" : 25,
		"amount7"  : 958,
		"amount9"  : 1,
		"file3"    : "/open/ping/obj/poison_pill",
		"file9"    : "/obj/gift/xisuidan",
		"file1"    : "/open/killer/obj/atman_pill",
		"file5"    : "/obj/gift/unknowdan",
		"amount1"  : 1189,
		"file2"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file4"    : "/obj/gift/xisuidan",
		"file6"    : "/open/killer/obj/s_pill",
		"amount3"  : 441,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 1,
		"file10"   : "/open/fire-hole/obj/g-pill",
		"amount5"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10172 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room101.c",
	]) );
	set( "long", @LONG
傳說中的聚寶盆，不知為何可以進到其中，傳聞聚寶盆中
裝滿著各式各樣的寶物，且在此盆中有取之不盡的財富與寶物
，可是進到盆內卻也只是空空的，不見任何東西，就連一私私
塵染也不得見了，更別說會有寶物與財富了呢？

LONG);
	setup();
	replace_program(ROOM);
}
