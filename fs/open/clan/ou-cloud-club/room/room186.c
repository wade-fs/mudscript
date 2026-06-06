inherit ROOM;
void create() {
	set( "short", "$HIY$金織手套$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"amount5"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file8"    : "/open/mon/obj/thousand-nectar",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"file7"    : "/open/capital/guard/gring",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount8"  : 2,
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"amount2"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/gblade/obj/sa-head",
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "light_up", 1 );
	set( "build", 12060 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room188",
		"west"      : "/open/clan/ou-cloud-club/room/room187",
	]) );
	set( "long", @LONG
         $HIR$以金絲織成的珍貴手套，其中似乎隱藏著某種魔力$NOR$



$WHT$跳躍閃躲之術(dodge)            技能效應： 3$NOR$


走到這邊...你已經看到了許多的珍貴防具
別以為這樣子就結束...後頭還很多呢..
看來風林山寨的二寨主也慘遭毒手了...連隨身的金織手套也被奪
LONG);
	setup();
	replace_program(ROOM);
}
