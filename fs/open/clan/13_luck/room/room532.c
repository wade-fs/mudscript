inherit ROOM;
void create() {
	set( "short", "迴雲廳" );
	set( "owner", "mill" );
	set( "object", ([
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
	]) );
	set( "build", 10270 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room533",
	]) );
	set( "long", @LONG

   此地四面皆是雕空玲瓏木，或流雲之貌，或山水人物，或翎毛花
卉，或奇思集錦，或鑑今博古，或萬福萬壽，均是名手雕縷，旁有遊
雲小閣，或儲書設鼎，或安硯置墨，或供瓶安景，或栽花植草，柳椅
聯成三方一應向外。
LONG);
	setup();
	replace_program(ROOM);
}
