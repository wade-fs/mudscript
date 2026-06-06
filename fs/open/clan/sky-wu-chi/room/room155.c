inherit ROOM;
void create() {
	set( "short", "$HBGRN$$HIB$阿嚕米的大廳$NOR$" );
	set( "owner", "cong" );
	set( "object", ([
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"file3"    : "/open/mogi/dragon/obj/water-1",
	]) );
	set( "light_up", 1 );
	set( "build", 11366 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room110.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"west"      : "/open/clan/sky-wu-chi/room/room167",
	]) );
	set( "long", @LONG
這裡便是令整個武林聞風喪膽的〔$CYN$黑牙聯殺手$NOR$～$HIR$寂雲$NOR$〕
的住所，阿嚕米是他的小名，跟他不熟的人可別這麼叫他，
擔心惹來殺身之禍。他正在跟〔$CYN$黑牙聯天才機關手$NOR$～$HIR$諸岡渡$NOR$
〕商討一些重大秘密，似乎要讓整個武林掀起一陣腥風血雨
，但你卻聽不懂他們的話語，原來他們正用殺手的語言在溝
通。
LONG);
	setup();
	replace_program(ROOM);
}
