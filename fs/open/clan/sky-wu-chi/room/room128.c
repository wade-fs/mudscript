inherit ROOM;
void create() {
	set( "short", "$HIC$思量之家$HIW$地窖$NOR$" );
	set( "owner", "salicili" );
	set( "light_up", 1 );
	set( "build", 10937 );
	set( "object", ([
		"file7"    : "/open/capital/room/king/obj/dagger1",
		"file5"    : "/open/capital/guard/gring",
		"amount3"  : 100,
		"amount1"  : 7,
		"amount7"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount10" : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
		"file3"    : "/open/doctor/pill/sky_pill",
		"file1"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room368",
		"up"        : "/open/clan/sky-wu-chi/room/room41.c",
	]) );
	set( "long", @LONG
地窖門一開,陣陣醇厚的醇酯香便撲鼻而來,
這誘人的酒香驅使你一探究竟,
忽然一陣寒風由下方湧出,
你走到最下階才發現地板滑滑濕濕的,
蹲下來一摸,才發覺是冰塊,
冰塊加上暗藏的陳年好酒,讓你不禁羨慕起思量優裕的生活,
$HIC$燕仔$NOR$又如幽魂班從旁冒出,
雙眼一瞪 喝道{你幾時偷藏這些好酒?不會又偷花公費吧?}
LONG);
	setup();
	replace_program(ROOM);
}
