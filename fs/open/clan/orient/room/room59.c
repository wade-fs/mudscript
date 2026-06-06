inherit ROOM;
void create() {
	set( "short", "$HIR$= 紅色靈扇 =$NOR$" );
	set( "owner", "fivewp" );
	set( "object", ([
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10054 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room60",
	]) );
	set( "long", @LONG
$HIR$紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇
    紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇
    紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇
    紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇紅色靈扇$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
