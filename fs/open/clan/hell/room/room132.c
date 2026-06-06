inherit ROOM;
void create() {
	set( "short", "中央驛站" );
	set( "owner", "vatsu" );
	set( "exits", ([
		"up"        : "/open/clan/hell/room/room129",
		"down"      : "/open/clan/hell/room/room23.c",
		"north"     : "/open/clan/hell/room/room131.c",
	]) );
	set( "long", @LONG
這兒就是最最出名的驛站, 鑣局的車隊, 來往於沙漠的駱駝隊, 甚
至是牛馬騾車, 幾乎只要你叫得出名字的交通工具這兒都有。

$HIY$在這裡，你可以使用(transfer)指令前往你以前曾經去過的驛站!!$NOR$

    白雲在天空中飄來飄去。
    太陽剛從東方的地平線升起。
  「$RED$小辣椒$NOR$」賣火柴的小辣妹(Sale girl)$HIM$(發呆中)$NOR$
  天道派第五代女弟子「$HIY$發呆天王$NOR$」(聊天專用)小敏(min)$HIC$(輸入文字中)$NOR$
  $HIW$漩羽$HIY$刀皇$NOR$「代tin中」(壞人)歐尼克斯(onyx) $HIG$(機器人中)$NOR$  
  $YEL$大$RED$壞$GRN$蛋$NOR$「$HIW$@@?$HIC$<<=$HIY$猴子$HIG$抓$HIR$跳蚤$NOR$」大飛(blur)$HIY$(看閣樓中)$NOR$
  $HIR$當$HIG$代$HIY$殺$HIB$手$NOR$ 藤木直人(neun)
  $HIR$當$HIG$代$HIY$殺$HIB$手$NOR$「$HIR$鬼   $HIC$武   $HIM$者   $HIG$2$NOR$」一粒沙白(ssc)
  $HIR$殺手全力追殺的人頭$NOR$「$HIY$越死越tin$HIC$,tin了又死$NOR$」天殺(php)
LONG);
	setup();
	replace_program(ROOM);
}
