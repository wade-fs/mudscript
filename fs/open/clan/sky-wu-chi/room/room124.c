inherit ROOM;
void create() {
	set( "short", "空瓶子EQ收藏室" );
	set( "object", ([
		"amount3"  : 1,
		"file4"    : "/open/dancer/obj/yuawaist",
		"file3"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount2"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/mon/obj/mon_item",
		"file2"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount4"  : 1,
		"amount10" : 1,
		"file10"   : "/open/mon/obj/beast_claw",
	]) );
	set( "light_up", 1 );
	set( "build", 10228 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"east"      : "/open/clan/sky-wu-chi/room/room125.c",
		"out"       : "/open/clan/sky-wu-chi/room/room117.c",
	]) );
	set( "long", @LONG
這裡的防具和兵器數量之多可真是讓你感到不可思議,感覺就是要把
這個FS的所有有名的EQ及WP都收集起來了..你看ㄚ看的你看到了一個指
引..要看兵器的往東邊要看防具的往西邊..要看寶物的就往北邊..至
於一些不知名的東西時就也許要讓你猜猜了..因為連主人也不知道有啥
麼用處 ...

LONG);
	setup();
	replace_program(ROOM);
}
