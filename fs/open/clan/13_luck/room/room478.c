inherit ROOM;
void create() {
	set( "short", "天璽客棧" );
	set( "object", ([
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/obj/gift/shenliwan",
		"file9"    : "/open/magic-manor/obj/sun-heart",
		"amount1"  : 1,
		"file4"    : "/open/capital/obj/4-1",
		"amount4"  : 1,
		"amount9"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"file10"   : "/open/magic-manor/obj/sun-heart",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file5"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
	]) );
	set( "owner", "zmud" );
	set( "build", 10006 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room482.c",
		"west"      : "/open/clan/13_luck/room/room477.c",
		"east"      : "/open/clan/13_luck/room/room475",
	]) );
	set( "long", @LONG

    店號是邑陽城內最負盛名的天璽客棧。店面寬敞，店內裝潢可謂十
分精緻，更提供了窗明几淨的雅座。飲食方面，店裡許多道菜餚聞名遐
邇，甚至有異域人士也特來品嚐；若你是趕路人，店家備有多種乾糧、
水酒，只須翻閱菜單(list)即可選購。當然，客棧中設有上等套房供客
夜宿。

LONG);
	setup();
	replace_program(ROOM);
}
