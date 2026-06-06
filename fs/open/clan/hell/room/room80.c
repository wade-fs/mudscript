inherit ROOM;
void create() {
	set( "short", "$HIW$長庚醫院$HIY$X皮$HIR$收藏室$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room42",
	]) );
	set( "long", @LONG

水公月老醫師因為年事已高,再加上有時外務纏身....
比如說送送宵夜..打打電話...看看Z頻道...
身為水月老醫師愛徒的小牙籤終結者...再也不好意思讓師父如此奔波..
所以他發揮長..在此開設一家專割X皮的診療室..
當然使男性恢復雄風...也是小牙籤終結者的拿手絕活...
如果你想要跟你的小牙籤說BYE BYE,或是想每晚一柱擎天的話...
記得來找怪醫小牙籤終結者喔.....

 救命專線 : 79979!! 並請告訴小牙籤終結者你的症狀...

      (症狀1)被吸乾 : tell nirvana heal代號gin
    (症狀2)老垂已已 : tell nirvana heal代號kee
      (症狀3)小牙籤 : tell nirvana heal代號sen
       (症狀4)X冷感 : tell nirvana deffire 
(症狀5)手斷腳痛青瞑 : tell nirvana heal代號ack

           如忙線...請稍後再撥.......
LONG);
	setup();
	replace_program(ROOM);
}
