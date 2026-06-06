inherit ROOM;
void create() {
	set( "short", "$HIY$尖叫$HIB$屋外$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10020 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room11",
	]) );
	set( "long", @LONG
尖叫屋是全英國鬧鬼鬧的最兇的一棟建築,也因為鬧鬼使得旁邊
沒有任何住家,門口也被封住,就是怕有人進去後會出事,
不過聽說活米村有許多秘密通道,說不定有通到可以到尖叫屋裡,
屋裡忽然傳來一陣狼嚎,聽說狼人在滿月時變身,
會把人生吞活剝,今晚又是滿月,嚇的你拔腿就跑

LONG);
	setup();
	replace_program(ROOM);
}
