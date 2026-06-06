inherit ROOM;
void create() {
	set( "short", "吟風小築" );
	set( "owner", "jsa" );
	set( "object", ([
		"amount5"  : 39,
		"amount1"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/mon/obj/mon-pill",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 4,
		"amount4"  : 1,
		"file3"    : "/obj/stone/powder",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/capital/obj/4-4",
	]) );
	set( "build", 10006 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room195.c",
		"out"       : "/open/clan/sky-wu-chi/room/room58.c",
		"west"      : "/open/clan/sky-wu-chi/room/room188.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"north"     : "/open/clan/sky-wu-chi/room/room190.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
山風徐徐吹來，將籠罩著的薄霧吹散，定
眼一看，已來到了吟風小築門前；這世上有流傳著
這麼一句話，沒參觀過吟風小築的人這一生算是白
活了，看這宅第蒼松環抱難辨大小，一色的白牆灰
瓦相當素雅，門口兩隻石獅子張嘴微笑著，似乎也
安於這隱世獨立般的情調。
LONG);
	setup();
	replace_program(ROOM);
}
