inherit ROOM;
void create() {
	set( "short", "gem" );
	set( "owner", "hild" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount7"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount10" : 1,
		"amount6"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room215",
	]) );
	set( "light_up", 1 );
	set( "build", 10016 );
	set( "long", @LONG
太極無定，陰陽無常，太極陰陽殿堂上，掛著太上老君的畫像，此乃
太極陰陽之創始人之一，堂堂大殿上，充斥著軌異的氣息總是令你不
由自主的顫抖，彷彿隨時會被這股氣息吞沒，一時間你竟不知所措四
處張望...忽然...你看到不可思議的事情.嚇的你連忙拔腿就跑...
LONG);
	setup();
	replace_program(ROOM);
}
