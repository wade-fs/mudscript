inherit ROOM;
void create() {
	set( "short", "浪花一朵朵" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 11667 );
	set( "exits", ([
		"up"        : "/open/clan/nine-sky-dragon/room/room25.c",
		"out"       : "/open/clan/nine-sky-dragon/room/room16.c",
		"west"      : "/open/clan/nine-sky-dragon/room/room23.c",
		"east"      : "/open/clan/nine-sky-dragon/room/room24.c",
		"north"     : "/open/clan/nine-sky-dragon/room/room21.c",
		"down"      : "/open/clan/nine-sky-dragon/room/room26",
		"south"     : "/open/clan/nine-sky-dragon/room/room22.c",
	]) );
	set( "long", @LONG
我要你陪著我 看著那海龜水中游 慢慢的爬在沙灘上 數著浪花一朵朵
你不要害怕 你不會寂寞 我會一直陪在無左右 讓你樂悠悠
日子一天一天過 我們會慢慢長大 我不管你懂不懂我在唱什麼
我知道有一天 你 一定會愛上我 因為我覺得我真的很不錯
時光匆匆匆匆流走 也也恢不回頭 美女變成老太婆
哎喲 那那那個時候 我我我我也也 已經變成糟老頭
啦啦~我們一起手牽手 啦啦~數著浪花一朵朵

LONG);
	setup();
	replace_program(ROOM);
}
