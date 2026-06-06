inherit ROOM;
void create() {
	set( "short", "$HIG$三年級生$HIY$教室$NOR$" );
	set( "owner", "wateribbon" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10304 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room59.c",
		"east"      : "/open/clan/time-limit/room/room54.c",
		"west"      : "/open/clan/time-limit/room/room33",
		"north"     : "/open/clan/time-limit/room/room58.c",
	]) );
	set( "long", @LONG
一群三年級生從身旁走過,興奮的說到週末可以到活米村玩,
原來三年級生開始可以在週末到活米村玩,不過最近發生了
一件事讓這項活動受到了考驗,那就是天狼星布萊克從
阿茲卡班逃獄成功,並且有證據顯示他將會到霍格華茲,
學校裡的安全措施讓人放心,但是學校外的活米村就不一定了

LONG);
	setup();
	replace_program(ROOM);
}
