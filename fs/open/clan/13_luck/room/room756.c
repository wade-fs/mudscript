inherit ROOM;
void create() {
	set( "short", "秘密山洞" );
	set( "light_up", 1 );
	set( "owner", "meimei" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/open/ping/obj/poison_pill",
		"amount1"  : 1,
		"amount4"  : 129,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
	]) );
	set( "build", 10015 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room101",
		"enter"     : "/open/clan/13_luck/room/room757",
	]) );
	set( "long", @LONG
望著眼前瀑布的水幕，你不禁懷疑剛剛是經歷了何種奇異的旅程，輕輕
地拂去了不小心沾染上的水氣，這才有機會看清這山洞的真面目，緩緩地漫
步在這奇異的山洞裡，山壁的兩旁燃著火把，螢螢的火光照亮著漆黑的山洞
，一陣微風拂過臉龐，往北望去似乎可見微弱的光線在黑暗中忽隱忽現。
LONG);
	setup();
	replace_program(ROOM);
}
