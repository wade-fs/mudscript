inherit ROOM;
void create() {
	set( "short", "$HIB$活米村$HIC$二景$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount5"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount6"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-boots",
	]) );
	set( "owner", "car" );
	set( "build", 11182 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room31.c",
		"north"     : "/open/clan/time-limit/room/room7.c",
		"east"      : "/open/clan/time-limit/room/room30.c",
		"south"     : "/open/clan/time-limit/room/room29",
	]) );
	set( "long", @LONG
活米村是全英國唯一一個全是巫師的村子,在這裡巫師
不必隱藏巫師的身份,可以盡情使用魔法而無所顧忌,
而霍格華茲三年級以上的學生更可以在週末到活米村玩
使得這個村落更為熱鬧,不遠處的尖叫屋是著名的景點,
還有豬頭酒吧更是怪胎們聚集的場所 

LONG);
	setup();
	replace_program(ROOM);
}
