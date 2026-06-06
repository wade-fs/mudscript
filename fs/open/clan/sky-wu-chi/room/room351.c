inherit ROOM;
void create() {
	set( "short", "自知喘息歡心" );
	set( "owner", "matrix" );
	set( "object", ([
		"file3"    : "/open/ping/obj/iceger",
		"amount7"  : 1,
		"file10"   : "/open/wu/npc/obj/armband",
		"file2"    : "/open/capital/guard/gring",
		"file8"    : "/open/mon/obj/ghost-claw",
		"file9"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"amount4"  : 1,
		"file6"    : "/open/ping/obj/gold_hand",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount9"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10377 );
	set( "light_up", 1 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"west"      : "/open/clan/sky-wu-chi/room/room350.c",
	]) );
	set( "long", @LONG
行者數息、隨息得定，突破色身束縛，入心之覺受，因息止，定生故，
心生歡喜(喜受)，行者自知之。諸法本幻有，何喜之有。第九個殊勝，
自知喘息歡心，為什麼從呼吸之間，就產生心的高興，這境界只有二
禪的境界少光天、無量光天、光音天。在心地上在呼吸時可以感覺心的
歡喜，自知喘息能夠誘發喜的感受，打坐的三要素，第一是打坐的姿勢
--七支坐法，第二是數息法--安那般那數息法，如果數息得定，就會有此
殊勝的現象。
LONG);
	setup();
	replace_program(ROOM);
}
