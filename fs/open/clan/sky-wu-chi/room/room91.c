inherit ROOM;
void create() {
	set( "short", "D" );
	set( "build", 6 );
	set( "exits", ([
		"ddt"       : "/open/clan/sky-wu-chi/room/room512.c",
		"out"       : "/open/clan/sky-wu-chi/room/room17.c",
		"dabbie"    : "/open/clan/sky-wu-chi/room/room75",
		"doctors"   : "/open/clan/sky-wu-chi/room/room167",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
在一陣七彩的光芒籠罩後..你出現再一個奇異的空間D裡
由於刀神燕仔的力量...你在這裡呼喚你自己的名字.....
就可以得到天道無極給你的奇異幻界...在這..你可以修練
你的武學...因為在結界的庇祐下...相信..一定能早日達到
深不可測的地步.....
LONG);
	setup();
	replace_program(ROOM);
}
