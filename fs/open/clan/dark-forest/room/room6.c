inherit ROOM;
void create() {
	set( "short", "$YEL$法貢$GRN$森林$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount5"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount6"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount9"  : 1,
		"amount1"  : 3,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount3"  : 7,
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file8"    : "/open/quests/snake/npc/obj/snake-key-1",
		"amount10" : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file5"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-ring",
	]) );
	set( "build", 10125 );
	set( "exits", ([
		"west"      : "/open/clan/dark-forest/room/room18",
		"east"      : "/open/clan/dark-forest/room/hall.c",
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
