inherit ROOM;
void create() {
	set( "short", "十三拳堂正殿" );
	set( "owner", "roar" );
	set( "object", ([
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount1"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount6"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount2"  : 1,
	]) );
	set( "build", 10107 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room394",
		"west"      : "/open/clan/13_luck/room/room396.c",
		"east"      : "/open/clan/13_luck/room/room395.c",
		"north"     : "/open/clan/13_luck/room/room398.c",
	]) );
	set( "long", @LONG

    來到大殿中央，見到十三拳堂的堂主『拳十三』，拳十三不如你所想
像的如此魁武高大，而是一個矮小肥胖的中年男子。他臉上的笑容更讓人
感覺不出他居然是一堂之主，但卻不能因此而小覷他，他可是經通各家拳
法的超級天才。

LONG);
	setup();
	replace_program(ROOM);
}
