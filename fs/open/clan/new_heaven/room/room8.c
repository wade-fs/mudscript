inherit ROOM;
void create() {
	set( "short", "$HIC$內堂$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/open/dancer/obj/yuawaist",
		"amount1"  : 1,
		"amount2"  : 1,
		"file1"    : "/u/b/bss/ring-4",
	]) );
	set( "owner", "xing" );
	set( "exits", ([
		"out"       : "/open/clan/new_heaven/room/room7",
	]) );
	set( "long", @LONG
這裡是傲笑紅塵用來放東西的地方, 牆上掛著一副圖, 上面有一
把劍, 用古體寫著[羽情]二字, 看來這就是傲笑紅塵的佩劍了
LONG);
	setup();
	replace_program(ROOM);
}
