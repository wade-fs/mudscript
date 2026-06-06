inherit ROOM;
void create() {
	set( "short", "幻魔的健身房" );
	set( "owner", "ads" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room165.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

                ◢██◣                ◢██◣
                █㊣██　　　★★　　　██㊣█
                ██㊣█　　　★★　　　█㊣██
                ◥██◤                ◥██◤

進來後可以看到左邊放的慢跑機，此機不但可以輕鬆的慢跑還
可以邊聽音樂，右邊放了一台腳力機可以鍛鍊強健的小腿肌，在中
間還有台擴胸機，男人可練就雄厚的胸肌，女人則可展現出挺拔的
胸部。
LONG);
	setup();
	replace_program(ROOM);
}
