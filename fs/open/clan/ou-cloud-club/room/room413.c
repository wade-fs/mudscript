inherit ROOM;
void create() {
	set( "short", "風雲閣" );
	set( "owner", "alus" );
	set( "object", ([
		"file7"    : "/open/doctor/pill/ice_pill",
		"file10"   : "/open/mogi/castle/obj/sspill",
		"amount1"  : 233,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/quests/snake/npc/obj/snake-key-1",
		"amount3"  : 624,
		"amount7"  : 243,
		"file9"    : "/obj/gift/lingzhi",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/quests/snake/npc/obj/snake-key-1",
		"amount4"  : 1,
		"file5"    : "/open/ping/obj/poison_pill",
		"file2"    : "/obj/gift/shenliwan",
		"file8"    : "/obj/gift/shenliwan",
		"amount5"  : 50,
		"file3"    : "/open/mon/obj/mon-pill",
		"amount10" : 77,
		"amount2"  : 1,
	]) );
	set( "build", 10330 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room408",
		"south"     : "/open/clan/ou-cloud-club/room/room419",
	]) );
	set( "long", @LONG
這是Alus的渡假小屋，一進門來就看到整理的一塵不染的環境，顯示
出Alus是一個非常細心的人，再抬起頭往牆壁上一看，卻又看到有許
多兇猛野獸的標本掛在上面，也顯現出Alus他擁有的能力，並非一般
常人所能及。不論是從那一角度來看，都有他過人的一面。
LONG);
	setup();
	replace_program(ROOM);
}
