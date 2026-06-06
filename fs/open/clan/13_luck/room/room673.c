inherit ROOM;
void create() {
	set( "short", "神祕洞穴" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount9"  : 1,
		"file8"    : "/open/main/room/sp/stone",
		"file9"    : "/daemon/class/taoist/necromancy/npc/obj/golden_sword",
		"file7"    : "/open/fire-hole/obj/k-pill",
		"file1"    : "/open/ping/questsfan/obj/stone",
		"amount8"  : 1,
		"amount7"  : 10,
		"amount4"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/fire-hole/obj/g-pill",
		"amount5"  : 4,
		"amount2"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"file4"    : "/open/killer/obj/dagger",
	]) );
	set( "build", 10087 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room675",
	]) );
	set( "long", @LONG
    前面有一道閃光,你好奇的跟著閃光走,眼前突然出先一頭
黃色巨龍,嘴中還泛著紅光,像是要噴出灼熱的火焰!!你整個人
急忙蹲在地上,絲毫不趕動,過了許久,並沒有什麼事情發生,你
好奇的抬了頭,才發現原來這頭異獸是用神秘的鱗片所拼出來.

LONG);
	setup();
	replace_program(ROOM);
}
