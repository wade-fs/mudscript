inherit ROOM;
void create() {
	set( "short", "穎穎的隱身小屋" );
	set( "object", ([
		"amount2"  : 27,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 116,
		"file5"    : "/open/killer/obj/hate_knife",
		"amount5"  : 553,
		"amount10" : 1,
		"amount1"  : 2,
		"file6"    : "/open/killer/obj/k_ring",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/killer/obj/dagger",
		"amount8"  : 1,
		"file3"    : "/obj/stone/powder",
		"amount4"  : 1,
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"amount6"  : 1,
		"file1"    : "/open/fire-hole/obj/k-pill",
		"amount7"  : 23,
		"amount9"  : 1,
		"file10"   : "/open/killer/obj/dagger",
		"file2"    : "/open/killer/obj/s_pill",
	]) );
	set( "owner", "sakira" );
	set( "light_up", 1 );
	set( "build", 10009 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room236",
	]) );
	set( "long", @LONG
這是穎穎平常休息的地方,在你面前有個非常奇怪的小盒子.....
似乎有個不可思議的寶物,你非常非常的好奇.....
卻又非常非常在意四周的環境,總覺得到處都是穎穎的身影....
逼的不敢你前進且馬上想離開這個地方.....
ㄏㄨ~~ㄏㄨ~~ㄏㄨ~~ㄏㄨ~~ㄏㄨ~~ㄏㄨ
突然穎穎出現在你的身旁....*^_^*...@#$%!


LONG);
	setup();
	replace_program(ROOM);
}
