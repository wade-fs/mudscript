inherit ROOM;
void create() {
	set( "short", "法貢森林1" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount7"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount1"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount6"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount4"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 10045 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/dark-forest/room/room19",
		"east"      : "/open/clan/dark-forest/room/room6",
	]) );
	set( "long", @LONG
沉靜的法貢森林是古老樹人的棲息地，千百年來天地的精
華以及精靈特有的魔法，造就了獨立思想又兼具毀滅力量的樹
人族群，在這裡沉睡的每一棵樹木都見證了數百年來中土世界
各方勢力的興衰，或許是中立的立場讓樹人族群能在此地度過
平靜的生活，一旦被激起怒火，將使得毀滅的力量再度爆發。

LONG);
	setup();
	replace_program(ROOM);
}
