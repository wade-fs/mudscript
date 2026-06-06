inherit ROOM;
void create() {
	set( "short", "魔劍丹藥室4" );
	set( "owner", "mekyn" );
	set( "build", 10034 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room454",
		"east"      : "/open/clan/ou-cloud-club/room/room456",
	]) );
	set( "long", @LONG


      ╭────╮  海水潮來潮去  白色的泡沫不停的出現
      ╰╮ .  ╭╯   也不停的消失  那 .....  
      ╭╯. . ╰╮  那痴情的美人魚在裡面嗎  
      │ .    ．│   還是在時間的轉移下不見了
      │  ．  . │  而我呢 .....  只是那消失的泡沫之一
      ╰────╯   我很快的出現  可能永遠的消失           mekyn筆


LONG);
	setup();
	replace_program(ROOM);
}
