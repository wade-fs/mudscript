inherit ROOM;
void create() {
	set( "short", "$HIC$【小佩的衣物間】$NOR$" );
	set( "owner", "peiyi" );
	set( "object", ([
		"file7"    : "/obj/gift/bingtang",
		"file5"    : "/open/killer/obj/k_ring",
		"amount8"  : 1,
		"amount6"  : 287,
		"amount1"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/doctor/pill/g_pill",
		"file2"    : "/open/killer/obj/k_ring",
		"amount5"  : 1,
		"file1"    : "/open/poison/obj/feather",
		"amount4"  : 1,
		"file4"    : "/obj/gift/bingtang",
		"amount3"  : 287,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file9"    : "/open/mogi/castle/obj/lochagem",
		"file10"   : "/obj/gift/hobowdan",
		"amount10" : 1,
		"file3"    : "/open/doctor/pill/taii_pill",
	]) );
	set( "build", 11616 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room303.c",
		"south"     : "/open/clan/sky-wu-chi/room/room74.c",
		"east"      : "/open/clan/sky-wu-chi/room/room311.c",
		"west"      : "/open/clan/sky-wu-chi/room/room302.c",
	]) );
	set( "long", @LONG
好不容易擠進這個小小的空間，這裡四周都是女孩子的衣物，小小只能容許一
個人轉身的空間裡，竟然能放的下上千套的服裝，只因為小佩的服裝也是小小的。
在進門的左手邊有著三排的衣架，上面放的是小佩出門時穿的漂漂衣服，這些有的
僅是小佩個人的收藏，並沒有穿過，而前方是三層的櫃子，裡面放的是小佩的貼身
衣物還有一些個人的物品，包括有一個醫藥箱，裡面放著一些神奇的藥物，還有一
些小佩個人珍藏的寶貝，而右手邊上面放的是小佩跳舞時穿的特殊服裝，還有一些
休閒服，下面擺的是好幾排的鞋子，各式各樣各種顏色。
LONG);
	setup();
	replace_program(ROOM);
}
