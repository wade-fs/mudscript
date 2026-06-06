inherit ROOM;
void create() {
	set( "short", "$HBBLU$ $HIW$ ★   $HIR$99 Ways To Die    $HIW$★  $NOR$" );
	set( "owner", "blur" );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room96.c",
		"west"      : "/open/clan/hell/room/room34.c",
		"east"      : "/open/clan/hell/room/room4",
		"south"     : "/open/clan/hell/room/room136.c",
	]) );
	set( "light_up", 1 );
	set( "build", 13755 );
	set( "long", @LONG

$MAG$大頭蛋最愛坐在客廳裡的破沙發上看MTV...
$MAG$嗯 ~ 最近都沒撥$HIC$Megadeath$MAG$的MTV..
$HIW$你鬼的$MAG$...又是$HIM$布蘭妮$MAG$要怎樣..cow
悶死人啦.....

$MAG$還是轉台看看$HIY$Z頻道$MAG$好了...
$WHT$口夷$MAG$ ~~  Die !!!!!!!
又是重播5年前的$HIG$東京情色派$MAG$... >_Q 
老妖小愛...醜死了.....

$RED$ ooxx....更!!         $HIW$凸 -,-$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
