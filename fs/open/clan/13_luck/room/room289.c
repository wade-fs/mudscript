inherit ROOM;
void create() {
	set( "short", "將軍道" );
	set( "object", ([
		"amount2"  : 2,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/gblade/mob/lotch",
		"amount1"  : 1,
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10548 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room288",
		"south"     : "/open/clan/13_luck/room/room284.c",
	]) );
	set( "long", @LONG
將軍道..為這營區最大的長官駕車所走的道路..所以走這條道路
希望不要自找麻煩..最好繞道而行..不然就等著吃不完兜著走..雖然
兩旁風景漂亮..但也沒時間在那享受風景..還是快去辦理自己的事情
,,免的長官經過就要倒大楣了..
LONG);
	setup();
	replace_program(ROOM);
}
