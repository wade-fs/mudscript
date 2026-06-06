inherit ROOM;
void create() {
	set( "short", "$HIB$麒麟甲$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"amount5"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/mogi/dragon/obj/key",
		"file7"    : "/open/mogi/dragon/obj/key",
		"file5"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"file6"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"file1"    : "/open/mogi/dragon/obj/key",
		"file10"   : "/open/mogi/dragon/obj/key",
		"file3"    : "/open/ping/obj/cloud_fan",
		"file2"    : "/open/mogi/dragon/obj/key",
		"file4"    : "/open/common/obj/liz_meat",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/common/obj/liz_meat",
	]) );
	set( "light_up", 1 );
	set( "build", 10089 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room186",
		"west"      : "/open/clan/ou-cloud-club/room/room169.c",
	]) );
	set( "long", @LONG
    $HIR$傳說中古代麒麟身上護甲所製成，具強大的防禦力$NOR$


$WHT$撲擊格鬥技巧(unarmed)          技能效應： 3$NOR$
$WHT$拆招卸力之術(parry)            技能效應： 4$NOR$


此為風林山寨的二寨主...劉信的貼身至寶
怎麼會在這邊呢.....原來前些日子劉信的死...
是小馬所為....
LONG);
	setup();
	replace_program(ROOM);
}
