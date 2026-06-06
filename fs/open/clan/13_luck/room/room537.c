inherit ROOM;
void create() {
	set( "short", "滌心園" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount10" : 3,
		"amount4"  : 3,
		"file8"    : "/obj/poison/five_poison",
		"file10"   : "/open/fire-hole/obj/y-pill",
		"file9"    : "/open/fire-hole/obj/k-pill",
		"amount5"  : 12383,
		"amount9"  : 5,
		"file7"    : "/obj/poison/rose_poison",
		"amount8"  : 13335,
		"amount6"  : 18950,
		"file2"    : "/open/prayer/obj/boris-cloth",
		"file6"    : "/obj/poison/dark_poison",
		"file5"    : "/obj/poison/faint_poison",
		"amount2"  : 1,
		"amount7"  : 18203,
		"file4"    : "/obj/stone/jiao",
	]) );
	set( "outdoors", "/open/clan/13_luck" );
	set( "item_desc", ([
		"小亭" : @ITEM
矗立於花池中的小涼亭，亭內擺設著數張可供遊客休憩的小石椅。
ITEM,
	]) );
	set( "build", 10209 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room100",
	]) );
	set( "long", @LONG

    轉身穿過月落門後，落入眼中的是由各種奇珍花木所構造成的庭
園。腳下的周迴外廊順延著莫名的規律延伸往園裡去，開擴了景深，
也因為遊廊穿行於各種奇花怪木的鮮豔美景之間，令人彷彿是置身於
花叢間的狂蜂浪蝶，不禁地被園中的景觀所吸引。
    迴廊左方坐落個花池，池中盛開的花朵雖不如岸邊的惹人，但在
池中確有一六角的小亭矗立於其中，花葉隨著水波的蕩漾，使得六角
小亭似乎也隨之漂泊不定。小亭和迴廊走道靠著一條只容單人通行的
小木橋連結著。

LONG);
	setup();
	replace_program(ROOM);
}
