inherit ROOM;
void create() {
	set( "short", "moi的休息室" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/dragon-key",
		"amount1"  : 1,
	]) );
	set( "owner", "blackdog" );
	set( "build", 10014 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room535",
		"east"      : "/open/clan/13_luck/room/room634.c",
		"south"     : "/open/clan/13_luck/room/room619",
		"north"     : "/open/clan/13_luck/room/room635.c",
	]) );
	set( "long", @LONG
俗話說的好，休息是為了走更長的路，為了繼續向廣大的ＦＳ世界挑戰
，也為了收集更多，更好，更珍貴的寶物，短暫的休息是必要的。你可以在
這裡稍作休息，休息夠了之後，到附近的房間拿取適當的武器裝備，繼續練
功去吧，去挑戰更強大的敵人吧。

LONG);
	setup();
	replace_program(ROOM);
}
