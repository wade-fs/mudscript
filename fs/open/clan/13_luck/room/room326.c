inherit ROOM;
void create() {
	set( "short", "路標區" );
	set( "owner", "woan" );
	set( "object", ([
		"amount10" : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 76,
		"amount2"  : 1,
		"amount3"  : 1,
		"file6"    : "/daemon/class/blademan/obj/ublade",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"file7"    : "/daemon/class/bonze/puty_pullium",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file4"    : "/open/scholar/obj/icefan",
		"file1"    : "/open/ping/obj/poison_pill",
		"file10"   : "/open/port/obj/wolf_ring",
		"amount5"  : 1,
		"amount1"  : 27,
	]) );
	set( "build", 11454 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room123.c",
		"west"      : "/open/clan/13_luck/room/room159",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    
    進來後..你看到一個標示牌..上面寫著
      
       想聽woan 演唱會的請往西
      
       想看woan 練功室的請網東 
此時你想.woan身為一個三刀流鬼斬傳人
有練功室不足為奇..但..一個刀客竟會開
演唱會...你也覺的.不可相信.但.一條條
動聽的歌曲打亂了你的思緒..而你所不相
信的事.卻一一的變事實了.而你只想做一
件事.就是過去聽好聽的歌曲.


LONG);
	setup();
	replace_program(ROOM);
}
