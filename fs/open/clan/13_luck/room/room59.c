inherit ROOM;
void create() {
	set( "short", "歹勇仔的窩" );
	set( "owner", "biob" );
	set( "item_desc", ([
		"dog" : @ITEM
一隻忠心看守歹勇仔小窩的小土狗
ITEM,
		"狗狗" : @ITEM
一隻看守歹勇仔小窩的狗狗
ITEM,
	]) );
	set( "object", ([
		"file9"    : "/open/killer/obj/fire-knife",
		"file3"    : "/open/magic-manor/obj/golden-ball",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/magic-manor/obj/soil-ball",
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/obj/fire-ball",
		"amount1"  : 1,
		"file1"    : "/open/killer/obj/fire-knife",
		"file8"    : "/open/magic-manor/obj/wood-ball",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10119 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room54.c",
		"enter"     : "/open/clan/13_luck/room/room120",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

                      十惡不赦

大大的扁額透露出當初amdmp 看上biob並收編十三吉祥的宏大眼光
也許你該小心謹慎地踏進這十分邪惡的地方, 說不定踩錯一步, 嘿
嘿....也許不會發生什麼事也不一定, 畢竟十三吉祥的地盤, 怎麼
能容許這種步步危機的地方存在呢? 也許歹勇仔是個面惡心善的人
只是當初加入惡人谷是他最大的抉擇, 一想到這裡, 你更加堅定決
定再進一步想認識歹勇仔......... 

狗狗(Dog)

LONG);
	setup();
	replace_program(ROOM);
}
