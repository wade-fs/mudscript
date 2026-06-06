inherit ROOM;
void create() {
	set( "short", "$HIW$白龍居$NOR$" );
	set( "owner", "yuki" );
	set( "object", ([
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount6"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount7"  : 1,
		"file7"    : "/open/mogi/castle/obj/white-ghost-head",
		"amount5"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount3"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10195 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room343.c",
		"east"      : "/open/clan/sky-wu-chi/room/room287.c",
		"out"       : "/open/clan/sky-wu-chi/room/room119.c",
		"north"     : "/open/clan/sky-wu-chi/room/room344.c",
		"west"      : "/open/clan/sky-wu-chi/room/room250.c",
	]) );
	set( "long", @LONG
$HIC$飄落的花雪在空中慢慢的落下，寒風瀟瀟更增加了幾分冷意，這
場大雪是多麼的美麗，房內裡面雖不是很華麗，但是讓人感到溫文儒
雅，龍總非池中物，$HIW$「白龍居」$NOR$$HIC$果然名不虛傳，而牆角上掛著一幅牌
匾上面所寫的正是「傲世群雄」。$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
