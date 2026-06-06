inherit ROOM;
void create() {
	set( "short", "武神居武器房" );
	set( "object", ([
		"amount3"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount1"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount7"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount2"  : 1,
		"amount10" : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount6"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount8"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file10"   : "/obj/gift/xisuidan",
		"amount9"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10062 );
	set( "owner", "zmud" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room677",
		"west"      : "/open/clan/13_luck/room/room680",
	]) );
	set( "long", @LONG

    四周擺滿了各方有名武器，都是武神精心收集而來，
各式各樣都陳列得很整齊。牆壁上留下很多招式的痕跡，
正是演練兵器所致，由此可見武神武功的不凡。面對這麼
多兵器，你也不禁手癢起來，目不轉睛的看著每一件神兵
利器。

LONG);
	setup();
	replace_program(ROOM);
}
