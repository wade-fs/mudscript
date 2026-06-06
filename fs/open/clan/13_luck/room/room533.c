inherit ROOM;
void create() {
	set( "short", "迴雲廊道" );
	set( "owner", "mill" );
	set( "object", ([
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10146 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room497",
		"east"      : "/open/clan/13_luck/room/room532",
	]) );
	set( "long", @LONG

　　你沿著迴雲廊道而行，只見一漾清流漫出，自花木芬芳深處瀉於
石隙之下。突而轉過一角，只見穿花度柳，扶出薜荔蘿藤，更有櫻穗
遮天，實若丹彤，花若金桂。偷再向裡一望，霜石岭嶒縱橫拱立而上
，藤蘿掩映，三方迎覽。

LONG);
	setup();
	replace_program(ROOM);
}
