// Room : /open/clan/sky-wu-chi/room/room22.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "long", @LONG
你現在所在的地方就是空瓶子的居所的外頭，在這裡你並無感覺到有什麼的
不同你看了一下四周的景色。遠處的峻秀高山林立，且七彩煙霧迷曼。在這裡你
其實已經感到身體方面有點怪異了。看了門外的兩隻石獅，像是用一種你完全都
不知道的石頭做的。四周的景色十分的漂亮，當你正想走進一點進去裡頭時。你
發現有一股抗拒的力量，且這股力量也隨你的前進越來越重。之後你看到了一個
石碑上頭寫著『入內者死』。你心中的一股不服氣於是你更是要往前而行。
LONG);
	set( "short", "空瓶子居外頭" );
	set( "build", 318 );
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "west" : "/open/clan/sky-wu-chi/room/room11",
  "enter" : "/open/clan/sky-wu-chi/room/room50.c",
]) );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	setup();

	}
