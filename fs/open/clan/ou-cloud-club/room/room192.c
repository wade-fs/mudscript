inherit ROOM;
void create() {
	set( "short", "神秘地帶" );
    set( "owner", "nanako" );
	set( "object", ([
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file8"    : "/open/snow/obj/stone",
		"amount6"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "item_desc", ([
		"製造" : @ITEM
test
ITEM,
	]) );
	set( "build", 12831 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room184.c",
		"east"      : "/open/clan/ou-cloud-club/room/room566",
	]) );
	set( "long", @LONG
來到此區你感到莫名的神秘, 據說武林中最神秘的神秘人物藏神秘就是藏身於此,
從來無人能夠了解他的經歷與背景, 或許你也是對於如此神秘的人物感興趣才來到這裡
四周黑暗卻不斷出現的七彩光芒, 更是把此人神秘的色彩加深, 傳聞中來此探查秘密者
都一去不歸, 你最好提高警覺免得成為下一個失蹤人口
LONG);
	setup();
	replace_program(ROOM);
}
