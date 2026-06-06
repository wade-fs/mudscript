inherit ROOM;
void create() {
	set( "short", "天魔沉睡洞窟" );
	set( "object", ([
		"amount7"  : 1,
		"amount10" : 1,
		"file2"    : "/open/killer/obj/k_ring",
		"amount8"  : 1,
		"file8"    : "/open/dancer/obj/maple_ribbon",
		"amount2"  : 1,
		"file10"   : "/obj/gift/lingzhi",
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/scholar/obj/icefan",
		"amount1"  : 1,
	]) );
	set( "build", 10048 );
	set( "exits", ([
		"corpse"    : "/open/clan/sky-wu-chi/room/room594.c",
		"out"       : "/open/clan/sky-wu-chi/room/room92.c",
		"down"      : "/open/clan/sky-wu-chi/room/room480.c",
		"evil"      : "/open/clan/sky-wu-chi/room/room584.c",
		"ghost"     : "/open/clan/sky-wu-chi/room/room604.c",
		"fire"      : "/open/clan/sky-wu-chi/room/hall",
		"god"       : "/open/clan/sky-wu-chi/room/room574.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是元始天魔沉睡的地方，不是普通人可以到達的，想必你到達這裡一定是
經過相當堅難的旅程與長途的跋涉才到達的，既然來到這裡，你不禁對附近的景觀
歎為觀止，另你想一再的留戀在這個地方，不過有一股相當大的壓力壓迫著你。
LONG);
	setup();
	replace_program(ROOM);
}
