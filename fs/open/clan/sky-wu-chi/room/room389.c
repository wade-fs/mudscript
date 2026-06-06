inherit ROOM;
void create() {
	set( "short", "酹江月" );
	set( "owner", "intel" );
	set( "object", ([
		"amount10" : 1,
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10218 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room217",
		"up"        : "/open/clan/sky-wu-chi/room/room388",
	]) );
	set( "long", @LONG

水天空闊，恨東風、不惜世間英物。

蜀鳥吳花殘照裏，忍見荒城頹壁！

銅雀春情，金人秋淚，此恨憑誰雪！

堂堂劍氣，鬥牛空認奇傑。

那信江海餘生，南行萬里，屬扁舟齊發。

正為鷗盟留醉眼，細看濤生雲滅。

睨柱吞嬴，回旗走懿，千古衝冠髮。

伴人無寐，秦淮應是孤月。



LONG);
	setup();
	replace_program(ROOM);
}
