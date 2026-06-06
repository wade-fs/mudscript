inherit ROOM;
void create() {
	set( "short", "法院" );
	set( "exits", ([
		"up"        : "/open/clan/hell/room/room128",
		"down"      : "/open/clan/hell/room/room129.c",
	]) );
	set( "long", @LONG
這裡是冰判官審問機器人的法院，你一定是被人檢舉或是
行為太像機器人，才會來到這裡，如果你答不出冰判官的三個
問題，可是會被冰判官踢回家睡覺唷! 好好回答(answer)吧。 

  專門對付笨蛋的審判官「$HIB$冷血無言$NOR$」冰判官(Judge ice)
$HIY$冰判官問道:「$HIW$十九減掉十七等於多少?$HIY$」$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
