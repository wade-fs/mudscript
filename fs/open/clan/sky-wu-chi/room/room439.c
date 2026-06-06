inherit ROOM;
void create() {
	set( "short", "聞古亭" );
	set( "owner", "imissyou" );
	set( "object", ([
		"amount10" : 1,
		"file6"    : "/open/capital/obj/4-3",
		"amount7"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file8"    : "/daemon/class/bonze/puty_pullium",
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/capital/obj/letter",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount1"  : 1,
		"file2"    : "/open/mogi/dragon/obj/sunblade",
	]) );
	set( "build", 10014 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room437",
	]) );
	set( "long", @LONG
李白二十五歲出蜀，目的就是訪道、求友和遊覽山水。他在《上安州裴長史書》中說：「以為士生
則桑弧蓬矢，射夫四方，故知大丈夫必有方之志，乃仗去國，辭親遠遊」，是很有抱負的。他離開
長江三峽東下，經荊門、江夏、到潯陽登廬山；訪金陵，遊揚州，浪跡吳、會之間；再回舟上，由
江夏泝漢水，過襄樊，走臨汝，其間曾與孟浩然相遇；又從臨汝到安陸(公元727年)，娶故相許圉
師孫女，開始“酒隱安陸，蹉跎十年”的生活。開元二十三年(公元735年)秋，曾應友人元之演之
邀，同遊太原祠。次年春天返返安陸不久，就移家東魯。

LONG);
	setup();
	replace_program(ROOM);
}
