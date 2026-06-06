inherit ROOM;
void create() {
	set( "short", "$HIR$走$HIY$廊$NOR$" );
	set( "owner", "goldblade" );
	set( "object", ([
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
	]) );
	set( "build", 10585 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room70",
		"south"     : "/open/clan/time-limit/room/room72.c",
		"north"     : "/open/clan/time-limit/room/room71.c",
		"east"      : "/open/clan/time-limit/room/room9.c",
	]) );
	set( "long", @LONG
長長的走廊上有著一些武士的盔甲,好像在守衛著學校的安全,牆上的畫像
全都會動,甚至會離開原本的畫到其他的畫裡串門子,卡多甘爵士正追著
他的小馬越跑越遠了,管理員-飛七在走廊上清理學生惡作劇所丟的屎炸彈,
一邊清一邊唸唸有詞的要把惡作劇的學生吊起來打,飛七的愛貓
-拿樂絲太太-則在飛七身旁打轉

LONG);
	setup();
	replace_program(ROOM);
}
