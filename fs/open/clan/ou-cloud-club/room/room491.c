inherit ROOM;
void create() {
	set( "short", "FS第一公墓" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount8"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/obj/gift/lingzhi",
		"file10"   : "/obj/gift/bingtang",
		"file4"    : "/obj/gift/lingzhi",
		"file2"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"amount10" : 1,
		"file9"    : "/obj/gift/bingtang",
		"amount7"  : 1,
		"file3"    : "/obj/gift/bingtang",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file6"    : "/obj/gift/lingzhi",
		"file8"    : "/obj/gift/bingtang",
		"file7"    : "/obj/gift/bingtang",
		"amount3"  : 1,
		"file5"    : "/obj/gift/lingzhi",
	]) );
	set( "build", 17472 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room495",
	]) );
	set( "long", @LONG
選擇了土葬的話,大部分棺木就是葬於此地了,此處就是全FS
最大最豪華的公墓墓地了, 葬在此地的墓地通通興建的相當豪華
幾乎可以比美一般洋房了,此外本公墓也有管理人員,所以不用擔
心建造好的墓地會有被偷竊的風險, 這點在其他墓地常常發生一
些專門偷墓地竊賊在這裡是不可能發生的。

LONG);
	setup();
	replace_program(ROOM);
}
