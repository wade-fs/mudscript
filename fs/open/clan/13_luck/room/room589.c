inherit ROOM;
void create() {
	set( "short", "棄刀塚" );
	set( "owner", "gever" );
	set( "item_desc", ([
		"兔子" : @ITEM
ITEM,
	]) );
	set( "object", ([
		"amount9"  : 1,
		"amount10" : 1,
		"file10"   : "/open/fire-hole/obj/g-pill",
		"file9"    : "/open/killer/outsea/dstone",
		"amount5"  : 7,
		"amount4"  : 1,
		"file6"    : "/open/fire-hole/obj/k-pill",
		"file4"    : "/obj/gift/shenliwan",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 183,
		"file7"    : "/obj/gift/shenliwan",
		"file5"    : "/open/mon/obj/thousand-nectar",
		"amount2"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"amount7"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/capital/obj/4-3",
		"amount6"  : 1,
	]) );
	set( "build", 10080 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room593.c",
		"enter"     : "/open/clan/13_luck/room/room691",
	]) );
	set( "long", @LONG
經年的風霜雨露，在刀客的臉上刻下歲月的痕跡，卻無
改其冷澈的眼神，漫長的鏖戰殺戮，讓刀客的眼神更添一份
蒼茫；卻依然讓人無從捉摸，以刀寫下的債，就該以刀償還
，曾經是刀客心中唯一的信念，然而當生死恩仇，盡歸塵土
，也許當初持刀的那一刻就是個錯誤。只要心中有風，仇恨
的翅膀就會不停的轉動。當手刃群仇後，所帶來的只有心中
的空虛及無法平息的失落。多思無益，暫且棄刀，盡泯恩仇
，也許明天，又會有持刀的理由。


LONG);
	setup();
	replace_program(ROOM);
}
