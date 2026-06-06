inherit ROOM;
void create() {
	set( "short", "核子試爆中心" );
	set( "object", ([
		"file9"    : "/obj/gift/shenliwan",
		"file10"   : "/obj/gift/shenliwan",
		"file5"    : "/obj/gift/shenliwan",
		"file8"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"amount4"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount9"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"file4"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10023 );
	set( "owner", "ctx" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room469",
	]) );
	set( "long", @LONG
一進入這間房間, 你發現一堆研究人員都穿者相當怪的防護
衣仔細一問才發現,原來這邊就是核子武器測試場,在這裡沒穿防
護衣的話小心自己的下一代就這樣不見了, 當然如果你對這種武
器有興趣的話,也歡迎加入這裡的研究團隊,但是請注意自身安全

LONG);
	setup();
	replace_program(ROOM);
}
