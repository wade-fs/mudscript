inherit ROOM;
void create() {
	set( "short", "書房" );
	set( "owner", "pighead" );
	set( "object", ([
		"amount2"  : 1,
		"file4"    : "/open/gblade/obj/book",
		"amount8"  : 1,
		"file5"    : "/open/gblade/obj/blade-book",
		"file3"    : "/open/gsword/obj/sword_book",
		"file1"    : "/open/mogi/castle/obj/fire_book",
		"amount9"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/snow/obj/book",
		"file9"    : "/open/marksman/obj/book",
		"file8"    : "/daemon/class/fighter/armband",
		"file7"    : "/open/center/obj/gamble_book",
		"file2"    : "/open/dancer/obj/magicbook",
		"amount10" : 1,
		"amount1"  : 1,
		"file10"   : "/open/ping/obj/linpo_book",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10422 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room276",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裏是滅殺龍的書房ㄝ藏書雖然不多，但也甚為可觀，書房的桌上
放著一本書，仔細一看書名好像是基本拳法，由於滅殺龍一年難得進書
房幾次，所以書都看起來很新！牆上有一幅對聯(couplet)，是滅殺龍親
手題的。

LONG);
	setup();
	replace_program(ROOM);
}
