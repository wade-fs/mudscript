inherit ROOM;
void create() {
	set( "short", "『墨子教大門』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10179 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room458",
		"south"     : "/open/clan/13_luck/room/room456",
	]) );
	set( "long", @LONG

     終於走到了墨子教的大門口了，你沒有想到這一段路竟然會這麼的長。
 走到了大門口，你的內心不由自主的升起一股滿足的感覺，而在門口的那兩
 位侍衛正虎視眈眈的看著你，怕有搗亂的人來入侵墨子教，看到門口的兩位
 守衛，你的內心升起了一股敬畏的心裡。

LONG);
	setup();
	replace_program(ROOM);
}
