inherit ROOM;
void create() {
	set( "short", "$BRED$一年級$BGRN$黑魔法$BBLU$防禦課$BMAG$教室$NOR$" );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room61",
	]) );
	set( "long", @LONG
一年級新生的黑魔法防禦術是由奎若教授來教導,而奎若教授總是包著一條紫色頭巾,
具奎若教授的說法那是他為某國王子驅除一位女巫糾纏所得到的報酬,
卻因此和一個吸血鬼結下樑子,頭巾散發出強烈大蒜氣味就是怕吸血鬼忽然襲擊他,
奎若教授也因為這樣變的神經兮兮,感覺他隨時都會暈倒的樣子

LONG);
	setup();
	replace_program(ROOM);
}
