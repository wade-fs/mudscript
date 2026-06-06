inherit ROOM;
void create() {
	set( "short", "沙塵暴" );
	set( "owner", "mill" );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"file6"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 11338 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room132",
	]) );
	set( "long", @LONG

    塵埃落定，這裡寂靜一片，地上只有少許的沙粒緩緩移動，似乎到了
這裡一切都平靜了，沒有任何的困擾煩著自己的腦袋，當一切都安心時，
地上的沙粒移動速度變快，忽然，眼前彌蔓著片片沙塵，以疾速的速度往
你逼進，你四處尋找躲避之處，發現到左邊有口乾井，你二話不說，一下
就往底下跳，到了井底，你仰頭看著上面飛馳而過的沙粒，感嘆的笑一笑
，原來十三的煙雨沙塵暴如此宏偉，難怪被稱為幫派奇景之一。

LONG);
	setup();
	replace_program(ROOM);
}
