inherit ROOM;
void create() {
	set( "short", "H" );
	set( "build", 45 );
	set( "exits", ([
		"heronotme" : "/open/clan/sky-wu-chi/room/room113",
		"herononame" : "/open/clan/sky-wu-chi/room/room166.c",
		"out"       : "/open/clan/sky-wu-chi/room/room17",
		"hild"      : "/open/clan/sky-wu-chi/room/room168.c",
		"herozero"  : "/open/clan/sky-wu-chi/room/room150",
		"hello"     : "/open/clan/sky-wu-chi/room/room376",
		"holeman"   : "/open/clan/sky-wu-chi/room/room305",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
在一陣七彩的光芒籠罩後..你出現再一個奇異的空間H裡
由於刀神燕仔的力量...你在這裡呼喚你自己的名字.....
就可以得到天道無極給你的奇異幻界...在這..你可以修練
你的武學...因為在結界的庇祐下...相信..一定能早日達到
深不可測的地步.....
LONG);
	setup();
	replace_program(ROOM);
}
