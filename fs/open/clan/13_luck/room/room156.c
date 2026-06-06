inherit ROOM;
void create() {
	set( "short", "劍缺" );
	set( "owner", "kaien" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room346",
	]) );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/gsword/obj/may_ring",
		"file1"    : "/open/scholar/obj/icefan",
		"file2"    : "/daemon/class/fighter/figring",
	]) );
	set( "build", 10690 );
	set( "light_up", 1 );
	set( "long", @LONG

    你費了一翻心力，走上了『劍缺』，你不禁把衣服拉緊了些，所謂
的高處不勝寒應該就是這樣吧，此處寒風刺骨，地上居然還有幾片殘雪
，可是你眼前還有一個比雪更白，比冰更冷的人，他穿著單薄的衣裳，
站在這裡不動以久，你更發現，這裡的巨岩缺了一腳，難道是被他用劍
所劈的？？劍缺，是缺情、缺愛、還是缺恨？？？

LONG);
	setup();
	replace_program(ROOM);
}
