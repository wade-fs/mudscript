inherit ROOM;
void create() {
	set( "short", "明日八傑武器室" );
	set( "owner", "tomorrow" );
	set( "object", ([
		"amount4"  : 1,
		"file3"    : "/open/ping/obj/poison_pill",
		"amount1"  : 400,
		"amount2"  : 261,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount6"  : 1,
		"file4"    : "/open/common/obj/liz_meat",
		"file6"    : "/open/common/obj/liz_meat",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/common/obj/liz_meat",
		"amount3"  : 345,
		"amount7"  : 1,
	]) );
	set( "build", 10122 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room736",
	]) );
	set( "long", @LONG

幔羅刀無影(Maun-shadow-blade)
凌微雲扇飄(Lin-cloud-fan)
閻匕影螫魂(Dark-soul-dagger)
雷火彩鳳翔(Fire-color-ribbon)
化劫菱歸真(Hwa-je-icer)
魔爪混天殺(Evil-kill-claw)
楓映天蓮劍(Fon-sky-sword)
刀斬邪元歸(Evil-gwe-blade)

牆上掛著一把一把的稀世武器  據說這些不但是稀有的武器
更是聚靈道裡不可或缺的道具  所以事先收集是有必要的
準備的越齊全  心理也就越踏實  離成功就越近

LONG);
	setup();
	replace_program(ROOM);
}
