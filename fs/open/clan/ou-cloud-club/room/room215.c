inherit ROOM;
void create() {
	set( "short", "$HIR$天$NOR$　$HIC$之$NOR$　$HIM$劫　$NOR$" );
	set( "owner", "kent" );
	set( "object", ([
		"file8"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/obj/stone/powder",
		"file10"   : "/open/capital/obj/blade2",
		"amount2"  : 107,
		"amount7"  : 96,
		"amount8"  : 1,
		"amount10" : 1,
		"amount6"  : 57,
		"file5"    : "/open/capital/obj/4-3",
		"amount1"  : 1102,
		"file3"    : "/obj/stone/jiao",
		"amount4"  : 144,
		"file9"    : "/open/capital/obj/4-3",
		"amount5"  : 1,
		"file2"    : "/obj/stone/suipian",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 14,
		"file7"    : "/open/mon/obj/mon-pill",
		"amount9"  : 1,
	]) );
	set( "build", 11260 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room243",
		"east"      : "/open/clan/ou-cloud-club/room/room214",
		"west"      : "/open/clan/ou-cloud-club/room/room241.c",
	]) );
	set( "long", @LONG

當秋天　再來的時候　　妳要我　笑著去愛去擁有
就算是　再短暫的溫柔　能重逢　這仁慈已足夠
可知道　有些事有些人　停留在　發生的那天不肯走

看時光的殘酷　　捨不得被遺忘　這命運我很滿足
有妳陪伴的幸福　為妳打開時間的鎖

讓愛自由　不被它束縛　是哭過　也掙扎過　心讓痛輾過
等那一天　落葉靜靜飄眼前　已不再傷悲　永恆終於相信了幸福的瞬間

為妳打開　時間的鎖　讓愛自由　不被它束縛　每一秒　都不後悔
我陪妳體會　過去未來　輕輕重疊　請原諒甜甜的眼淚
感謝今生與妳在　幸福的瞬間　依偎

LONG);
	setup();
	replace_program(ROOM);
}
