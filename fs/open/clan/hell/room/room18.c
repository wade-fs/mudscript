inherit ROOM;
void create() {
	set( "short", "min的私房菜" );
	set( "owner", "neun" );
	set( "light_up", 1 );
	set( "build", 10656 );
	set( "exits", ([
		"south"     : "/open/clan/hell/room/room119",
		"north"     : "/open/clan/hell/room/room120.c",
		"west"      : "/open/clan/hell/room/room9",
	]) );
	set( "long", @LONG

這裡是小敏藏私房東西的地方,一般人員禁止進入,尤其是符合下面條件任一項的
若被小敏發現,一定會Sm一萬次,還要請小敏吃10頓飯已做補償

    1.$HIY$最愛小護士的人$NOR$
    2.$HIY$電腦裡有A片的人$NOR$
    3.$HIY$要考研究所的人$NOR$
    4.$HIY$抽煙的人$NOR$
    5.$HIY$龜毛的人$NOR$
    6.$HIY$處女座的人$NOR$
    7.$HIY$狗屎的人$NOR$

以上人員發現進入 隨即cjail           2002.1.2 min
            
LONG);
	setup();
	replace_program(ROOM);
}
