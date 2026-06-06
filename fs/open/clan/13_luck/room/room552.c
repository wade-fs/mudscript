inherit ROOM;
void create() {
	set( "short", "最佳時間(3)" );
	set( "owner", "dfyw" );
	set( "object", ([
		"file8"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/mon/obj/mon-pill",
		"file7"    : "/open/fire-hole/obj/w-pill",
		"amount5"  : 49,
		"amount1"  : 100,
		"amount6"  : 100,
		"file1"    : "/open/mon/obj/mon-pill",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 40,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 4,
		"amount3"  : 300,
	]) );
	set( "build", 10039 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room548",
	]) );
	set( "long", @LONG
洗澡的最佳時間
晚上臨睡前，洗一次溫水澡能讓全身的肌肉和關節放鬆，有助於安
然入睡。
減肥的最佳時間
飯後45分鐘。在二十分鐘內散步行程1600米，最有利於減肥。如過
二小時後再散步二十分鐘，則減肥效果更佳。
睡眠的最佳時間
午睡最好從午後一小時開始，這時身體感覺較遲鈍，很容易入睡。
晚上則以十時至十一時上床最佳，因為人的深睡時間一般在夜裏十
二時至淩晨三時，而人在睡後一個半小時進入深睡狀態。

LONG);
	setup();
	replace_program(ROOM);
}
