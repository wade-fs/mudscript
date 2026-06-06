inherit ROOM;
void create() {
	set( "short", "小魚的惡夢" );
	set( "object", ([
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/killer/memory/static",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "owner", "snowy" );
	set( "build", 10386 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room740",
	]) );
	set( "long", @LONG
這裡幾乎幽暗到伸手不見五指的程度了，釵h的活死屍在你的四周漫無
目的的走來走去，而不知從何而來的慘叫聲更讓你心如刀割，一旁倒掛在矛
上的屍體尚未腐爛，死屍上屍斑點點，你的腳下傳來潺潺的流水聲，你凝神
一看，暗紅色的血水夾雜著被撕裂的人體緩緩的流向一旁的血湖，你看到許
多不知名的妖怪正聚集在血湖旁休息。
LONG);
	setup();
	replace_program(ROOM);
}
