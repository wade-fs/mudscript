inherit ROOM;

void create()
{
        seteuid(getuid());
        set( "short", "『碧綠石道』" );
        set( "cmkroom", 1 );
        set( "exits", ([ /* sizeof() == 2 */
  "west" : "/open/clan/orient/room/room34.c",
  "east" : "/open/clan/orient/room/room29.c",
]) );
        set( "clan_room", "煙雨江南" );
        set( "light_up", 1 );
        set( "no_transmit", 1 );
        set( "outdoor", "/open/clan" );
        set( "long", "青石板鋪成的街道向兩側綿延過去，天空中時時飄著輕盈如飛花的細細
雨絲，沾得路面潤著青青的苔綠；行走至此人跡漸少，但聞湯湯流水如奏宮
商，更有那兩岸楊柳綠袖相招，枝頭鶯燕穿梭啁啾，聊慰寂寥之情。
" );
        set( "no_clean_up", 0 );
        setup();
        replace_program(ROOM);
        }
