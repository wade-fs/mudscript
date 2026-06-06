inherit ROOM;
void create() {
	set( "short", "$BGRN$刀室$NOR$" );
	set( "object", ([
		"file7"    : "/open/capital/obj/4-3",
		"amount2"  : 572,
		"file9"    : "/open/firedancer/npc/eq/r_pants",
		"amount6"  : 1,
		"amount10" : 1,
		"file8"    : "/open/firedancer/npc/eq/r_hands",
		"amount9"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 1,
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/open/wu/obj/figring",
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"amount1"  : 914,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 95,
		"amount8"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/open/firedancer/npc/eq/r_boots",
	]) );
	set( "owner", "auo" );
	set( "build", 11028 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room82",
	]) );
	set( "long", @LONG
這裡是欲蒼穹練習刀法的石室,石壁上到處都是被雄霸刀法所砍破的痕跡,地上
一堆碎石說明了刀法的勁道,一邊牆上留有一張欲蒼穹的畫像,並說明他的刀法
已達忘心無我的境界,欲蒼穹在參加百戰決之前,為了讓兄弟舒石公取勝,殺了邪
能境之主陰陽師,雖然中了陰陽師的泣月陰掌,但仍然和炎熇兵燹戰成平手,實力
之強可見一斑

LONG);
	setup();
	replace_program(ROOM);
}
