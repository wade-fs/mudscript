inherit ROOM;
void create() {
	set( "short", "殿前大道" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount10" : 1,
		"file9"    : "/open/mogi/castle/obj/blood-water",
		"file3"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"amount4"  : 1,
		"file6"    : "/obj/gift/bingtang",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file5"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"file8"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"file7"    : "/obj/gift/unknowdan",
		"file4"    : "/open/gblade/obj/sa-head",
		"amount9"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10365 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room87.c",
		"enter"     : "/open/clan/13_luck/room/room325",
	]) );
	set( "long", @LONG
    這裡是狂龍宮殿的進宮大道，四周沉靜無聲，可推測當家無比的
權威，筆直的大道象徵你學武生涯的一往直前。順著漠北特產血凶狼
的皮看做成的紅毛地毯，一步一步向前走去，兩旁壁邊放置的兵器，
好似訴說當年練功的回憶，刀、劍、槍、拳等。接著而來的是立在兩
旁的兒郎，看著他們硬挺的身子，頭頂兩旁太陽穴高起，顯示內功精
深，可與中原各家一較長短。

LONG);
	setup();
	replace_program(ROOM);
}
