inherit ROOM;
void create() {
	set( "short", "女神傳說" );
	set( "owner", "ctx" );
	set( "object", ([
		"file2"    : "/obj/gift/shenliwan",
		"file8"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"amount9"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"amount10" : 1,
		"file9"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file4"    : "/obj/gift/shenliwan",
	]) );
	set( "light_up", 1 );
	set( "build", 10050 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room531.c",
		"north"     : "/open/clan/ou-cloud-club/room/room529.c",
		"south"     : "/open/clan/ou-cloud-club/room/room532",
		"west"      : "/open/clan/ou-cloud-club/room/room530.c",
		"up"        : "/open/clan/ou-cloud-club/room/room517.c",
	]) );
	set( "long", @LONG
遙遠的異世界,路凱思神創造了大地分化出東方的「龍麟之
怒」、西方的「羽虎風華」、南方的「黑暗鳳凰」、北方的 「
長蛇圓舞」、中心的「路凱思之恩賜」、「消失的陸地」 六塊
大陸。六個大陸代表著六個人，他們就隱藏在大陸的名姓中 ，
他們代表著天地浩然正氣,大陸最終的救世主。但燦爛的光製造
濃濃的影子，他們對應著的影子也是他們對頭。 從傳說中走出
的人們,參與進牽涉到未來的爭戰之中去，他們和她們將何去何
從？一個弱質女流又是如何挽救大陸的浩劫？天與地,神和魔，
遠古的戰爭和人類又有何關係？一場立場絕對顛倒的戰爭,一個
壓倒男性的時代就要降臨了,歌頌吧！女神的時代，就要來臨了

LONG);
	setup();
	replace_program(ROOM);
}
