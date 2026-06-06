inherit ROOM;
void create() {
	set( "short", "StarTrek-DS9" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"file2"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"amount4"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/shenliwan",
		"file5"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
		"amount6"  : 1,
		"file7"    : "/obj/gift/shenliwan",
	]) );
	set( "build", 11082 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room545",
	]) );
	set( "long", @LONG
StarTrek的第三部作品，DS9即Deep Space 9的縮寫(深太空
9號)，這部作品台灣並沒有電視台播過，所以認識的人較少，而
ctx本人也沒看過，只是看過部份敘述性的劇情,而這部的作品主
要在講述與同TNG同時代中聯邦一個遠在邊界的前哨站的故事,裡
面的主角自從天狼星之役後父親死亡(天狼星之役與TNG有關),主
角被轉調DS9的行政長官，與邊境上的各種種族的交手的故事,在
所有StarTrek系列中，這個系列算是比較灰暗的，裡面對於人性
的論述比較偏向於黑暗面。

LONG);
	setup();
	replace_program(ROOM);
}
