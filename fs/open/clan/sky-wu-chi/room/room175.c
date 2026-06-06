inherit ROOM;
void create() {
	set( "short", "機器人一號之製造工廠" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "object", ([
		"amount4"  : 1,
		"file4"    : "/open/tendo/obj/chaosbelt",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount6"  : 1,
		"amount7"  : 19,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/open/ping/obj/poison_pill",
		"amount5"  : 29,
		"amount3"  : 1,
		"file8"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file3"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
		"file2"    : "/open/capital/guard/gring",
		"amount8"  : 20,
		"amount10" : 64,
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10029 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room278.c",
		"north"     : "/open/clan/sky-wu-chi/room/room279.c",
		"south"     : "/open/clan/sky-wu-chi/room/room70.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room272.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room280.c",
		"down"      : "/open/clan/sky-wu-chi/room/room176",
		"west"      : "/open/clan/sky-wu-chi/room/room281.c",
	]) );
	set( "long", @LONG
地窖門一開,陣陣醇厚的醇酯香便撲鼻而來,
你雖被眼前的黑暗籠罩著,
但這誘人的酒香驅使你一探究竟,
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
