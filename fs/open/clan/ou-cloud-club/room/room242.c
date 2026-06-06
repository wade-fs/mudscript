inherit ROOM;
void create() {
	set( "short", "$HIG$無  $HIB$心  $HIY$界$NOR$" );
	set( "owner", "vice" );
	set( "object", ([
		"amount9"  : 271,
		"amount4"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/mon/obj/mon-pill",
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"amount5"  : 56,
		"file1"    : "/open/marksman/obj/dragon_bow",
		"amount6"  : 1,
		"amount2"  : 534,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"amount1"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/open/dancer/obj/yuawaist",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 1,
	]) );
	set( "build", 10425 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room241",
	]) );
	set( "long", @LONG
天真的笑容  已令我情動
這生中是你陪我  創出無盡的夢
                                                                                
深刻的笑容  已幻化迷夢
我無法再接近你  我心已被困於漆黑晚空
                                                                                
無心  怎會  要得痴心瞞騙
盼望你會再回看  你的眼神會將生命燃亮
                                                                                
無心  可會  再賜我光輝明天
笑問誰可  這生追尋回憶中的光明
我是寧可  每天追尋回憶中的流星

LONG);
	setup();
	replace_program(ROOM);
}
