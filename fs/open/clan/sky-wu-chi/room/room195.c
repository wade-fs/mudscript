inherit ROOM;
void create() {
	set( "short", "芷卉園" );
	set( "owner", "jsa" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount1"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount3"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-leggings",
	]) );
	set( "build", 10737 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room200.c",
		"east"      : "/open/clan/sky-wu-chi/room/room183",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
九重葛架成的花廊在你的上方展成一片綠蔭，紫紅
色的花朵隨著微風輕輕搖曳著，顯得婀娜多姿；園中遍
植各色花木，一年四季因時綻放蓓蕾，另有兩盆特別用
雕花白玉盆養著的芙蓉花，品名『清露』、『雨月』，
皆重重疊瓣清香淡淡，『清露』酷愛飲朝露而散清芬，
『雨月』偏好在近滿月的雨夜裏挺起一身冷豔，倒是兩
株奇異的花朵。
LONG);
	setup();
	replace_program(ROOM);
}
