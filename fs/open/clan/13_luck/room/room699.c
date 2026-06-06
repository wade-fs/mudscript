inherit ROOM;
void create() {
	set( "short", "二樓west" );
	set( "object", ([
		"amount7"  : 1,
		"file7"    : "/open/main/room/sp/stone",
		"file1"    : "/open/main/room/sp/stone",
		"file2"    : "/open/main/room/sp/stone",
		"amount5"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/main/room/sp/stone",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/main/room/sp/stone",
		"amount1"  : 1,
		"file5"    : "/open/main/room/sp/stone",
		"file4"    : "/open/main/room/sp/stone",
	]) );
	set( "owner", "djlh" );
	set( "build", 10013 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room702.c",
		"north"     : "/open/clan/13_luck/room/room703",
		"east"      : "/open/clan/13_luck/room/room662.c",
	]) );
	set( "long", @LONG

   ╦╩╦╠═╗╩╩╦╩╩   以敦煌為圓心的東北東  這民族　的海岸線像一支弓╗    
   ╩═╩╚═╗══╬══   那長城　像五千年來待射的夢  我用手臂拉開這整個║    
   ╔╦╗╔═╝╦═╬═╦   土地的重  蒙古高原南下的風寫些什麼內容  漢字到║    
   ║║║╠═╝║╔╬╗║   底懂不懂　一樣膚色和面孔  跨越黃河　東　登上泰║    
   ╠╩╣╠═╝║╔╬╗║   山峰頂  我向西　引北風　晒成一身古銅  渴望著血║    
   ║  ╝╚═╝╝═╝═╝   脈相通  無限個千萬弟兄  我把天地拆封將長江水掏║    
   ║ 空  人在古老河床蛻變中  我　右拳打開了天　化身為龍  把　山河重新移動║    
   ║ 填平裂縫  將　東方　的日出調整了時空  回到洪荒　 去支配　 去操縱  我║    
   ║ 右拳打開了天　化身為龍  那　大地心臟洶湧　不安跳動  全　世界　的表情║    
   ╚只剩下一種  等待英雄　我就是那條龍  周杰倫  ｊａｙ  龍拳  by hakeks  ╝    

LONG);
	setup();
	replace_program(ROOM);
}
