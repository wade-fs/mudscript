inherit ROOM;
void create() {
	set( "short", "瀟湘館" );
	set( "owner", "jsa" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount7"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10119 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room190",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
你來到一處幽靜的屋宇，門首懸著個小匾額，乃是
一方木片以利刃削出『瀟湘館』三字；雕著細花格子的
窗櫺頗見巧思，上面還設著若干小橫木，供鸚鵡翱翔棲
息；館外一排湘妃竹，隨風輕輕搖落，沙沙輕響彷彿聞
人長嘆，幸而有鸚語稍減這寂寂蕭瑟之意；不遠處的芷
卉園不時傳來花香淡淡。
LONG);
	setup();
	replace_program(ROOM);
}
