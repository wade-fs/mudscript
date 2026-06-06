inherit ROOM;
void create() {
	set( "short", "赫氏門徒" );
	set( "owner", "ctx" );
	set( "light_up", 1 );
	set( "object", ([
		"amount2"  : 1,
		"file8"    : "/obj/gift/xisuidan",
		"file4"    : "/obj/gift/xisuidan",
		"file10"   : "/obj/gift/xisuidan",
		"amount10" : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"file7"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"file6"    : "/obj/gift/xisuidan",
		"amount9"  : 1,
		"amount3"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10170 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room525.c",
		"down"      : "/open/clan/ou-cloud-club/room/room528",
		"north"     : "/open/clan/ou-cloud-club/room/room524.c",
		"west"      : "/open/clan/ou-cloud-club/room/room526.c",
		"up"        : "/open/clan/ou-cloud-club/room/room511",
		"south"     : "/open/clan/ou-cloud-club/room/room527.c",
	]) );
	set( "long", @LONG
一個剛剛離開了師父的十六歲少年，卻被賣到了武鬥場,成
為了最最低賤的奴隸。通過自己的努力和運氣,他終於獲得了自
由，可惜，額上卻被烙上了永遠的奴隸印記.. 戴上了藍色的面
具，他開始走進這個陌生的世界.. 一個魔法與科技交相輝映的
神奇年代，一個人類文明高度發達的未來世界.. 在這個魔法與
龍的世界裏，他走進了有著世界精神領袖地位的赫迪亞學校,開
始了他動人的傳奇。美麗而又出身高貴的少女,具有無比神秘色
彩的傳說中的龍騎將,還有那曾經帶給人類無盡憧憬和恐懼的龍
----漸漸的開始圍繞在他的周圍----

LONG);
	setup();
	replace_program(ROOM);
}
