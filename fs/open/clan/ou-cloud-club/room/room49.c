// Room : /open/clan/ou-cloud-club/room/room49.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$鍊金研究棟$NOR$" );
	set( "build", 10032 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "west" : "/open/clan/ou-cloud-club/room/room54.c",
  "eastdown" : "/open/clan/ou-cloud-club/room/room48",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
你來到一扇青光之門的前方,柔和的青光卻似乎想要阻止你開啟,
或許門後正有群魔張牙舞爪的準備迎接客人,看來似乎不適合以帥氣
的破門方式強行進入,最好是尋找一把可以開啟的鑰匙吧!!不過你好
像隱約聽到鐘聲由門後傳來,邪惡的地方也存在著神的淨地嗎!?
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
