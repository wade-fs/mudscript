inherit ROOM;
void create() {
	set( "short", "$HIC$思量之家$HIW$佛堂$NOR$" );
	set( "owner", "cdrom" );
	set( "object", ([
		"amount10" : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"file1"    : "/open/dancer/obj/yuawaist",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/prayer/obj/boris-cloth",
		"amount6"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/scholar/obj/icefan",
		"amount4"  : 1,
		"amount8"  : 1,
		"file4"    : "/daemon/class/fighter/armband",
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/scholar/obj/s_hands",
	]) );
	set( "build", 12012 );
	set( "light_up", 1 );
	set( "item_desc", ([
		"念佛機" : @ITEM
思量就隨著這台念佛機在這邊念佛  ^^
ITEM,
	]) );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room132",
	]) );
	set( "long", @LONG


    爾時世尊,從肉髻中,
    湧百寶光,光中湧出,
    千葉寶蓮,有化如來,
    坐寶花中,頂放十道,
    百寶光明,一一光明,
    皆遍示現,十恒河沙,
    金剛密跡,擎山持杵,
    遍虛空界,大眾仰觀,
    畏愛兼抱,求佛哀祐,
    一心聽佛,無見頂相,
    放光如來,宣說神咒.


南無薩怛他  蘇伽多耶  阿囉訶帝
....................
....................
角落擺台小小黑色的機器,你仔細觀察發現是台<念佛機>.


LONG);
	setup();
	replace_program(ROOM);
}
