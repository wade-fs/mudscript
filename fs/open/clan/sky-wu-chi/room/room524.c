inherit ROOM;
void create() {
	set( "short", "血痕居-太極拳" );
	set( "owner", "holeman" );
	set( "build", 10032 );
	set( "exits", ([
		"southeast" : "/open/clan/sky-wu-chi/room/room519",
		"east"      : "/open/clan/sky-wu-chi/room/room522.c",
		"south"     : "/open/clan/sky-wu-chi/room/room520.c",
	]) );
	set( "long", @LONG

縱放屈伸人莫知，諸靠纏繞我皆依。劈打推壓得進步，搬擱橫採也難敵。

鉤掤逼沉人人曉，閃驚取巧有誰知，佯輸詐走誰雲敗，引誘回衝致勝歸。

滾拴搭掃靈微妙，橫直劈砍奇更奇，截進遮攔穿心肘，迎風接步紅炮捶。

二換掃壓掛麵腳，左右邊簪莊跟腿，截前壓後無縫鎖，聲東擊西要熟識。

上籠下提君須記，進攻退閃莫遲遲，藏頭蓋面天下有，慣心剁脅世間稀。



LONG);
	setup();
	replace_program(ROOM);
}
