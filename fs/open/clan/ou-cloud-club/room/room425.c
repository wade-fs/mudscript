inherit ROOM;
void create() {
	set( "short", "實驗室指揮中心" );
	set( "object", ([
		"amount6"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/poison/obj/armband1",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/mogi/castle/obj/lochagem",
		"amount3"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"file8"    : "/open/firedancer/npc/eq/r_hands",
		"file1"    : "/open/firedancer/npc/eq/r_boots",
		"file10"   : "/open/firedancer/npc/eq/r_pants",
	]) );
	set( "item_desc", ([
		"menu" : @ITEM
東方-皮鞭研發中心
南方-實驗室專用倉庫
西方-阿魯發研究室
北方-一隻筆實驗室

附註： 請勿隨變更動實驗室的設定 否則造成生產系統當機 則必阿魯巴驅之別院
ITEM,
	]) );
	set( "build", 10548 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room469.c",
		"west"      : "/open/clan/ou-cloud-club/room/room423.c",
		"east"      : "/open/clan/ou-cloud-club/room/room422.c",
		"out"       : "/open/clan/ou-cloud-club/room/room426.c",
		"up"        : "/open/clan/ou-cloud-club/room/room486",
		"south"     : "/open/clan/ou-cloud-club/room/room421.c",
		"north"     : "/open/clan/ou-cloud-club/room/room424.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
進入這房間後,你發現這裡正是整個實驗室的中心所在,而地
上散佈了各種實驗的數據,可見主人沒空整理環境,當你環顧四方
時,也發現了原來四周都是不同種類的實驗室,只是不知道那些實
驗事是作何功用的,不過地上擺了一本實驗室手冊。

一本說明實驗室工作內容的工作手冊(Menu)

LONG);
	setup();
	replace_program(ROOM);
}
