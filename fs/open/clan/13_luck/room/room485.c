inherit ROOM;
void create() {
	set( "short", "通天閣" );
	set( "object", ([
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"file4"    : "/open/magic-manor/obj/sun-heart",
		"file3"    : "/open/center/obj/mechoufen-head",
		"amount7"  : 1,
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount10" : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount8"  : 827,
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/obj/lunar-heart",
		"file5"    : "/open/center/obj/mechoufen-head",
		"file1"    : "/open/center/obj/mechoufen-head",
		"file9"    : "/open/magic-manor/obj/lunar-heart",
		"file8"    : "/open/ping/obj/poison_pill",
		"amount9"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
	]) );
	set( "owner", "zmud" );
	set( "build", 10021 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room354",
	]) );
	set( "long", @LONG

一進到此處發現四周風景一覽無遺,可真是可賞景的好地方,在閣樓的
正中央擺設的一組精緻的茶具,看樣子常常有人到這裡享受泡茶聊天的
樂趣,還發現有兩跟樑柱間懸掛這網狀的吊床,大概還有人非常喜歡在
這裡休息,想想還真是個不錯的享受.~抬頭向上看看到樑上寫這
,紅塵俗事憂---獨我笑紅塵!
,紅塵俗事憂---獨我笑紅塵!

LONG);
	setup();
	replace_program(ROOM);
}
