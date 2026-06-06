inherit ROOM;
void create() {
	set( "short", "『山道二』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10043 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room460",
		"south"     : "/open/clan/13_luck/room/room458",
	]) );
	set( "long", @LONG

     走過了有名的棲霞崖之後，你在往山上走了過來，此時距離山頂上那座
 古色古香的建築物愈來愈趨接近，你的心情也瞬間興奮了起來，而爬上山的
 那股疲勞感也一下子就消失無蹤了。只想趕快走上山，看看在墨子教裡面的
 人們是否像聽說的那麼友善。

LONG);
	setup();
	replace_program(ROOM);
}
