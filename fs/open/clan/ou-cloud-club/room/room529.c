inherit ROOM;
void create() {
	set( "short", "惡魔戰記" );
	set( "owner", "ctx" );
	set( "object", ([
		"file2"    : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"file6"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"file8"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"file3"    : "/obj/gift/xisuidan",
		"amount9"  : 1,
		"amount10" : 1,
		"file1"    : "/obj/gift/xisuidan",
		"file4"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 11385 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room528",
	]) );
	set( "long", @LONG
    「離大魔王滅世後第九九九個月蝕之日
      從黑闇出現少女手
      持正義之旗　心卻朝向黑暗
      魔界將為她歡呼　大魔王因她而復蘇」
一個從天使界接受聖命，為了阻止地獄的魔王的陰謀,而轉世成
為人類，但是在數萬年前,這名天使和過去的魔王又有者數不清
的糾葛，一場天界與魔界的紛爭就此開始。

LONG);
	setup();
	replace_program(ROOM);
}
