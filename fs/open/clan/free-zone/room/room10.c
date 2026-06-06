inherit ROOM;
void create() {
	set( "short", "聖境北一街" );
	set( "object", ([
		"amount3"  : 1,
		"amount4"  : 1,
		"amount1"  : 267,
		"amount7"  : 1,
		"file5"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file9"    : "/open/mogi/dragon/obj/dragon-head",
		"file6"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"amount6"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"file2"    : "/obj/gift/unknowdan",
		"file1"    : "/open/ping/obj/poison_pill",
		"file10"   : "/open/mogi/dragon/obj/dragon-head",
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
		"amount2"  : 1,
		"file7"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 11943 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/hall.c",
		"north"     : "/open/clan/free-zone/room/room12",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├北┤☆├一┤☆├街┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 


LONG);
	setup();
	replace_program(ROOM);
}
