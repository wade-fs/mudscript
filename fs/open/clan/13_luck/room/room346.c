inherit ROOM;
void create() {
	set( "short", "兵器重地" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "owner", "kaien" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room237.c",
		"north"     : "/open/clan/13_luck/room/room352.c",
		"west"      : "/open/clan/13_luck/room/room156",
	]) );
	set( "build", 10463 );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡有一個兵器架(rack)，十八般兵刃樣樣齊全。架子旁邊掛著數
十副閃閃發光的盔甲(armor)，腰帶(blet)，和戰靴(boots)等物。旁邊
一位將軍正閉目養神，看來可以跟他要一副以攻擊性為主的裝備或是以
防禦為主要的裝備，穿上不同性質的裝備會有不同的效果。

LONG);
	setup();
	replace_program(ROOM);
}
