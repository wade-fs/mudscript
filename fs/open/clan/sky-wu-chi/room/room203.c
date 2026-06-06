inherit ROOM;
void create() {
	set( "short", "防具房間" );
	set( "owner", "yuki" );
	set( "object", ([
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file9"    : "/open/marksman/obj/arrow-g",
		"amount8"  : 1,
		"amount9"  : 90000,
		"file1"    : "/obj/gift/xisuidan",
		"amount10" : 9998,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/magic-manor/obj/magic-sign",
		"file10"   : "/open/marksman/obj/arrow-g",
		"file3"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10830 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room162",
		"west"      : "/open/clan/sky-wu-chi/room/room201.c",
	]) );
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
