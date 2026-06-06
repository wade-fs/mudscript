inherit ROOM;
void create() {
	set( "short", "S" );
	set( "build", 14 );
	set( "exits", ([
		"sanora"    : "/open/clan/sky-wu-chi/room/room509.c",
		"small"     : "/open/clan/sky-wu-chi/room/room433.c",
		"sqrr"      : "/open/clan/sky-wu-chi/room/room640",
		"snowman"   : "/open/clan/sky-wu-chi/room/room307.c",
		"saintber"  : "/open/clan/sky-wu-chi/room/room511.c",
		"smile"     : "/open/clan/sky-wu-chi/room/room369.c",
		"srat"      : "/open/clan/sky-wu-chi/room/room158.c",
		"out"       : "/open/clan/sky-wu-chi/room/room17.c",
		"salicili"  : "/open/clan/sky-wu-chi/room/room41.c",
		"scorpizo"  : "/open/clan/sky-wu-chi/room/room349.c",
		"sweety"    : "/open/clan/sky-wu-chi/room/room510.c",
		"shih"      : "/open/clan/sky-wu-chi/room/room244.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
在一陣七彩的光芒籠罩後..你出現再一個奇異的空間S裡
由於刀神燕仔的力量...你在這裡呼喚你自己的名字.....
就可以得到天道無極給你的奇異幻界...在這..你可以修練
你的武學...因為在結界的庇祐下...相信..一定能早日達到
深不可測的地步.....
LONG);
	setup();
	replace_program(ROOM);
}
