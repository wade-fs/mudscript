inherit ROOM;
void create() {
	set( "short", "血痕居-唐門" );
	set( "owner", "holeman" );
	set( "build", 10386 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room518.c",
	]) );
	set( "long", @LONG

    霹靂一聲鬼神驚，飛刀無痕不留影。
    奪魄追魂誅敵項，心眼獨開天地明。
    追心箭似情人淚，漫天花雨若精靈。
    蘸毒非是愛殺戮，冰魄寒光四海寧。
    天羅地網囚鼠輩，小李飛刀射流星。
    馭毒蝕骨放江湖，我行我素享太平。
    閒時漫步竹林道，來去自如任我行。
    武林正道算哪般，民族大義無心情。
    豪傑奸邪不相與，王侯將相難入庭。
    脫身世外圖自在，不求權財一身輕。



LONG);
	setup();
	replace_program(ROOM);
}
