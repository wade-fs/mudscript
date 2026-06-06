inherit ROOM;
void create() {
	set( "short", "飄雲扇室" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10035 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room275",
	]) );
	set( "long", @LONG

    飄雲扇，段家的老大隨身之物，為段家之人使用有著火鳳凰之術，
段家以點穴出名，被點到無不看著自己被眼睜睜的被打死就是被火鳳凰
燒死，所以段家攻擊雖低，但是被定走了也會掛，小心段家的敵人，可
別輕易跟他們結仇。

LONG);
	setup();
	replace_program(ROOM);
}
