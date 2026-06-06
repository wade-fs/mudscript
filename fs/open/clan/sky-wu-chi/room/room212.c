inherit ROOM;
void create() {
	set( "short", "jtl的主臥房" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "object", ([
		"file3"    : "/obj/gift/bingtang",
		"amount10" : 1,
		"amount2"  : 43,
		"file10"   : "/obj/gift/lingzhi",
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount9"  : 1,
		"file2"    : "/open/killer/obj/black",
		"file4"    : "/obj/gift/lingzhi",
		"amount6"  : 1,
		"file9"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10010 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"enter"     : "/open/clan/sky-wu-chi/room/room318.c",
		"east"      : "/open/clan/sky-wu-chi/room/room213.c",
	]) );
	set( "long", @LONG
在這裡可以看到這個房間的主人,也就是刀姬小青..能看到她
是你這輩子最榮幸的事,因為他不一定是你想見就可以見到的人
這幾天,他為了一些事正出去尋找失落的花瓶,你可以看到裡面
是一個很樸素的房間,並沒有太大的奢華氣息,但是你卻感覺
有一股自然的殺氣存在,這代表著刀姬小青的殺氣還留在
裡面所導致的結果,你在裡面不安的坐著等小青的到來,心裡也恍
恍不安...

LONG);
	setup();
	replace_program(ROOM);
}
