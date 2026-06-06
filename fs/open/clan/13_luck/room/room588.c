inherit ROOM;
void create() {
	set( "short", "新區域" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"southwest" : "/open/clan/13_luck/room/room587",
		"northeast" : "/open/clan/13_luck/room/room589",
	]) );
	set( "long", @LONG
附近遍滿了蔓藤的包圍，蔓藤不斷的向周圍生長，且上面長滿了
可怕的尖刺並不時的朝你這裏衍生了過來。隱居在木靈道內的妖物們
，不知帶何有詭異的能力，帶著驚異的嘶吼聲，一見到陌生的人闖了
進來，就開始狂叫和發了亂性的攻擊著闖進來的人。

LONG);
	setup();
	replace_program(ROOM);
}
