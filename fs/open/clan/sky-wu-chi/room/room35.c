inherit ROOM;
void create() {
	set( "short", "C" );
	set( "exits", ([
		"coling"    : "/open/clan/sky-wu-chi/room/room471.c",
		"conpse"    : "/open/clan/sky-wu-chi/room/room40.c",
		"crlin"     : "/open/clan/sky-wu-chi/room/room115",
		"cdrom"     : "/open/clan/sky-wu-chi/room/room237.c",
		"out"       : "/open/clan/sky-wu-chi/room/room17.c",
		"clarinet"  : "/open/clan/sky-wu-chi/room/room438",
		"coin"      : "/open/clan/sky-wu-chi/room/room504",
		"clodsnow"  : "/open/clan/sky-wu-chi/room/room219.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
在一陣七彩的光芒籠罩後..你出現再一個奇異的空間C裡
由於刀神燕仔的力量...你在這裡呼喚你自己的名字.....
就可以得到天道無極給你的奇異幻界...在這..你可以修練
你的武學...因為在結界的庇祐下...相信..一定能早日達到
深不可測的地步.....
LONG);
	setup();
	replace_program(ROOM);
}
