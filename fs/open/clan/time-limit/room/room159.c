inherit ROOM;
void create() {
	set( "short", "日之金字塔一樓" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room16.c",
		"east"      : "/open/clan/time-limit/room/room160",
		"west"      : "/open/clan/time-limit/room/room155",
		"north"     : "/open/clan/time-limit/room/room158.c",
	]) );
	set( "long", @LONG
四周一片漆黑,點起火把,發現石壁上刻著難以理解的圖案及文字,像是訴說著這座金字塔悠
久的歷史,其中一面石壁刻著太陽從地平線升起到沒入的圖案,旁邊則是刻著太陽剛升起的圖
案,原來這裡是用太陽一天的位置來代表樓層,前方傳來陣陣聲響,古墓自動打開來,我的媽呀
,是木乃伊!你被嚇的魂飛魄散,不知所措

LONG);
	setup();
	replace_program(ROOM);
}
