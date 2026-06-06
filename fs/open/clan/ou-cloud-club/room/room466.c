inherit ROOM;
void create() {
	set( "short", "生化武器實驗室" );
	set( "object", ([
		"amount8"  : 1,
		"amount6"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"file7"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/xiandan",
		"file10"   : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"file5"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"file6"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10397 );
	set( "item_desc", ([
		"paper" : @ITEM
目前研究項目有:
  1.SARS
  2.AIDS
  3.禽流感
  4.項目繁多不備載
ITEM,
	]) );
	set( "owner", "ctx" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room469",
	]) );
	set( "long", @LONG
一進入這裡,你發現這裡的桌子上放滿了各式各樣的器皿,於
是你就用桌上的顯微鏡一看, 原來器皿裡面都是各式各樣的病毒
和細菌,這時你才驚覺到,原來這裡就是全狂想中最大的生化武器
實驗室,當然,進出此地都要經過嚴格的消毒, 如果忘了消毒的步
驟,那你準備乖乖被隔離吧,另外牆上貼了一張紙(paper),上面寫
著現在正在研究的細菌及病毒。

LONG);
	setup();
	replace_program(ROOM);
}
