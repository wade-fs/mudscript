inherit ROOM;
void create() {
	set( "short", "最佳時間(2)" );
	set( "owner", "dfyw" );
	set( "build", 10017 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room548",
	]) );
	set( "long", @LONG
吃水果的最佳時間
飯前一小時吃水果最有益，因為水果是生食，吃生食再吃熟食，體
內就不會有白細胞增高的反應，有利於保護人體免疫系統，增強防
病抗癌的能力。
鍛煉的最佳時間
傍晚時鍛鍊身體是最好的，因為人的各種活動都受〝生物鐘〞的影
響，無論是身體的適應或體力的發揮都在下午近傍晚時分最佳，早
上則反之，運動時的血壓和心率都較傍晚時高，對人體有害。
LONG);
	setup();
	replace_program(ROOM);
}
