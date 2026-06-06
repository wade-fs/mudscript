inherit ROOM;
void create() {
	set( "short", "白$HIY$虎$HIC$時$HIG$空$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 10792 );
	set( "exits", ([
		"pass"      : "/open/clan/time-limit/room/room200",
		"east"      : "/open/clan/time-limit/room/hall.c",
	]) );
	set( "long", @LONG
這裡是時空秘境中的白虎時空,高聳的山壁正是天地門,也是通往霹靂世界的通道,
你以內力打開天地門的入口,一陣狂風吹來,猶如老虎在旁張牙舞爪,看來這趟旅程
可不是那麼容易完成,而霹靂的地域何其大,一旦進入後不知是否能夠再出來,進入
前請三思而後行吧

LONG);
	setup();
	replace_program(ROOM);
}
