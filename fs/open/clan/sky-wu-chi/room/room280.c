inherit ROOM;
void create() {
	set( "short", "資源回收區" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "object", ([
		"amount10" : 1,
		"amount6"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"amount3"  : 33,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 1,
		"file8"    : "/open/gblade/obj/sa-head",
		"amount9"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/gsword/obj1/sadsword",
		"file9"    : "/open/snow/obj/cold_pill",
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"file10"   : "/obj/gift/xiandan",
	]) );
	set( "build", 10030 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room314",
		"east"      : "/open/clan/sky-wu-chi/room/room341.c",
		"west"      : "/open/clan/sky-wu-chi/room/room175.c",
	]) );
	set( "long", @LONG

這是機器人一號ㄉ資源回收區,裡面收齊ㄌ許多能回收ㄉ資源;

在別人ㄉ眼裡全是不值錢ㄉ垃圾,在機器人一號ㄉ眼裡卻是能回收ㄉ資源

一些值得他回收ㄉ資源;這時你不由得懷疑機器人一號ㄉ眼睛長在哪裡;

竟然收集ㄌ那麼多ㄉ垃圾

LONG);
	setup();
	replace_program(ROOM);
}
