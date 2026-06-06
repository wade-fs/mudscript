inherit ROOM;
void create() {
	set( "short", "月之金字塔四樓" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room230",
		"north"     : "/open/clan/time-limit/room/room228.c",
	]) );
	set( "long", @LONG
四周一片漆黑,點起火把,發現石壁上刻著難以理解的圖案及文字,像是訴說著這座金字塔悠
久的歷史,其中一面石壁刻著月亮從上弦月-滿月-下弦月的圖案,旁邊則是刻著滿月,原來這
裡是用月亮的圓缺來代表樓層,前方傳來陣陣聲響,古墓自動打開來,我的媽呀,是木乃伊!你
被嚇的魂飛魄散,不知所措

LONG);
	setup();
	replace_program(ROOM);
}
