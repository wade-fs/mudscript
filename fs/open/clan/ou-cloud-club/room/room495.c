inherit ROOM;
void create() {
	set( "short", "4樓天天來葬儀社" );
	set( "owner", "ctx" );
	set( "object", ([
		"file10"   : "/obj/gift/lingzhi",
		"file1"    : "/obj/gift/bingtang",
		"amount4"  : 1,
		"amount5"  : 1,
		"file4"    : "/obj/gift/bingtang",
		"amount3"  : 1,
		"file5"    : "/obj/gift/bingtang",
		"file2"    : "/obj/gift/bingtang",
		"file8"    : "/obj/gift/lingzhi",
		"amount10" : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"file9"    : "/obj/gift/lingzhi",
		"file6"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file7"    : "/obj/gift/lingzhi",
		"file3"    : "/obj/gift/lingzhi",
		"amount7"  : 1,
	]) );
	set( "build", 10944 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room500.c",
		"up"        : "/open/clan/ou-cloud-club/room/room540",
		"north"     : "/open/clan/ou-cloud-club/room/room492.c",
		"east"      : "/open/clan/ou-cloud-club/room/room493.c",
		"south"     : "/open/clan/ou-cloud-club/room/room491",
		"west"      : "/open/clan/ou-cloud-club/room/room494.c",
	]) );
	set( "long", @LONG
全FS中唯一的殯儀館,這裡提供了全套的服務,包括了要選擇
那些棺木,以及中式還是西式的葬禮,火葬還是土葬, 這裡所有的
諮詢應有盡有,不過其實這裡生意不太好,因為FS裡面的屍體都習
慣就地掩埋的, 所以其實為什麼到現在都只有一個殯儀館的原因
就在這了。

LONG);
	setup();
	replace_program(ROOM);
}
