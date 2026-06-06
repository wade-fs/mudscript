inherit ROOM;
void create() {
	set( "short", "冬雪的惡夢" );
	set( "object", ([
		"amount1"  : 1,
		"amount3"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"amount10" : 1,
		"file9"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"amount9"  : 1,
		"file3"    : "/obj/gift/shenliwan",
		"file5"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"file4"    : "/obj/gift/shenliwan",
	]) );
	set( "owner", "snowy" );
	set( "build", 10294 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room740",
	]) );
	set( "long", @LONG
身旁的嘶吼聲不知是來自陰慘的野風還是那些舐血的鬼怪，你的眼前是
一些漂浮不定的遊魂與奇怪的黑影，你正走在一段由人類碎骨所鋪設的白色
小道，喀擦喀擦的聲響讓你覺得於心不忍，這些骸骨是冬雪冒險曾經看過的
屍骸，如今徘徊不去而殘留在冬雪的夢境當中，你附近的獸人正在屍堆中尋
找肉塊大快朵頤，看起來噁心恐怖極了。
LONG);
	setup();
	replace_program(ROOM);
}
