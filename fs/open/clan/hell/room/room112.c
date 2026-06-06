inherit ROOM;
void create() {
	set( "short", "$HIY$Shine On You Crazy Diamond$NOR$" );
	set( "owner", "blur" );
	set( "object", ([
		"file5"    : "/open/mon/obj/ghost-legging",
		"file6"    : "/open/ping/obj/ring-2",
		"amount3"  : 1,
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 1,
		"amount9"  : 2,
		"file3"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10023 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room115.c",
		"north"     : "/open/clan/hell/room/room111.c",
		"west"      : "/open/clan/hell/room/room93.c",
		"south"     : "/open/clan/hell/room/room110",
	]) );
	set( "long", @LONG
$HIC$
Nobody knows where you are,how near or how far.
Shine on you crazy diamond.
Pile on many more layers and I'll be joining you there.
Shine on you crazy diamond.
And we'll bask in the shadow of yesterday's triumph,
and sail on the steel breeze.
Come on you boy-child,you winner and loser,
Come on you miner for truth and delusion,and shine
$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
