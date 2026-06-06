inherit ROOM;
void create() {
	set( "short", "秘密訓練埸 - " );
	set( "owner", "zeros" );
	set( "object", ([
		"file4"    : "/obj/gift/shenliwan",
		"amount10" : 1,
		"file5"    : "/obj/gift/shenliwan",
		"file10"   : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"amount7"  : 1,
		"file3"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10140 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room119",
	]) );
	set( "long", @LONG
這裡就是鼎鼎有名的湖心小築的夜夢宮所有人的訓練埸所，能加入這裡修業的
精英分子都是通過嚴苛的考驗的湖心小築的高深隱士。能成為湖心小築的高深
隱士的一份子是所有湖心小築的隱士夢寐以求的殊榮。牆上有一張公告(sign)﹐
來提醒高深隱士如何使用這個練習場。
LONG);
	setup();
	replace_program(ROOM);
}
