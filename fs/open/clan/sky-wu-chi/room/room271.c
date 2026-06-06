inherit ROOM;
void create() {
	set( "short", "$HIY$鑄劍池$NOR$" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/xiandan",
		"file9"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file4"    : "/obj/gift/bingtang",
		"file2"    : "/obj/gift/shenliwan",
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file5"    : "/obj/gift/unknowdan",
	]) );
	set( "build", 10042 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room221.c",
		"north"     : "/open/clan/sky-wu-chi/room/room119",
	]) );
	set( "long", @LONG
四周擺滿了一堆材料，各式各樣的鋼材還有劍身靠在牆邊，
一池清澈的水擺在火爐邊，火爐裡的木炭正在熊熊的燃燒著，四
周的溫度十分的高，你不經留下汗來，正當你走出來時卻踢到一
塊漆黑的東西，你心想莫非這是傳說中的玄鐵嗎？？？
LONG);
	setup();
	replace_program(ROOM);
}
