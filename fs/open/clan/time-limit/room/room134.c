inherit ROOM;
void create() {
	set( "short", "日之金字塔五樓" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room133",
	]) );
	set( "long", @LONG
四周一片漆黑,點起火把,發現石壁上刻著難以理解的圖案及文字,像是訴說著這座金字塔悠
久的歷史,其中一面石壁刻著太陽從地平線升起到沒入的圖案,旁邊則是刻著太陽剛過中午的
圖案,原來這裡是用太陽一天的位置來代表樓層,前方傳來陣陣聲響,古墓自動打開來,我的媽
呀,是木乃伊!你被嚇的魂飛魄散,不知所措
y
LONG);
	setup();
	replace_program(ROOM);
}
