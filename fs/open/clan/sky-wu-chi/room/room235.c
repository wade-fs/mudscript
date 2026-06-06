inherit ROOM;
void create() {
	set( "short", "armor" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount6"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount7"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount10" : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armor",
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room215",
	]) );
	set( "build", 10350 );
	set( "long", @LONG
乾無定，坤無常，乾坤殿堂上，掛著乾坤八卦圖，此乃
五行幻化之八卦合一，堂堂大殿上，雄壯的氣息總是不會缺
少，在乾坤八卦殿上，總覺得比一般的殿堂上還要有種不可思議
的力量存在，這裡也像其他殿上那像的平傭，你不知不覺走入後
，彷彿被殿中的八卦陣給迷惑了，一時間竟不知如何是好....
LONG);
	setup();
	replace_program(ROOM);
}
