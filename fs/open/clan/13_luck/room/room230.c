inherit ROOM;
void create() {
	set( "short", "龍滅之道" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount2"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount8"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
	]) );
	set( "build", 10515 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room229",
		"west"      : "/open/clan/13_luck/room/room228",
	]) );
	set( "long", @LONG

　　四周圍靜的讓人毛骨聳然，空氣中充斥著一股作人欲嘔的血腥味
，往東方望去，只見一座高塔聳立，外表看來相當的老舊，不知己佇
立在那裡多久了，傳說塔裡有一武林最強兵器，不過塔裡群龍聚集守
衛，不知有多少武林人士偷窺塔裡寶物，卻命喪塔裡。

LONG);
	setup();
	replace_program(ROOM);
}
