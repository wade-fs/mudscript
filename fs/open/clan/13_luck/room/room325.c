inherit ROOM;
void create() {
	set( "short", "狂龍殿" );
	set( "owner", "mill" );
	set( "object", ([
		"amount4"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount10" : 1,
		"amount8"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount9"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount7"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
	]) );
	set( "build", 14145 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room128.c",
		"south"     : "/open/clan/13_luck/room/room343",
	]) );
	set( "long", @LONG

　　一路來到這，如此的近距離看這狂龍殿，更是覺的壯麗無比，兩
扇厚重的銅門上刻畫著雙龍奪珠。推開銅門進到殿內，中央走道鋪著
血凶狼做成的毛毯，而兩旁的四根大理石做成的巨大柱子，分別刻著
青龍、朱雀、玄武、白虎。在毛毯的盡頭放著一張巨大的龍椅，上頭
鋪著極為罕見的雪狼皮。而在龍椅後頭的壁上，掛著一幅碩大的扁額
，上頭刻著「　傲　世　狂　龍　」四個斗大的字。

LONG);
	setup();
	replace_program(ROOM);
}
