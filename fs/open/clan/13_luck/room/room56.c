inherit ROOM;
void create() {
	set( "short", "仙屋藏豆" );
	set( "owner", "biob" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room108",
	]) );
	set( "object", ([
		"file9"    : "/obj/stone/powder",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount8"  : 221,
		"amount4"  : 142,
		"amount5"  : 19,
		"file6"    : "/open/fire-hole/obj/p-pill",
		"amount3"  : 300,
		"file5"    : "/obj/stone/suipian",
		"amount1"  : 166,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file8"    : "/open/fire-hole/obj/b-pill",
		"file4"    : "/obj/stone/jiao",
		"amount9"  : 168,
		"amount6"  : 120,
	]) );
	set( "build", 10072 );
	set( "light_up", 1 );
	set( "long", @LONG

這裡是小二擺防具的地方
看起來好像有一些奇怪的地方
ㄟ....
你看到牆角...
那裡居然擺著diamond eq...
這...
你開始懷疑小二怎可能打的到
大概是他花了很多錢去跟人家買的吧
不過
還有一些 force eq...
如果需要的話
可以問一下小二
他應該會借你..
如果他沒有再發呆的話

LONG);
	setup();
	replace_program(ROOM);
}
