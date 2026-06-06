inherit ROOM;
void create() {
	set( "short", "星之金字塔五樓" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room272.c",
		"north"     : "/open/clan/time-limit/room/room274",
	]) );
	set( "long", @LONG
四周一片漆黑,點起火把,發現石壁上刻著難以理解的圖案及文字,像是訴說著這座金字塔悠
久的歷史,其中一面石壁刻著北斗七星的圖案,旁邊則是刻著天機星發光的圖案,原來這裡是
用北斗七星的順序來代表樓層,前方傳來陣陣聲響,古墓自動打開來,我的媽呀!是木乃伊!你
被嚇的魂飛魄散,不知所措

LONG);
	setup();
	replace_program(ROOM);
}
