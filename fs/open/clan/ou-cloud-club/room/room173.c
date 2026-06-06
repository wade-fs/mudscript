inherit ROOM;
void create() {
	set( "short", "$HIW$按摩浴缸$NOR$" );
	set( "object", ([
		"file8"    : "/open/fire-hole/obj/g-pill",
		"file10"   : "/obj/gift/shenliwan",
		"file7"    : "/open/mon/obj/thousand-nectar",
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount2"  : 167,
		"amount3"  : 65,
		"file9"    : "/open/killer/obj/atman_pill",
		"amount4"  : 12,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 3,
		"amount9"  : 198,
		"amount5"  : 38,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount1"  : 203,
		"amount10" : 1,
		"amount6"  : 163,
		"file6"    : "/open/ping/obj/poison_pill",
		"amount8"  : 22,
		"file1"    : "/open/mon/obj/mon-pill",
	]) );
	set( "owner", "dklove" );
	set( "light_up", 1 );
	set( "build", 10085 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room634",
		"east"      : "/open/clan/ou-cloud-club/room/room176.c",
	]) );
	set( "long", @LONG
這裡是佑希的家,每當佑希結束工作後,就會回到這裡來休息,
讓疲憊的身心有適當的恢復,以迎接明天的工作,佑希是個敬業
的演員,她拍過很多的作品,都很受歡迎,她希望能有更棒的演出
讓大家都能更喜歡她,也歡迎大家有空可以來看看佑希喔!!
LONG);
	setup();
	replace_program(ROOM);
}
