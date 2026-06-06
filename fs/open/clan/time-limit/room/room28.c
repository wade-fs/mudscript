inherit ROOM;
void create() {
	set( "short", "$BRED$霍格$BGRN$華茲$BBLU$特$BMAG$快$BCYN$車$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armor",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10033 );
	set( "exits", ([
		"up"        : "/open/clan/time-limit/room/room27",
		"out"       : "/open/clan/time-limit/room/room29.c",
	]) );
	set( "long", @LONG
霍格華茲特快車內坐滿霍格華茲的學生,互相交談並且炫耀自己的新寵物,
奈威-隆巴頓正把他的蟾蜍-吹寶-捧在手心,不過吹寶一下就跳開了,
一位女巫推著裝滿零食的推車走過來,裡頭的東西真不少,
有太妃糖和巧克力蛙,最特別的就是柏蒂全口味豆,說是全口味豆就真的是
所有口味都有,聽說有人吃到耳垢口味的豆子,從此就不敢再吃了

LONG);
	setup();
	replace_program(ROOM);
}
