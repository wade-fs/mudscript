inherit ROOM;
void create() {
	set( "short", "立法怨" );
	set( "object", ([
		"amount1"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"file3"    : "/obj/gift/lingzhi",
		"amount3"  : 1,
		"file6"    : "/obj/gift/lingzhi",
		"file4"    : "/obj/gift/bingtang",
		"file7"    : "/obj/gift/lingzhi",
		"file9"    : "/obj/gift/bingtang",
		"amount4"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file8"    : "/obj/gift/lingzhi",
		"amount10" : 1,
		"file1"    : "/obj/gift/bingtang",
		"file10"   : "/obj/gift/lingzhi",
		"amount5"  : 1,
		"amount8"  : 1,
		"file5"    : "/obj/gift/bingtang",
	]) );
	set( "owner", "ctx" );
	set( "build", 10170 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room500",
	]) );
	set( "long", @LONG
這裡就是全國最會製造民怨的機關了,從以前的打架,到現在
的低議事效率,都是相當令人嘖嘖稱奇的事情,像是目前尚未通過
的diamond六法,就是最明顯的範例, 不會好好審查案子導致FS經
濟不振,現在還在搞什麼『豬頭』法案,由此可見立法怨從古至今
引起多少民怨喔。

LONG);
	setup();
	replace_program(ROOM);
}
