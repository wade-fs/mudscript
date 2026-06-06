inherit ROOM;
void create() {
	set( "short", "$HIR$『赤獄混沅』$NOR$焚天魔王人頭丟棄室" );
	set( "owner", "blur" );
	set( "object", ([
		"amount10" : 1,
		"amount7"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10027 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room23",
	]) );
	set( "long", @LONG
說到有人頭的地方，就屬陰曹地府最多，多到數不完
雖然說焚天魔王是一等一的高手，不過由於陰曹地府有強
力的實力之下，也是輕易打倒，不過這裡怎會多到如此多
呢，事實上，地府裡面有專門收集別人打贏敵人後所留下
的頭，又因為在敵人死後又要來到陰曹地府，所以也就順
手又多了幾個，在狂想裡，焚天魔王算是最難打也是最常
去被打的高手，所以多到要被丟到啦機筒去了。。。

LONG);
	setup();
	replace_program(ROOM);
}
