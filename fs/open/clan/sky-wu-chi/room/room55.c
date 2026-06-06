inherit ROOM;
void create() {
	set( "short", "$HIB$Φ $HIY$聖者幻界 $HIB$Φ$NOR$" );
	set( "build", 24 );
	set( "exits", ([
		"lazycancer" : "/open/clan/sky-wu-chi/room/room111.c",
		"lyichi"    : "/open/clan/sky-wu-chi/room/room505",
		"out"       : "/open/clan/sky-wu-chi/room/room17.c",
		"limit"     : "/open/clan/sky-wu-chi/room/room304",
		"lonsan"    : "/open/clan/sky-wu-chi/room/room140.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
在一陣七彩的光芒籠罩後..你出現再一個奇異的空間L裡
由於刀神燕仔的力量...你在這裡呼喚你自己的名字.....
就可以得到天道無極給你的奇異幻界...在這..你可以修練
你的武學...因為在結界的庇祐下...相信..一定能早日達到
深不可測的地步.....
LONG);
	setup();
	replace_program(ROOM);
}
