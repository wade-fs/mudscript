inherit ROOM;
void create() {
	set( "short", "聖彼得大教堂" );
	set( "object", ([
		"amount5"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file8"    : "/obj/gift/xiandan",
		"file7"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount1"  : 1,
		"file5"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file10"   : "/obj/gift/xiandan",
		"file4"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"file9"    : "/obj/gift/xiandan",
		"file6"    : "/obj/gift/xiandan",
		"file1"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/xiandan",
	]) );
	set( "item_desc", ([
		"note" : @ITEM
信我者得永生
死後有地獄
天堂近了
ITEM,
	]) );
	set( "owner", "ctx" );
	set( "build", 11514 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room495",
	]) );
	set( "long", @LONG
想禮拜嗎?還是要辦個西式的葬禮阿,選擇這裡就對了, 這裡
可是相當知名也有相當歷史的教堂, 裡面的西式葬禮保證讓你滿
意到沒有瑕疵可以挑剔的,當然,如果你只是信耶穌的想來這裡做
各禮拜的話也相當歡迎啦,教徒記得每星期日來禮拜喔。

           一個note貼在牆上

LONG);
	setup();
	replace_program(ROOM);
}
