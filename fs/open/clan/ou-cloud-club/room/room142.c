inherit ROOM;
void create() {
	set( "short", "$HIY$藏$HIR$龍$NOR$居$NOR$" );
	set( "owner", "long" );
	set( "object", ([
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file10"   : "/obj/gift/shenliwan",
		"amount10" : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount4"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount3"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
		"amount2"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-shield",
	]) );
	set( "build", 10086 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room119",
		"east"      : "/open/clan/ou-cloud-club/room/room118.c",
		"go"        : "/open/clan/ou-cloud-club/room/room718",
		"west"      : "/open/clan/ou-cloud-club/room/room120.c",
	]) );
	set( "long", @LONG
$HIY$　　　　　　　　　║　　║    ║
　　　　　　　　  ═╦═╦═╠══╯
　　　　　　　　  ║╰╦╯║╰══╮
　　　　　  　　　╰═╬═╯╭══╯
　　　　　　　　  ╭═╩═╮╠═══
　　　　　　　　  ╠═══╣╠═══
　　　　　  　　　╠═══╣╠═══
　　　　　　　　  ╯  ══╯╰═══$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
